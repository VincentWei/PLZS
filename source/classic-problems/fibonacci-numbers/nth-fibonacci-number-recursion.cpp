/*
 * The recursion version to calculate the nth Fibonacci number.
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

using namespace std;

intmax_t nth_fibonacci_number(unsigned n)
{
    if (n < 2)
        return n;

    intmax_t a = nth_fibonacci_number(n - 2);
    intmax_t b = nth_fibonacci_number(n - 1);
    intmax_t fib = a + b;
    if (b > fib)
        return -1;
    return fib;
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

