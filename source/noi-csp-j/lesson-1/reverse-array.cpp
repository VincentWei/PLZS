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
void reverse_array(T* arr, size_t n)
{
    for (size_t i = 0; i < n / 2; i++) {
        T tmp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = tmp;
    }
}

#define SZ_MAX 100

int main()
{
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

    reverse_array(a, n);

    for (size_t i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    cout << endl;
}

