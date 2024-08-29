/*
 * The Eratosthenes sieve for prime numbers.
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
#include <iostream>     // for cout and cin
#include <string>       // for string
#include <vector>       // for vector
#include <algorithm>    // for binary_search()
#include <cstdint>      // for uint16_t and UINT16_MAX
#include <cstring>      // for memset()
#include <cassert>      // for assert()

using namespace std;
using uint16_v = vector<uint16_t>;

void eratosthenes_sieve(uint16_v& primes)
{
    // 保存所有 UINT16 范围内自然数的素性。
    static bool primalities[UINT16_MAX + 1];

    // 假定所有数值都是素数。
    memset(primalities, 1, sizeof(primalities));

    // 从 2 筛起。
    for (uint32_t i = 2; i <= UINT16_MAX; i++) {
        if (primalities[i]) {
            primes.push_back(i);

            // 若 i 的平方超过 UINT16_MAX 则无需继续检查素性。
            if (i * i > UINT16_MAX)
                continue;

            // i 的倍数均不是素数。
            for (uint32_t j = i * i; j <= UINT16_MAX; j += i)
                primalities[j] = false;
        }
    }
}

bool check_prime(const uint16_v& primes, uint16_t n)
{
    return binary_search(primes.begin(), primes.end(), n);
}

#include <ctime>

/* 计算间隔时间，以秒为单位。 */
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
    struct timespec t1;
    clock_gettime(CLOCK_THREAD_CPUTIME_ID, &t1);

    uint16_v primes;
    eratosthenes_sieve(primes);

    assert(check_prime(primes, 0) == false);
    assert(check_prime(primes, 1) == false);
    assert(check_prime(primes, 2) == true);
    assert(check_prime(primes, 3) == true);
    assert(check_prime(primes, 5) == true);
    assert(check_prime(primes, 1973) == true);
    assert(check_prime(primes, 1974) == false);

    unsigned nr = 10;
    auto it = primes.begin();
    while (nr--) {
        clog << *it << endl;
        it = next(it);
    }

    clog << "..." << endl;

    nr = 10;
    auto rit = primes.rbegin();
    while (nr--) {
        clog << *rit << endl;
        rit = next(rit);
    }

    double duration = calc_elapsed_seconds(&t1, NULL);
    cout << "Totally " << primes.size() << " primes (" << duration
        << " seconds consumed)." << endl;
}

