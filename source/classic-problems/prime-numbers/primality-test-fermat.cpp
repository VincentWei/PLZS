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

long long pi(uint64_t n)
{
    return llroundl(n / logl((long double)n));
}

uint64_t quick_power_modulo(uint64_t base, uint64_t exp, uint64_t modulus)
{
    uint64_t ret = 1;

    while (exp) {
        if (exp & 1)
            ret = (ret * base) % modulus;
        base = (base * base) % modulus;
        exp >>= 1;
    }

    return ret;
}

bool primality(uint64_t n)
{
    if (n <= UINT16_MAX)
        return check_prime(n);

    if ((n & 1) == 0)
        return false;

    for (int i = 0; i < NR_TESTS; i++) {
        uint64_t base = static_cast<uint64_t>(random()) % (n - 2) + 2;
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
    assert(check_prime(0) == false);
    assert(check_prime(1) == false);
    assert(check_prime(2) == true);
    assert(check_prime(3) == true);
    assert(check_prime(5) == true);
    assert(check_prime(6) == false);

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
    uint64_t n = UINT32_MAX + 1ULL;
    unsigned i = 0;
    while (true) {
        if (i == nr_primes)
            break;
        clog << "testing " << n << endl;
        if (primality(n)) {
            cout << n << endl;
            i++;
        }

        n++;
    }

    double duration = calc_elapsed_seconds(&t1, NULL);
    cout << "Totally " << (n - UINT32_MAX - 1) << " natural numbers tested (" << duration
        << " seconds consumed)." << endl;
}

