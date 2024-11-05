/*
 * This program implements arbitrary precision arithmetic for integer numbers.
 *
 * This program is a part of PLZS (the Programming Lessons for
 * Zero-based Students Aged 10+) project.
 * For more information about PLZS, please visit:
 *
 *  - <https://github.com/VincentWei/PLZS>
 *  - <https://gitee.com/vincentwei7/PLZS>
 *
 * Author: Vincent Wei
 *
 * Copyright (C) 2024 FMSoft <https://www.fmsoft.cn>.
 * License: GPLv3
 */

#include "bigint.hpp"
#include <cinttypes>

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

    do {
        slice_t r = nint % slice_base_k;
        slices.push_back(r);
        nint /= slice_base_k;
    } while (nint != 0);
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
#ifndef NTEST
    clog << "copy constructor called\n";
#endif

    _sign = other.sign();
    _slices = other.slices();
}

bigint::bigint(bigint &&other)
{
#ifndef NTEST
    clog << "move constructor called\n";
#endif

    _sign = other._sign;
    _slices.clear();
    _slices = std::move(other._slices);
}

// copy assignment operator
bigint& bigint::operator= (const bigint& other)
{
#ifndef NTEST
    clog << "copy assignment operator called\n";
#endif

    _sign = other._sign;
    _slices = other._slices;
    return *this;
}

