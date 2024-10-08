/*
 * The plain version for checking prime.
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
#include <cassert>

using namespace std;

bool check_prime(uint64_t n)
{
    if (n < 2)
        return false;

    for (unsigned i = 2; i < n; i++) {
        if (n % i == 0)
            return false;
    }

    return true;
}

int main()
{
    assert(check_prime(0) == false);
    assert(check_prime(1) == false);
    assert(check_prime(2) == true);
    assert(check_prime(3) == true);
    assert(check_prime(5) == true);
    assert(check_prime(6) == false);

    uint64_t n;
    cin >> n;

    cout << (check_prime(n) ? "True" : "False") << endl;
}

