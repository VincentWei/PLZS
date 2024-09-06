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
#include <cstdlib>      // for malloc()
#include <cassert>      // for assert()

using namespace std;

template <class T>
void merge(const T* src_a, size_t len_a, const T* src_b, size_t len_b, T* dst)
{
    size_t i = 0, j = 0, k = 0;

    while (i < len_a && j < len_b) {
        // XXX 先判断 src_b[j] < src_a[i]，保证稳定性
        if (src_b[j] < src_a[i]) {
            dst[k] = src_b[j];
            ++j;
        }
        else {
            dst[k] = src_a[i];
            ++i;
        }
        ++k;
    }

    // 此时可能有一个数组已空，而另一个数组非空，将非空的数组直接并入 dst 中
    for (; i < len_a; ++i, ++k)
        dst[k] = src_a[i];
    for (; j < len_b; ++j, ++k)
        dst[k] = src_b[j];
}

template <class T>
void merge_sort_asc(T* t, size_t start, size_t stop, T* buf)
{
    // 递归终止条件：只有一个元素或者没有元素时终止
    if (stop - start <= 1)
        return;

    // 将数组从中间分开，然后递归对两个分区执行合并排序。
    size_t mid = start + ((stop - start) >> 1);
    merge_sort_asc(t, start, mid, buf);
    merge_sort_asc(t, mid, stop, buf);

    // 合并到 buf 数组中。
    merge(t + start, mid - start, t + mid, stop - mid, buf + start);

    // 将合并后的 buf 放到 t 中。
    for (size_t i = start; i < stop; ++i)
        t[i] = buf[i];
}

#define NR_REALS   5

int main()
{
    double a[NR_REALS];
    for (size_t i = 0; i < NR_REALS; i++) {
        cin >> a[i];
    }

    double* buf = new double[NR_REALS];
    merge_sort_asc(a, 0, sizeof(a)/sizeof(a[0]), buf);
    delete[] buf;

    cout << "Ascending order:" << endl;
    for (size_t i = 0; i < NR_REALS; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

