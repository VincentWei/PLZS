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

#define NR_TESTS        9

bool check_prime(uint32_t n)
{
    if (n < 2)
        return false;

    uint32_t max = llroundl(sqrtl(n));
    for (uint32_t i = 2; i <= max; i++) {
        if (n % i == 0)
            return false;
    }

    return true;
}

long long pi(uint64_t n)
{
    return llroundl(n / logl((long double)n));
}

uint32_t quick_power_modulo(uint32_t base, uint32_t exp, uint32_t modulus)
{
    uint64_t ret = 1;
    uint64_t base_64 = base;

    while (exp) {
        if (exp & 1)
            ret = (ret * base_64) % modulus;
        base_64 = (base_64 * base_64) % modulus;
        exp >>= 1;
    }

    return static_cast<uint32_t>(ret);
}

bool primality_fermat(uint32_t n)
{
    if (n < 3 || n % 2 == 0)
        return n == 2;
    if (n % 3 == 0)
        return n == 3;

    for (int i = 0; i < NR_TESTS; i++) {
        uint32_t base = static_cast<uint32_t>(random()) % (n - 2) + 2;
        if (quick_power_modulo(base, n - 1, n) != 1)
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
    assert(primality_fermat(0) == false);
    assert(primality_fermat(1) == false);
    assert(primality_fermat(2) == true);
    assert(primality_fermat(3) == true);
    assert(primality_fermat(1973) == true);
    assert(primality_fermat(1975) == false);
    assert(primality_fermat(1979) == true);
    assert(primality_fermat(4294967029) == true);
    assert(primality_fermat(UINT32_MAX) == false);

    long long nr_all_primes = pi(UINT64_MAX);
    cout << "According to the Prime Numbers Theorem, there are approximately "
        << nr_all_primes << " prime numbers less than " << UINT64_MAX << "."
        << endl;
    cout << "It will take " << nr_all_primes * sizeof(uint32_t) / 1024 / 1024 / 1024
        << " GB memory." << endl;

    unsigned nr_primes;
    cin >> nr_primes;

    struct timespec t1;
    clock_gettime(CLOCK_THREAD_CPUTIME_ID, &t1);

    srandom(time(NULL));
    uint32_t n = UINT32_MAX;
    unsigned i = 0;
    while (true) {
        if (i == nr_primes)
            break;
        clog << "testing " << n << endl;
        if (primality_fermat(n)) {
            cout << n << endl;
            i++;
        }

        n--;
    }

    double duration = calc_elapsed_seconds(&t1, NULL);
    cout << "Totally " << (UINT32_MAX - n) << " natural numbers tested (" << duration
        << " seconds consumed)." << endl;
}

