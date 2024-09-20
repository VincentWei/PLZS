/*
 * This program factors an integer number by using Fermat's method
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
#include <vector>
#include <cmath>
#include <cstdlib>
#include <cstdint>
#include <cassert>

using namespace std;

using uint128_t = unsigned __int128;

uint64_t fermat_method(uint64_t n)
{
    uint128_t a = llroundl(ceill(sqrtl(static_cast<long double>(n))));
    uint128_t b2 = a * a - n;
    uint128_t b = llroundl(sqrtl(static_cast<long double>(b2)));

    while (b * b != b2) {
        a = a + 1;
        b2 = a*a - n;
        b = llroundl(sqrtl(static_cast<long double>(b2)));
    }

    return static_cast<uint64_t>(a - b);
}

int main()
{
    cout << "You can try 18446744073709551557\n";

    uint64_t n;
    cin >> n;

    if (n < 2)
        return 1;

    auto factor = fermat_method(n);
    if (factor != 1 || factor != n)
        cout << "Got a nontrival factor: " << factor << endl;
    else
        cout << "PRIME\n";
}

