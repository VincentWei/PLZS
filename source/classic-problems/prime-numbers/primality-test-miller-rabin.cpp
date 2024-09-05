/*
 * This program tests the primalities of all natural numbers less than 2^64
 *  by using Fermat's Little Theorem.
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
#include <iostream>     // for cin and cout
#include <cmath>        // for sqrtl() and llroundl()
#include <cstdlib>      // for srandom() and random()
#include <ctime>        // for time()
#include <cassert>      // for assert()

using namespace std;

long long pi(uint64_t n)
{
    return llroundl(n / logl((long double)n));
}

uint64_t quick_power_modulo(uint64_t base, uint64_t exp, uint64_t modulus)
{
    uint64_t ret = 1;
    __int128 base_128 = base;

    while (exp) {
        if (exp & 1)
            ret = (ret * base_128) % modulus;
        base_128 = (base_128 * base_128) % modulus;
        exp >>= 1;
    }

    return ret;
}

bool primality_miller_rabin(uint64_t n)
{
    static const uint64_t bases_32[] = {
        2, 7, 61,
    };

    static const uint64_t bases_64[] = {
        2, 325, 9375, 28178, 450775, 9780504, 1795265022ULL,
    };


    if (n < 3 || (n & 1) == 0)
        return n == 2;

    if (n % 3 == 0)
        return n == 3;

    uint64_t u = n - 1, t = 0;
    while (u % 2 == 0) {
        u /= 2, ++t;
    }

    const uint64_t *bases;
    int nr_tests;
    if (n <= UINT32_MAX) {
        bases = bases_32;
        nr_tests = sizeof(bases_32)/sizeof(bases_32[0]);
    }
    else {
        bases = bases_64;
        nr_tests = sizeof(bases_64)/sizeof(bases_64[0]);
    }

    for (int i = 0; i < nr_tests; i++) {
        uint64_t a = bases[i];
        uint64_t v = quick_power_modulo(a, u, n);
        if (v == 1)
            continue;

        uint64_t s;
        for (s = 0; s < t; ++s) {
            // 若得到平凡平方根 n-1，则通过此轮测试
            if (v == n - 1)
                break;
            v = v * v % n;
        }

        // 如果找到了非平凡平方根，则会由于无法提前 break; 而运行到 s == t
        // 如果费马素性测试无法通过，则一直运行到 s == t 前 v 都不会等于 -1
        if (s == t)
            return false;
    }

    return true;
}

double calc_elapsed_seconds(const struct timespec *ts_from,
        const struct timespec *ts_to)
{
    struct timespec ts_curr;
    time_t ds;
    long dns;

    if (ts_to == NULL) {
        clock_gettime(CLOCK_THREAD_CPUTIME_ID, &ts_curr);
        ts_to = &ts_curr;
    }

    ds = ts_to->tv_sec - ts_from->tv_sec;
    dns = ts_to->tv_nsec - ts_from->tv_nsec;
    return ds + dns * 1.0E-9;
}

int main()
{
    assert(primality_miller_rabin(0) == false);
    assert(primality_miller_rabin(1) == false);
    assert(primality_miller_rabin(2) == true);
    assert(primality_miller_rabin(3) == true);
    assert(primality_miller_rabin(1973) == true);
    assert(primality_miller_rabin(1975) == false);
    assert(primality_miller_rabin(1979) == true);
    assert(primality_miller_rabin(4294967029UL) == true);
    assert(primality_miller_rabin(UINT32_MAX) == false);
    assert(primality_miller_rabin(UINT64_MAX) == false);

    long long nr_all_primes = pi(UINT64_MAX);
    cout << "According to the Prime Numbers Theorem, there are approximately "
        << nr_all_primes << " prime numbers less than " << UINT64_MAX << "."
        << endl;
    cout << "It will take " << nr_all_primes * sizeof(uint64_t) / 1024 / 1024 / 1024
        << " GB memory." << endl;

    unsigned nr_primes;
    cin >> nr_primes;

    struct timespec t1;
    clock_gettime(CLOCK_THREAD_CPUTIME_ID, &t1);

    srandom(time(NULL));
    uint64_t n = UINT64_MAX;
    unsigned i = 0;
    while (true) {
        if (i == nr_primes)
            break;
        clog << "testing " << n << endl;
        if (primality_miller_rabin(n)) {
            cout << n << endl;
            i++;
        }

        n--;
    }

    double duration = calc_elapsed_seconds(&t1, NULL);
    cout << "Totally " << (UINT64_MAX - n) << " natural numbers tested (" << duration
        << " seconds consumed)." << endl;
}

