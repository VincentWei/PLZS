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
void insertion_sort_asc(T* t, size_t len)
{
    // i 的左侧是已经排好序的部分，右侧是未排好序的部分。
    // i 从 1 开始，此时左侧只有一个元素，无需排序。
    for (size_t i = 1; i < len; i++) {

        // 要将 i 右侧的第一个元素插入到左侧，
        // 但插入操作将覆盖该位置，故而先保存起来。
        T key = t[i];

        // 接下来在 i 的左侧寻找用来插入 key 位置。
        // XXX j 可能会变为 -1，故而使用 ssize_t 类型。
        ssize_t j = i - 1;
        while (j >= 0 and key < t[j]) {
            t[j + 1] = t[j];
            j--;
        }

        // 找到了插入位置，将 key 存入。
        t[j + 1] = key;
    }
}

#define NR_REALS   5

int main()
{
    double a[NR_REALS];
    for (size_t i = 0; i < NR_REALS; i++) {
        cin >> a[i];
    }

    insertion_sort_asc(a, sizeof(a)/sizeof(a[0]));

    cout << "Ascending order:" << endl;
    for (size_t i = 0; i < NR_REALS; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

