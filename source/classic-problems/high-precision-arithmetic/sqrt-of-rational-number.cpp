/*
 * This program estimates the square root of a positive rational number
 * to the given number of the decimal part.
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
bigint bigint_power(const bigint &base, unsigned exp)
{
    bigint ret = 1;
    bigint lifting_base = base;

    while (exp) {
        if (exp & 1)
            ret = ret * lifting_base;
        lifting_base = lifting_base * lifting_base;
        exp >>= 1;
    }

    return ret;
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
        bigint tmp = move(a);
        a = b;
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

using rational = pair<bigint, bigint>;

rational q_from_string(const string& str, unsigned recurring_len)
{
    string int_part;                // 整数部分
    string not_recurring_part;      // 小数中的不循环部分
    string recurring_part;          // 小数中的循环部分

    size_t pos_point;       // 小数点位置
    pos_point = str.find('.');
    if (pos_point == string::npos) {
        int_part = str;
    }
    else {
        int_part = str.substr(0, pos_point);
        not_recurring_part = str.substr(pos_point + 1);
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

    return rational {numerator, denominator};
}

void q_normalize(rational& q)
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

rational q_from_int(intmax_t n)
{
    return rational {bigint {n}, bigint {1}};
}

rational q_from_int(intmax_t n, intmax_t m)
{
    if (m == 0) {
        throw std::runtime_error("Rational: division by zero!");
    }
    if (n <= 0 && m < 0) {
        return rational {bigint {abs(n)}, bigint {abs(m)}};
    }
    else if ((n < 0 && m > 0) || (n > 0 && m < 0)) {
        return rational {bigint {-abs(n)}, bigint {abs(m)}};
    }
    else {
        return rational {bigint {n}, bigint {m}};
    }
}

rational q_from_reciprocal(intmax_t n)
{
    if (n == 0)
        throw std::runtime_error("Rational: division by zero!");
    else if (n < 0)
        return rational {bigint {-1}, bigint {-n}};

    return rational {bigint {1}, bigint {n}};
}

rational q_abs(const rational& q)
{
    rational r = q;
    r.first.sign(false);
    r.second.sign(false);
    return r;
}

void operator /= (rational& q, intmax_t n)
{
    if (n == 0)
        throw std::runtime_error("Rational: division by zero!");
    else if (n > 0)
        q.second *= n;
    else {
        q.first.reverse();
        q.second *= -n;
    }
    // q_normalize(q);
}

rational operator / (const rational& q, intmax_t n)
{
    if (n == 0)
        throw std::runtime_error("Rational: division by zero!");

    rational r = q;
    if (n > 0)
        r.second *= n;
    else {
        r.first.reverse();
        r.second *= -n;
    }

    // q_normalize(r);
    return r;
}

rational operator / (const rational& q1, const rational& q2)
{
    if (q2.first == 0)
        throw std::runtime_error("Rational: division by zero!");

    rational r = { q1.first * q2.second, q1.second * q2.first };
    // q_normalize(r);
    return r;
}

rational operator * (const rational& q, intmax_t n)
{
    rational r = { q.first * n, q.second };
    // q_normalize(r);
    return r;
}

rational operator * (const rational& q1, const rational& q2)
{
    rational r = { q1.first * q2.first, q1.second * q2.second };
    // q_normalize(r);
    return r;
}

rational operator + (const rational& q, intmax_t n)
{
    rational p = q;
    p.first += q.second * n;
    // q_normalize(r);
    return p;
}

rational operator - (const rational& q1, const rational& q2)
{
    rational r;
    r.first = q1.first * q2.second - q2.first * q1.second;
    r.second = q1.second * q2.second;
    // q_normalize(r);
    return r;
}

bool operator > (const rational& q, intmax_t n)
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

bool operator < (const rational& q, intmax_t n)
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

bool operator < (const rational& q1, const rational& q2)
{
    if (q1.first.sign() != q2.first.sign())
        return q1.first < q2.first;

    bigint num1 = q1.first * q2.second;
    bigint num2 = q2.first * q1.second;

    return num1 < num2;
}

bool operator > (const rational& q1, const rational& q2)
{
    if (q1.first.sign() != q2.first.sign())
        return q1.first > q2.first;

    bigint num1 = q1.first * q2.second;
    bigint num2 = q2.first * q1.second;

    return num1 > num2;
}

bool operator == (const rational& q, intmax_t z)
{
    if (q.first == 0)
        return z == 0;
    else if (z == 1) {
        return q.first == q.second;
    }
    else if (z == -1) {
        return q.first.sign() && q.first.abscmp(q.second) == 0;
    }

    bigint product = q.second * z;
    return product == q.first;
}

ostream& operator<< (ostream& os, const rational& q)
{
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

int compare_square(const bigint& mid, const bigint& n)
{
    bigint square_mid = mid * mid;
    if (square_mid == n)
        return 0;

    if (square_mid < n) {
        square_mid += mid * 2;
        square_mid++;
        if (square_mid > n) {
            return 0;
        }

        return -1;
    }

    return 1;
}

bigint maximum_le_sqrt(const bigint& n)
{
    if (n < 2)
        return bigint(n);

    bigint start = 0;
    bigint end = n;
    bigint mid = 0;

    while (start <= end) {
        mid = start + (end - start) / 2;
        if (mid == 0)
            break;

        int r = compare_square(mid, n);
        if (r == 0) {
            break;
        }
        else if (r > 0) {
            end = mid;
        }
        else {
            start = mid;
        }
    }

    return mid;
}

rational q_sqrt(const rational& q, unsigned scale)
{
    // clog << "rational number: " << q << endl;

    if (q.first < 0)
        throw std::domain_error("Rational: the square root for a negative number is undefined!");

    if (q.first == 0) {
        return q_from_int(0);
    }
    else if (q.first == q.second) {
        return q_from_int(1);
    }

    rational tolerance = q_from_int(1);
    while (scale != 0) {
        tolerance /= 10;
        scale--;
    }

    // clog << "tolerance: " << tolerance << endl;

    rational x0;
    if (q > 4) {
        bigint quot, rem;
        bigint::divmod(q.first, q.second, quot, rem);
        rem = maximum_le_sqrt(quot);
        x0 = rational {rem, bigint {1}};
    }
    else if (q > 1)
        x0 = (q + 1) / 2;
    else if (q < 1)
        x0 = q / 2;
    else
        x0 = q_from_int(1);

    rational x1 = x0;
    unsigned i = 0;
    while (i < 1000) {

        rational last = x1;
        x1 = x0 - (x0 * x0 - q) / (x0 * 2);
        q_normalize(x1);
        rational errors = q_abs(last - x1);
        clog << "Iteration #" << i << ":\tx = " << x1 << "; errors: "
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
    rational a;
    ostringstream oss;

    a = q_from_int(4);
    oss.str("");
    oss << a;
    // clog << oss.str() << endl;
    assert(oss.str() == "4");

    a = q_from_reciprocal(4);
    oss.str("");
    oss << a;
    // clog << oss.str() << endl;
    assert(oss.str() == "0.25");

    oss.precision(10);
    a = q_from_reciprocal(-3);
    oss.str("");
    oss << a;
    // clog << oss.str() << endl;
    assert(oss.str() == "-0.3333333333");

    a = q_from_int(2, 3);
    oss.str("");
    oss << a;
    // clog << oss.str() << endl;
    assert(oss.str() == "0.6666666667");

    a = q_from_int(2, -3);
    oss.str("");
    oss << a;
    // clog << oss.str() << endl;
    assert(oss.str() == "-0.6666666667");
}

int main()
{
    test_rational();

    string str;
    unsigned recurring_len, scale;
    cin >> str >> recurring_len >> scale;

    rational q = q_from_string(str, recurring_len);
    q_normalize(q);

    cout.precision(scale);
    try {
        q = q_sqrt(q, scale);
        cout << q << endl;
    }
    catch (std::exception& e) {
        cerr << "exception caught: " << e.what() << endl;
        cout << "NAN" << endl;
    }

    return 0;
}

