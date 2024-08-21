/*
 * The optimized Euler sieve for prime numbers.
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
#include <bitset>       // for bitset
#include <algorithm>    // for binary_search()
#include <cmath>        // for sqrt() and lround()
#include <cstdint>      // for uint32_t, uint64_t and UINT64_MAX
#include <cassert>      // for assert()

using namespace std;
using natural_t = uint32_t;
using wider_t = uint64_t;
using natural_v = vector<natural_t>;

bool is_next_prime(natural_t n, const natural_v& primes)
{
    natural_t mid = lround(sqrt(n));

    for (natural_t prime: primes) {
        if (prime > mid) {
            break;
        }

        if (n % prime == 0) {
            return false;
        }
    }

    return true;
}

natural_v euler_sieve(natural_t max)
{
    natural_v primes;

    if (max < 2)
        goto done;
#if 1
    static bitset<UINT32_MAX + 1ULL> not_primalities;

    for (wider_t n = 2; n <= max; n++) {
        if (!not_primalities[n]) {
            primes.push_back(n);
        }

        for (natural_t prime: primes) {
            if (n * prime > max)
                break;
            not_primalities[n * prime] = true;
            if (n % prime == 0) {
                break;
            }
        }
    }
#else
    primes.push_back(2);
    for (wider_t n = 3; n <= max; n += 2) {
        if (is_next_prime(n, primes)) {
            primes.push_back(n);
            cout << n << endl;
        }
    }
#endif

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

