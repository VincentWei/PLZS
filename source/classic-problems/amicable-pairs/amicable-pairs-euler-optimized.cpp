/*
 * The optimized Euler version for amicable pairs:
 *
 * Author: Vincent Wei
 *  - <https://github.com/VincentWei>
 *  - <https://gitee.com/vincentwei7>
 *
 * Copyright (C) 2024 FMSoft <https://www.fmsoft.cn>.
 * License: GPLv3
 */
#include <iostream>     // for cout, cin and clog
#include <vector>       // for vector
#include <map>          // for map
#include <algorithm>    // for sort() and binary_search()
#include <cmath>        // for sqrtl() and llroundl()
#include <cinttypes>    // for imaxdiv()
#include <cassert>      // for assert()

using namespace std;

using ordered_pairs = map<uint64_t, uint64_t>;

/*
 * Calculates the sigma of a given natural number.
 * Teturns -1 if overflow occurred.
 */
int64_t sigma(int64_t n)
{
    if (n <= 1)
        return -1;

    int64_t max = llroundl(sqrtl(n));

    int64_t ans = 1;
    for (int64_t i = 2; i <= max; i++) {
        imaxdiv_t div = imaxdiv(n, i);

        if (div.rem == 0) {
            ans += i;
            if (i != div.quot)
                ans += div.quot;
        }
    }

    // test overflow
    ans += n;
    if (ans < n) {
        return -1;
    }

    return ans;
}

int64_t gcd(int64_t a, int64_t b)
{
    while (b != 0) {
        int64_t tmp = a;
        a = b;
        b = tmp % b;
    }

    return a;
}

bool check_prime(int64_t n)
{
    if (n < 2)
        return false;

    int64_t max = llroundl(sqrtl(n));
    for (int64_t i = 2; i <= max; i++) {
        if (n % i == 0)
            return false;
    }

    return true;
}

int64_t summary_of_true_factors(int64_t n)
{
    int64_t summary = 1;
    int64_t max = llroundl(sqrtl(n));

    for (int64_t i = 2; i <= max; i++) {
        imaxdiv_t div = imaxdiv(n, i);

        if (div.rem == 0) {
            summary += i;
            if (i != div.quot)
                summary += div.quot;
        }
    }

    return summary;
}

bool look_for_three_primes(int64_t b, int64_t c,
        int64_t& p, int64_t& q, int64_t& r)
{
    vector<int64_t> factors;

    int64_t square_b = b * b;

    factors.push_back(1);
    for (int64_t i = 2; i <= b; i++) {
        if (square_b % i == 0) {
            factors.push_back(i);
        }
    }

    size_t nr_found  = 0;
    for (int64_t factor: factors) {
        int64_t x, y;

        x = factor + b;
        if (x % c) {
            // clog << "Failed in " << __func__ << "(): cannot get an integral result for x." << endl;
            continue;
        }

        y = square_b/factor  + b;
        if (y % c) {
            // clog << "Failed in " << __func__ << "(): cannot get an integral result for y." << endl;
            continue;
        }

        x /= c;
        y /= c;

        int64_t _p, _q, _r;
        _p = x - 1;
        _q = y - 1;
        _r = x * y - 1;

        if (check_prime(_p) && check_prime(_q) && check_prime(_r)) {
            p = _p; q = _q; r = _r;
            nr_found++;
        }
    }

    if (nr_found > 1)
        clog << "Got " << nr_found << " solutions" << endl;
    return (nr_found > 0);
}

bool euler(int64_t a, int64_t& M, int64_t& N)
{
    int64_t sigma_a;
    int64_t b, c, gcd_b_c, p, q, r;

    assert(a > 1);

    if (a > INT32_MAX)
        goto failed;

    sigma_a = sigma(a);
    if (sigma_a < 0)
        goto failed;

    b = a;
    c = a * 2 - sigma_a;
    if (c == 0)
        goto failed;

    gcd_b_c = gcd(b, c);
    b /= gcd_b_c;
    c /= gcd_b_c;

    if (look_for_three_primes(b, c, p, q, r)) {
        M = a * p * q;
        N = a * r;
        return (sigma(M) == M + N);
    }

failed:
    return false;
}

