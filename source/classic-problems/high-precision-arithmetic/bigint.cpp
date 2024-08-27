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

#include "bigint.hpp"

using namespace std;

int bigint::_max_nint_slices;

int bigint::max_nint_slices()
{
    if (_max_nint_slices == 0) {
        std::string max_nint = std::to_string(INTMAX_MAX);
        _max_nint_slices = (max_nint.length() + 1)/slice_width_k;
    }

    return _max_nint_slices;
}

ostream& operator<< (ostream& os, const bigint& bi)
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
            intmax_t r = slices[i];
            if (i == len - 1) {
                os << r;
            }
            else {
                intmax_t tens = 10;
                for (int i = 0; i < bigint::slice_width_k - 1; i++) {
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
void bigint::initfrom(intmax_t nint, T& slices)
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

void bigint::initfrom(intmax_t nint)
{
    if (nint < 0) {
        _sign = true;
    }
    else
        _sign = false;

    initfrom(nint, _slices);
}

bigint::bigint(intmax_t nint)
{
    initfrom(nint);
}

bigint::bigint(const string& str)
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

bigint::bigint(const bigint &other)
{
#ifndef NDEBUG
    clog << "copy constructor called\n";
#endif

    _sign = other.sign();
    _slices = other.slices();
}

bigint::bigint(bigint &&other)
{
#ifndef NDEBUG
    clog << "move constructor called\n";
#endif

    _sign = other._sign;
    _slices.clear();
    _slices = std::move(other._slices);
}

// copy assignment operator
bigint& bigint::operator= (const bigint& other)
{
#ifndef NDEBUG
    clog << "copy assignment operator called\n";
#endif

    _sign = other._sign;
    _slices = other._slices;
    return *this;
}

// move assignment operator
bigint& bigint::operator= (bigint&& other) noexcept
{
#ifndef NDEBUG
    clog << "move assignment operator called\n";
#endif

    if (this != &other) {
        _sign = other._sign;
        _slices.clear();
        _slices = std::move(other._slices);
    }

    return *this;
}

bigint& bigint::operator= (intmax_t other)
{
    _slices.clear();
    initfrom(other);
    _slices.shrink_to_fit();
    return *this;
}

void bigint::normalize()
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
void bigint::absadd(const Ta& one, const Tb& other, bigint &result)
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
void bigint::absaddto(const T& other)
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
void bigint::abssub(const Ta& one, const Tb& other, bigint &result)
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
void bigint::absmul(const Ta& one, const Tb& other, bigint &result)
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
void bigint::abssubfrom(const T& other)
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
int bigint::abscmp(const Ta& one, const Tb& other)
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

bigint bigint::operator+ (const bigint& other) const
{
    bigint result;

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

bigint& bigint::operator+= (const bigint& other)
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
            bigint result;
            abssub(other._slices, _slices, result);
            _sign = other._sign;
            _slices = std::move(result._slices);
        }
    }

    return *this;
}

bigint bigint::operator+ (intmax_t other) const
{
    if (other == 0) {
        return *this;
    }

    bigint result;

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

bigint& bigint::operator+= (intmax_t other)
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
            bigint result;
            abssub(other_slices, _slices, result);
            _sign = (other < 0);
            _slices = std::move(result._slices);
        }
    }

    return *this;
}

bigint bigint::operator- () const
{
    if (iszero())
        return *this;

    bigint result(*this);
    result._sign = !_sign;
    return result;
}

bigint bigint::operator- (const bigint& other) const
{
    if (other.iszero()) {
        return *this;
    }

    bigint result;
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

bigint& bigint::operator-= (const bigint& other)
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
            bigint result;
            abssub(other._slices, _slices, result);
            _sign = !_sign;
            _slices = std::move(result._slices);
        }
    }

    return *this;
}

bigint bigint::operator- (intmax_t other) const
{
    if (other == 0) {
        return *this;
    }

    bigint result;

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

bigint& bigint::operator-= (intmax_t other)
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
            bigint result;
            abssub(other_slices, _slices, result);
            _sign = !_sign;
            _slices = std::move(result._slices);
        }
    }

    return *this;
}

