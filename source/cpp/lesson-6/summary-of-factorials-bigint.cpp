/*
 * The answer key for Problem 5 of CPP Lesson 6:
 *  <https://courses.fmsoft.cn/plzs/cpp-arbitrary-precision-arithmetic.html#/8/4>
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

void factorial(bigint& result, unsigned n)
{
    if (n > 1) {
        factorial(result, n - 1);
        result *= n;
    }
    else
        result = 1;
}

void summary_of_factorials(bigint& result, unsigned max)
{
    result = 0;

    unsigned n = 0;
    while (n <= max) {
        bigint tmp;
        factorial(tmp, n);
        result += tmp;
        n++;
    }
}

int main()
{
    unsigned n;
    cin >> n;

    bigint ans;
    summary_of_factorials(ans, n);
    cout << ans << endl;
    return 0;
}

