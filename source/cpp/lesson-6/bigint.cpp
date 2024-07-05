/*
 * This program implements arbitrary arithmetic for integer numbers.
 *
 * Author: Vincent Wei
 *  - <https://github.com/VincentWei>
 *  - <https://gitee.com/vincentwei7>
 *
 * Copyright (C) 2024 FMSoft <https://www.fmsoft.cn>.
 * License: GPLv3
 */
#include <vector>
#include <string>
#include <cstdint>

class BigInt {
    bool _sign;
    std::vector<int8_t> _bytes;

  public:
    BigInt() {
        _sign = false;
    }

    BigInt(intmax_t native_int);
    BigInt(const std::string& str);
    BigInt(const BigInt &other);            // copy constructor
    BigInt(const BigInt &&other);           // move constructor

    bool sign() const { return _sign; }
    const std::vector<int8_t>& bytes() const { return _bytes; }

    BigInt& operator= (const BigInt& other);
    // BigInt& operator= (const BigInt&& other);
    BigInt& operator= (intmax_t native_int);

    BigInt operator+ (const BigInt& other) const;
    BigInt& operator+= (const BigInt& other);

    BigInt& operator- (const BigInt& other) const;
    BigInt& operator-= (const BigInt& other);
    BigInt& operator- () const;             // -bi

    BigInt& operator++ ();                  // ++bi
    BigInt& operator++ (int);               // bi++

    BigInt& operator-- ();                  // --bi
    BigInt& operator-- (int);               // bi--

    BigInt& operator* (const BigInt& other) const;
    BigInt& operator*= (const BigInt& other);

    BigInt& operator/ (const BigInt& other) const;
    BigInt& operator/= (const BigInt& other);

    BigInt& operator% (const BigInt& other) const;
    BigInt& operator%= (const BigInt& other);

    bool operator== (const BigInt& other) const;
    bool operator!= (const BigInt& other) const;
    bool operator> (const BigInt& other) const;
    bool operator>= (const BigInt& other) const;
    bool operator< (const BigInt& other) const;
    bool operator<= (const BigInt& other) const;
};

#include <iostream>

using namespace std;

BigInt::BigInt(intmax_t native_int)
{
    if (native_int < 0) {
        _sign = true;
        native_int = -native_int;
    }
    else
        _sign = false;

    for (size_t i = 0; i < sizeof(intmax_t); i++) {
        if (native_int == 0)
            break;

        int8_t r = native_int % 100;
        _bytes.push_back(r);
        native_int /= 100;
    }
}

BigInt::BigInt(const string& str)
{
    size_t len = str.length();
    if (len == 0) {
        _sign = false;
        _bytes.clear();
        return;
    }

    if (str[0] == '-')
        _sign = true;
    else
        _sign = false;

    size_t left = len;
    size_t two_digits = _sign ? 2 : 1;
    size_t one_digit = _sign ? 1 : 0;
    while (left > 0) {
        string digits;
        if (left > two_digits) {
            digits = str.substr(left - 2, 2);
            left -= 2;
        }
        else if (left > one_digit) {
            digits = str.substr(left - 1, 1);
            left -= 1;
        }

        if (digits.empty()) {
            break;
        }

        int r = stoi(digits);
        _bytes.push_back(r);
    }
}

BigInt::BigInt(const BigInt &other)
{
    _sign = other.sign();
    _bytes = other.bytes();
}

BigInt::BigInt(const BigInt &&other)
{
    cout << "move constructor called\n";
    _sign = other._sign;
    _bytes = std::move(other._bytes);
}

BigInt& BigInt::operator= (const BigInt& other)
{
    _sign = other._sign;
    _bytes = other._bytes;
    return *this;
}

#if 0
BigInt& BigInt::operator= (const BigInt&& other)
{
    _sign = other._sign;
    // _bytes = other._bytes;
    _bytes = std::move(tmp._bytes);
    return *this;
}
#endif

BigInt& BigInt::operator= (intmax_t native_int)
{
    BigInt tmp(native_int);
    _sign = tmp._sign;
    _bytes = std::move(tmp._bytes);
    return *this;
}

BigInt BigInt::operator+ (const BigInt& other) const
{
    BigInt result;

    size_t len_a = this->_bytes.size();
    size_t len_b = other._bytes.size();
    size_t len_max = (len_a > len_b) ? len_a : len_b;

    int c = 0;
    for (size_t i = 0; i < len_max; i++) {
        int n_a = (i < len_a) ? this->_bytes[i] : 0;
        int n_b = (i < len_b) ? other._bytes[i] : 0;

        int r = n_a + n_b + c;
        if (r >= 100) {
            c = 1;
            r -= 100;
        }
        else
            c = 0;

        result._bytes.push_back(r);
    }

    if (c > 0) {
        result._bytes.push_back(c);
    }

    return result;
}

ostream& operator<< (ostream& os, const BigInt& bi) {
    if (bi.sign()) {
        os << "-";
    }

    auto bytes = bi.bytes();
    size_t len = bytes.size();
    if (len == 0) {
        os << "0";
    }
    else {
        for (size_t i = len - 1; ; i--) {
            int r = (int)bytes[i];
            if (i == len - 1) {
                os << r;
            }
            else {
                if (r < 10)
                    os << "0";
                os << r;
            }

            if (i == 0)
                break;
        }
    }

    return os;
}

#include <cassert>
#include <sstream>

int main()
{
    BigInt a(1234567890);

    ostringstream oss;
    oss << a;
    assert(oss.str() == "1234567890");
    oss.str("");

    BigInt b(-1234567890);
    oss << b;
    assert(oss.str() == "-1234567890");
    oss.str("");

    BigInt c("123456789");
    oss << c;
    assert(oss.str() == "123456789");
    oss.str("");

    BigInt d("-123456789");
    oss << d;
    assert(oss.str() == "-123456789");
    oss.str("");

    BigInt e("0");
    oss << e;
    assert(oss.str() == "0");
    oss.str("");

    BigInt f("10");
    oss << f;
    assert(oss.str() == "10");
    oss.str("");

    BigInt g("");
    oss << g;
    assert(oss.str() == "0");
    oss.str("");

    g = a;
    oss << g;
    assert(oss.str() == "1234567890");
    oss.str("");

    g = 121;
    oss << g;
    assert(oss.str() == "121");
    oss.str("");

    cout << a << endl;
    cout << " " << c << endl;

    oss << a + c;
    cout << a + c << endl;
    assert(oss.str() == "1358024679");
    oss.str("");
}