// ++bi
bigint& bigint::operator++ ()
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
bigint bigint::operator++ (int)
{
   bigint temp = *this;
   ++*this;
   return temp;
}

// --bi
bigint& bigint::operator-- ()
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
bigint bigint::operator-- (int)
{
   bigint temp = *this;
   --*this;
   return temp;
}

bool bigint::operator== (const bigint& other) const
{
    if (_sign == other._sign && abscmp(_slices, other._slices) == 0)
        return true;

    return false;
}

bool bigint::operator!= (const bigint& other) const
{
    if (_sign == other._sign && abscmp(_slices, other._slices) == 0)
        return false;

    return true;
}

bool bigint::operator> (const bigint& other) const
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

bool bigint::operator>= (const bigint& other) const
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

bool bigint::operator< (const bigint& other) const
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

bool bigint::operator<= (const bigint& other) const
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

bool bigint::operator== (intmax_t other) const
{
    slice_a other_slices;
    initfrom(other, other_slices);

    if (_sign == (other < 0) && abscmp(_slices, other_slices) == 0)
        return true;

    return false;
}

bool bigint::operator!= (intmax_t other) const
{
    slice_a other_slices;
    initfrom(other, other_slices);

    if (_sign == (other < 0) && abscmp(_slices, other_slices) == 0)
        return false;

    return true;
}

bool bigint::operator> (intmax_t other) const
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

bool bigint::operator>= (intmax_t other) const
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

bool bigint::operator< (intmax_t other) const
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

bool bigint::operator<= (intmax_t other) const
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

