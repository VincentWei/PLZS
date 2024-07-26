/*
 * The answer key for Problem 2 of CPP Lesson 4:
 * <https://courses.fmsoft.cn/plzs/cpp-data-types-more.html#/9/1>
 *
 * Author: Vincent Wei
 *  - <https://github.com/VincentWei>
 *  - <https://gitee.com/vincentwei7>
 *
 * Copyright (C) 2024 FMSoft <https://www.fmsoft.cn>.
 * License: GPLv3
 */
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    unsigned nr_rows;
    cin >> nr_rows;

    // 检查输入合法性
    if (nr_rows == 0)
        return 1;

#ifdef LINUX
    unsigned yang_numbers[nr_rows][nr_rows] = {};
#else
    // workaround for clang++
    unsigned yang_numbers[nr_rows][nr_rows];
    memset(yang_numbers, 0, sizeof(yang_numbers));
#endif

    // 计算杨辉三角中各元素的值
    for (unsigned i = 0; i < nr_rows; i++) {
        // 每行第一个元素始终为 1
        yang_numbers[i][0] = 1;

        for (unsigned j = 1; j < nr_rows; j++) {
            // 满足该条件的元素保持其值为零
            if (j > i)
                break;

            // 该元素的值等于上方元素的值加上左上方元素的值
            yang_numbers[i][j] =
                yang_numbers[i - 1][j] + yang_numbers[i - 1][j - 1];
        }
    }

    // 输出杨辉三角
    for (unsigned i = 0; i < nr_rows; i++) {
        for (unsigned j = 0; j < nr_rows; j++) {
            // 如遇值为零的元素，则跳过当前元素以及其后的所有元素
            if (yang_numbers[i][j] == 0)
                break;

            cout << yang_numbers[i][j] << " ";
        }

        cout << endl;
    }
}

