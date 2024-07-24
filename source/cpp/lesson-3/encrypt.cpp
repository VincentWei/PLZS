/*
 * The answer key for Problem 4 of CPP Lesson 3:
 * https://courses.fmsoft.cn/plzs/cpp-data-types.html#/6/3
 *
 * Author: Vincent Wei
 *  - <https://github.com/VincentWei>
 *  - <https://gitee.com/vincentwei7>
 *
 * Copyright (C) 2024 FMSoft <https://www.fmsoft.cn>.
 * License: GPLv3
 */
#include <iostream>     // for cin and cout
#include <string>       // for string
#include <cstdio>       // for BUFSIZ
#include <cctype>       // for islower() and isupper()
#include <cassert>      // for assert()

using namespace std;

int main()
{
#if 0
    // 待加密的字符串。
    const char *p = "I Love You!";
#else
    // 从标准输入读取待加密的字符串，使用如下代码：
    char buf[BUFSIZ];
    cin.getline(buf, sizeof(buf));
    const char *p = buf;
#endif

    string encrypted;

    while (*p) {
        char en;

        if (islower(*p)) {
            en = (*p + 7);
            if (en > 'z') {
                en = 'a' + en - 'z' - 1;
            }
        }
        else if (isupper(*p)) {
            en = *p - 'A';
            en += 7;
            en %= 26;
            en += 'A';
        }
        else if (*p == ' ') {
            en = '&';
        }
        else {
            en = *p;
        }

        encrypted.push_back(en);
        p++;
    }

    cout << encrypted << endl;
}
