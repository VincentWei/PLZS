/*
 * This program implements arbitrary precision arithmetic for integer numbers.
 *
 * Author: Vincent Wei
 *  - <https://github.com/VincentWei>
 *  - <https://gitee.com/vincentwei7>
 *
 * Copyright (C) 2024 FMSoft <https://www.fmsoft.cn>.
 * License: GPLv3
 */
#include <array>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <cassert>
#include <cinttypes>

class BigInt {
  public:
    using slice_t = int8_t;
    using twin_t  = int16_t;
    using slice_v = std::vector<BigInt::slice_t>;
    static const int slice_width_k = 2;         // 99
    static const int max_slice_nint_k = 99;     // int32: 999999999
    static const int slice_base_k = (max_slice_nint_k + 1);
    static const int max_nint_slices_k = 10;    // 9223372036854775807
    static const int max_group_slices_k = 4;
    static const int group_base_k = 100000000;
        // slice_base_k ^ max_group_slices_k

  private:
    class slice_a {
       size_t  _size;
       slice_t _slices[max_nint_slices_k];

    public:
       slice_a(): _size(0) { }

       slice_a(slice_t slice) {
           _size = 1;
           _slices[0] = slice;
       }

       size_t size() const { return _size; };

       void clear() { _size = 0; }

       void push_back(slice_t val) {
           assert(_size < max_nint_slices_k);
           _slices[_size] = val;
           _size++;
       }

       slice_t operator[](size_t i) const {
           assert(i < _size);
           return _slices[i];
       }
    };

  public:
    BigInt(): _sign(false) { }

    BigInt(intmax_t nint);
    BigInt(const std::string& str);
    BigInt(const BigInt& other);            // copy constructor
    BigInt(BigInt&& other);                 // move constructor

    // some getters
    bool sign() const { return _sign; }
    const slice_v& slices() const { return _slices; }

    // getter or setter for max number of slices for native integer
    static int max_nint_slices();

    // overloaded operators
    BigInt& operator= (const BigInt& other);        // copy assignment operator
    BigInt& operator= (BigInt&& other) noexcept;    // move assignment operator
    BigInt& operator= (intmax_t other);

    BigInt  operator+  (const BigInt& other) const;
    BigInt& operator+= (const BigInt& other);
    BigInt  operator+  (intmax_t other) const;
    BigInt& operator+= (intmax_t other);

    BigInt  operator-  () const;             // -bi

    BigInt  operator-  (const BigInt& other) const;
    BigInt& operator-= (const BigInt& other);
    BigInt  operator-  (intmax_t other) const;
    BigInt& operator-= (intmax_t other);

    BigInt& operator++ ();                  // ++bi
    BigInt  operator++ (int);               // bi++

    BigInt& operator-- ();                  // --bi
    BigInt  operator-- (int);               // bi--

    bool operator== (const BigInt& other) const;
    bool operator!= (const BigInt& other) const;
    bool operator>  (const BigInt& other) const;
    bool operator>= (const BigInt& other) const;
    bool operator<  (const BigInt& other) const;
    bool operator<= (const BigInt& other) const;

    bool operator== (intmax_t other) const;
    bool operator!= (intmax_t other) const;
    bool operator>  (intmax_t other) const;
    bool operator>= (intmax_t other) const;
    bool operator<  (intmax_t other) const;
    bool operator<= (intmax_t other) const;

    BigInt  operator*  (const BigInt& other) const;
    BigInt& operator*= (const BigInt& other);
    BigInt  operator*  (intmax_t other) const;
    BigInt& operator*= (intmax_t other);

    BigInt  operator/  (const BigInt& other) const;
    BigInt& operator/= (const BigInt& other);
    BigInt  operator/  (intmax_t other) const;
    BigInt& operator/= (intmax_t other);

    BigInt  operator%  (const BigInt& other) const;
    BigInt& operator%= (const BigInt& other);
    BigInt  operator%  (intmax_t other) const;
    BigInt& operator%= (intmax_t other);

    static bool divmod(const BigInt& dividend, const BigInt& divisor,
            BigInt& quotient, BigInt& remainder);
    static bool divmod(const BigInt& dividend, intmax_t divisor,
            BigInt& quotient, BigInt& remainder);

  private:
    static int _max_nint_slices;

    template <class T>
    static void initfrom(intmax_t nint, T& slices);

    bool _sign;
    slice_v _slices;

    void initfrom(intmax_t nint);
    void normalize();
    bool iszero() const {
        if (_slices.size() == 0 ||
                (_slices.size() == 1 and _slices[0] == 0))
            return true;
        return false;
    }

    bool isone() const {
        if (_slices.size() == 1 and _slices[0] == 0)
            return true;
        return false;
    }

