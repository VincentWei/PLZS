/*
 * The binary lifting version to calculate the nth Fibonacci number.
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
#include <utility>      // for pair

using namespace std;

using fib_pair = pair<intmax_t, intmax_t>;

fib_pair nth_fibnacci_pair(unsigned n)
{
    if (n == 0)
        return {0, 1};

    auto p = nth_fibnacci_pair(n >> 1);
    intmax_t c = p.first * (2 * p.second - p.first);
    intmax_t d = p.first * p.first + p.second * p.second;
    if (n & 1)
        return {d, c + d};
    else
        return {c, d};
}

intmax_t nth_fibonacci_number(unsigned n)
{
    fib_pair pair = nth_fibnacci_pair(n);

    if (pair.second < pair.first)
        return -1;

    return pair.first;
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

