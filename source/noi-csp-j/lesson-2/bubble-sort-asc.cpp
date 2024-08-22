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
#include <utility>      // for swap
#include <cassert>      // for assert()

using namespace std;

template <class T>
void bubble_sort_asc(T* t, size_t len)
{
    size_t i, j;
    for (i = 0; i < len - 1; i++) {
        for (j = 0; j < len - 1 - i; j++) {
            if (t[j] > t[j + 1])
                swap(t[j], t[j + 1]);
        }
    }
}

#define NR_REALS   5

int main()
{
    double a[NR_REALS];
    for (size_t i = 0; i < NR_REALS; i++) {
        cin >> a[i];
    }

    bubble_sort_asc(a, sizeof(a)/sizeof(a[0]));

    cout << "Ascending order:" << endl;
    for (size_t i = 0; i < NR_REALS; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

