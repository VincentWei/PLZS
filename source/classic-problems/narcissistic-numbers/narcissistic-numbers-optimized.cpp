/*
 * The plain version for narcissistic numbers.
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
#include <cassert>

using namespace std;

uintmax_t binary_power(uintmax_t base, uintmax_t exp)
{
    if (base == 0)
        return 0;
    else if (base == 1)
        return 1;

    uintmax_t res = 1ULL;
    while (exp > 0) {
        if (exp & 1)
            res = res * base;
        base = base * base;
        exp >>= 1;
    }

    return res;
}

bool is_narcissistic(uintmax_t n)
{
    vector<unsigned> digits;

    uintmax_t t = n;
    do {
        unsigned d = t % 10;
        digits.push_back(d);
        t /= 10;
    } while (t > 0);

    size_t nr_digits = digits.size();
    uintmax_t sum = 0;
    for (unsigned digit: digits) {
        uintmax_t power = binary_power(digit, nr_digits);
        sum += power;
    }

    if (sum == n) {
        return true;
    }

    return false;
}

int main()
{
    assert(binary_power(1, 2) == 1);
    assert(binary_power(2, 3) == 8);
    assert(is_narcissistic(153));

    uintmax_t n = 150;
    while (true) {
        if (is_narcissistic(n)) {
            cout << n << endl;
        }

        n++;
    }
}

