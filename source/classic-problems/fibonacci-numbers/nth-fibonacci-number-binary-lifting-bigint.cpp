/*
 * The binary lifting with bigint version to calculate the nth Fibonacci number.
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

#define NDEBUG
#define NTEST
#include "bigint.cpp"

#include <utility>      // for pair

using namespace std;

using fib_pair = pair<bigint, bigint>;

fib_pair nth_fibnacci_pair(unsigned n)
{
    if (n == 0)
        return {0, 1};

    auto p = nth_fibnacci_pair(n >> 1);
    bigint c = p.first * (p.second * 2 - p.first);
    bigint d = p.first * p.first + p.second * p.second;
    if (n & 1)
        return {d, c + d};
    else
        return {c, d};
}

bigint nth_fibonacci_number(unsigned n)
{
    fib_pair pair = nth_fibnacci_pair(n);
    return pair.first;
}

int main()
{
    unsigned n;
    cin >> n;

    bigint fib = nth_fibonacci_number(n);
    cout << fib << endl;
}

