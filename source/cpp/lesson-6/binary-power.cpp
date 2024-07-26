/*
 * The answer key for Problem 4 of CPP Lesson 6:
 *  <https://courses.fmsoft.cn/plzs/cpp-arbitrary-precision-arithmetic.html#/8/3>
 *
 * Author: Vincent Wei
 *  - <https://github.com/VincentWei>
 *  - <https://gitee.com/vincentwei7>
 *
 * Copyright (C) 2024 FMSoft <https://www.fmsoft.cn>.
 * License: GPLv3
 */

#define NTEST
#include "bigint.cpp"

/*
 * bigint_power:
 *
 * @base: the base.
 * @exp: the exponent.
 *
 * returns: The power of @base raised to @exp.
 */
bigint bigint_power(bigint &base, unsigned exp)
{
    bigint r(1);

    while (exp--) {
        r *= base;
    }

    return r;
}

/*
 * bigint_bin_power:
 *
 * @base: the base.
 * @exp: the exponent.
 *
 * returns: The power of @base raised to @exp.
 */
bigint bigint_bin_power(const bigint &_base, unsigned exp)
{
    bigint base(_base);
    bigint res(1);

    while (exp > 0) {
        if (exp & 1)
            res = res * base;
        base = base * base;
        exp >>= 1;
    }

    return res;
}

int main()
{
    string base_s;
    unsigned exponent;
    cin >> base_s >> exponent;

    bigint base(base_s);
    bigint ans_pln, ans_bin;
    ans_pln = bigint_power(base, exponent);
    ans_bin = bigint_bin_power(base, exponent);

    assert(ans_pln == ans_bin);
    cout << ans_bin << endl;
    return 0;
}

