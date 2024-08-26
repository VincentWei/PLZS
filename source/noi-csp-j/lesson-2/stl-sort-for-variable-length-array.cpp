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
#include <algorithm>    // for sort()
#include <functional>   // for greater()
#include <cassert>      // for assert()

using namespace std;

bool my_compare_desc(double a, double b)
{
    return (a > b);
}

int main()
{
    size_t n;
    cin >> n;

    double a[n];
    for (size_t i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    cout << "Ascending order:" << endl;
    for (size_t i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    sort(a, a + n, greater<double>());

    cout << "Descending order:" << endl;
    for (size_t i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

