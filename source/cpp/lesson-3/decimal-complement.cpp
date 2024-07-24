/*
 * The answer key for Problem 5 of CPP Lesson 3:
 * https://courses.fmsoft.cn/plzs/cpp-data-types.html#/6/3
 *
 * Author: Vincent Wei
 *  - <https://github.com/VincentWei>
 *  - <https://gitee.com/vincentwei7>
 *
 * Copyright (C) 2024 FMSoft <https://www.fmsoft.cn>.
 * License: GPLv3
 */
#include <iostream>     // for cout and cin
#include <string>       // for string
#include <cctype>       // for isdigit()

using namespace std;

int main()
{
    string digits;
    cin >> digits;

#if 0
    // 这是遍历字符串中各个元素的基本写法。
    for (size_t i = 0; i < digits.length(); i++) {
        char c = digits[i];
#else
    // 也可以用这种写法；将遍历 digits 中的每个元素，并赋值给局部变量 c。
    for (char c: digits) {
#endif
        if (isdigit(c)) {
#if 0
            // 注意：下面这种用法将打印字符对应的整数值，这是因为编译器将该
            // 表达式的值隐含转换成了 int 类型。
            cout << '0' + '9' - c;
#else
            c = '0' + '9' - c;
            cout << c;
#endif
        }
    }

    cout << endl;
}

