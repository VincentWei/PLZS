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
#include <cassert>

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
    BigInt(BigInt &&other);                 // move constructor

    bool sign() const { return _sign; }
    const std::vector<int8_t>& bytes() const { return _bytes; }

    BigInt& operator= (const BigInt& other);        // copy assignment operator
    BigInt& operator= (BigInt&& other) noexcept;    // move assignment operator
    BigInt& operator= (intmax_t native_int);

    BigInt operator+ (const BigInt& other) const;
    BigInt& operator+= (const BigInt& other);

    BigInt operator- () const;             // -bi
    BigInt operator- (const BigInt& other) const;
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
    void normalize();
    bool iszero() const;
    void absadd(const BigInt& other, BigInt& result) const;
    void absaddto(const BigInt& other);
    int  abscmp(const BigInt& other) const;

    void abssub(const BigInt& other, BigInt& result) const;
    void abssubfrom(const BigInt& other);
};

#include <iostream>

using namespace std;

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
    clog << "copy constructor called\n";
    _sign = other.sign();
    _bytes = other.bytes();
}

BigInt::BigInt(BigInt &&other)
{
    clog << "move constructor called\n";
    _sign = other._sign;
    _bytes.clear();
    _bytes = std::move(other._bytes);
}

BigInt& BigInt::operator= (const BigInt& other)
{
    clog << "copy assignment operator called\n";

    _sign = other._sign;
    _bytes = other._bytes;
    return *this;
}

// move assignment operator
BigInt& BigInt::operator= (BigInt&& other) noexcept
{
    clog << "move assignment operator called\n";

    if (this != &other) {
        _sign = other._sign;
        _bytes.clear();
        _bytes = std::move(other._bytes);
    }

    return *this;
}

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

    int carry = 0;
    for (size_t i = 0; i < len_max; i++) {
        int n_a = (i < len_a) ? this->_bytes[i] : 0;
        int n_b = (i < len_b) ? other._bytes[i] : 0;

        int r = n_a + n_b + carry;
        if (r >= 100) {
            carry = 1;
            r -= 100;
        }
        else
            carry = 0;

        result._bytes.push_back(r);
    }

    if (carry > 0) {
        result._bytes.push_back(carry);
    }
}

void BigInt::absaddto(const BigInt& other)
{
    size_t len_a = this->_bytes.size();
    size_t len_b = other._bytes.size();
    size_t len_max = (len_a > len_b) ? len_a : len_b;

    int carry = 0;
    for (size_t i = 0; i < len_max; i++) {
        int n_a = (i < len_a) ? this->_bytes[i] : 0;
        int n_b = (i < len_b) ? other._bytes[i] : 0;

        int r = n_a + n_b + carry;
        if (r >= 100) {
            carry = 1;
            r -= 100;
        }
        else
            carry = 0;

        if (i >= len_a)
            _bytes.push_back(r);
        else
            _bytes[i] = r;
    }

    if (carry > 0) {
        _bytes.push_back(carry);
    }
}

void BigInt::normalize()
{
    auto it = end(_bytes);
    while (it != begin(_bytes)) {
        it--;

        int n = *it;
        if (n == 0)
            _bytes.pop_back();
        else
            break;
    }

    /* check if it is zero */
    if (it == begin(_bytes) && *it == 0)
        _sign = false;
}

/* this must be large than other */
void BigInt::abssub(const BigInt& other, BigInt &result) const
{
    size_t len_a = this->_bytes.size();
    size_t len_b = other._bytes.size();
    size_t len_max = (len_a > len_b) ? len_a : len_b;

    result._bytes.clear();

    int borrow = 0;
    for (size_t i = 0; i < len_max; i++) {
        int n_a = (i < len_a) ? this->_bytes[i] : 0;
        int n_b = (i < len_b) ? other._bytes[i] : 0;

        int r;
        if (n_a - borrow >= n_b) {
            r = n_a - borrow - n_b;
            borrow = 0;
        }
        else {
            r = n_a - borrow + 100 - n_b;
            borrow = 1;
        }

        result._bytes.push_back(r);
    }

    assert(borrow == 0);
    result.normalize();
}

/* this must be large than other */
void BigInt::abssubfrom(const BigInt& other)
{
    size_t len_a = this->_bytes.size();
    size_t len_b = other._bytes.size();
    size_t len_max = (len_a > len_b) ? len_a : len_b;

    for (size_t i = 0; i < len_max; i++) {
        int n_a = (i < len_a) ? this->_bytes[i] : 0;
        int n_b = (i < len_b) ? other._bytes[i] : 0;

        int r;
        if (n_a >= n_b) {
            r = n_a - n_b;
        }
        else {
            assert(i + 1 < len_a);

            r = n_a + 100 - n_b;
            _bytes[i + 1] -= 1;
        }

        _bytes[i] = r;
    }

    normalize();
}

