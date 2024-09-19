/*
 * The trick version to calculate the summary of factorials.
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

#define NTEST

#include "nap-arithmetic.cpp"

string nap_mul_plain(const string &a, unsigned b)
{
    unsigned times = 0;
    string result("0");
    while (b != times) {
        nap_add_to(result, a);
        times++;
    }

    return result;
}

int main()
{
    unsigned n;
    cin >> n;

    string summary = "1";
    string last = "1";  // factorial of 0
    for (unsigned i = 1; i <= n; i++) {

        string factorial = nap_mul_plain(last, i);
        nap_add_to(summary, factorial);
        last = factorial;
    }
    cout << summary << endl;
    return 0;
}

