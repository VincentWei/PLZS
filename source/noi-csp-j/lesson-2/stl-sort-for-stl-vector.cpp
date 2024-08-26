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
#include <vector>       // for vector
#include <algorithm>    // for sort()
#include <cassert>      // for assert()

using namespace std;

struct my_greater_function {
    bool operator() (double a, double b) {
        return a > b;
    }
};

#define NR_REALS   5

int main()
{
    vector<double> a;

    for (size_t i = 0; i < NR_REALS; i++) {
        a.push_back(0);
        cin >> a[i];
    }

    sort(begin(a), end(a));

    cout << "Ascending order:" << endl;
    for (size_t i = 0; i < NR_REALS; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    my_greater_function my_compare_desc;
    sort(begin(a), end(a), my_compare_desc);

    cout << "Descending order:" << endl;
    for (size_t i = 0; i < NR_REALS; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

