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
#include <iostream>         // for cin and cout
#include <algorithm>        // for max() and min()

using namespace std;

int main()
{
    double a, b;
    cin >> a >> b;

    cout << max(a, b) << endl;
    cout << min(a, b) << endl;
}
