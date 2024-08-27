/*
 * This program calculates the summary of factorials.
 *
 * Author: Vincent Wei
 *  - <https://github.com/VincentWei>
 *  - <https://gitee.com/vincentwei7>
 *
 * Copyright (C) 2024 FMSoft <https://www.fmsoft.cn>.
 * License: GPLv3
 */

#define NTEST

#include "nap-arithmetic.cpp"

int main()
{
    unsigned n;
    cin >> n;

    string summary = "1";
    string last = "1";  // factorial of 0
    for (unsigned i = 1; i <= n; i++) {

        string factorial = nap_mul_alt(last, i);
        nap_add_to(summary, factorial);
        last = factorial;
    }
    cout << summary << endl;
    return 0;
}