bigint  bigint::operator*  (const bigint& other) const
{
    bigint result;

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

bigint& bigint::operator*= (const bigint& other)
{
    if (iszero() || other.iszero()) {
        _sign = false;
        _slices.clear();
        _slices.shrink_to_fit();
        return *this;
    }

    bigint result;
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

bigint  bigint::operator*  (intmax_t other) const
{
    bigint result;

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

bigint& bigint::operator*= (intmax_t other)
{
    if (iszero() || other == 0) {
        _sign = false;
        _slices.clear();
        _slices.shrink_to_fit();
        return *this;
    }

    bigint result;
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
void bigint::absdiv_slice(const T& dividend, slice_t denominator,
        bigint& quotient, bigint& remainder)
{
    size_t pos = dividend.size() - 1;

    quotient._slices.clear();

    slice_t rem = 0;
    while (true) {
        twin_t numerator = dividend[pos] + rem * (twin_t)slice_base_k;
        imaxdiv_t div = imaxdiv(numerator, denominator);

        // clog << numerator << " / " << denominator << ": "
        //      << div.quot << "..." << div.rem << endl;

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
intmax_t bigint::makenint(const T& slices, size_t off, size_t len)
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
void bigint::absdiv_nint(const T& dividend, intmax_t denominator,
        bigint& quotient, bigint& remainder)
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
bool bigint::absdiv_fast(const Ta& dividend, const Tb& divisor,
        bigint& quotient, bigint& remainder)
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

void bigint::absdiv_slow(const slice_v& numerator, const slice_v& denominator,
        bigint& quotient, bigint& remainder)
{
    remainder._sign = false;
    remainder._slices = numerator;

    quotient._sign = false;
    quotient._slices.clear();

    assert(numerator.size() >= denominator.size());

    while (abscmp(remainder._slices, denominator) >= 0) {
        remainder.abssubfrom(denominator);
        quotient++;
    }
}

bool bigint::divmod(const bigint& dividend, const bigint& divisor,
            bigint& quotient, bigint& remainder)
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

bool bigint::divmod(const bigint& dividend, intmax_t divisor,
            bigint& quotient, bigint& remainder)
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

bigint  bigint::operator/  (const bigint& other) const
{
    bigint quotient, remainder;
    divmod(*this, other, quotient, remainder);
    return quotient;
}

bigint& bigint::operator/= (const bigint& other)
{
    bigint quotient, remainder;
    divmod(*this, other, quotient, remainder);
    _sign = quotient._sign;
    _slices = std::move(quotient._slices);
    return *this;
}

bigint  bigint::operator/  (intmax_t other) const
{
    bigint quotient, remainder;
    divmod(*this, other, quotient, remainder);
    return quotient;
}

bigint& bigint::operator/= (intmax_t other)
{
    bigint quotient, remainder;
    divmod(*this, other, quotient, remainder);
    _sign = quotient._sign;
    _slices = std::move(quotient._slices);
    return *this;
}

bigint  bigint::operator%  (const bigint& other) const
{
    bigint quotient, remainder;
    divmod(*this, other, quotient, remainder);
    return remainder;
}

bigint& bigint::operator%= (const bigint& other)
{
    bigint quotient, remainder;
    divmod(*this, other, quotient, remainder);
    _sign = remainder._sign;
    _slices = std::move(remainder._slices);
    return *this;
}

bigint  bigint::operator%  (intmax_t other) const
{
    bigint quotient, remainder;
    divmod(*this, other, quotient, remainder);
    return remainder;
}

bigint& bigint::operator%= (intmax_t other)
{
    bigint quotient, remainder;
    divmod(*this, other, quotient, remainder);
    _sign = remainder._sign;
    _slices = std::move(remainder._slices);
    return *this;
}

#ifndef NTEST

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
        bigint   big_a(ntv_a);
        bigint   big_aa = bigint(str_a);

        ostringstream oss;
        oss << big_a;
        assert(oss.str() == str_a);
        assert(big_a == big_aa);

        for (size_t j = 0; j < sizeof(cases)/sizeof(cases[0]); j++) {
            intmax_t ntv_b = cases[j];
            bigint   big_b(cases[j]);

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
        bigint   big_a(ntv_a);

        ostringstream oss;
        string str_ntv_r;
        for (size_t j = 0; j < sizeof(cases)/sizeof(cases[0]); j++) {
            intmax_t ntv_b = cases[j];
            bigint   big_b(cases[j]);

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

            bigint big_r(big_a);
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
        bigint   big_a(ntv_a);

        ostringstream oss;
        string str_ntv_r;
        for (size_t j = 0; j < sizeof(cases)/sizeof(cases[0]); j++) {
            intmax_t ntv_b = cases[j];
            bigint   big_b(cases[j]);

            // XXX: only small integer for this test method. */
            if (big_b.slices().size() > bigint::max_group_slices_k) {
                continue;
            }

            cout << "native integers: " << ntv_a << " and " << ntv_b << endl;
            cout << "   big integers: " << big_a << " and " << big_b << endl;

            bigint quotient, remainder;
            if (bigint::divmod(big_a, big_b, quotient, remainder)) {
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

            if (bigint::divmod(big_a, ntv_b, quotient, remainder)) {
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
    cout << "sizeof(slice_t): " << sizeof(bigint::slice_t) << endl;

    cout << "slice_width_k: " << bigint::slice_width_k << endl;
    cout << "max_slice_nint_k: " << bigint::max_slice_nint_k << endl;
    cout << "slice_base_k: " << bigint::slice_base_k << endl;
    cout << "max_nint_slices: " << bigint::max_nint_slices() << endl;
}

void factorial(bigint& result, unsigned n)
{
    if (n > 1) {
        factorial(result, n - 1);
        result *= n;
    }
    else
        result = 1;
}

void summary_of_factorials(bigint& result, unsigned max)
{
    result = 0;

    unsigned n = 0;
    while (n <= max) {
        bigint tmp;
        factorial(tmp, n);
        result += tmp;
        n++;
    }
}

int main()
{
    test_bigint();

    bigint result;
    factorial(result, 5);
    assert(result == 120);

    bigint r1, r2;
    factorial(r1, 50);
    factorial(r2, 51);
    assert(r1 == (r2 / 51));
    result = r2 / r1;
    assert(result == 51);

    cout << "An integer needed to calculate the summary of factorials:";
    unsigned max;
    cin >> max;
    summary_of_factorials(result, max);
    cout << result << endl;
}
#endif /* not defined(NTEST) */

