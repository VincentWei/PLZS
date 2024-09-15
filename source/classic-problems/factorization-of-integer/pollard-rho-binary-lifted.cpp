/*
 * This program factors an integer number by using Pollard Rho algorithm
 *  with binary lifting.
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
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdint>
#include <ctime>
#include <cassert>

using namespace std;

using uint128_t = unsigned __int128;

uint64_t generator(uint64_t x, uint64_t c, uint64_t n)
{
    uint128_t next;

    next = x * x;
    next = (next % n + c % n) % n;
    return static_cast<uint64_t>(next);
}

uint64_t randomll(uint64_t n)
{
    uint64_t low = random() % (static_cast<uint32_t>(n) - 1) + 1;
    uint64_t high = random() % (static_cast<uint32_t>(n >> 32) - 1) + 1;
    return (low | (high << 32));
}

template <typename T>
T gcd(T a, T b)
{
    while (b != 0) {
        T tmp = a;
        a = b;
        b = tmp % b;
    }

    return a;
}

template <typename T>
T abs_diff(T a, T b)
{
    if (a >= b)
        return a - b;
    return b - a;
}

#define MAX_STEPS       ((1U << 8) - 1)

uint64_t pollard_rho(uint64_t n)
{
    uint64_t c = randomll(n);
    uint64_t x_i = generator(randomll(n), c, n);
    unsigned goal;

    // 使用倍增法降低 GCD 的求解次数。
    for (goal = 1;; goal <<= 1) {
        uint64_t d;

        uint64_t x_0 = x_i;
        uint128_t prod = 1;

        // 这层循环的 goal 值每轮倍增。
        for (unsigned step = 1; step <= goal; ++step) {
            x_i = generator(x_i, c, n);

            // prod = \prod |x_0 - x_i| \bmod n
            prod = prod * abs_diff(x_i, x_0) % n;
            if (prod == 0)
                return n;

            // 每隔 MAX_STEPS 次求解一次 GCD。
            if (step % MAX_STEPS == 0) {
                d = gcd(static_cast<uint64_t>(prod), n);
                if (d > 1)
                    return d;
            }
        }

        d = gcd(static_cast<uint64_t>(prod), n);
        if (d > 1)
            return d;
    }

    return n;
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

using uint64_v = vector<uint64_t>;

uint64_v factor_integer(uint64_t n, double& duration)
{
    struct timespec t1;
    clock_gettime(CLOCK_THREAD_CPUTIME_ID, &t1);

    uint64_v factors;

    while (n > 1) {
        uint64_t factor;

        unsigned tries = 0;
        while (true) {
            factor = pollard_rho(n);
            if (factor < n) {
                factors.push_back(factor);
                clog << "Got a nontrivial factor: " << factor << endl;
                break;
            }

            if (++tries == 100) {
                clog << "May be a prime number: " << n << endl;
                break;
            }
        }

        n /= factor;
    }

    duration = calc_elapsed_seconds(&t1, NULL);
    return factors;
}

int main()
{
    srandom(time(NULL));

    double duration;
    vector<uint64_t> factors;
    factors = factor_integer(UINT64_MAX, duration);
    assert(factors.size() > 0);

    cout << "You can try 2305843009213693907" << endl;

    uint64_t n;
    cin >> n;
    factors = factor_integer(n, duration);

    if (factors.size() > 0) {
        cout << factors[0];
        for (size_t i = 1; i < factors.size(); i++) {
            cout << ", " << factors[i];
        }
        cout << "." << endl;
    }

    cout << "Totally " << factors.size() << " nontrivial factors found (" << duration
        << " seconds consumed)." << endl;
}

