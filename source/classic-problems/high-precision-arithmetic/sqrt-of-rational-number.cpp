/*
 * This program converts a given rational number to a fraction.
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

#define NTEST
#include "bigint.cpp"

/*
 * bigint_power:
 *
 * @base: the base.
 * @exp: the exponent.
 *
 * returns: The power of @base raised to @exp.
 */
bigint bigint_power(bigint &base, unsigned exp)
{
    bigint r(1);

    while (exp--) {
        r *= base;
    }

    return r;
}

/*
 * bigint_gcd:
 *
 * @_a: one of two bigints.
 * @_b: the other of two bigints.
 *
 * returns: The GCD of two bigints.
 */
bigint bigint_gcd(const bigint &_a, const bigint &_b)
{
    bigint a(_a);
    bigint b(_b);

    while (b != 0) {
        bigint tmp(a);
        a = b;
        cout << "modulo: " << tmp << " % " << b << endl;
        b = tmp % b;
    }

    return a;
}

/*
 * bigint_lcm:
 *
 * @_a: one of two bigints.
 * @_b: the other of two bigints.
 *
 * returns: The LCM of two bigints.
 */
bigint bigint_lcm(const bigint &_a, const bigint &_b)
{
    return _a * _b / bigint_gcd(_a, _b);
}

#include <utility>

using rational_t = pair<bigint, bigint>;

rational_t string_to_rational(const string& rational, unsigned recurring_len)
{
    string int_part;                // 整数部分
    string not_recurring_part;      // 小数中的不循环部分
    string recurring_part;          // 小数中的循环部分

    size_t pos_point;       // 小数点位置
    pos_point = rational.find('.');
    if (pos_point == string::npos) {
        int_part = rational;
    }
    else {
        int_part = rational.substr(0, pos_point);
        not_recurring_part = rational.substr(pos_point + 1);
        if (recurring_len > 0) {
            size_t len_not_recur = not_recurring_part.length() - recurring_len;
            recurring_part = not_recurring_part.substr(len_not_recur);
            not_recurring_part = not_recurring_part.substr(0, len_not_recur);
        }
    }

    bigint integer(int_part);       // 整数部分

    bigint numerator_nr;            // 不循环部分的分子
    bigint denominator_nr;          // 不循环部分的分母
    if (not_recurring_part.length() > 0) {
        numerator_nr = not_recurring_part;

        bigint base(10);
        denominator_nr = bigint_power(base, not_recurring_part.length());
    }
    else {
        numerator_nr = 0;
        denominator_nr = 1;
    }

    bigint numerator_rc;            // 循环部分的分子
    bigint denominator_rc;          // 循环部分的分母
    if (recurring_part.length() > 0) {
        numerator_rc = recurring_part;

        bigint base(10);
        denominator_rc = bigint_power(base,
                not_recurring_part.length() + recurring_len);
        denominator_rc--;
    }
    else {
        numerator_rc = 0;
        denominator_rc = 1;
    }

    bigint denominator = denominator_nr * denominator_rc;
    bigint numerator = integer * denominator
        + numerator_nr * denominator_rc
        + numerator_rc * denominator_nr;

    return rational_t {numerator, denominator};
}

void rn_normalize(rational_t& q)
{
    bigint gcd = bigint_gcd(q.first, q.second);

    if (gcd != 1) {
        q.first /= gcd;
        q.second /= gcd;
    }

    if (q.first.sign() == q.second.sign()) {
        q.first.sign(false);
        q.second.sign(false);
    }
    else {
        q.first.sign(true);
        q.second.sign(false);
    }
}

rational_t rn_nan()
{
    return rational_t {bigint {0}, bigint {0}};
}

bool rn_is_nan(const rational_t q)
{
    return q.second == 0;
}

rational_t rn_from_int(intmax_t n)
{
    return rational_t {bigint {n}, bigint {1}};
}

rational_t rn_from_int(intmax_t n, intmax_t m)
{
    if (n <= 0 && m < 0) {
        return rational_t {bigint {abs(n)}, bigint {abs(m)}};
    }
    else if ((n < 0 && m > 0) || (n > 0 && m < 0)) {
        return rational_t {bigint {-abs(n)}, bigint {abs(m)}};
    }
    else {
        return rational_t {bigint {n}, bigint {m}};
    }
}

rational_t rn_from_reciprocal(intmax_t n)
{
    if (n == 0)
        return rn_nan();
    else if (n < 0)
        return rational_t {bigint {-1}, bigint {-n}};

    return rational_t {bigint {1}, bigint {n}};
}

rational_t rn_abs(const rational_t& q)
{
    rational_t r = q;
    r.first.sign(false);
    r.second.sign(false);
    return r;
}

void operator /= (rational_t& q, intmax_t n)
{
    if (n == 0)
        q.first = q.second = 0;
    else if (n > 0)
        q.second *= n;
    else {
        q.first.reverse();
        q.second *= -n;
    }
}

rational_t operator / (const rational_t& q, intmax_t n)
{
    if (n == 0)
        return rn_nan();

    rational_t r = q;
    if (n > 0)
        r.second *= n;
    else {
        r.first.reverse();
        r.second *= -n;
    }

    return r;
}

rational_t operator / (const rational_t& q1, const rational_t& q2)
{
    if (q2.first == 0)
        return rn_nan();

    rational_t r = { q1.first * q2.second, q1.second * q2.first };
    rn_normalize(r);
    return r;
}

