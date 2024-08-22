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

int gcd_l(int a, int b)
{
    while (b != 0) {
        int tmp = a;
        a = b;
        b = tmp % b;
    }

    return a;
}

int ex_gcd(int a, int b, int& x, int& y)
{
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    int gcd = ex_gcd(b, a % b, x, y);
    int temp = x;
    x = y;
    y = temp - a / b * y;
    return gcd;
}

int main()
{
    int a, b, d;
    cin >> a >> b >> d;

    if (a == 0 || b == 0 || d == 0) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }

    int x0, y0;
    int gcd = ex_gcd(a, b, x0, y0);
    if (d % gcd != 0) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }

    int m0 = d / gcd;
    x0 *= m0;
    y0 *= m0;

    cout << x0 << " " << y0 << endl;
    assert(a * x0 + b * y0 == d);

    for (int k = 1; k < 10; k++) {
        int x = x0 + k * b / gcd;
        int y = y0 - k * a / gcd;
        cout << x << " " << y << endl;
        assert(a * x + b * y == d);
    }
}

