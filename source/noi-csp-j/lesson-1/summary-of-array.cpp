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
T sum(const T* arr, size_t nr)
{
    T sum = 0;
    for (size_t i = 0; i < nr; i++) {
        sum += arr[i];
    }

    return sum;
}

int main()
{
    double a[5];
    cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];

    cout << sum(a, 5) << endl;
}
