/*
 * The answer key for Problem 1 of CPP Lesson 4:
 * <https://courses.fmsoft.cn/plzs/cpp-data-types-more.html#/9>
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
    unsigned nr_students, nr_courses;
    cin >> nr_students >> nr_courses;

    // 检查输入合法性
    if (nr_students == 0 || nr_courses == 0)
        return 1;

    // 用于存储各学生各科目成绩的二维数组
#ifdef LINUX
    unsigned scores[nr_students][nr_courses] = { };
#else
    unsigned scores[nr_students][nr_courses];
    memset(scores, 0, sizeof(scores));      // 初始化二维数组 scores 为全零
#endif

    // 读取各学生各科目成绩
    for (unsigned i = 0; i < nr_students; i++) {
        for (unsigned j = 0; j < nr_courses; j++) {
            cin >> scores[i][j];
        }
    }

    double total_scores[nr_courses];        // 各科总分
    memset(total_scores, 0, sizeof(total_scores));
    // 计算各科目总分及总分
    for (unsigned i = 0; i < nr_students; i++) {
        for (unsigned j = 0; j < nr_courses; j++) {
            total_scores[j] += scores[i][j];
        }
    }

    // 计算并输出各科目平均分
    for (unsigned i = 0; i < nr_courses; i++) {
        // 使用 llround() 函数对各科目平均分四舍五入
        cout << llround(total_scores[i] / nr_students) << " ";
    }
    cout << endl;
}
