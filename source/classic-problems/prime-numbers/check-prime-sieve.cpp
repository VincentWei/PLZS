/*
 * The sieve version for checking prime.
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
#include <algorithm>    // for binary_search()
#include <cmath>        // for sqrtl() and llroundl()
#include <cstdint>      // for uint64_t and UINT64_MAX
#include <cassert>      // for assert()

using namespace std;
using uint64_v = vector<uint64_t>;

bool is_next_prime(uint64_t number, const uint64_v& primes)
{
    uint64_t mid = llroundl(sqrtl(number));

    for (uint64_t prime: primes) {
        if (prime > mid) {
            break;
        }

        if (number % prime == 0) {
            return false;
        }
    }

    return true;
}

uint64_v sieve_primes(uint64_t max)
{
    uint64_v result;

    if (max < 2)
        goto done;

    result.push_back(2);
    for (uint64_t n = 3; n <= max; n += 2) {
        if (is_next_prime(n, result)) {
            result.push_back(n);
        }
    }

done:
    return result;
}

bool check_prime(const uint64_v& primes, uint64_t n)
{
    return binary_search(primes.begin(), primes.end(), n);
}

int main()
{
    string buf;
    getline(cin, buf, '\n');

    uint64_v integers;
    while (!buf.empty()) {
        size_t sz;
        unsigned long long ull = stoull(buf, &sz, 0);
        buf = buf.substr(sz);
        integers.push_back(ull);
    }

    uint64_t max = 0;
    for (uint64_t n: integers) {
        if (n > max)
            max = n;
    }

    uint64_v primes = sieve_primes(max);
    clog << "Got " << primes.size() << " primes which are less than " << max << "." << endl;

    for (uint64_t n: integers) {
        cout << (check_prime(primes, n) ? "True" : "False") << ' ';
    }

    cout << endl;
}

