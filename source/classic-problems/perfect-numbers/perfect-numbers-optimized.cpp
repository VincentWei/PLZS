/*
 * The optimized version for perfect numbers:
 *
 * Author: Vincent Wei
 *  - <https://github.com/VincentWei>
 *  - <https://gitee.com/vincentwei7>
 *
 * Copyright (C) 2024 FMSoft <https://www.fmsoft.cn>.
 * License: GPLv3
 */
#include <iostream>     // for cout and cin
#include <vector>       // for vector
#include <cinttypes>    // for imaxdiv()
#include <cassert>      // for assert()

using namespace std;

intmax_t summary_of_true_factors(intmax_t n)
{
    intmax_t summary = 1;
    for (intmax_t i = 2; i * i <= n; i++) {
        imaxdiv_t div = imaxdiv(n, i);

        if (div.rem == 0) {
            summary += i;
            if (i != n)
                summary += div.quot;
        }
    }

    return summary;
}

int main()
{
    assert(summary_of_true_factors(220) == 284);
    assert(summary_of_true_factors(284) == 220);

    intmax_t n = 2;
    while (n != INT64_MAX) {
        if (summary_of_true_factors(n) == n) {
            cout << n << endl;
        }

        n++;
    }
}