    template <class Ta, class Tb>
    static void absadd(const Ta& one, const Tb& other, BigInt& result);
    template <class Ta, class Tb>
    static int  abscmp(const Ta& one, const Tb& other);
    template <class Ta, class Tb>
    static void abssub(const Ta& one, const Tb& other, BigInt& result);
    template <class Ta, class Tb>
    static void absmul(const Ta& one, const Tb& other, BigInt& result);
    template <class T>
    static void absdiv_slice(const T& dividend, slice_t denominator,
            BigInt& quotient, BigInt& remainder);
    template <class T>
    static void absdiv_nint(const T& dividend, intmax_t denominator,
            BigInt& quotient, BigInt& remainder);
    template <class Ta, class Tb>
    static bool absdiv_fast(const Ta& dividend, const Tb& divisor,
            BigInt& quotient, BigInt& remainder);
    template <class T>
    static intmax_t makenint(const T& slices, size_t off = 0,
            size_t len = max_group_slices_k);

    static void absdiv_slow(const slice_v& dividend, const slice_v& divisor,
            BigInt& quotient, BigInt& remainder);

    template <class T>
    void abssubfrom(const T& other);
    template <class T>
    void absaddto(const T& other);
};

#include <iostream>

using namespace std;

int BigInt::_max_nint_slices;

int BigInt::max_nint_slices()
{
    if (_max_nint_slices == 0) {
        std::string max_nint = std::to_string(INTMAX_MAX);
        _max_nint_slices = (max_nint.length() + 1)/slice_width_k;
    }

    return _max_nint_slices;
}

ostream& operator<< (ostream& os, const BigInt& bi)
{
    if (bi.sign() && bi.slices().size() > 0) {
        os << "-";
    }

    auto slices = bi.slices();
    size_t len = slices.size();
    if (len == 0) {
        os << "0";
    }
    else {
        for (size_t i = len - 1; ; i--) {
            int r = (int)slices[i];
            if (i == len - 1) {
                os << r;
            }
            else {
                intmax_t tens = 10;
                for (int i = 0; i < BigInt::slice_width_k - 1; i++) {
                    if (r < tens)
                        os << "0";

                    tens *= 10;
                }

                os << r;
            }

            if (i == 0)
                break;
        }
    }

    return os;
}

template <class T>
void BigInt::initfrom(intmax_t nint, T& slices)
{
    assert(slices.size() == 0);

    if (nint < 0)
        nint = -nint;

    for (size_t i = 0; i < sizeof(intmax_t); i++) {
        if (nint == 0)
            break;

        slice_t r = nint % slice_base_k;
        slices.push_back(r);
        nint /= slice_base_k;
    }
}

void BigInt::initfrom(intmax_t nint)
{
    if (nint < 0) {
        _sign = true;
    }
    else
        _sign = false;

    initfrom(nint, _slices);
}

BigInt::BigInt(intmax_t nint)
{
    initfrom(nint);
}

BigInt::BigInt(const string& str)
{
    size_t len = str.length();
    if (len == 0) {
        _sign = false;
        _slices.clear();
        return;
    }

    const char *digits = str.c_str();
    if (str[0] == '-') {
        _sign = true;
        digits++;
        len--;
    }
    else {
        _sign = false;
    }

    size_t left = len;
    while (left > 0) {
        string slice;
        if (left > slice_width_k) {
            slice = string(digits + left - slice_width_k, slice_width_k);
            left -= slice_width_k;
        }
        else {
            slice = string(digits, left);
            left = 0;
        }

        assert(!slice.empty());

        int r = stoi(slice);
        _slices.push_back(r);
    }
}

BigInt::BigInt(const BigInt &other)
{
    clog << "copy constructor called\n";

    _sign = other.sign();
    _slices = other.slices();
}

BigInt::BigInt(BigInt &&other)
{
    clog << "move constructor called\n";

    _sign = other._sign;
    _slices.clear();
    _slices = std::move(other._slices);
}

// copy assignment operator
BigInt& BigInt::operator= (const BigInt& other)
{
    clog << "copy assignment operator called\n";

    _sign = other._sign;
    _slices = other._slices;
    return *this;
}

// move assignment operator
BigInt& BigInt::operator= (BigInt&& other) noexcept
{
    clog << "move assignment operator called\n";

    if (this != &other) {
        _sign = other._sign;
        _slices.clear();
        _slices = std::move(other._slices);
    }

    return *this;
}

BigInt& BigInt::operator= (intmax_t other)
{
    _slices.clear();
    initfrom(other);
    _slices.shrink_to_fit();
    return *this;
}

void BigInt::normalize()
{
    auto it = end(_slices);
    while (it != begin(_slices)) {
        it--;

        int n = *it;
        if (n == 0)
            _slices.pop_back();
        else
            break;
    }

    /* check if it is zero */
    if (it == begin(_slices) && *it == 0)
        _sign = false;

    _slices.shrink_to_fit();
}

