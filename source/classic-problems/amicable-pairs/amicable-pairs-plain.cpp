/*
 * The plain version for amicable paris:
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
#include <cassert>      // for assert()

using namespace std;
using uint64_v = vector<uint64_t>;

bool check_prime(uint64_t number)
{
    if (number < 2)
        return false;
    else if (number == 2)
        return true;

    uint64_t max = llroundl(sqrtl(number));

    for (uint64_t n = 2; n <= max; n++) {
        if (number % n == 0)
            return false;
    }

    return true;
}

uint64_t summary_of_true_factors(uint64_t n)
{
    uint64_v factors;

    assert(n > 2);

    for (uint64_t i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            factors.push_back(i);
        }
    }

    uint64_t summary = 0;
    for (uint64_t i: factors) {
        summary += i;
    }

    return summary;
}

int main()
{
    assert(check_prime(1) == false);
    assert(check_prime(2) == true);
    assert(check_prime(3) == true);
    assert(check_prime(4) == false);
    assert(check_prime(1973) == true);

    assert(summary_of_true_factors(220) == 284);
    assert(summary_of_true_factors(284) == 220);

    uint64_v found;
    uint64_t n = 200;
    while (true) {
        if (!check_prime(n)) {
            if (!binary_search(found.begin(), found.end(), n)) {
                uint64_t other = summary_of_true_factors(n);
                if (other != n && summary_of_true_factors(other) == n) {
                    cout << n << " " << other << endl;
                    found.push_back(n);
                    found.push_back(other);
                    sort(found.begin(), found.end());
                }
            }
        }

        n++;
    }
}

