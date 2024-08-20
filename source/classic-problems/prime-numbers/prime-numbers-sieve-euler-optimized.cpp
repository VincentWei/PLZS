/*
 * The Euler sieve prime numbers.
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
#include <cstdint>      // for uint16_t and UINT64_MAX
#include <cassert>      // for assert()

using namespace std;
using uint16_v = vector<uint16_t>;

bool is_next_prime(uint16_t number, const uint16_v& primes)
{
    uint16_t mid = lround(sqrt(number));

    for (uint16_t prime: primes) {
        if (prime > mid) {
            break;
        }

        if (number % prime == 0) {
            return false;
        }
    }

    return true;
}

uint16_v euler_sieve(uint16_t max)
{
    uint16_v primes;

    if (max < 2)
        goto done;
#if 1
    static bitset<UINT16_MAX + 1> not_primalities;

    for (uint32_t n = 2; n <= max; n++) {
        if (!not_primalities[n]) {
            primes.push_back(n);
        }

        for (uint16_t prime: primes) {
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
    for (uint32_t n = 3; n <= max; n += 2) {
        if (is_next_prime(n, primes)) {
            primes.push_back(n);
        }
    }
#endif

done:
    return primes;
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

    uint16_v primes = euler_sieve(UINT16_MAX);

    assert(check_prime(primes, 0) == false);
    assert(check_prime(primes, 1) == false);
    assert(check_prime(primes, 2) == true);
    assert(check_prime(primes, 3) == true);
    assert(check_prime(primes, 5) == true);
    assert(check_prime(primes, 1973) == true);
    assert(check_prime(primes, 1974) == false);

    for (auto prime: primes) {
        clog << prime << endl;
    }

    double duration = calc_elapsed_seconds(&t1, NULL);
    cout << "Totally " << primes.size() << " primes ("
        << duration << " seconds consumed)." << endl;
}

