/*
 * The plain version for narcissistic numbers:
 *
 * Author: Vincent Wei
 *  - <https://github.com/VincentWei>
 *  - <https://gitee.com/vincentwei7>
 *
 * Copyright (C) 2024 FMSoft <https://www.fmsoft.cn>.
 * License: GPLv3
 */
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

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

        uintmax_t power = digit;
        size_t j = 1;
        while (j < nr_digits) {
            power *= digit;
            j++;
        }

        sum += power;
    }

    if (sum == n) {
        return true;
    }

    return false;
}

int main()
{
    assert(!is_narcissistic(150));
    assert(is_narcissistic(153));

    uintmax_t n = 150;
    while (true) {
        if (is_narcissistic(n)) {
            cout << n << endl;
        }

        n++;
    }
}

