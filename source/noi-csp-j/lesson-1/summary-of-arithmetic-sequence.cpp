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

template <class T>
T as_sum(const T& first, const T& diff, size_t n)
{
    assert(n > 0);

    T last = first + (n - 1) * diff;
    return (first + last) * n / 2;
}

int main()
{
    assert(as_sum(1, 1, 1) == 1);
    assert(as_sum(1.0, 2.0, 10.0) == 100.0);

    double first, diff;
    size_t n;
    cin >> first >> diff >> n;

    if (n == 0)
        return 1;

    cout << as_sum(first, diff, n) << endl;
}