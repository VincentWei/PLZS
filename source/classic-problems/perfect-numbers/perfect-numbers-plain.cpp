/*
 * The plain version for perfect numbers.
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
#include <iostream>     // for cout and cin
#include <vector>       // for vector
#include <cassert>      // for assert()

using namespace std;

uintmax_t summary_of_true_factors(uintmax_t n)
{
    uintmax_t summary = 1;
    for (uintmax_t i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            summary += i;
        }
    }

    return summary;
}

int main()
{
    assert(summary_of_true_factors(220) == 284);
    assert(summary_of_true_factors(284) == 220);

    uintmax_t n = 2;
    while (n != UINT64_MAX) {
        if (summary_of_true_factors(n) == n) {
            cout << n << endl;
        }

        n++;
    }
}

