/*
 * One example for NOI CSP-J Lesson 2:
 * <https://courses.fmsoft.cn/plzs/noijunior-sort-algorithms.html>
 *
 * Author: Vincent Wei
 *  - <https://github.com/VincentWei>
 *  - <https://gitee.com/vincentwei7>
 *
 * Copyright (C) 2024 FMSoft <https://www.fmsoft.cn>.
 * License: GPLv3
 */
#include <iostream>     // for cin and cout
#include <cstdlib>      // for assert()
#include <cassert>      // for assert()

using namespace std;

int my_compare_asc(const void* a, const void* b)
{
    const double* pa = static_cast<const double *>(a);
    const double* pb = static_cast<const double *>(b);
    return (int)(*pa - *pb);
}

int my_compare_desc(const void* a, const void* b)
{
    const double* pa = static_cast<const double *>(a);
    const double* pb = static_cast<const double *>(b);
    return (int)(*pb - *pa);
}

int main()
{
    size_t n;
    cin >> n;

    if (n == 0)
        return 1;

    double a[n];
    for (size_t i = 0; i < n; i++) {
        cin >> a[i];
    }

    qsort(a, n, sizeof(double), my_compare_asc);

    cout << "Ascending order:" << endl;
    for (size_t i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    qsort(a, n, sizeof(double), my_compare_desc);

    cout << "Descending order:" << endl;
    for (size_t i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

