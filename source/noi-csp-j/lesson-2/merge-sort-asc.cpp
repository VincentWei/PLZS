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
void merge(const T* a, size_t len_a, const T* b, size_t len_b, T* c)
{
    size_t i = 0, j = 0, k = 0;

    while (i < len_a && j < len_b) {
        // XXX 先判断 b[j] < a[i]，保证稳定性
        if (b[j] < a[i]) {
            c[k] = b[j];
            ++j;
        }
        else {
            c[k] = a[i];
            ++i;
        }
        ++k;
    }

    // 此时一个数组已空，另一个数组非空，将非空的数组并入 c 中
    for (; i < len_a; ++i, ++k)
        c[k] = a[i];
    for (; j < len_b; ++j, ++k)
        c[k] = b[j];
}

template <class T>
void merge_sort_asc(T *t, size_t start, size_t stop)
{
    // 递归终止条件：只有一个元素或者没有元素时终止
    if (stop - start <= 1)
        return;

    // 将数组从中间分开，然后递归对两个分区执行合并排序。
    size_t mid = start + ((stop - start) >> 1);
    merge_sort_asc(t, start, mid);
    merge_sort_asc(t, mid, stop);

    // 临时空间，用于保存合并结果
    T tmp[stop - start];

    // 合并到 tmp 数组中。
    merge(t + start, mid - start, t + mid, stop - mid, tmp);

    // 将合并后的 tmp 放到 t 中。
    for (size_t i = start; i < stop; ++i)
        t[i] = tmp[i - start];
}

#define NR_REALS   5

int main()
{
    double a[NR_REALS];
    for (size_t i = 0; i < NR_REALS; i++) {
        cin >> a[i];
    }

    merge_sort_asc(a, 0, sizeof(a)/sizeof(a[0]));

    cout << "Ascending order:" << endl;
    for (size_t i = 0; i < NR_REALS; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

