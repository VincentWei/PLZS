/*
 * This program converts a given rational number to a fraction by
 * using native integer types.
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
#include <iostream>     // for std::cin and std::cout
#include <string>       // for std::string and std::stoll()
#include <cstdint>      // for intmax_t
#include <cassert>      // for assert()

using namespace std;

/*
 * intmax_power:
 *
 * @base: the base.
 * @exp: the exponent.
 *
 * returns: The power of @base raised to @exp.
 */
intmax_t intmax_power(intmax_t &base, unsigned exp)
{
    intmax_t r(1);

    while (exp--) {
        r *= base;
    }

    return r;
}

/*
 * intmax_gcd:
 *
 * @_a: one of two intmax_ts.
 * @_b: the other of two intmax_ts.
 *
 * returns: The GCD of two intmax_ts.
 */
intmax_t intmax_gcd(const intmax_t &_a, const intmax_t &_b)
{
    intmax_t a(_a);
    intmax_t b(_b);

    while (b != 0) {
        intmax_t tmp(a);
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

    intmax_t integer = stoll(int_part);       // 整数部分

    intmax_t numerator_nr;            // 不循环部分的分子
    intmax_t denominator_nr;          // 不循环部分的分母
    if (not_recurring_part.length() > 0) {
        numerator_nr = stoll(not_recurring_part);

        intmax_t base(10);
        denominator_nr = intmax_power(base, not_recurring_part.length());
    }
    else {
        numerator_nr = 0;
        denominator_nr = 1;
    }

    intmax_t numerator_rc;            // 循环部分的分子
    intmax_t denominator_rc;          // 循环部分的分母
    if (recurring_part.length() > 0) {
        numerator_rc = stoll(recurring_part);

        intmax_t base(10);
        denominator_rc = intmax_power(base, recurring_part.length());
        denominator_rc--;
    }
    else {
        numerator_rc = 0;
        denominator_rc = 1;
    }

    denominator_rc *= denominator_nr;

    intmax_t denominator, numerator;
    denominator = denominator_nr * denominator_rc;
    numerator = integer * denominator
        + numerator_nr * denominator_rc
        + numerator_rc * denominator_nr;

    intmax_t gcd = intmax_gcd(numerator, denominator);

    cout << numerator / gcd << "/" << denominator / gcd << endl;
    return 0;
}

