/*
 * The Binet's formula version to calculate the nth Fibonacci number.
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
#include <iostream>
#include <cmath>        // for sqrtl(), powl(), and llroundl()

using namespace std;

intmax_t nth_fibonacci_number(unsigned n)
{
    static long double sqrt_5;
    if (sqrt_5 == 0)
        sqrt_5 = sqrtl(5.0L);

    long double fib = powl((1.0L + sqrt_5)/2.0L, n) / sqrt_5;
    if (fib > INTMAX_MAX)
        return -1;
    return llroundl(fib);
}

int main()
{
    unsigned n;
    cin >> n;

    intmax_t fib = nth_fibonacci_number(n);
    if (fib >= 0)
        cout << fib << endl;
    else
        cout << "OVERFLOWED" << endl;
}

