/*
 * One example for NOI CSP-J Lesson 1:
 * <https://courses.fmsoft.cn/plzs/noijunior-basic-algorithms.html>
 *
 * Author: Vincent Wei
 *  - <https://github.com/VincentWei>
 *  - <https://gitee.com/vincentwei7>
 *
 * Copyright (C) 2024 FMSoft <https://www.fmsoft.cn>.
 * License: GPLv3
 */
#include <iostream>     // for cout and cin
#include <cinttypes>    // for intmax_t
#include <cassert>      // for assert()

using namespace std;

intmax_t binary_mul_r(intmax_t a, intmax_t b)
{
    assert(b >= 0);

    if (b == 0)
        return 0;

    intmax_t res = binary_mul_r(a, b >> 1);
    if (b % 2)
        return res + res + a;

    return res + res;
}

intmax_t binary_mul_i(intmax_t a, intmax_t b)
{
    int sign = 1;
    if (b < 0) {
        b = -b;
        sign = -1;
    }

    intmax_t res = 0;

    while (b > 0) {
        if (b & 1)
            res += a;
        a += a;
        b >>= 1;
    }

    return sign * res;
}

int main()
{
    struct test_case {
        intmax_t a, b;
    } cases[] = {
        { 0,    0 },
        { 0,    33 },
        { 22,   0 },
        { 1,    1 },
        { 2,    -2 },
        { 3,    3 },
        { 4,    -4 },
        { 5,    5 },
        { -5,   3 },
        { 55,   33 },
        { 100,  100 },
        { 1973, -1973 },
        { 1979, 1979 },
        { 2355, -2355 },
    };

    for (size_t i = 0; i < sizeof(cases)/sizeof(cases[0]); i++) {
        intmax_t result;
        if (cases[i].b >= 0) {
            result = binary_mul_r(cases[i].a, cases[i].b);
            assert(result == cases[i].a * cases[i].b);
        }

        result = binary_mul_i(cases[i].a, cases[i].b);
        assert(result == cases[i].a * cases[i].b);
    }
}

