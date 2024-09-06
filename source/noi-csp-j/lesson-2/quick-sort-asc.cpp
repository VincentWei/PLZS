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
#include <cassert>      // for assert()

template <class T>
size_t partition(T t[], size_t low, size_t high)
{
    // 选择数组中的第一个元素作为基准，并保存到临时变量；
    // XXX 注意 low 的值在后续操作中会不断变化。
    T pivot = t[low];

    // 在数组中不断将大于 pivot 的值放到右边，将小于 pivot 的值放到左边。
    // 同时调整 pivot 所在位置，也就是 low 的值。
    while (low < high) {
        // 注意在整个循环中 low 在逐步变大，high 在逐步变小。

        // 此循环将从数组尾部开始找比 pivot 还小的元素。
        while (low < high && pivot < t[high])
            --high;
        t[low] = t[high];   // 将找到的比 pivot 还小的元素放到头部。

        // 此循环将从数组头部开始找比 pivot 还大的元素。
        while (low < high && t[low] < pivot)
            ++low;
        t[high] = t[low];   // 将找到的比 pivot 还大的元素放到尾部。
    }

    // low 中包含的是 pivot 的新位置，将保存的 pivot 值放到这个位置。
    t[low] = pivot;

    // 返回 pivot 的位置（索引值）。
    return low;
}

template <class T>
void quick_sort_asc(T t[], size_t low, size_t high)
{
    if (low < high) {
        // 以分区找到的 pivot 位置将数组一分为二，然后递归执行快速排序。
        size_t pos_pivot = partition(t, low, high);
        quick_sort_asc(t, low, pos_pivot - 1);
        quick_sort_asc(t, pos_pivot + 1, high);
    }
}

template <class T>
void quick_sort_asc(T t[], size_t len)
{
    quick_sort_asc(t, 0, len - 1);
}

using namespace std;

#define NR_REALS   5

int main()
{
    double a[NR_REALS];
    for (size_t i = 0; i < NR_REALS; i++) {
        cin >> a[i];
    }

    quick_sort_asc(a, sizeof(a)/sizeof(a[0]));

    cout << "Ascending order:" << endl;
    for (size_t i = 0; i < NR_REALS; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

