/*
 * This program factors an integer number by using Pollard Brent algorithm.
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

#define NTEST
#include "bigint.cpp"

#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

bigint generator(const bigint& x, const bigint& c, const bigint& n)
{
    return (x * x + c) % n;
}

bigint random(const bigint& n)
{
    long rand = random();

    bigint ret;
    auto slices = n.slices();
    if (slices.size())
        ret = rand % slices.front();
    else
        ret = 0;

    bigint base = bigint::slice_base_k;
    for (size_t i = 1; i < slices.size(); i++) {
        if (slices[i] > 0)
            ret += base * (rand % slices[i]);
        base *= bigint::slice_base_k;
    }

    // clog << "random number " << ret << " for " << n << endl;
    return ret;
}

bigint gcd(const bigint &_a, const bigint &_b)
{
    bigint a(_a);
    bigint b(_b);

    while (b != 0) {
        bigint tmp = std::move(a);
        a = b;
        b = tmp % b;
    }

    // clog << __func__ << "(" << _a << ", " << _b << "): " << a << endl;
    return a;
}

bigint abs_diff(const bigint& a, const bigint& b)
{
    if (a >= b)
        return a - b;
    return b - a;
}

bigint quick_power_modulo(const bigint& base, const bigint& exp,
        const bigint& modulus)
{
    bigint ret = 1;
    bigint my_base = base;
    bigint my_exp = exp;

    while (my_exp != 0) {
        bigint::slice_t lsd = my_exp.least_significant_slice();
        if (lsd & 1)
            ret = (ret * my_base) % modulus;
        my_base = (my_base * my_base) % modulus;
        my_exp /= 2;
    }

    return ret;
}

bool primality_miller_rabin(bigint n)
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

    // n-1 一定是偶数；此处将 n-1 分解成 u * 2^t 形式。
    bigint u = n - 1;
    bigint t = 0;
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

    static const uint64_t bases_big[] = {
        2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37,
    };

    // 根据待测试的整数大小选择合适的基数数组。
    const uint64_t *bases;
    int nr_tests;
    if (n <= UINT32_MAX) {
        bases = bases_32;
        nr_tests = sizeof(bases_32)/sizeof(bases_32[0]);
    }
    else if (n <= UINT64_MAX) {
        bases = bases_64;
        nr_tests = sizeof(bases_64)/sizeof(bases_64[0]);
    }
    else {
        bases = bases_big;
        nr_tests = sizeof(bases_big)/sizeof(bases_big[0]);
    }

    for (int i = 0; i < nr_tests; i++) {
        bigint a = bases[i];
        if (a >= n)
            a %= n;     // 当 a 大于 n 时，取模作为基数。
        if (a == 0)
            continue;   // 这表明基数 a 是 n 的倍数，选择下一个基数进行测试。

        bigint x = quick_power_modulo(a, u, n);
        if (x == 1 || x == n - 1)
            continue;   // 通过此轮测试；n 是概素数，继续使用下个基数测试。

        bigint j;
        for (j = 0; j < t; ++j) {
            // 计算模意义下的平方根
            x = (x * x) % n;
            if (x == n - 1)
                break;  // 得到平凡平方根 n-1，通过二次探测。
        }

        // 此时表明找到了 *非* 平凡平方根，则 n 一定是合数。
        if (j == t)
            return false;
    }

    return true;
}

bigint pollard_rho_floyd_loop(const bigint& n)
{
    bigint c = random(n);
    bigint loop_t = 0;
    loop_t = generator(loop_t, c, n);
    bigint loop_r = generator(loop_t, c, n);

    clog << "Try with a random constant " << c
        << " and y " << loop_r << "...\n";

    uintmax_t nr_tests = 0;
    while (loop_t != loop_r) {
        bigint d = gcd(abs_diff(loop_t, loop_r), n);
        if (d > 1)
            return d;

        loop_t = generator(loop_t, c, n);
        loop_r = generator(generator(loop_r, c, n), c, n);
        nr_tests++;
    }

    clog << "Failed to factor the integer with the initial arguments; "
       << "the number of total tests: " << nr_tests << endl;
    return n;
}

#define MAX_STEPS       ((1U << 10) - 1)

bigint pollard_rho_brent(const bigint& n)
{
    bigint c = random(); c = (c % (n - 1)) + 1;
    bigint x = 0;
    x = generator(x, c, n);

    for (int i = 0; i < 73; i++)
        x = generator(x, c, n);

    clog << "Try with a random constant " << c
        << " and x " << x << "...\n";

    // 使用倍增法降低 GCD 的求解次数。
    for (unsigned goal = 1; goal != 0; goal <<= 1) {
        bigint d;

        bigint y = x;
        bigint prod = 1;

        // 这层循环的 goal 值每轮倍增。
        for (unsigned step = 1; step <= goal; ++step) {
            x = generator(x, c, n);

            // prod = (\prod \times |y - x|) \bmod n
            prod = prod * abs_diff(x, y) % n;
            if (prod == 0)
                return n;

            // 每隔 MAX_STEPS 次求解一次 GCD。
            if (step % MAX_STEPS == 0) {
                d = gcd(prod, n);
                // clog << "\tStep #" << step << ": gcd(" << prod << ", " << n << "): " << d << endl;
                if (d > 1)
                    return d;
            }
        }

        d = gcd(prod, n);
        clog << "\tGoal #" << goal << ": gcd(" << prod << ", " << n << "): "
            << d << endl;
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

using bigint_v = vector<bigint>;

#define MAX_ATTEMPTS        ((1U << 16) - 1)

bigint_v factor_integer(bigint n, double& duration)
{
    struct timespec t1;
    clock_gettime(CLOCK_THREAD_CPUTIME_ID, &t1);

    bigint_v factors;

    if (primality_miller_rabin(n)) {
        clog << n << " is a prime number." << endl;
        goto done;
    }

    clog << n << " is not a prime number." << endl;

    while (n > 1) {
        bigint factor;

        unsigned attempts = 0;
        while (true) {
            factor = pollard_rho_brent(n);
            if (factor < n) {
                factors.push_back(factor);
                clog << "Got a nontrivial factor: " << factor << endl;
                break;
            }

            if (++attempts == MAX_ATTEMPTS) {
                clog << "Reached the attempt limit; give up to factor "
                    << n << endl;
                break;
            }
        }

        n /= factor;
        // clog << "Now n is " << n << endl;

        if (primality_miller_rabin(n)) {
            factors.push_back(n);
            clog << n << " is a prime number." << endl;
            goto done;
        }
    }

done:
    duration = calc_elapsed_seconds(&t1, NULL);
    return factors;
}

int main()
{
    srandom(time(NULL));

    double duration;
    vector<bigint> factors;

    bigint n;
    n = bigint { "18446744073709551615" };
    cout << "Trying to factor " << n << ":" << endl;
    factors = factor_integer(n, duration);
    assert(factors.size() > 0);

    n = bigint { "65537" };
    cout << "Trying to factor " << n << ":" << endl;
    factors = factor_integer(n, duration);
    assert(factors.size() == 0);

    n = bigint { "2305843009213693907" };
    cout << "Trying to factor " << n << ":" << endl;
    factors = factor_integer(n, duration);
    assert(factors.size() == 0);

    n = bigint { "18446744073709551253" };
    cout << "Trying to factor " << n << ":" << endl;
    factors = factor_integer(n, duration);
    assert(factors.size() == 0);

    cout << "You can try the following numbers now: \n"
        << "\t4295098369 = 65537 * 65537\n"
        << "\t18446743979220271189 = 4294967291 * 4294967279\n"
        << "\t79228162422030615665923065623 = 4294967291 * 18446744073709551253\n"
        << "\t42535295865117306265797330267470315471 = 2305843009213693907 * 18446744073709551253\n";

    string str;
    cin >> str;
    factors = factor_integer(bigint {str}, duration);

    if (factors.size() > 0) {
        cout << "Totally " << factors.size() << " nontrivial factors found (" << duration
            << " seconds consumed):\n";

        cout << factors[0];
        for (size_t i = 1; i < factors.size(); i++) {
            cout << ", " << factors[i];
        }
        cout << "." << endl;
    }
    else {
        cout << "PRIME" << endl;
    }
}

