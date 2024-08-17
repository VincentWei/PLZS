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
#include <iostream>     // for cin and cout
#include <cassert>      // for assert()

using namespace std;

#include <cmath>

template <class T>
T gs_sum(const T& first, const T& ratio, size_t n)
{
    assert(n > 0 && ratio != 0);

    T denominator = static_cast<T>(1.0 - ratio);
    if (fpclassify(denominator) != FP_NORMAL) {
        return first * n;
    }

    return first * (1.0 - pow(ratio, static_cast<T>(n))) / denominator;
}

int main()
{
    assert(gs_sum(1, 1, 5) == 5);
    assert(gs_sum(1.0, 2.0, 2) == 3.0);

    double first, ratio;
    size_t n;
    cin >> first >> ratio >> n;

    if (ratio == 0 || n == 0)
        return 1;

    cout << gs_sum(first, ratio, n) << endl;
}
