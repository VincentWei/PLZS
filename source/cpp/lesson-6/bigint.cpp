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
        _bytes.push_back(0);
    }

    BigInt(intmax_t native_int);
    BigInt(const std::string& str);
    BigInt(const BigInt &other);            // copy constructor
    BigInt(const BigInt &&other);           // move constructor

    bool sign() const { return _sign; }
    const std::vector<int8_t>& bytes() const { return _bytes; }

    BigInt& operator= (const BigInt& other);
    BigInt& operator= (intmax_t native_int);

    BigInt& operator+ (const BigInt& other) const;
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
        _bytes.push_back(0);
        return;
    }

    if (str[0] == '-')
        _sign = true;
    else
        _sign = false;

    size_t left = _sign ? len - 1 : len;
    while (left > 0) {
        string digits;
        size_t pos = len - left;
        if (left > 1) {
            digits = str.substr(pos, 2);
            left -= 2;
        }
        else {
            digits = str.substr(pos, 1);
            left -= 1;
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

BigInt& BigInt::operator= (intmax_t native_int)
{
    BigInt tmp(native_int);
    _sign = tmp._sign;
    _bytes = std::move(tmp._bytes);
    return *this;
}

ostream& operator<< (ostream& os, const BigInt& bi) {
    if (bi.sign()) {
        os << "-";
    }

    auto bytes = bi.bytes();
    for (auto it = end(bytes); ; --it) {
        if (it == end(bytes))
            continue;

        os << (int)*it;
        if (it == begin(bytes))
            break;
    }

    return os;
}

#include <cassert>

int main()
{
    BigInt a(1234567890);
    cout << a << endl;

    BigInt b(-1234567890);
    cout << b << endl;

    BigInt c("123456789");
    cout << c << endl;

    BigInt d("-123456789");
    cout << d << endl;

    BigInt e("0");
    cout << e << endl;

    BigInt f("10");
    cout << f << endl;

    BigInt g("");
    cout << g << endl;

    g = a;
    cout << g << endl;

    g = 121;
    cout << g << endl;
}