template <class Ta, class Tb>
void BigInt::absadd(const Ta& one, const Tb& other, BigInt &result)
{
    size_t len_a = one.size();
    size_t len_b = other.size();
    size_t len_max = (len_a > len_b) ? len_a : len_b;

    result._slices.clear();

    int carry = 0;
    for (size_t i = 0; i < len_max; i++) {
        int n_a = (i < len_a) ? one[i] : 0;
        int n_b = (i < len_b) ? other[i] : 0;

        int r = n_a + n_b + carry;
        if (r >= slice_base_k) {
            carry = 1;
            r -= slice_base_k;
        }
        else
            carry = 0;

        result._slices.push_back(r);
    }

    if (carry > 0) {
        result._slices.push_back(carry);
    }
}

template <class T>
void BigInt::absaddto(const T& other)
{
    size_t len_a = _slices.size();
    size_t len_b = other.size();
    size_t len_max = (len_a > len_b) ? len_a : len_b;

    int carry = 0;
    for (size_t i = 0; i < len_max; i++) {
        int n_a = (i < len_a) ? _slices[i] : 0;
        int n_b = (i < len_b) ? other[i] : 0;

        int r = n_a + n_b + carry;
        if (r >= slice_base_k) {
            carry = 1;
            r -= slice_base_k;
        }
        else
            carry = 0;

        if (i >= len_a)
            _slices.push_back(r);
        else
            _slices[i] = r;
    }

    if (carry > 0) {
        _slices.push_back(carry);
    }
}

/* this must be larger than other */
template <class Ta, class Tb>
void BigInt::abssub(const Ta& one, const Tb& other, BigInt &result)
{
    size_t len_a = one.size();
    size_t len_b = other.size();
    size_t len_max = (len_a > len_b) ? len_a : len_b;

    result._slices.clear();

    int borrow = 0;
    for (size_t i = 0; i < len_max; i++) {
        int n_a = (i < len_a) ? one[i] : 0;
        int n_b = (i < len_b) ? other[i] : 0;

        int r;
        if (n_a - borrow >= n_b) {
            r = n_a - borrow - n_b;
            borrow = 0;
        }
        else {
            r = n_a - borrow + slice_base_k - n_b;
            borrow = 1;
        }

        result._slices.push_back(r);
    }

    assert(borrow == 0);
    result.normalize();
}

/* this must be larger than other */
template <class Ta, class Tb>
void BigInt::absmul(const Ta& one, const Tb& other, BigInt &result)
{
    size_t len_a = one.size();
    size_t len_b = other.size();
    size_t len_r = 0;   // length of result

    result._slices.clear();

    for (size_t i = 0; i < len_a; i++) {
        twin_t slice_a = one[i];

        twin_t carry = 0;
        for (size_t j = 0; j < len_b; j++) {
            twin_t slice_b = other[j];

            twin_t p = slice_a * slice_b + carry;
            if (p >= slice_base_k) {
                carry = p / slice_base_k;
                p %= slice_base_k;
            }
            else {
                carry = 0;
            }

            size_t k = j + i;
            if (k >= len_r) {
                result._slices.push_back(p);
                len_r++;
            }
            else {
                twin_t slice_r = result._slices[k];
                slice_r += p;
                if (slice_r >= slice_base_k) {
                    carry++;
                    slice_r -= slice_base_k;
                }

                result._slices[k] = slice_r;
            }
        }

        if (carry > 0) {
            result._slices.push_back(carry);
            len_r++;
            carry = 0;
        }

        assert(len_r == result._slices.size());
    }
}

/* this must be larger than other */
template <class T>
void BigInt::abssubfrom(const T& other)
{
    size_t len_a = _slices.size();
    size_t len_b = other.size();
    size_t len_max = (len_a > len_b) ? len_a : len_b;

    for (size_t i = 0; i < len_max; i++) {
        int n_a = (i < len_a) ? _slices[i] : 0;
        int n_b = (i < len_b) ? other[i] : 0;

        int r;
        if (n_a >= n_b) {
            r = n_a - n_b;
        }
        else {
            assert(i + 1 < len_a);

            r = n_a + slice_base_k - n_b;
            _slices[i + 1] -= 1;
        }

        _slices[i] = r;
    }

    normalize();
}

template <class Ta, class Tb>
int BigInt::abscmp(const Ta& one, const Tb& other)
{
    size_t len_a = one.size();
    size_t len_b = other.size();

    if (len_a > len_b) {
        return one[len_a - 1];
    }
    else if (len_a < len_b) {
        return -other[len_b - 1];
    }

    // same size
    size_t i = len_a;
    while (i > 0) {
        int cmp = one[i - 1] - other[i - 1];
        if (cmp != 0)
            return cmp;

        i--;
    }

    return 0;
}

