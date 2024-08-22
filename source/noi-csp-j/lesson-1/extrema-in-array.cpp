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
const T& max(const T* arr, size_t nr)
{
    assert(nr > 0);

    const T* max = arr;
    for (size_t i = 1; i < nr; i++) {
        if (arr[i] > *max) {
            max = arr + i;
        }
    }

    return *max;
}

template <class T>
const T& min(const T* arr, size_t nr)
{
    assert(nr > 0);

    const T* min = arr;
    for (size_t i = 1; i < nr; i++) {
        if (*min > arr[i]) {
            min = arr + i;
        }
    }

    return *min;
}

int main()
{
    double a[5];
    cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];

    cout << max(a, 5) << endl;
    cout << min(a, 5) << endl;
}

