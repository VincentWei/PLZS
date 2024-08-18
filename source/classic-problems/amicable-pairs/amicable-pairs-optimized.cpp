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
using uint64_v = vector<uint64_t>;

uint64_t summary_of_true_factors(uint64_t n)
{
    uint64_t summary = 1;
    uint64_t max = llroundl(sqrtl(n));
    for (uint64_t i = 2; i <= max; i++) {
        imaxdiv_t div = imaxdiv(n, i);

        if (div.rem == 0) {
            summary += i;
            if (i != max)
                summary += div.quot;
        }
    }

    return summary;
}

int main()
{
    assert(summary_of_true_factors(220) == 284);
    assert(summary_of_true_factors(284) == 220);

    uint64_v found;
    uint64_t n = 200;
    while (true) {
        if (!binary_search(found.begin(), found.end(), n)) {
            uint64_t other = summary_of_true_factors(n);
            if (other > n && summary_of_true_factors(other) == n) {
                cout << n << " " << other << endl;
                found.push_back(n);
                found.push_back(other);
                sort(found.begin(), found.end());
            }
        }

        n++;
    }
}

