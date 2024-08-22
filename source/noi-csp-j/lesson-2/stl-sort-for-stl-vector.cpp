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
    // 支持函数对象的类通过重载 () 运算符实现像函数一样使用这个类的对象的效果：
    //
    //  my_greater_function func_obj;
    //  assert(func_obj(0.1, 0.2) == false);
    //
    // 当在该类的实例 func_obj 上使用 () 运算符时，将调用下面这个函数。
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

