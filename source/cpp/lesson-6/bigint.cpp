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

    BigInt operator- () const;             // -bi
    BigInt& operator- (const BigInt& other) const;
    BigInt& operator-= (const BigInt& other);

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

  private:
    bool iszero() const;
    void absadd(const BigInt& other, BigInt& result) const;
    void absaddto(const BigInt& other);
    int  abscmp(const BigInt& other) const;
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
    _bytes = std::move(other._bytes);
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

bool BigInt::iszero() const
{
    if (_bytes.size() == 0 ||
            (_bytes.size() == 1 && _bytes[0] == 0))
        return true;

    return false;
}

void BigInt::absadd(const BigInt& other, BigInt &result) const
{
    size_t len_a = this->_bytes.size();
    size_t len_b = other._bytes.size();
    size_t len_max = (len_a > len_b) ? len_a : len_b;

    result._bytes.clear();

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
}

void BigInt::absaddto(const BigInt& other)
{
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

        if (i >= len_a)
            _bytes.push_back(r);
        else
            _bytes[i] = r;
    }

    if (c > 0) {
        _bytes.push_back(c);
    }
}

BigInt BigInt::operator+ (const BigInt& other) const
{
    BigInt result;
    if (_sign == other._sign) {
        absadd(other, result);
        result._sign = _sign;
    }
    // TODO

    return result;
}

BigInt& BigInt::operator+= (const BigInt& other)
{
    absaddto(other);
    return *this;
}

BigInt BigInt::operator- () const
{
    if (iszero())
        return *this;

    BigInt result(*this);
    result._sign = !_sign;
    return result;
}

int BigInt::abscmp(const BigInt& other) const
{
    size_t len_a = this->_bytes.size();
    size_t len_b = other._bytes.size();
    size_t len_max = (len_a > len_b) ? len_a : len_b;

    size_t i = len_max;
    while (i > 0) {
        int n_a = (i - 1 < len_a) ? this->_bytes[i - 1] : 0;
        int n_b = (i - 1 < len_b) ? other._bytes[i - 1] : 0;

        int cmp = n_a - n_b;
        if (cmp != 0)
            return cmp;

        i--;
    }

    return 0;
}

bool BigInt::operator== (const BigInt& other) const
{
    if (_sign == other._sign && abscmp(other) == 0)
        return true;

    return false;
}

bool BigInt::operator!= (const BigInt& other) const
{
    if (_sign == other._sign && abscmp(other) == 0)
        return false;

    return true;
}

bool BigInt::operator> (const BigInt& other) const
{
    if (!_sign && other._sign)
        return true;

    if (_sign && !other._sign)
        return false;

    int r = abscmp(other);
    cout << r << endl;

    // same sign
    if (!_sign)
        return r > 0;

    return r < 0;
}

bool BigInt::operator>= (const BigInt& other) const
{
    if (!_sign && other._sign)
        return true;

    if (_sign && !other._sign)
        return false;

    // same sign
    if (!_sign)
        return abscmp(other) >= 0;

    return abscmp(other) <= 0;
}

bool BigInt::operator< (const BigInt& other) const
{
    if (!_sign && other._sign)
        return false;

    if (_sign && !other._sign)
        return true;

    // same sign
    if (!_sign)
        return abscmp(other) < 0;

    return abscmp(other) > 0;
}

bool BigInt::operator<= (const BigInt& other) const
{
    if (!_sign && other._sign)
        return false;

    if (_sign && !other._sign)
        return true;

    // same sign
    if (!_sign)
        return abscmp(other) <= 0;

    return abscmp(other) >= 0;
}

ostream& operator<< (ostream& os, const BigInt& bi)
{
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
    static intmax_t cases[] = {
        1234567890,
        1204507800,
        123456789,
        10999,
        999,
        123,
        100,
        70,
        10,
        7,
        0,
        -7,
        -10,
        -70,
        -100,
        -123,
        -999,
        -10999,
        -123456789,
        -1204507800,
        -1234567890,
    };

    for (size_t i = 0; i < sizeof(cases)/sizeof(cases[0]); i++) {
        intmax_t ntv_a = cases[i];
        string   str_a = to_string(ntv_a);
        BigInt   big_a(ntv_a);
        BigInt   big_aa(str_a);

        ostringstream oss;
        oss << big_a;
        assert(oss.str() == str_a);
        assert(big_a == big_aa);

        for (size_t j = 0; j < sizeof(cases)/sizeof(cases[0]); j++) {
            intmax_t ntv_b = cases[j];
            BigInt   big_b(cases[j]);

            cout << "compare " << ntv_a << " and " << ntv_b << endl;
            cout << "compare " << big_a << " and " << big_b << endl;

            bool exp_r, act_r;
            exp_r = (ntv_a == ntv_b);
            act_r = (big_a == big_b);
            cout << "ntv_int compare: " << exp_r << endl;
            cout << "big_int compare: " << act_r << endl;
            assert(exp_r == act_r);

            exp_r = (ntv_a != ntv_b);
            act_r = (big_a != big_b);
            assert(exp_r == act_r);

            exp_r = (ntv_a > ntv_b);
            act_r = (big_a > big_b);
            cout << "ntv_int compare: " << exp_r << endl;
            cout << "big_int compare: " << act_r << endl;
            assert(exp_r == act_r);

            exp_r = (ntv_a >= ntv_b);
            act_r = (big_a >= big_b);
            assert(exp_r == act_r);

            exp_r = (ntv_a < ntv_b);
            act_r = (big_a < big_b);
            assert(exp_r == act_r);

            exp_r = (ntv_a <= ntv_b);
            act_r = (big_a <= big_b);
            assert(exp_r == act_r);

            string str_ntv_r;

            oss.str("");
            oss << -big_b;
            str_ntv_r = to_string(-ntv_b);
            cout << oss.str() << endl;
            cout << str_ntv_r << endl;
            assert(oss.str() == str_ntv_r);

            // TODO
            if ((ntv_a >= 0 && ntv_b >= 0) ||
                    (ntv_a < 0 && ntv_b < 0)) {
                oss.str("");
                oss << big_a + big_b;
                str_ntv_r = to_string(ntv_a + ntv_b);
                assert(oss.str() == str_ntv_r);
            }
        }
    }
}