// move assignment operator
bigint& bigint::operator= (bigint&& other) noexcept
{
#ifndef NTEST
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

bigint bigint::abs() const
{
    bigint ret;
    ret._sign = false;
    ret._slices = _slices;
    return ret;
}

int bigint::abscmp(const bigint& other) const
{
    return abscmp(_slices, other._slices);
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

#if defined(USE_INT32_AS_SLICE)
static int32_t
qpower(int32_t base, int32_t exp, int32_t modulus)
{
    int64_t ret = 1;
    int64_t base_64 = base;

    while (exp) {
        if (exp & 1)
            ret = (ret * base_64) % modulus;
        base_64 = (base_64 * base_64) % modulus;
        exp >>= 1;
    }

    return static_cast<int32_t>(ret);
}

std::map<size_t, bigint::slice_v> bigint::ntt_reverse_map;

/*
 * This function prepare the reverse data for different lengthes.
 * @length should be an integer in power of 2 and
 *      less than or equal to ntt_max_slices_k.
 */
const bigint::slice_v& bigint::get_reverse(size_t length)
{
    if (ntt_reverse_map.count(length) == 0) {
        slice_v& rev = ntt_reverse_map[length];

        rev.resize(length, 0);
        for (size_t i = 1; i < length; ++i) {
            rev[i] = rev[i >> 1] >> 1;
            if (i & 1)
                rev[i] |= length >> 1;
        }

        return rev;
    }

    return ntt_reverse_map[length];
}

std::map<size_t, bigint::slice_v> bigint::ntt_omega_powers_map;

/*
 * This function prepare the omega powers for different lengthes.
 * @length should be an integer in power of 2 and
 *      less than or equal to ntt_max_slices_k.
 */
const bigint::slice_v& bigint::get_omega_powers(size_t length)
{
    if (ntt_omega_powers_map.count(length) == 0) {
        slice_v& omega_powers = ntt_omega_powers_map[length];

        size_t oi = 0;
        for (size_t m = 2; m <= length; m <<= 1) {
            size_t k = m >> 1;
            int32_t gn = qpower(ntt_g_k, (ntt_prime_k - 1) / m, ntt_prime_k);
            for (size_t i = 0; i < length; i += m) {
                int64_t g = 1;
                for (size_t j = 0; j < k; ++j) {
                    omega_powers.push_back(static_cast<int32_t>(g));
                    g = g * gn % ntt_prime_k;
                    oi++;
                }
            }
        }

        return omega_powers;
    }

    return ntt_omega_powers_map[length];
}

void bigint::ntt(slice_v& x, int32_t length, bool invert)
{
    const slice_v& reverse = get_reverse(length);

    for (int32_t i = 0; i < length; ++i) {
        if (reverse[i] < i)
            std::swap(x[i], x[reverse[i]]);
    }

    const slice_v& omega_powers = get_omega_powers(length);

    size_t oi = 0;
    for (int32_t m = 2; m <= length; m <<= 1) {
        int32_t k = m >> 1;
#if 0
        int32_t gn;
        if (invert)
           gn = qpower(ntt_invg_k, (ntt_prime_k - 1) / m, ntt_prime_k);
        else
           gn = qpower(ntt_g_k, (ntt_prime_k - 1) / m, ntt_prime_k);
#endif

        for (int32_t i = 0; i < length; i += m) {
            // int64_t g = 1;
            for (int32_t j = 0; j < k; ++j) {
                int64_t g = omega_powers[oi];
#if 1
                int64_t tmp = x[i + j + k] * g % ntt_prime_k;
                x[i + j + k] = (x[i + j] - tmp + ntt_prime_k) % ntt_prime_k;
                x[i + j] = (x[i + j] + tmp) % ntt_prime_k;
#else
                int64_t e = x[i + j], o = x[i + j + k];
                x[i + j] = (e + o * g) % ntt_prime_k;
                x[i + j + k] = ((e - o * g) % ntt_prime_k + ntt_prime_k)
                    % ntt_prime_k;
#endif
                oi++;
                // g = g * gn % ntt_prime_k;
            }
        }
    }

    if (invert) {
        std::reverse(x.begin() + 1, x.begin() + length);
        int64_t inv = qpower(length, ntt_prime_k - 2, ntt_prime_k);
        for (int32_t i = 0; i < length; ++i) {
            x[i] = (x[i] * inv) % ntt_prime_k;
        }
    }
}

/*
 * This function uses NTT algorithm for multiplication.
 *
 * For more information, please refer to:
 *  https://www.cnblogs.com/zimujun/p/14472471.html
 *  https://github.com/SRI-CSL/NTT
 */
void bigint::nttmul(const bigint& multiplicand, const bigint& multiplier,
            bigint& result)
{
    if (multiplicand.iszero() || multiplier.iszero()) {
        result._sign = false;
        result._slices.clear();
        return;
    }
    else if (multiplicand.isone() == 1) {
        result = multiplier;
        result._sign = (multiplicand._sign != multiplier._sign);
        return;
    }
    else if (multiplier.isone() == 1) {
        result = multiplicand;
        result._sign = (multiplicand._sign != multiplier._sign);
        return;
    }

    size_t length = 1;
    size_t n = multiplicand._slices.size();
    while (length < (n << 1))
        length <<= 1;
    n = multiplier._slices.size();
    while (length < (n << 1))
        length <<= 1;

    assert(length > 0 && length <= ntt_max_slices_k);
    assert((length & (length - 1)) == 0);

    slice_v a = multiplicand._slices;
    if (length > a.size())
        a.resize(length, 0);
    ntt(a, (int32_t)length);

    slice_v b = multiplier._slices;
    if (length > b.size())
        b.resize(length, 0);
    ntt(b, (int32_t)length);

    slice_v my_result;
    my_result.resize(length, 0);
    for (size_t i = 0; i < length; ++i) {
        twin_t tmp = 1LL * a[i] * b[i];
        my_result[i] = (slice_t)(tmp % ntt_prime_k);
    }

    ntt(my_result, (int32_t)length, true);

    result._slices.clear();

    // normalize the result to make sure
    // that all slice values are in [0, slice_base_k).
    size_t last = 0;
    for (size_t i = 0; i < length; ++i) {
        if (my_result[i] >= slice_base_k) {
            last = i + 1;
            if (last >= my_result.size()) {
                my_result.push_back(0);
            }

            my_result[i + 1] += my_result[i] / slice_base_k;
            my_result[i] = my_result[i] % slice_base_k;
        }

        result._slices.push_back(my_result[i]);

        if (my_result[i])
            last = std::max(last, i);
    }

    while (my_result[last] >= slice_base_k) {
        my_result.push_back(0);
        my_result[last + 1] += my_result[last] / slice_base_k;
        my_result[last] = my_result[last] % slice_base_k;
        result._slices.push_back(my_result[last]);
        last++;
    }

    result._sign = (multiplicand._sign != multiplier._sign);
    result.normalize();
}
#endif /* defined(USE_INT32_AS_SLICE) */

/* This method uses binary-lifting algorithm. But for small multiplicand,
   we cannot gain much benefit from this algorithm. */
void bigint::binmul(const bigint& multiplicand, const bigint& multiplier,
        bigint& result)
{
    if (multiplicand.iszero() || multiplier.iszero()) {
        result._sign = false;
        result._slices.clear();
        return;
    }
    else if (multiplicand.isone() == 1) {
        result = multiplier;
        result._sign = (multiplicand._sign != multiplier._sign);
        return;
    }
    else if (multiplier.isone() == 1) {
        result = multiplicand;
        result._sign = (multiplicand._sign != multiplier._sign);
        return;
    }

    result._sign = false;
    result._slices.clear();

    bigint longer;
    bigint shorter;

    if (multiplicand._slices.size() > multiplier._slices.size()) {
        longer = multiplicand;
        shorter = multiplier;
    }
    else {
        longer = multiplier;
        shorter = multiplicand;
    }

    while (!shorter.iszero()) {
        bigint quot, rem;
        divmod(shorter, 2, quot, rem);
        shorter = std::move(quot);

        if (!rem.iszero()) {
            result += longer;
        }

        longer += longer;
    }

    result._sign = (multiplicand._sign != multiplier._sign);
}

/* This method uses binary-lifting algorithm. But for small multiplicand,
   we cannot gain much benefit from this algorithm. */
void bigint::binmul(const bigint& multiplicand, intmax_t multiplier,
        bigint& result)
{
    if (multiplicand.iszero() || multiplier == 0) {
        result._sign = false;
        result._slices.clear();
        return;
    }
    else if (multiplicand.isone() == 1) {
        result = multiplier;
        result._sign = (multiplicand._sign != (multiplier < 0));
        return;
    }
    else if (multiplier == 1) {
        result = multiplicand;
        result._sign = (multiplicand._sign != (multiplier < 0));
        return;
    }

    result._sign = false;
    result._slices.clear();

    bigint longer = multiplicand;
    intmax_t shorter = imaxabs(multiplier);
    while (shorter > 0) {
        if (shorter & 1) {
            result += longer;
        }
        longer += longer;
        shorter >>= 1;
    }

    if (multiplier < 0) {
        result._sign = !result._sign;
    }
}

/* this must be larger than other */
template <class T>
void bigint::abssubfrom(const T& other)
{
    size_t len_a = _slices.size();
    size_t len_b = other.size();
    size_t len_max = (len_a > len_b) ? len_a : len_b;

    int borrow = 0;
    for (size_t i = 0; i < len_max; i++) {
        int n_a = (i < len_a) ? _slices[i] : 0;
        int n_b = (i < len_b) ? other[i] : 0;

        int r;
        if (n_a - borrow >= n_b) {
            r = n_a - borrow - n_b;
            borrow = 0;
        }
        else {
            assert(i + 1 < len_a);

            r = n_a - borrow + slice_base_k - n_b;
            borrow = 1;
        }

        _slices[i] = r;
    }

    assert(borrow == 0);
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

    if (imaxabs(other) > max_nint_to_fit_k) {
        bigint other_bi { other };
        return *this + other_bi;
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

    if (imaxabs(other) > max_nint_to_fit_k) {
        bigint other_bi { other };
        *this += other_bi;
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

    if (imaxabs(other) > max_nint_to_fit_k) {
        bigint other_bi { other };
        return *this - other_bi;
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

    if (imaxabs(other) > max_nint_to_fit_k) {
        bigint other_bi { other };
        *this -= other_bi;
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
    if (imaxabs(other) > max_nint_to_fit_k) {
        bigint other_bi { other };
        return *this == other_bi;
    }

    slice_a other_slices;
    initfrom(other, other_slices);

    if (_sign == (other < 0) && abscmp(_slices, other_slices) == 0)
        return true;

    return false;
}

bool bigint::operator!= (intmax_t other) const
{
    if (imaxabs(other) > max_nint_to_fit_k) {
        bigint other_bi { other };
        return *this != other_bi;
    }

    slice_a other_slices;
    initfrom(other, other_slices);

    if (_sign == (other < 0) && abscmp(_slices, other_slices) == 0)
        return false;

    return true;
}

bool bigint::operator> (intmax_t other) const
{
    if (imaxabs(other) > max_nint_to_fit_k) {
        bigint other_bi { other };
        return *this > other_bi;
    }

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
    if (imaxabs(other) > max_nint_to_fit_k) {
        bigint other_bi { other };
        return *this >= other_bi;
    }

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
    if (imaxabs(other) > max_nint_to_fit_k) {
        bigint other_bi { other };
        return *this < other_bi;
    }

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
    if (imaxabs(other) > max_nint_to_fit_k) {
        bigint other_bi { other };
        return *this <= other_bi;
    }

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

    if (imaxabs(other) > max_nint_to_fit_k) {
        bigint other_bi { other };
        return *this * other_bi;
    }

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

    if (imaxabs(other) > max_nint_to_fit_k) {
        bigint other_bi { other };
        *this *= other_bi;
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
void bigint::absdiv_slice(const T& dividend, slice_t divisor,
        bigint& quotient, bigint& remainder)
{
    size_t pos = dividend.size() - 1;

    quotient._slices.clear();

    slice_t rem = 0;
    while (true) {
        twin_t numerator = dividend[pos] + rem * (twin_t)slice_base_k;
        imaxdiv_t div = imaxdiv(numerator, divisor);

        // clog << numerator << " / " << divisor << ": "
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
void bigint::absdiv_nint(const T& dividend, intmax_t divisor,
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
        __int128 numerator = makenint(dividend, pos, len);
        __int128 scale = 1;
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
        // imaxdiv_t div = imaxdiv(numerator, divisor);

        quotient *= scale;
        quotient += (numerator / divisor);
        rem = (numerator % divisor);

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
        // clog << "calling absdiv_slice()\n";
        absdiv_slice(dividend, divisor[0], quotient, remainder);
    }
    else if (divisor.size() <= max_group_slices_k) {
        intmax_t denominator = makenint(divisor);
        // clog << "calling absdiv_nint()\n";
        absdiv_nint(dividend, denominator, quotient, remainder);
    }
    else {
        return false;
    }

    return true;
}

void bigint::absdiv_slow(const bigint& numerator, const bigint& denominator,
        bigint& quotient, bigint& remainder)
{
    remainder._sign = false;
    remainder._slices = numerator._slices;

    quotient._sign = false;
    quotient._slices.clear();

    assert(numerator._slices.size() >= denominator._slices.size());

    const size_t sz_deno_slices = denominator._slices.size();
    while (abscmp(remainder._slices, denominator._slices) >= 0) {
        bigint quot_assumed;

        quot_assumed._sign = false;
        quot_assumed._slices.clear();
        if (remainder._slices.size() > sz_deno_slices) {
            size_t pos = sz_deno_slices;
            while (pos < remainder._slices.size()) {
                quot_assumed._slices.push_back(remainder._slices[pos]);
                pos++;
            }

            slice_t scale;
            scale = slice_base_k / denominator._slices.back();
            quot_assumed *= scale;
        }
        else {
            quot_assumed._slices.push_back(
                    remainder._slices.back() / denominator._slices.back());
        }

        quot_assumed._sign = remainder._sign;
        remainder -= quot_assumed * denominator;
        quotient += quot_assumed;
    }

    // clog << "absdiv_slow(): " << quotient << "..." << remainder << endl;

    while (remainder < 0) {
        quotient--;
        remainder += denominator;
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
        absdiv_slow(dividend, divisor, quotient, remainder);
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
    if (imaxabs(divisor) > max_nint_to_fit_k) {
        bigint divisor_bi { divisor };
        return divmod(dividend, divisor_bi, quotient, remainder);
    }

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

/*
 * This function calculates the result of
 * (rem_pre + ((factor * base^exp) % modulus)) % modulus
 */
bigint::slice_t bigint::quick_modulo(slice_t factor, slice_t base, uintmax_t exp,
        slice_t modulus, slice_t rem_pre)
{
    twin_t rem_w = 1;
    twin_t base_w = base;

    while (exp) {
        if (exp & 1)
            rem_w = (rem_w * base_w) % modulus;
        base_w = (base_w * base_w) % modulus;
        exp >>= 1;
    }

    rem_w = (rem_w * factor) % modulus;
    rem_w = (rem_w + rem_pre) % modulus;
    return static_cast<slice_t>(rem_w);
}

/*
 * This function calculates the result of
 * (rem_pre + ((factor * base^exp) % modulus)) % modulus
 */
intmax_t bigint::quick_modulo_128(intmax_t factor, intmax_t base, uintmax_t exp,
        intmax_t modulus, intmax_t rem_pre)
{
    __int128 rem_128 = 1;
    __int128 base_128 = base;

    while (exp) {
        if (exp & 1)
            rem_128 = (rem_128 * base_128) % modulus;
        base_128 = (base_128 * base_128) % modulus;
        exp >>= 1;
    }

    rem_128 = (rem_128 * factor) % modulus;
    rem_128 += rem_pre;
    rem_128 %= modulus;
    return static_cast<intmax_t>(rem_128);
}

template <class T>
void bigint::absmod_slice(const T& dividend, slice_t divisor,
        bigint& remainder)
{
    uintmax_t exp = 0;
    slice_t rem = 0;
    size_t pos = 0;
    while (pos < dividend.size()) {
        slice_t numerator = dividend[pos];
        rem = quick_modulo(numerator, slice_base_k, exp, divisor, rem);
        exp++;
        pos++;
    }

    remainder = rem;
}

template <class T>
void bigint::absmod_nint(const T& dividend, intmax_t divisor,
        bigint& remainder)
{
    uintmax_t exp = 0;
    intmax_t rem = 0;
    size_t size = dividend.size();
    size_t left = size;
    while (left > 0) {
        size_t len;
        if (left < max_group_slices_k) {
            len = left;
        }
        else {
            len = max_group_slices_k;
        }

        size_t pos = size - left;
        intmax_t numerator = makenint(dividend, pos, len);

        rem = quick_modulo_128(numerator, group_base_k, exp, divisor, rem);
        exp++;

        left -= len;
    }

    remainder = rem;
}

bigint  bigint::operator/  (const bigint& other) const
{
    if (other.iszero())
        throw std::runtime_error("BigInt: division by zero!");

    bigint quotient, remainder;
    divmod(*this, other, quotient, remainder);
    return quotient;
}

bigint& bigint::operator/= (const bigint& other)
{
    if (other.iszero())
        throw std::runtime_error("BigInt: division by zero!");

    bigint quotient, remainder;
    divmod(*this, other, quotient, remainder);
    _sign = quotient._sign;
    _slices = std::move(quotient._slices);
    return *this;
}

bigint  bigint::operator/  (intmax_t other) const
{
    if (other == 0)
        throw std::runtime_error("BigInt: division by zero!");

    bigint quotient, remainder;
    divmod(*this, other, quotient, remainder);
    return quotient;
}

bigint& bigint::operator/= (intmax_t other)
{
    if (other == 0)
        throw std::runtime_error("BigInt: division by zero!");

    bigint quotient, remainder;
    divmod(*this, other, quotient, remainder);
    _sign = quotient._sign;
    _slices = std::move(quotient._slices);
    return *this;
}

bigint  bigint::operator%  (const bigint& other) const
{
    bigint remainder;

    if (other.iszero()) {
        throw std::runtime_error("BigInt: division by zero!");
    }
    else if (iszero() || other.isone()) {
        remainder = 0;
    }
    else if (other._slices.size() == 1) {
        absmod_slice(_slices, other._slices[0], remainder);
        if (!remainder.iszero())
            remainder._sign = _sign;
    }
    else if (other._slices.size() <= max_group_slices_k) {
        intmax_t denominator = makenint(other._slices);
        absmod_nint(_slices, denominator, remainder);
        if (!remainder.iszero())
            remainder._sign = _sign;
    }
    else {
        bigint quotient;
        divmod(*this, other, quotient, remainder);
    }

    return remainder;
}

bigint& bigint::operator%= (const bigint& other)
{
    if (other.iszero())
        throw std::runtime_error("BigInt: division by zero!");
    else if (iszero() || other.isone()) {
        _sign = false;
        _slices.clear();
    }
    else if (other._slices.size() == 1) {
        bigint remainder;
        absmod_slice(_slices, other._slices[0], remainder);
        if (remainder.iszero())
            _sign = false;
        _slices = std::move(remainder._slices);
    }
    else if (other._slices.size() <= max_group_slices_k) {
        bigint remainder;
        intmax_t denominator = makenint(other._slices);
        absmod_nint(_slices, denominator, remainder);
        if (remainder.iszero())
            _sign = false;
        _slices = std::move(remainder._slices);
    }
    else {
        bigint quotient, remainder;
        divmod(*this, other, quotient, remainder);
        _sign = remainder._sign;
        _slices = std::move(remainder._slices);
    }

    return *this;
}

bigint  bigint::operator%  (intmax_t other) const
{
    bigint remainder;
    absmod_nint(_slices, other, remainder);
    if (!remainder.iszero())
        remainder._sign = _sign;
    return remainder;
}

bigint& bigint::operator%= (intmax_t other)
{
    bigint remainder;
    absmod_nint(_slices, other, remainder);
    if (remainder.iszero())
        _sign = false;
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

void test_bigint2(void)
{
    static struct bigintcase {
        const char *op1;
        const char *op2;
        const char *sum;
        const char *diff;
        const char *prod;
        const char *quot;
        const char *rem;
    } cases[] = {
        {
            "000000010000000200000003",
            "000000010000000200000003",
            "20000000400000006",
            "0",
            "100000004000000100000001200000009",
            "1",
            "0",
        },
        {
            "000000020000000400000006",
            "000000010000000200000003",
            "30000000600000009",
            "10000000200000003",
            "200000008000000200000002400000018",
            "2",
            "0",
        },
        {
            "000000050000001000000015",
            "000000010000000200000003",
            "60000001200000018",
            "40000000800000012",
            "500000020000000500000006000000045",
            "5",
            "0",
        },
        {
            "000000150000021000000015",
            "3",
            "150000021000000018",
            "150000021000000012",
            "450000063000000045",
            "50000007000000005",
            "0",
        },
        {
            "30257056966624049406876268303231201200",
            "41908997197273957480890101023095532464",
            "72166054163898006887766369326326733664",
            "-11651940230649908074013832719864331264",
            "1268042915612005756251291646890691548708773202990750170847771603412315756800",
            "0",
            "30257056966624049406876268303231201200",
        },
        {
            "30257056966624049406876268303231201200",
            "-41908997197273957480890101023095532464",
            "-11651940230649908074013832719864331264",
            "72166054163898006887766369326326733664",
            "-1268042915612005756251291646890691548708773202990750170847771603412315756800",
            "0",
            "30257056966624049406876268303231201200",
        },
        {
            "-30257056966624049406876268303231201200",
            "-41908997197273957480890101023095532464",
            "-72166054163898006887766369326326733664",
            "11651940230649908074013832719864331264",
            "1268042915612005756251291646890691548708773202990750170847771603412315756800",
            "0",
            "-30257056966624049406876268303231201200",
        },
        {
            "41908997197273957480890101023095532464",
            "30257056966624049406876268303231201200",
            "72166054163898006887766369326326733664",
            "11651940230649908074013832719864331264",
            "1268042915612005756251291646890691548708773202990750170847771603412315756800",
            "1",
            "11651940230649908074013832719864331264",
        },
        {
            "30257056966624049406876268303231201200",
            "419089971972739574",
            "30257056966624049407295358275203940774",
            "30257056966624049406457178331258461626",
            "12680429156120057538037952521989157217197986678796288800",
            "72197043570854450248",
            "48608744987486848",
        },
        {
            "30257056966624049406876268303231201200",
            "41908997",
            "30257056966624049406876268303273110197",
            "30257056966624049406876268303189292203",
            "1268042909643076386720629307691311501397196400",
            "721970439107002475074177229849",
            "21149747",
        },
        {
            "30257056966624049406876268303231201200",
            "-41908997",
            "30257056966624049406876268303189292203",
            "30257056966624049406876268303273110197",
            "-1268042909643076386720629307691311501397196400",
            "-721970439107002475074177229849",
            "21149747",
        },
        {
            "-30257056966624049406876268303231201200",
            "-41908997",
            "-30257056966624049406876268303273110197",
            "-30257056966624049406876268303189292203",
            "1268042909643076386720629307691311501397196400",
            "721970439107002475074177229849",
            "-21149747",
        },
        {
            "30257056966624049406876268303231201200",
            "1",
            "30257056966624049406876268303231201201",
            "30257056966624049406876268303231201199",
            "30257056966624049406876268303231201200",
            "30257056966624049406876268303231201200",
            "0",
        },
        {
            "-30257056966624049406876268303231201200",
            "1",
            "-30257056966624049406876268303231201199",
            "-30257056966624049406876268303231201201",
            "-30257056966624049406876268303231201200",
            "-30257056966624049406876268303231201200",
            "0",
        },
        {
            "1",
            "30257056966624049406876268303231201200",
            "30257056966624049406876268303231201201",
            "-30257056966624049406876268303231201199",
            "30257056966624049406876268303231201200",
            "0",
            "1",
        },
        {
            "-1",
            "30257056966624049406876268303231201200",
            "30257056966624049406876268303231201199",
            "-30257056966624049406876268303231201201",
            "-30257056966624049406876268303231201200",
            "0",
            "-1",
        },
    };

    for (size_t i = 0; i < sizeof(cases)/sizeof(cases[0]); i++) {
        bigint a(cases[i].op1);
        bigint b(cases[i].op2);

        clog << "Tesing with " << a << " and " << b << endl;
        string expect;
        ostringstream oss;

        expect = cases[i].sum;
        oss.str("");
        oss << (a + b);
        assert(oss.str() == expect);

        expect = cases[i].diff;
        oss.str("");
        oss << (a - b);
        assert(oss.str() == expect);

        expect = cases[i].prod;
        oss.str("");
        oss << (a * b);
        assert(oss.str() == expect);

        bigint prod;
        bigint::nttmul(a, b, prod);
        expect = cases[i].prod;
        oss.str("");
        oss << prod;
        clog << prod << " vs " << expect << endl;
        assert(oss.str() == expect);

        expect = cases[i].quot;
        oss.str("");
        oss << (a / b);
        // clog << (a / b) << " vs " << expect << endl;
        assert(oss.str() == expect);

        expect = cases[i].rem;
        oss.str("");
        oss << (a % b);
        assert(oss.str() == expect);

        bigint quot, rem;
        bigint::divmod(a, b, quot, rem);

        expect = cases[i].quot;
        oss.str("");
        oss << quot;
        assert(oss.str() == expect);

        expect = cases[i].rem;
        oss.str("");
        oss << rem;
        assert(oss.str() == expect);

        bigint ret;

        ret = a, ret += b;
        expect = cases[i].sum;
        oss.str("");
        oss << ret;
        assert(oss.str() == expect);

        ret = a, ret -= b;
        expect = cases[i].diff;
        oss.str("");
        oss << ret;
        assert(oss.str() == expect);

        ret = a, ret *= b;
        expect = cases[i].prod;
        oss.str("");
        oss << ret;
        assert(oss.str() == expect);

        ret = a, ret /= b;
        expect = cases[i].quot;
        oss.str("");
        oss << ret;
        assert(oss.str() == expect);

        ret = a, ret %= b;
        expect = cases[i].rem;
        oss.str("");
        oss << ret;
        assert(oss.str() == expect);
    }
}

void test_bigint3(void)
{
    static struct bigintcase {
        const char *op1;
        intmax_t    op2;
        const char *sum;
        const char *diff;
        const char *prod;
        const char *quot;
        const char *rem;
    } cases[] = {
        {
            "30257056966624049406876268303231201200",
            41908997LL,
            "30257056966624049406876268303273110197",
            "30257056966624049406876268303189292203",
            "1268042909643076386720629307691311501397196400",
            "721970439107002475074177229849",
            "21149747",
        },
        {
            "30257056966624049406876268303231201200",
            -41908997,
            "30257056966624049406876268303189292203",
            "30257056966624049406876268303273110197",
            "-1268042909643076386720629307691311501397196400",
            "-721970439107002475074177229849",
            "21149747",
        },
        {
            "-30257056966624049406876268303231201200",
            -41908997,
            "-30257056966624049406876268303273110197",
            "-30257056966624049406876268303189292203",
            "1268042909643076386720629307691311501397196400",
            "721970439107002475074177229849",
            "-21149747",
        },
        {
            "30257056966624049406876268303231201200",
            1,
            "30257056966624049406876268303231201201",
            "30257056966624049406876268303231201199",
            "30257056966624049406876268303231201200",
            "30257056966624049406876268303231201200",
            "0",
        },
        {
            "-30257056966624049406876268303231201200",
            1,
            "-30257056966624049406876268303231201199",
            "-30257056966624049406876268303231201201",
            "-30257056966624049406876268303231201200",
            "-30257056966624049406876268303231201200",
            "0",
        },
    };

    for (size_t i = 0; i < sizeof(cases)/sizeof(cases[0]); i++) {
        bigint a(cases[i].op1);
        bigint b(cases[i].op2);

        clog << "Tesing with " << a << " and " << b << endl;
        string expect;
        ostringstream oss;

        expect = cases[i].sum;
        oss.str("");
        oss << (a + b);
        assert(oss.str() == expect);

        expect = cases[i].diff;
        oss.str("");
        oss << (a - b);
        assert(oss.str() == expect);

        expect = cases[i].prod;
        oss.str("");
        oss << (a * b);
        assert(oss.str() == expect);

        bigint prod;
        bigint::nttmul(a, b, prod);
        expect = cases[i].prod;
        oss.str("");
        oss << prod;
        clog << prod << " vs " << expect << endl;
        assert(oss.str() == expect);

        expect = cases[i].quot;
        oss.str("");
        oss << (a / b);
        // clog << (a / b) << " vs " << expect << endl;
        assert(oss.str() == expect);

        expect = cases[i].rem;
        oss.str("");
        oss << (a % b);
        assert(oss.str() == expect);

        bigint quot, rem;
        bigint::divmod(a, b, quot, rem);

        expect = cases[i].quot;
        oss.str("");
        oss << quot;
        assert(oss.str() == expect);

        expect = cases[i].rem;
        oss.str("");
        oss << rem;
        assert(oss.str() == expect);

        bigint ret;

        ret = a, ret += b;
        expect = cases[i].sum;
        oss.str("");
        oss << ret;
        assert(oss.str() == expect);

        ret = a, ret -= b;
        expect = cases[i].diff;
        oss.str("");
        oss << ret;
        assert(oss.str() == expect);

        ret = a, ret *= b;
        expect = cases[i].prod;
        oss.str("");
        oss << ret;
        assert(oss.str() == expect);

        ret = a, ret /= b;
        expect = cases[i].quot;
        oss.str("");
        oss << ret;
        assert(oss.str() == expect);

        ret = a, ret %= b;
        expect = cases[i].rem;
        oss.str("");
        oss << ret;
        assert(oss.str() == expect);
    }
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
    test_bigint2();
    test_bigint3();

    bigint result;

    bigint nine = 9;
    result = nine * 9;
    assert(result == 81);

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