BigInt BigInt::operator+ (const BigInt& other) const
{
    BigInt result;

    if (other.iszero()) {
        return *this;
    }
    else if (_sign == other._sign) {
        absadd(_slices, other._slices, result);
        result._sign = _sign;
    }
    else {
        int cmp = abscmp(_slices, other._slices);
        if (cmp == 0) {
            return result;
        }
        else if (cmp > 0) {
            abssub(_slices, other._slices, result);
            result._sign = _sign;
        }
        else {      // cmp < 0
            abssub(other._slices, _slices, result);
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
        absaddto(other._slices);
    }
    else {
        int cmp = abscmp(_slices, other._slices);
        if (cmp == 0) {
            _sign = false;
            _slices.clear();
            return *this;
        }
        else if (cmp > 0) {
            abssubfrom(other._slices);
        }
        else {      // cmp < 0
            BigInt result;
            abssub(other._slices, _slices, result);
            _sign = other._sign;
            _slices = std::move(result._slices);
        }
    }

    return *this;
}

BigInt BigInt::operator+ (intmax_t other) const
{
    if (other == 0) {
        return *this;
    }

    BigInt result;

    slice_a other_slices;
    initfrom(other, other_slices);

    if (_sign == (other < 0)) {
        absadd(_slices, other_slices, result);
        result._sign = _sign;
    }
    else {
        int cmp = abscmp(_slices, other_slices);
        if (cmp == 0) {
            return result;
        }
        else if (cmp > 0) {
            abssub(_slices, other_slices, result);
            result._sign = _sign;
        }
        else {      // cmp < 0
            abssub(other_slices, _slices, result);
            result._sign = (other < 0);
        }
    }

    return result;
}

BigInt& BigInt::operator+= (intmax_t other)
{
    if (other == 0) {
        return *this;
    }

    slice_a other_slices;
    initfrom(other, other_slices);

    if (_sign == (other < 0)) {
        absaddto(other_slices);
    }
    else {
        int cmp = abscmp(_slices, other_slices);
        if (cmp == 0) {
            _sign = false;
            _slices.clear();
        }
        else if (cmp > 0) {
            abssubfrom(other_slices);
        }
        else {      // cmp < 0
            BigInt result;
            abssub(other_slices, _slices, result);
            _sign = (other < 0);
            _slices = std::move(result._slices);
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
        absadd(_slices, other._slices, result);
        result._sign = _sign;
    }
    else {
        int cmp = abscmp(_slices, other._slices);
        if (cmp == 0) {
            return result;
        }
        else if (cmp > 0) {
            abssub(_slices, other._slices, result);
            result._sign = _sign;
        }
        else {      // cmp < 0
            abssub(other._slices, _slices, result);
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
        absaddto(other._slices);
    }
    else {
        int cmp = abscmp(_slices, other._slices);
        if (cmp == 0) {
            _sign = false;
            _slices.clear();
        }
        else if (cmp > 0) {
            abssubfrom(other._slices);
        }
        else {      // cmp < 0
            BigInt result;
            abssub(other._slices, _slices, result);
            _sign = !_sign;
            _slices = std::move(result._slices);
        }
    }

    return *this;
}

BigInt BigInt::operator- (intmax_t other) const
{
    if (other == 0) {
        return *this;
    }

    BigInt result;

    slice_a other_slices;
    initfrom(other, other_slices);

    if (_sign != (other < 0)) {
        absadd(_slices, other_slices, result);
        result._sign = _sign;
    }
    else {
        int cmp = abscmp(_slices, other_slices);
        if (cmp == 0) {
            return result;
        }
        else if (cmp > 0) {
            abssub(_slices, other_slices, result);
            result._sign = _sign;
        }
        else {      // cmp < 0
            abssub(other_slices, _slices, result);
            result._sign = !_sign;
        }
    }

    return result;
}

BigInt& BigInt::operator-= (intmax_t other)
{
    if (other == 0) {
        return *this;
    }

    slice_a other_slices;
    initfrom(other, other_slices);

    if (_sign != (other < 0)) {
        absaddto(other_slices);
    }
    else {
        int cmp = abscmp(_slices, other_slices);
        if (cmp == 0) {
            _sign = false;
            _slices.clear();
        }
        else if (cmp > 0) {
            abssubfrom(other_slices);
        }
        else {      // cmp < 0
            BigInt result;
            abssub(other_slices, _slices, result);
            _sign = !_sign;
            _slices = std::move(result._slices);
        }
    }

    return *this;
}

// ++bi
BigInt& BigInt::operator++ ()
{
    slice_a other_slices(1);

    if (iszero()) {
        _sign = false;
        _slices.clear();
        _slices.push_back(1);
    }
    else if (!_sign) {      // this is larger than 0
        absaddto(other_slices);
    }
    else {                  // this is less than 0
        int cmp = abscmp(_slices, other_slices);
        if (cmp == 0) { // this is equal to -1
            _sign = false;
            _slices.clear();
        }
        else {          // this is less than -1
            abssubfrom(other_slices);
        }
    }

    return *this;
}

// bi++
BigInt BigInt::operator++ (int)
{
   BigInt temp = *this;
   ++*this;
   return temp;
}

// --bi
BigInt& BigInt::operator-- ()
{
    slice_a other_slices(1);

    if (iszero()) {
        _sign = true;
        _slices.clear();
        _slices.push_back(1);
    }
    else if (_sign) {           // this is less than 0
        absaddto(other_slices);
    }
    else {                      // this is larger than 0
        int cmp = abscmp(_slices, other_slices);
        if (cmp == 0) {         // this is equal to 1
            _sign = false;
            _slices.clear();
        }
        else {                  // this is larger than or equal to 1
            abssubfrom(other_slices);
        }
    }

    return *this;
}

// bi--
BigInt BigInt::operator-- (int)
{
   BigInt temp = *this;
   --*this;
   return temp;
}

bool BigInt::operator== (const BigInt& other) const
{
    if (_sign == other._sign && abscmp(_slices, other._slices) == 0)
        return true;

    return false;
}

bool BigInt::operator!= (const BigInt& other) const
{
    if (_sign == other._sign && abscmp(_slices, other._slices) == 0)
        return false;

    return true;
}

bool BigInt::operator> (const BigInt& other) const
{
    if (!_sign && other._sign)
        return true;

    if (_sign && !other._sign)
        return false;

    // same sign
    int cmp = abscmp(_slices, other._slices);
    if (!_sign)
        return cmp > 0;
    return cmp < 0;
}

bool BigInt::operator>= (const BigInt& other) const
{
    if (!_sign && other._sign)
        return true;

    if (_sign && !other._sign)
        return false;

    // same sign
    int cmp = abscmp(_slices, other._slices);
    if (!_sign)
        return cmp >= 0;
    return cmp <= 0;
}

bool BigInt::operator< (const BigInt& other) const
{
    if (!_sign && other._sign)
        return false;

    if (_sign && !other._sign)
        return true;

    // same sign
    int cmp = abscmp(_slices, other._slices);
    if (!_sign)
        return cmp < 0;
    return cmp > 0;
}

bool BigInt::operator<= (const BigInt& other) const
{
    if (!_sign && other._sign)
        return false;

    if (_sign && !other._sign)
        return true;

    // same sign
    int cmp = abscmp(_slices, other._slices);
    if (!_sign)
        return cmp <= 0;
    return cmp >= 0;
}

bool BigInt::operator== (intmax_t other) const
{
    slice_a other_slices;
    initfrom(other, other_slices);

    if (_sign == (other < 0) && abscmp(_slices, other_slices) == 0)
        return true;

    return false;
}

bool BigInt::operator!= (intmax_t other) const
{
    slice_a other_slices;
    initfrom(other, other_slices);

    if (_sign == (other < 0) && abscmp(_slices, other_slices) == 0)
        return false;

    return true;
}

bool BigInt::operator> (intmax_t other) const
{
    if (!_sign && (other < 0))
        return true;

    if (_sign && !(other < 0))
        return false;

    // same sign
    slice_a other_slices;
    initfrom(other, other_slices);

    int cmp = abscmp(_slices, other_slices);
    if (!_sign)
        return cmp > 0;
    return cmp < 0;
}

bool BigInt::operator>= (intmax_t other) const
{
    if (!_sign && (other < 0))
        return true;

    if (_sign && !(other < 0))
        return false;

    // same sign
    slice_a other_slices;
    initfrom(other, other_slices);

    int cmp = abscmp(_slices, other_slices);
    if (!_sign)
        return cmp >= 0;
    return cmp <= 0;
}

bool BigInt::operator< (intmax_t other) const
{
    if (!_sign && (other < 0))
        return false;

    if (_sign && !(other < 0))
        return true;

    // same sign
    slice_a other_slices;
    initfrom(other, other_slices);

    int cmp = abscmp(_slices, other_slices);
    if (!_sign)
        return cmp < 0;
    return cmp > 0;
}

bool BigInt::operator<= (intmax_t other) const
{
    if (!_sign && (other < 0))
        return false;

    if (_sign && !(other < 0))
        return true;

    // same sign
    slice_a other_slices;
    initfrom(other, other_slices);

    int cmp = abscmp(_slices, other_slices);
    if (!_sign)
        return cmp <= 0;
    return cmp >= 0;
}

BigInt  BigInt::operator*  (const BigInt& other) const
{
    BigInt result;

    if (iszero() || other.iszero()) {
        return result;
    }

    absmul(_slices, other._slices, result);
    if (_sign == other._sign) {
        result._sign = false;
    }
    else {
        result._sign = true;
    }

    return result;
}

BigInt& BigInt::operator*= (const BigInt& other)
{
    if (iszero() || other.iszero()) {
        _sign = false;
        _slices.clear();
        _slices.shrink_to_fit();
        return *this;
    }

    BigInt result;
    absmul(_slices, other._slices, result);
    if (_sign == other._sign) {
        _sign = false;
    }
    else {
        _sign = true;
    }
    _slices = std::move(result._slices);

    return *this;
}

BigInt  BigInt::operator*  (intmax_t other) const
{
    BigInt result;

    if (iszero() || other == 0) {
        return result;
    }

    slice_a other_slices;
    initfrom(other, other_slices);

    absmul(_slices, other_slices, result);
    if (_sign == (other < 0)) {
        result._sign = false;
    }
    else {
        result._sign = true;
    }

    return result;
}

BigInt& BigInt::operator*= (intmax_t other)
{
    if (iszero() || other == 0) {
        _sign = false;
        _slices.clear();
        _slices.shrink_to_fit();
        return *this;
    }

    BigInt result;
    slice_a other_slices;
    initfrom(other, other_slices);

    absmul(_slices, other_slices, result);
    if (_sign == (other < 0)) {
        _sign = false;
    }
    else {
        _sign = true;
    }
    _slices = std::move(result._slices);

    return *this;
}

template <class T>
void BigInt::absdiv_slice(const T& dividend, slice_t denominator,
        BigInt& quotient, BigInt& remainder)
{
    size_t pos = dividend.size() - 1;

    quotient._slices.clear();

    slice_t rem = 0;
    while (true) {
        twin_t numerator = dividend[pos] + rem * slice_base_k;
        ldiv_t div = ldiv(numerator, denominator);

        slice_t quot = (slice_t)div.quot;
        quotient._slices.push_back(quot);
        rem = (slice_t)div.rem;

        if (pos == 0)
            break;
        pos--;
    }

    std::reverse(quotient._slices.begin(), quotient._slices.end());
    quotient.normalize();

    remainder._slices.clear();
    remainder._slices.push_back(rem);
}

template <class T>
intmax_t BigInt::makenint(const T& slices, size_t off, size_t len)
{
    size_t size = slices.size();
    intmax_t nint = 0, base = 1;

    for (size_t i = off, n = 0; i < size && n < len; i++, n++) {
        nint += slices[i] * base;
        base *= slice_base_k;
    }

    return nint;
}

template <class T>
void BigInt::absdiv_nint(const T& dividend, intmax_t denominator,
        BigInt& quotient, BigInt& remainder)
{
    intmax_t rem = 0;
    size_t left = dividend.size();
    while (left > 0) {
        size_t len;
        if (left < max_group_slices_k) {
            len = left;
        }
        else {
            len = max_group_slices_k;
        }

        size_t pos = left - len;
        intmax_t numerator = makenint(dividend, pos, len);
        intmax_t scale = 1;
        if (len == max_group_slices_k) {
            scale = group_base_k;
        }
        else if (len > 0) {
            size_t n = len;
            while (n > 0) {
                scale *= slice_base_k;
                n--;
            }
        }

        numerator += rem * scale;
        imaxdiv_t div = imaxdiv(numerator, denominator);

        quotient *= scale;
        quotient += div.quot;
        rem = div.rem;

        left -= len;
    }

    remainder = rem;
}

template <class Ta, class Tb>
bool BigInt::absdiv_fast(const Ta& dividend, const Tb& divisor,
        BigInt& quotient, BigInt& remainder)
{
    assert(divisor.size() > 0);

    if (dividend.size() < divisor.size()) {         /* 99 / 9999 = 0 ... 99 */
        /* The quotient is eqaul to zero,
           and the remainder is equal to divisor. */
        quotient._sign = false;
        quotient._slices.clear();

        remainder._slices.clear();
        for (size_t i = 0; i < dividend.size(); i++) {
            remainder._slices.push_back(dividend[i]);
        }
    }
    else if (divisor.size() == 1) {
        absdiv_slice(dividend, divisor[0], quotient, remainder);
    }
    else if (divisor.size() <= max_group_slices_k) {
        intmax_t denominator = makenint(divisor);
        absdiv_nint(dividend, denominator, quotient, remainder);
    }
    else {
        return false;
    }

    return true;
}

void BigInt::absdiv_slow(const slice_v& numerator, const slice_v& denominator,
        BigInt& quotient, BigInt& remainder)
{
    remainder._sign = false;
    remainder._slices = numerator;

    quotient._sign = false;
    quotient._slices.clear();

    size_t len_n = numerator.size();
    size_t len_d = denominator.size();
    assert(len_n >= len_d);

    while (abscmp(remainder._slices, denominator) >= 0) {
        remainder.abssubfrom(denominator);
        quotient++;
    }
}

bool BigInt::divmod(const BigInt& dividend, const BigInt& divisor,
            BigInt& quotient, BigInt& remainder)
{
    if (divisor.iszero()) {
        return false;
    }

    if (dividend.iszero() == 0) {                   /* 0 / 9999 = 0 */
        quotient._sign = false;
        quotient._slices.clear();

        remainder._sign = false;
        remainder._slices.clear();
    }
    else if (divisor.isone()) {                     /* 99 / 1 = 99 ... 0 */
        quotient._sign = (dividend._sign != divisor._sign);
        quotient._slices = dividend._slices;

        remainder._sign = false;
        remainder._slices.clear();
    }

    if (!absdiv_fast(dividend._slices, divisor._slices, quotient, remainder)) {
        absdiv_slow(dividend._slices, divisor._slices, quotient, remainder);
    }

    /* adjust sign */
    if (!quotient.iszero())
        quotient._sign = (dividend._sign != divisor._sign);
    if (!remainder.iszero())
        remainder._sign = dividend._sign;

    return true;
}

bool BigInt::divmod(const BigInt& dividend, intmax_t divisor,
            BigInt& quotient, BigInt& remainder)
{
    if (divisor ==  0) {
        return false;
    }

    if (dividend.iszero() == 0) {                   /* 0 / 9999 = 0 */
        quotient._sign = false;
        quotient._slices.clear();

        remainder._sign = false;
        remainder._slices.clear();
    }
    else if (divisor == 1 || divisor == -1) {       /* 99 / 1 = 99 ... 0 */
        quotient._sign = (dividend._sign != (divisor < 0));
        quotient._slices = dividend._slices;

        remainder._sign = false;
        remainder._slices.clear();
    }

    slice_a divisor_slices;
    initfrom(divisor, divisor_slices);
    absdiv_fast(dividend._slices, divisor_slices, quotient, remainder);

    /* adjust sign */
    if (!quotient.iszero())
        quotient._sign = (dividend._sign != (divisor < 0));
    if (!remainder.iszero())
        remainder._sign = dividend._sign;

    return true;
}

BigInt  BigInt::operator/  (const BigInt& other) const
{
    BigInt quotient, remainder;
    divmod(*this, other, quotient, remainder);
    return quotient;
}

BigInt& BigInt::operator/= (const BigInt& other)
{
    BigInt quotient, remainder;
    divmod(*this, other, quotient, remainder);
    _sign = quotient._sign;
    _slices = std::move(quotient._slices);
    return *this;
}

BigInt  BigInt::operator/  (intmax_t other) const
{
    BigInt quotient, remainder;
    divmod(*this, other, quotient, remainder);
    return quotient;
}

BigInt& BigInt::operator/= (intmax_t other)
{
    BigInt quotient, remainder;
    divmod(*this, other, quotient, remainder);
    _sign = quotient._sign;
    _slices = std::move(quotient._slices);
    return *this;
}

BigInt  BigInt::operator%  (const BigInt& other) const
{
    BigInt quotient, remainder;
    divmod(*this, other, quotient, remainder);
    return remainder;
}

BigInt& BigInt::operator%= (const BigInt& other)
{
    BigInt quotient, remainder;
    divmod(*this, other, quotient, remainder);
    _sign = remainder._sign;
    _slices = std::move(remainder._slices);
    return *this;
}

BigInt  BigInt::operator%  (intmax_t other) const
{
    BigInt quotient, remainder;
    divmod(*this, other, quotient, remainder);
    return remainder;
}

BigInt& BigInt::operator%= (intmax_t other)
{
    BigInt quotient, remainder;
    divmod(*this, other, quotient, remainder);
    _sign = remainder._sign;
    _slices = std::move(remainder._slices);
    return *this;
}

#include <sstream>

void test_bigint(void)
{
    static intmax_t cases[] = {
        INT32_MAX,
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
        INT32_MIN,
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

            exp_r = (ntv_a == ntv_b);
            act_r = (big_a == ntv_b);
            assert(exp_r == act_r);

            exp_r = (ntv_a != ntv_b);
            act_r = (big_a != ntv_b);
            assert(exp_r == act_r);

            exp_r = (ntv_a > ntv_b);
            act_r = (big_a > ntv_b);
            assert(exp_r == act_r);

            exp_r = (ntv_a >= ntv_b);
            act_r = (big_a >= ntv_b);
            assert(exp_r == act_r);

            exp_r = (ntv_a < ntv_b);
            act_r = (big_a < ntv_b);
            assert(exp_r == act_r);

            exp_r = (ntv_a <= ntv_b);
            act_r = (big_a <= ntv_b);
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

            big_a = big_a + ntv_b;
            ntv_a = ntv_a + ntv_b;

            oss.str("");
            oss << big_a;
            str_ntv_r = to_string(ntv_a);
            cout << oss.str() << endl;
            cout << str_ntv_r << endl;
            assert(oss.str() == str_ntv_r);

            big_a += ntv_b;
            ntv_a += ntv_b;

            oss.str("");
            oss << big_a;
            str_ntv_r = to_string(ntv_a);
            assert(oss.str() == str_ntv_r);

            big_a = big_a - ntv_b;
            ntv_a = ntv_a - ntv_b;

            oss.str("");
            oss << big_a;
            str_ntv_r = to_string(ntv_a);
            assert(oss.str() == str_ntv_r);

            big_a -= ntv_b;
            ntv_a -= ntv_b;

            oss.str("");
            oss << big_a;
            str_ntv_r = to_string(ntv_a);
            assert(oss.str() == str_ntv_r);

            big_a++;
            ntv_a++;

            oss.str("");
            oss << big_a;
            str_ntv_r = to_string(ntv_a);
            assert(oss.str() == str_ntv_r);

            big_a = ++big_b;
            ntv_a = ++ntv_b;

            oss.str("");
            oss << big_a;
            str_ntv_r = to_string(ntv_a);
            assert(oss.str() == str_ntv_r);

            big_a--;
            ntv_a--;

            oss.str("");
            oss << big_a;
            str_ntv_r = to_string(ntv_a);
            assert(oss.str() == str_ntv_r);

            big_a = --big_b;
            ntv_a = --ntv_b;

            oss.str("");
            oss << big_a;
            str_ntv_r = to_string(ntv_a);
            assert(oss.str() == str_ntv_r);
        }
    }

    /* test operators: * and *= */
    for (size_t i = 0; i < sizeof(cases)/sizeof(cases[0]); i++) {
        intmax_t ntv_a = cases[i];
        BigInt   big_a(ntv_a);

        ostringstream oss;
        string str_ntv_r;
        for (size_t j = 0; j < sizeof(cases)/sizeof(cases[0]); j++) {
            intmax_t ntv_b = cases[j];
            BigInt   big_b(cases[j]);

            cout << "native integers: " << ntv_a << " and " << ntv_b << endl;
            cout << "   big integers: " << big_a << " and " << big_b << endl;

            oss.str("");
            oss << big_a * big_b;
            str_ntv_r = to_string(ntv_a * ntv_b);
            cout << ntv_a * ntv_b << endl;
            cout << big_a * big_b << endl;
            assert(oss.str() == str_ntv_r);

            oss.str("");
            oss << big_a * ntv_b;
            str_ntv_r = to_string(ntv_a * ntv_b);
            assert(oss.str() == str_ntv_r);

            BigInt big_r(big_a);
            intmax_t ntv_r = ntv_a;

            big_r *= ntv_b;
            ntv_r *= ntv_b;

            oss.str("");
            oss << big_r;
            str_ntv_r = to_string(ntv_r);
            assert(oss.str() == str_ntv_r);
        }
    }

    cout << "C/C++ mod result: " << -5 % 3 << endl;

    /* test divmod() */
    for (size_t i = 0; i < sizeof(cases)/sizeof(cases[0]); i++) {
        intmax_t ntv_a = cases[i];
        BigInt   big_a(ntv_a);

        ostringstream oss;
        string str_ntv_r;
        for (size_t j = 0; j < sizeof(cases)/sizeof(cases[0]); j++) {
            intmax_t ntv_b = cases[j];
            BigInt   big_b(cases[j]);

            // XXX: only small integer for this test method. */
            if (big_b.slices().size() > BigInt::max_group_slices_k) {
                continue;
            }

            cout << "native integers: " << ntv_a << " and " << ntv_b << endl;
            cout << "   big integers: " << big_a << " and " << big_b << endl;

            BigInt quotient, remainder;
            if (BigInt::divmod(big_a, big_b, quotient, remainder)) {
                imaxdiv_t div = imaxdiv(ntv_a, ntv_b);

                oss.str("");
                oss << quotient << " ... " << remainder;
                str_ntv_r = to_string(div.quot);
                str_ntv_r += " ... ";
                str_ntv_r += to_string(div.rem);
                clog << oss.str() << " vs " << str_ntv_r << endl;
                assert(oss.str() == str_ntv_r);
            }
            else {
                clog << "Failed division: " << big_a << " / " << big_b << endl;
            }

            if (BigInt::divmod(big_a, ntv_b, quotient, remainder)) {
                imaxdiv_t div = imaxdiv(ntv_a, ntv_b);

                oss.str("");
                oss << quotient << " ... " << remainder;
                str_ntv_r = to_string(div.quot);
                str_ntv_r += " ... ";
                str_ntv_r += to_string(div.rem);
                clog << oss.str() << " vs " << str_ntv_r << endl;
                assert(oss.str() == str_ntv_r);
            }
            else {
                clog << "Failed division: " << big_a << " / " << big_b << endl;
            }
        }
    }

    cout << "sizeof(intmax_t): " << sizeof(intmax_t) << endl;
    cout << "sizeof(slice_t): " << sizeof(BigInt::slice_t) << endl;

    cout << "slice_width_k: " << BigInt::slice_width_k << endl;
    cout << "max_slice_nint_k: " << BigInt::max_slice_nint_k << endl;
    cout << "slice_base_k: " << BigInt::slice_base_k << endl;
    cout << "max_nint_slices: " << BigInt::max_nint_slices() << endl;
}

void factorial(BigInt& result, unsigned n)
{
    if (n > 1) {
        factorial(result, n - 1);
        result *= n;
    }
    else
        result = 1;
}

void summary_of_factorials(BigInt& result, unsigned max)
{
    result = 0;

    unsigned n = 0;
    while (n <= max) {
        BigInt tmp;
        factorial(tmp, n);
        result += tmp;
        n++;
    }
}

int main()
{
    test_bigint();

    BigInt result;
    factorial(result, 5);
    assert(result == 120);

    BigInt r1, r2;
    factorial(r1, 50);
    factorial(r2, 51);
    result = r2 / r1;
    assert(result == 51);

    unsigned max;
    cin >> max;
    summary_of_factorials(result, max);
    cout << result << endl;
}

