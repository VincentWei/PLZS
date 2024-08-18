/*
 * The optimized version for amicable pairs:
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
#include <algorithm>    // for sort() and binary_search()
#include <cmath>        // for sqrtl() and llroundl()
#include <cinttypes>    // for imaxdiv()
#include <cassert>      // for assert()

using namespace std;
using intmax_v = vector<intmax_t>;

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

    intmax_v found;
    intmax_t n = 200;
    unsigned nr = 0;
    while (n < INTMAX_MAX) {
        if (!binary_search(found.begin(), found.end(), n)) {
            intmax_t other = summary_of_true_factors(n);
            if (other > n && summary_of_true_factors(other) == n) {
                cout << nr << ":\t" << n << " " << other << endl;
                found.push_back(n);
                found.push_back(other);
                sort(found.begin(), found.end());
                nr++;
            }
        }

        n++;
    }
}

