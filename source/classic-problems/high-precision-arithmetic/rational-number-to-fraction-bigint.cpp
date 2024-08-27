/*
 * This program converts a given rational number to a fraction.
 *
 * Author: Vincent Wei
 *  - <https://github.com/VincentWei>
 *  - <https://gitee.com/vincentwei7>
 *
 * Copyright (C) 2024 FMSoft <https://www.fmsoft.cn>.
 * License: GPLv3
 */

#define NDEBUG
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
        b = tmp % b;
    }

    return a;
}

int main()
{
    string rational;
    unsigned n;
    cin >> rational >> n;

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
        if (n > 0) {
            size_t len_not_recur = not_recurring_part.length() - n;
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
        denominator_rc = bigint_power(base, not_recurring_part.length() + n);
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

    bigint gcd = bigint_gcd(numerator, denominator);

    cout << numerator / gcd << "/" << denominator / gcd << endl;
    return 0;
}

