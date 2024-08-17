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

using namespace std;

template <class T>
void as_init(T* result, const T& first, const T& diff, size_t n)
{
    for (size_t i = 0; i < n; i++) {
        result[i] = first + diff * i;
    }
}

template <class T>
void gs_init(T* result, const T& first, const T& ratio, size_t n)
{
    for (size_t i = 0; i < n; i++) {
        result[i] =  first * pow(ratio, static_cast<T>(i));
    }
}

int main()
{
    double first, diff_ratio;
    size_t n;
    cin >> first >> diff_ratio >> n;

    if (n == 0)
        return 1;

    double as[n];
    as_init(as, first, diff_ratio, n);

    cout << as[0];
    for (size_t i = 1; i < n; i++) {
        cout << ", " << as[i];
    }
    cout << endl;

    double gs[n];
    gs_init(gs, first, diff_ratio, n);

    cout << gs[0];
    for (size_t i = 1; i < n; i++) {
        cout << ", " << gs[i];
    }
    cout << endl;
}

