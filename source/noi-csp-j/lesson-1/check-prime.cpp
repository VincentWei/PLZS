/*
 * The example 1 of NOI CSP-J Lesson 1:
 * <https://courses.fmsoft.cn/plzs/noijunior-basic-algorithms.html>
 *
 * Author: Vincent Wei
 *  - <https://github.com/VincentWei>
 *  - <https://gitee.com/vincentwei7>
 *
 * Copyright (C) 2024 FMSoft <https://www.fmsoft.cn>.
 * License: GPLv3
 */
#include <iostream>     // for cout and cin
#include <string>       // for string
#include <vector>       // for vector
#include <algorithm>    // for binary_search()
#include <cmath>        // for sqrtl() and llroundl()
#include <cstdint>      // for uint64_t and UINT32_MAX
#include <cassert>      // for assert()

using namespace std;
using uint64_v = vector<uint64_t>;

bool check_prime_plain(uint64_t n)
{
    if (n < 2)
        return false;

    for (uint64_t i = 2; i < n; i++) {
        if (n % i == 0)
            return false;
    }

    return true;
}

bool check_prime_opt(uint64_t n)
{
    if (n < 2)
        return false;
    else if (n == 2)
        return true;

    uint64_t max = llroundl(sqrtl(n));

    for (uint64_t i = 2; i <= max; i++) {
        if (n % i == 0)
            return false;
    }

    return true;
}

bool is_next_prime(uint64_t n, const uint64_v& primes_sieved)
{
    uint64_t mid = llroundl(sqrtl(n));

    for (uint64_t prime: primes_sieved) {
        if (prime > mid) {
            break;
        }

        if (n % prime == 0) {
            return false;
        }
    }

    return true;
}

uint64_v sieve_primes(uint64_t max)
{
    uint64_v primes_sieved;

    if (max < 2)
        goto done;

    primes_sieved.push_back(2);
    for (uint64_t n = 3; n <= max; n += 2) {
        if (is_next_prime(n, primes_sieved)) {
            primes_sieved.push_back(n);
        }
    }

done:
    return primes_sieved;
}

bool check_prime_sieved(const uint64_v& primes_sieved, uint64_t n)
{
    return binary_search(primes_sieved.begin(), primes_sieved.end(), n);
}

int main()
{
    struct test_case {
        uint64_t n;
        bool     expected;
    } cases[] = {
        { 0,    false },
        { 1,    false },
        { 2,    true },
        { 3,    true },
        { 4,    false },
        { 5,    true },
        { 100,  false },
        { 1973, true },
        { 1979, true },
        { 2355, false },
    };

    for (size_t i = 0; i < sizeof(cases)/sizeof(cases[0]); i++) {
        bool result = check_prime_plain(cases[i].n);
        assert(result == cases[i].expected);
    }

    for (size_t i = 0; i < sizeof(cases)/sizeof(cases[0]); i++) {
        bool result = check_prime_opt(cases[i].n);
        assert(result == cases[i].expected);
    }

    uint64_v primes_sieved = sieve_primes(UINT16_MAX);

    for (size_t i = 0; i < sizeof(cases)/sizeof(cases[0]); i++) {
        bool result = check_prime_sieved(primes_sieved, cases[i].n);
        assert(result == cases[i].expected);
    }
}

