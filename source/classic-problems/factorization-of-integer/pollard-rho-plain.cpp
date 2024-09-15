/*
 * The plain version to factor an integer number by using
 *  Pollard Rho algorithm with Floyd judgment loop.
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

uint64_t pollard_rho(uint64_t n)
{
    uint64_t c = randomll(n);
    uint64_t t = generator(0, c, n);
    uint64_t r = generator(generator(0, c, n), c, n);

    while (t != r) {
        uint64_t d = gcd(abs_diff(t, r), n);
        if (d > 1)
            return d;
        t = generator(t, c, n);
        r = generator(generator(r, c, n), c, n);
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

int main()
{
    uint64_t org_n;
    cin >> org_n;

    struct timespec t1;
    clock_gettime(CLOCK_THREAD_CPUTIME_ID, &t1);

    srandom(time(NULL));

    vector<uint64_t> factors;

    uint64_t n = org_n;
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

    double duration = calc_elapsed_seconds(&t1, NULL);

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