BigInt BigInt::operator+ (const BigInt& other) const
{
    BigInt result;

    if (other.iszero()) {
        return *this;
    }
    else if (_sign == other._sign) {
        absadd(other, result);
        result._sign = _sign;
    }
    else {
        int cmp = abscmp(other);
        if (cmp == 0) {
            return result;
        }
        else if (cmp > 0) {
            abssub(other, result);
            result._sign = _sign;
        }
        else {      // cmp < 0
            other.abssub(*this, result);
            result._sign = other._sign;
        }
    }

    return result;
}

BigInt& BigInt::operator+= (const BigInt& other)
{
    if (other.iszero()) {
        return *this;
    }

    if (_sign == other._sign) {
        absaddto(other);
    }
    else {
        int cmp = abscmp(other);
        if (cmp == 0) {
            _sign = false;
            _bytes.clear();
            return *this;
        }
        else if (cmp > 0) {
            abssubfrom(other);
        }
        else {      // cmp < 0
            BigInt result;
            other.abssub(*this, result);
            _sign = other._sign;
            _bytes = std::move(result._bytes);
        }
    }

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

BigInt BigInt::operator- (const BigInt& other) const
{
    if (other.iszero()) {
        return *this;
    }

    BigInt result;
    if (_sign != other._sign) {
        absadd(other, result);
        result._sign = _sign;
    }
    else {
        int cmp = abscmp(other);
        if (cmp == 0) {
            return result;
        }
        else if (cmp > 0) {
            abssub(other, result);
            result._sign = _sign;
        }
        else {      // cmp < 0
            other.abssub(*this, result);
            result._sign = !_sign;
        }
    }

    return result;
}

BigInt& BigInt::operator-= (const BigInt& other)
{
    if (other.iszero()) {
        return *this;
    }

    if (_sign != other._sign) {
        absaddto(other);
    }
    else {
        int cmp = abscmp(other);
        if (cmp == 0) {
            _sign = false;
            _bytes.clear();
        }
        else if (cmp > 0) {
            abssubfrom(other);
        }
        else {      // cmp < 0
            BigInt result;
            other.abssub(*this, result);
            _sign = !_sign;
            _bytes = std::move(result._bytes);
        }
    }

    return *this;
}

int BigInt::abscmp(const BigInt& other) const
{
    size_t len_a = this->_bytes.size();
    size_t len_b = other._bytes.size();

    if (len_a > len_b) {
        return _bytes[len_a - 1];
    }
    else if (len_a < len_b) {
        return -other._bytes[len_b - 1];
    }

    // same size
    size_t i = len_a;
    while (i > 0) {
        int cmp = _bytes[i - 1] - other._bytes[i - 1];
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
        intmax_t ntv_aa = cases[i];
        string   str_a = to_string(ntv_a);
        BigInt   big_a(ntv_a);
        BigInt   big_aa = BigInt(str_a);

        ostringstream oss;
        oss << big_a;
        assert(oss.str() == str_a);
        assert(big_a == big_aa);

        for (size_t j = 0; j < sizeof(cases)/sizeof(cases[0]); j++) {
            intmax_t ntv_b = cases[j];
            BigInt   big_b(cases[j]);

            cout << "native integers: " << ntv_a << " and " << ntv_b << endl;
            cout << "   big integers: " << big_a << " and " << big_b << endl;

            bool exp_r, act_r;
            exp_r = (ntv_a == ntv_b);
            act_r = (big_a == big_b);
            assert(exp_r == act_r);

            exp_r = (ntv_a != ntv_b);
            act_r = (big_a != big_b);
            assert(exp_r == act_r);

            exp_r = (ntv_a > ntv_b);
            act_r = (big_a > big_b);
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
            assert(oss.str() == str_ntv_r);

            oss.str("");
            oss << big_a + big_b;
            str_ntv_r = to_string(ntv_a + ntv_b);
            assert(oss.str() == str_ntv_r);

            big_a += big_b;
            ntv_a += ntv_b;

            oss.str("");
            oss << big_a;
            str_ntv_r = to_string(ntv_a);
            assert(oss.str() == str_ntv_r);

            oss.str("");
            oss << big_a - big_b;
            str_ntv_r = to_string(ntv_a - ntv_b);
            assert(oss.str() == str_ntv_r);

            cout << "native integers: " << ntv_a << " and " << ntv_b << endl;
            cout << "   big integers: " << big_a << " and " << big_b << endl;

            big_a -= big_b;
            ntv_a -= ntv_b;

            oss.str("");
            oss << big_a;
            str_ntv_r = to_string(ntv_a);
            cout << oss.str() << endl;
            cout << str_ntv_r << endl;
            assert(oss.str() == str_ntv_r);

            big_aa = big_a + big_b;
            ntv_aa = ntv_a + ntv_b;

            oss.str("");
            oss << big_aa;
            str_ntv_r = to_string(ntv_aa);
            assert(oss.str() == str_ntv_r);
        }
    }
}

