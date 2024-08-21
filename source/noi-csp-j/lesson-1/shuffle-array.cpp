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
#include <ctime>        // for time()
#include <cstdlib>      // for srandom() and random()
#include <cassert>      // for assert()

using namespace std;

template <class T>
void shuffle_array(T* arr, size_t n)
{
    assert(sizeof(size_t) == sizeof(long));

    srandom(time(NULL));
    for (size_t i = 0; i < n; i++) {
        size_t a = static_cast<size_t>(random());
        size_t j = a % n;

        T tmp = arr[0];
        arr[0] = arr[j];
        arr[j] = tmp;
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

    shuffle_array(a, n);

    for (size_t i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    cout << endl;
}

