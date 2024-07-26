/*
 * The answer key for Problem 2 of CPP Lesson 3:
 * https://courses.fmsoft.cn/plzs/cpp-data-types.html#/6/1
 *
 * Author: Vincent Wei
 *  - <https://github.com/VincentWei>
 *  - <https://gitee.com/vincentwei7>
 *
 * Copyright (C) 2024 FMSoft <https://www.fmsoft.cn>.
 * License: GPLv3
 */
#include <iostream>
#include <cstring>      // for memset()

using namespace std;

int main()
{
    unsigned n;
    cin >> n;

    if (n < 2)
        return 1;

#ifdef LINUX
    // Only works when using g++
    uint64_t fibonacci[n] = {};
#else
    uint64_t fibonacci[n];
    memset(fibonacci, 0, sizeof(fibonacci));
#endif

    fibonacci[0] = 1;
    fibonacci[1] = 1;
    for (size_t i = 0; i < sizeof(fibonacci)/sizeof(fibonacci[0]); i++) {
        if (fibonacci[i] == 0) {
            fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
        }
    }

    for (size_t i = 1; i < sizeof(fibonacci)/sizeof(fibonacci[0]); i++) {
        double ratio = (double)fibonacci[i - 1] / fibonacci[i];
        cout << fibonacci[i - 1] << " / " << fibonacci[i] << ": " << ratio << endl;
    }
}

