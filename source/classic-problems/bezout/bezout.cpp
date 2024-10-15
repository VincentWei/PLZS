/*
 * The extended Euclid version for Bezout equation.
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
#include <iostream>     // for cin and cout
#include <cassert>      // for assert()

using namespace std;

intmax_t ex_gcd_r(intmax_t a, intmax_t b, intmax_t& x, intmax_t& y)
{
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    intmax_t gcd = ex_gcd_r(b, a % b, x, y);
    intmax_t temp = x;
    x = y;
    y = temp - a / b * y;
    return gcd;
}

intmax_t ex_gcd_i(intmax_t a, intmax_t b, intmax_t& x, intmax_t& y)
{
    intmax_t prev_x, prev_y;

    prev_x = 0; prev_y = 1;
    x = 1; y = 0;
    while (b != 0) {
        intmax_t q = a / b;

        intmax_t tmp;
        tmp = prev_x; prev_x = prev_x - q * x; prev_x = x;
        tmp = prev_y; prev_y = prev_y - q * y; prev_y = y;
        tmp = b; b = a % b; a = tmp;
    }

    x = prev_x; y = prev_y;
    return a;
}

int main()
{
    intmax_t a, b, d;
    cin >> a >> b >> d;

    if (a == 0 || b == 0 || d == 0) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }

    intmax_t x0, y0;
    intmax_t gcd = ex_gcd_r(a, b, x0, y0);
    if (d % gcd != 0) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }

    intmax_t m0 = d / gcd;
    x0 *= m0;
    y0 *= m0;

    cout << x0 << " " << y0 << endl;
    assert(a * x0 + b * y0 == d);

    for (int k = 1; k < 10; k++) {
        intmax_t x = x0 + k * b / gcd;
        intmax_t y = y0 - k * a / gcd;
        cout << x << " " << y << endl;
        assert(a * x + b * y == d);
    }
}