unsigned daughter_pairs(ordered_pairs* pairs, int64_t M, int64_t N)
{
    int64_t a = gcd(M, N);
    int64_t p = N / a;

    if (!check_prime(p))
        return 0;

    assert(a % p != 0);

    int64_t u = M / a;
    int64_t right = (p + 1) * (p + u);
    if (right < (p + 1) || right < (p + u)) {
        // overflowed
        return 0;
    }

    unsigned nr = 0;
    int64_t max = llroundl(sqrtl(right));
    for (int64_t i = 2; i <= max; i++) {
        if (right % i == 0) {
            int64_t r = i + p;
            int64_t s = right / i + p;
            if (r != s and check_prime(r) and check_prime(s)) {
                if (gcd(a, r * s) != 1)
                    continue;

                int64_t q = r + s + u;

                M = a * u * q;
                N = a * r * s;
                if (sigma(M) == M + N) {
                    assert(sigma(N) == M + N);
                    if (pairs) {
                        cout << "\t(daughter):\t" << M << " " << N << endl;
                        (*pairs)[M] = N;
                    }
                    nr++;
                }
            }
        }
    }

    return nr;
}

int main()
{
    {
        assert(sigma(2) == 3);
        assert(sigma(4) == 7);
        assert(sigma(5) == 6);
        assert(check_prime(2) == true);
        assert(check_prime(5) == true);
        assert(check_prime(11) == true);
        assert(check_prime(71) == true);
        assert(check_prime(64) == false);

        assert(summary_of_true_factors(220) == 284);
        assert(summary_of_true_factors(284) == 220);

        int64_t p, q, r;
        bool ret;
        ret = look_for_three_primes(4, 1, p, q, r);
        // clog << ret << " " << p << " " << q << " " << r << endl;
        assert(ret == true && p == 5 && q == 11 && r == 71);

        int64_t M, N;
        ret = euler(4, M, N);
        // clog << ret << " " << M << " " << N << endl;
        assert(ret == true && M == 220 && N == 284);

        M = 3 * 3 * 5 * 5 * 5 * 13 * 11 * 59LL;
        N = 3 * 3 * 5 * 13 * 18719LL;
        assert(daughter_pairs(nullptr, M, N) == 2);
    }

    clog << "Please input two numbers of amicable pairs to find by using exhaustion method and Euler method: " << endl;
    unsigned max_one, max_two;
    cin >> max_one >> max_two;

    if (max_one == 0 || max_two == 0)
        return 1;

    ordered_pairs initials;
    ordered_pairs pairs;

    clog << "Seeking " << max_one << " amicable pairs by using exhaustion method..." << endl;
    int64_t n = 200;
    unsigned nr = 0;
    while (nr < max_one) {
        if (pairs.count(n) == 0) {
            intmax_t other = summary_of_true_factors(n);
            if (other > n && summary_of_true_factors(other) == n) {
                initials[n] = 0;
                pairs[n] = other;
                cout << nr << ":\t" << n << " " << other << endl;
                nr++;
            }
        }

        n++;
    }

    clog << "Seeking " << max_two << " amicable pairs by using Euler method..." << endl;
    int64_t a = 2;
    nr = 0;
    while (nr < max_two) {
        int64_t M, N;

        if (euler(a, M, N) && initials.count(M) == 0) {
            initials[M] = a;
            pairs[M] = N;
            cout << nr << ":\t" << M << " " << N << endl;
            nr++;
        }

        a++;
    }

    clog << "Seeking daughter amicable pairs by using Euler method..." << endl;
    nr = 1;
    for (auto& initial: initials) {
        auto a = initial.second;
        auto M = initial.first;
        auto N = pairs[M];

        cout << "No. " << nr << " (" << a << "):\t\t" << M << " " << N << endl;
        nr++;

        nr += daughter_pairs(&pairs, M, N);
    }

    for (auto& pair: pairs) {
        auto M = pair.first;
        auto N = pair.second;

        cout << M << " " << N << endl;
    }

    clog << "Totally " << pairs.size() << " amicable pairs found." << endl;
}

