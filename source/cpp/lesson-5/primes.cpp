/*
 * The answer key for Problem 4 of CPP Lesson 5:
 * <https://courses.fmsoft.cn/plzs/cpp-class-template-and-stl.html#/8/3>
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
#include <cmath>        // for sqrtl() and llroundl()
#include <cstdint>      // for uint64_t and UINT64_MAX
#include <cassert>      // for assert()

using namespace std;
using uint64_v = vector<uint64_t>;

bool check_prime(uint64_t number, const uint64_v& primes)
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

uint64_v prime_sieve(uint64_t n)
{
    uint64_v result;

    if (n < 2)
        goto done;

    result.push_back(2);
    for (uint64_t number = 3; number <= n; number += 2) {
        if (check_prime(number, result)) {
            result.push_back(number);
        }
    }

done:
    return result;
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

    uint64_v primes = prime_sieve(max);
    clog << "Got " << primes.size() << " primes." << endl;

    for (uint64_t n: integers) {
        cout << (binary_search(primes.begin(), primes.end(), n) ? 'T' : 'F') << ' ';
    }

    cout << endl;
}

