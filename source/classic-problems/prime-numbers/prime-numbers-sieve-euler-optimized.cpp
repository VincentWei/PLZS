/*
 * The optimized Euler sieve for prime numbers.
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
#include <bitset>       // for bitset
#include <algorithm>    // for binary_search()
#include <cstdint>      // for uint32_t, uint64_t and UINT64_MAX
#include <cassert>      // for assert()

using namespace std;
using natural_t = uint32_t;
using wider_t = uint64_t;
using natural_v = vector<natural_t>;

natural_v euler_sieve(natural_t max)
{
    natural_v primes;

    if (max < 2)
        goto done;

    static bitset<UINT32_MAX + 1ULL> not_primalities;

    for (wider_t n = 2; n <= max; n++) {
        // 如果 n 尚未被标记为合数，则一定是质数。
        if (!not_primalities[n]) {
            primes.push_back(n);
        }

        // 标记任意已知质数 p * n 为合数。
        for (natural_t prime: primes) {
            // 测试 p * n 是否超过最大值 max
            if (n * prime > max)
                break;

            // p * n 为合数。
            not_primalities[n * prime] = true;

            // 测试 n 是否可以被任意已知质数整除，
            // 若真，则表明 p * n 可能被多次标记，
            // 为确保只标记一次，故而在此处 break，从而将此机会留给更大的 n。
            if (n % prime == 0) {
                break;
            }
        }
    }

    /* 流程说明：

       n = 2:
       primes: [2]，not primes: 4

       n = 3:
       primes: [2, 3], not primes: 4, +6, +9

       n = 4:
       primes: [2, 3], not primes: 4, 6, +8, 9
                                (break on p = 2, skip 12)

       n = 5:
       primes: [2, 3, 5], not primes: 4, 6, 8, 9, +10, +15, +25

       n = 6:
       primes: [2, 3, 5], not primes: 4, 6, 8, 9, 10, +12, 15, 25
                                (break on p = 2, skip 18, 30)
    */

done:
    return primes;
}

bool check_prime(const natural_v& primes, natural_t n)
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

    natural_v primes = euler_sieve(UINT32_MAX);

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
    cout << "Totally " << primes.size() << " primes ("
        << duration << " seconds consumed)." << endl;
}

