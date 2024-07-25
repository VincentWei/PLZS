/*
 * The answer key for Problem 4 of CPP Lesson 4:
 * <https://courses.fmsoft.cn/plzs/cpp-data-types-more.html#/9/3>
 *
 * Author: Vincent Wei
 *  - <https://github.com/VincentWei>
 *  - <https://gitee.com/vincentwei7>
 *
 * Copyright (C) 2024 FMSoft <https://www.fmsoft.cn>.
 * License: GPLv3
 */
#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <cassert>

using namespace std;

unsigned print_prime_factors(unsigned natural)
{
    unsigned nr_factors = 0;

    for (unsigned int u = 2; u <= natural; u++) {
        if (natural % u == 0) {
            do {
                natural = natural / u;

            } while (natural % u == 0);

            cout << u << " ";
            nr_factors++;
        }
    }

    return nr_factors;
}

int main()
{
    unsigned natural;
    cin >> natural;

    if (natural < 2)
        return 1;

    print_prime_factors(natural);
    cout << endl;
}

