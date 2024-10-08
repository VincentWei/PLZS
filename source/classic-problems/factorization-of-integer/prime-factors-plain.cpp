/*
 * The plain version to factor an integer number.
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
using factor_v = vector<uintmax_t>;

bool check_prime(uintmax_t n)
{
    if (n < 2)
        return false;

    uintmax_t max = llroundl(sqrtl(n));
    for (uintmax_t i = 2; i <= max; i++) {
        if (n % i == 0)
            return false;
    }

    return true;
}

factor_v prime_factors(uintmax_t n)
{
    factor_v factors;

    uintmax_t max = llroundl(sqrtl(n));
    for (uintmax_t i = 2; i <= max; i++) {
        if (n % i == 0 && check_prime(i)) {
            factors.push_back(i);
        }
    }

    if (factors.empty())
        factors.push_back(n);

    return factors;
}

int main()
{
    uintmax_t n;
    cin >> n;

    if (n < 2)
        return 1;

    auto factors = prime_factors(n);

    cout << factors[0];
    for (size_t i = 1; i < factors.size(); i++) {
        cout << ", " << factors[i];
    }
    cout << "." << endl;
}

