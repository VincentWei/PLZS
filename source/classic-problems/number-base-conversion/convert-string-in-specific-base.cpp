/*
 * This program converts a string in specific base.
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
#include <iostream>     // for cout and cin
#include <string>       // for string
#include <cctype>       // for isdigit() and islower()
#include <cstdlib>      // for strtoll()
#include <cassert>      // for assert()

using namespace std;

/*
 * mypower:
 *
 * @base: the base.
 * @exp: the exponent.
 *
 * returns: The power of @base raised to @exp.
 */
long long mypower(long long base, unsigned exp)
{
    int r = 1;

    while (exp--) {
        r *= base;
    }

    return r;
}

/*
 * mystrtoll:
 *
 * @str: the pointer to the number string in the given base.
 * @base: the base.
 * returns: The number value.
 */
long long mystrtoll(const char *str, int base)
{
    /* 记录字符串的开始位置。 */
    const char *start = str;

    /* 找到字符串的尾部。 */
    while (*str) {
        str++;
    }

    long long ans = 0;
    unsigned exp = 0;

    /* 从字符串的最后一个字符开始倒序处理。 */
    str--;
    while (str >= start) {
        /* v 表示当前数码位置的具体值。 */
        long long v = 0;
        char ch = *str;
        if (isdigit(ch)) {
            v = ch - '0';
        }
        else if (islower(ch)) {
            v = ch - 'a' + 10;
        }
        else if (isupper(ch)) {
            v = ch - 'A' + 10;
        }

        /* 将当前位置数码位置代表的值累加到 ans */
        ans += v * mypower(base, exp);

        exp++;  // 指数加 1
        str--;  // 数码位置向前一位
    }

    return ans;
}

int main()
{
    /* 使用 assert() 函数通过和 strtoll() 对比测试 mystrtoll() 的正确性。 */
    assert(strtoll("1100", NULL, 2) == mystrtoll("1100", 2));
    assert(strtoll("12ABCD", NULL, 16) == mystrtoll("12ABCD", 16));

    string digits;
    int base;
    cin >> digits >> base;

    if (base > -2 && base < 2)
        return 1;

    long long ans = mystrtoll(digits.c_str(), base);
    cout << ans << endl;
}

