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
#include <utility>      // for swap()
#include <cassert>      // for assert()

using namespace std;

template <class T>
size_t minimum_index(T* t, size_t len)
{
    assert(len > 0);

    size_t min = 0;
    for (size_t i = 1; i < len; i++) {
        if (t[i] < t[min])
            min = i;
    }

    return min;
}

template <class T>
void selection_sort_asc(T* t, size_t len)
{
    size_t start = 0;
    while (true) {
        if (start + 1 == len)
            break;
        size_t min = minimum_index(t + start, len - start);
        min += start;       // XXX
        if (min != start) {
            swap(t[start], t[min]);
        }

        start++;
    }
}

#define NR_REALS   5

int main()
{
    double a[NR_REALS];
    for (size_t i = 0; i < NR_REALS; i++) {
        cin >> a[i];
    }

    selection_sort_asc(a, sizeof(a)/sizeof(a[0]));

    cout << "Ascending order:" << endl;
    for (size_t i = 0; i < NR_REALS; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

