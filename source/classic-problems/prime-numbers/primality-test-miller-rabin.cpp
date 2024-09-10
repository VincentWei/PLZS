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
    unsigned __int128 base_128 = base;

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
    // 处理小于 3 的特殊情形。
    if (n < 3)
        return n == 2;

    // 定义小质数数组，用于过滤简单合数。
    static const unsigned little_primes[] = {
        2, 3, 5, 7, 11, 13
    };

    // 使用小质数过滤掉简单合数。
    for (size_t i = 0; i < sizeof(little_primes)/sizeof(little_primes[0]); i++) {
        if (n % little_primes[i] == 0)
            return n == little_primes[i];
    }

    // n-1 一定是偶数；此处将 n-1 分解成 u * 2^t 形式的 u 和 t。
    uint64_t u = n - 1;
    int t = 0;
    while (u % 2 == 0) {
        u /= 2, ++t;
    }

    // 可选基数数组。
    static const uint64_t bases_32[] = {
        2, 7, 61,
    };

    static const uint64_t bases_64[] = {
        2, 325, 9375, 28178, 450775, 9780504, 1795265022ULL,
    };

    // 根据待测试的整数大小选择合适的基数数组。
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
        if (a >= n)
            a %= n;     // 当 a 大于 n 时，取模作为基数。
        if (a == 0)
            continue;   // 这表明基数 a 是 n 的倍数，选择下一个基数进行测试。

        uint64_t x = quick_power_modulo(a, u, n);
        if (x == 1 || x == n - 1)
            continue;   // 通过此轮测试；n 是概素数，继续使用下个基数测试。

        int j;
        for (j = 0; j < t; ++j) {
            // 计算模意义下的平方根；注意防止溢出。
            x = (((unsigned __int128)x) * x) % n;
            if (x == n - 1)
                break;  // 得到平凡平方根 n-1，通过二次探测。
        }

        // 此时表明找到了 *非* 平凡平方根，则 n 一定是合数。
        if (j == t)
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
    assert(primality_miller_rabin((1ULL << 31) - 1) == true);
    assert(primality_miller_rabin(UINT32_MAX) == false);
    assert(primality_miller_rabin(UINT64_MAX) == false);
    assert(primality_miller_rabin(18446744073709551557ULL) == true);

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

#define FROM_TOP  0
#if FROM_TOP
    uint64_t n = UINT64_MAX;
#else
    uint64_t n = UINT32_MAX + 1ULL;
#endif
    unsigned i = 0;
    while (true) {
        if (i == nr_primes)
            break;
        clog << "testing " << n << endl;
        if (primality_miller_rabin(n)) {
            cout << n << endl;
            i++;
        }

#if FROM_TOP
        n--;
#else
        n++;
#endif
    }

    double duration = calc_elapsed_seconds(&t1, NULL);
#if FROM_TOP
    cout << "Totally " << (UINT64_MAX - n) << " natural numbers tested (" << duration
#else
    cout << "Totally " << (n - UINT32_MAX - 1) << " natural numbers tested (" << duration
#endif
        << " seconds consumed)." << endl;
}

