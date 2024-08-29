/*
 * This program calculates the ratio of two adjacent Fibonacci numbers.
 *
 * This program is a part of PLZS (the Programming Lessons for
 * Zero-based Students Aged 10+) project.
 * For more information about PLZS, please visit:
 *
 *  - <https://github.com/VincentWei/PLZS>
 *  - <https://gitee.com/vincentwei7/PLZS>
 *
 * Author: Vincent Wei
 *
 * Copyright (C) 2024 FMSoft <https://www.fmsoft.cn>.
 * License: GPLv3
 */
#include <iostream>
#include <cstring>      // for memset()

using namespace std;

int main()
{
    uintmax_t a = 0;
    uintmax_t b = 1;

    cout.precision(20);
    while (true) {
        long double ratio = (long double)a / b;
        cout << a << " / " << b << ":\n\t\e[1;31m" << ratio << "\e[0m" << endl;

        auto tmp = a;
        a = b;
        b = tmp + b;

        if (b < a) {
            cout << "OVERFLOWED" << endl;
            break;
        }
    }
}

