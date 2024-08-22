/*
 * Showing a number in differenct bases.
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
#include <algorithm>    // for reverse()
#include <cstdlib>      // for strtoll()
#include <cassert>      // for assert()
#include <cinttypes>    // for imaxdiv()

using namespace std;

/*
 * integer_in_different_base
 *
 * @integer: The given integer number to convert.
 * @base: The base ranges from -36 to 36, not -1, 0, or 1.
 *
 * Returns: An STL string object.
 */
string integer_in_different_base(intmax_t integer, int base)
{
    // 可用的数码字符。声明为 static 变量，仅初始化一次。
    static const char *digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    /* sign 表示给定整数的符号。
     * 如果给定的整数 integer 是负数，则转换时使用其绝对值，之后再根据
     * sign 标志添加负号。
     */
    bool sign = false;
    if (integer < 0) {
        sign = true;
        integer = -integer;
    }

    /* ans 中将保存转换后的各位上的数码字符。
     *
     * 为方便处理和提高效率，和常见的记法不同，该转换算法将低位上的数码字符保存
     * 在字符串的前面。比如十进制的 1234，将被转换为 4321，然后在转换结束后执行
     * 反转操作变成 1234。
     *
     * 如果不使用这种方法，就要调用 .insert() 方法将转换后的数码字符插入
     * 到字符串 ans 的前面，而这个操作比 .push_back() 方法的执行效率低。
     */
    string ans;

    do {
#if 1
        // 使用 / 和 % 运算符的版本
        intmax_t quot = integer / base;
        intmax_t rem  = integer % base;
        char digit;
        if (rem >= 0) {
            digit = digits[rem];
        }
        else {
            quot++;
            rem -= base;
            digit = digits[rem];
        }

        integer = quot;
#else
        // 这里调用 imaxdiv() 函数执行带余除法，一次返回商和余数。
        // 相比使用 / 和 % 分别求商和求余要干净利落许多。
        imaxdiv_t result;
        result = imaxdiv(integer, base);

        char digit;
        if (result.rem >= 0) {
            digit = digits[result.rem];
        }
        else {
            result.quot++;
            result.rem -= base;
            digit = digits[result.rem];
        }

        integer = result.quot;
#endif

        ans.push_back(digit);

    } while (integer != 0);

    // 如果 sign 为 true，则添加负号。
    if (sign)
        ans.push_back('-');

    // 将 ans 中的字符执行反转。
#if 0
    // 这里给出的是将数组中的元素执行反转操作的典型算法。
    size_t len = ans.length();
    for (size_t i = 0; i < len / 2; i++) {
        char tmp = ans[i];
        ans[i] = ans[len - i - 1];
        ans[len - i - 1] = tmp;
    }
#else
    // 调用 STL reverse 函数，使用迭代器亦可完成反转元素的功能。
    reverse(ans.begin(), ans.end());
#endif

    return ans;
}

int main()
{
    {
        static struct test_case {
            long long n;
            int base;
        } cases[] = {
            // <cstdlib> 中的 strtoll() 只支持 base 为正整数的情况。
            { 0, 2 },
            { 8, 2 },
            { 10, 3 },
            { 980, 5 },
        };

        for (size_t i = 0; i < sizeof(cases)/sizeof(cases[0]); i++) {
            string ans = integer_in_different_base(cases[i].n, cases[i].base);
            long long ll = strtoll(ans.c_str(), NULL, cases[i].base);
            assert(ll == cases[i].n);
        }
    }

    long long integer;
    cin >> integer;

    for (int base = 2; base < 37; base++) {
        string ans;
        ans = integer_in_different_base(integer, base);
        cout << "(" << ans << ")" << base << endl;
        ans = integer_in_different_base(integer, -base);
        cout << "(" << ans << ")" << -base << endl;
    }
}

