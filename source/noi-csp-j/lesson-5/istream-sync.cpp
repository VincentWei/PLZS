/*
 * One example for NOI CSP-J Lesson 5:
 * <https://courses.fmsoft.cn/plzs/noijunior-midterm-project.html>
 *
 * Author: Vincent Wei
 *  - <https://github.com/VincentWei>
 *  - <https://gitee.com/vincentwei7>
 *
 * Copyright (C) 2024 FMSoft <https://www.fmsoft.cn>.
 * License: GPLv3
 */

#include <iostream>     // std::cin, std::cout

int main()
{
    char first, second;

    std::cout << "Please, enter a word: ";
    first = std::cin.get();

    // XXX：此调用的效果和 STL 的实现有关，g++ 和 clang++ 无效。
    std::cin.sync();

    std::cout << "Please, enter another word: ";
    second = std::cin.get();

    std::cout << "The first word began by " << first << '\n';
    std::cout << "The second word began by " << second << '\n';

    return 0;
}