rational_t operator * (const rational_t& q, intmax_t n)
{
    rational_t r = { q.first * n, q.second };
    rn_normalize(r);
    return r;
}

rational_t operator * (const rational_t& q1, const rational_t& q2)
{
    rational_t r = { q1.first * q2.first, q1.second * q2.second };
    rn_normalize(r);
    return r;
}

rational_t operator + (const rational_t& q, intmax_t n)
{
    rational_t p = q;
    p.first += q.second * n;
    return p;
}

rational_t operator - (const rational_t& q1, const rational_t& q2)
{
    rational_t r;
    r.first = q1.first * q2.second - q2.first * q1.second;
    r.second = q1.second * q2.second;

    rn_normalize(r);
    return r;
}

bool operator > (const rational_t& q, intmax_t n)
{
    bool sign = q.first.sign() == q.second.sign();
    if (sign && n < 0)
        return true;
    else if (sign == false && n > 0)
        return false;

    bigint quot = q.first / q.second;
    if (sign) {
        return (quot > n);
    }
    else {
        return (quot < n);
    }
}

bool operator < (const rational_t& q, intmax_t n)
{
    bool sign = q.first.sign() == q.second.sign();
    if (sign == false && n > 0)
        return true;
    else if (sign && n < 0)
        return false;

    bigint quot = q.first / q.second;
    if (sign) {
        return (quot < n);
    }
    else {
        return (quot > n);
    }
}

bool operator < (const rational_t& q1, const rational_t& q2)
{
    if (q1.first.sign() != q2.first.sign())
        return q1.first < q2.first;

    bigint num1 = q1.first * q2.second;
    bigint num2 = q2.first * q1.second;

    return num1 < num2;
}

bool operator > (const rational_t& q1, const rational_t& q2)
{
    if (q1.first.sign() != q2.first.sign())
        return q1.first > q2.first;

    bigint num1 = q1.first * q2.second;
    bigint num2 = q2.first * q1.second;

    return num1 > num2;
}

ostream& operator<< (ostream& os, const rational_t& q)
{
    if (rn_is_nan(q)) {
        os << "NAN";
        return os;
    }

    bigint numerator = q.first;
    const bigint& denominator = q.second;

    if (numerator.sign()) {
        numerator.reverse();
        os << "-";
    }

    bigint quot, rem;
    bigint::divmod(numerator, denominator, quot, rem);
    os << quot;
    if (rem != 0) {
        os << ".";

        bigint last_quot;
        numerator = rem * 10;
        size_t precision = os.precision() + 1;
        while (precision--) {
            last_quot = quot;
            bigint::divmod(numerator, denominator, quot, rem);
            if (precision > 1)
                os << quot;
            if (rem == 0) {
                break;
            }

            numerator = rem * 10;
        }

        if (rem != 0) {
            if (quot > 4)
                last_quot++;
            os << last_quot;
        }
    }

    return os;
}

rational_t rn_estimate_square_root(const rational_t& q, unsigned scale)
{
    clog << "rational number: " << q << endl;

    if (q.first < 0)
        return rn_nan();

    if (q.first == 0) {
        return rn_from_int(0);
    }
    else if (q.first == q.second) {
        return rn_from_int(1);
    }

    rational_t tolerance = rn_from_int(1);
    while (scale != 0) {
        tolerance /= 10;
        scale--;
    }

    cout << "tolerance: " << tolerance << endl;

    rational_t x0;
    if (q > 1)
        x0 = (q + 1) / 2;
    else if (q < 1)
        x0 = q / 2;
    else
        x0 = rn_from_int(1);

    rational_t x1 = x0;
    unsigned i = 0;
    while (i < 1000) {

        rational_t last = x1;
        x1 = x0 - (x0 * x0 - q) / (x0 * 2);
        rational_t errors = rn_abs(last - x1);
        cout << "Iteration #" << i << ":\tx_i = " << x1 << "; errors: "
            << errors << endl;
        if (errors < tolerance) {
            break;
        }

        x0 = x1;
        i++;
    }

    return x1;
}

#include <sstream>

void test_rational()
{
    rational_t a;
    ostringstream oss;

    a = rn_nan();
    oss << a;
    clog << oss.str() << endl;
    assert(oss.str() == "NAN");

    a = rn_from_int(4);
    oss.str("");
    oss << a;
    clog << oss.str() << endl;
    assert(oss.str() == "4");

    a = rn_from_reciprocal(4);
    oss.str("");
    oss << a;
    clog << oss.str() << endl;
    assert(oss.str() == "0.25");

    oss.precision(10);
    a = rn_from_reciprocal(-3);
    oss.str("");
    oss << a;
    clog << oss.str() << endl;
    assert(oss.str() == "-0.3333333333");

    a = rn_from_int(2, 3);
    oss.str("");
    oss << a;
    clog << oss.str() << endl;
    assert(oss.str() == "0.6666666667");

    a = rn_from_int(2, -3);
    oss.str("");
    oss << a;
    clog << oss.str() << endl;
    assert(oss.str() == "-0.6666666667");
}

int main()
{
    test_rational();

    string rational;
    unsigned recurring_len, scale;
    cin >> rational >> recurring_len >> scale;

    rational_t q = string_to_rational(rational, recurring_len);
    rn_normalize(q);

    cout.precision(scale);
    rational_t r = rn_estimate_square_root(q, scale);
    cout << r << endl;
    return 0;
}

