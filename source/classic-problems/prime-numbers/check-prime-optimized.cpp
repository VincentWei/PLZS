/*
 * The optimized version for checking prime:
 *
 * Author: Vincent Wei
 *  - <https://github.com/VincentWei>
 *  - <https://gitee.com/vincentwei7>
 *
 * Copyright (C) 2024 FMSoft <https://www.fmsoft.cn>.
 * License: GPLv3
 */
#include <iostream>     // for cin and cout
#include <cmath>        // for sqrtl() and llroundl()
#include <cassert>      // for assert()

using namespace std;

bool check_prime(uint64_t n)
{
    if (n < 2)
        return false;

    uint64_t max = llroundl(sqrtl(n));
    for (uint64_t i = 2; i <= max; i++) {
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

