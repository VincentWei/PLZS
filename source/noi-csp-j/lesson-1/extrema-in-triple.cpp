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

using namespace std;

template <class T>
const T& max(const T& a, const T& b, const T& c)
{
    const T& tmp = (a > b) ? b : a;
    return (tmp > c) ? c : tmp;
}

template <class T>
const T& min(const T& a, const T& b, const T& c)
{
    const T& tmp = (a < b) ? b : a;
    return (tmp < c) ? c : tmp;
}

int main()
{
    double a, b, c;
    cin >> a >> b >> c;

    cout << max(a, b, c) << endl;
    cout << min(a, b, c) << endl;
}
