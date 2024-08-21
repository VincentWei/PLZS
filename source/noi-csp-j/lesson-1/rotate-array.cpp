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
#include <string>       // for stod()
#include <cassert>      // for assert()

using namespace std;

template <class T>
void rotate_array(T* arr, size_t n, size_t m)
{
    assert(n > 0);
    if (m % n == 0)
        return;

    T tmp[n];
    for (size_t i = 0; i < n; i++) {
        tmp[i] = arr[i];
    }

    for (size_t i = 0; i < n; i++) {
        size_t j = (i + m) % n;
        arr[j] = tmp[i];
    }
}

#define SZ_MAX 100

int main()
{
    cout << sizeof(size_t) << " " << sizeof(long) << " " << sizeof(long long) << endl;

    string buf;
    getline(cin, buf, '\n');

    double a[SZ_MAX];
    size_t n = 0;
    while (!buf.empty() && n < SZ_MAX) {
        size_t sz;
        double d = stod(buf, &sz);
        buf = buf.substr(sz);
        a[n++] = d;
    }

    rotate_array(a, n, 1);
    for (size_t i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    cout << endl;

    rotate_array(a, n, 2);
    for (size_t i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    cout << endl;
}

