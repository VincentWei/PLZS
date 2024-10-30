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
#include <fstream>      // std::fstream

int main()
{
    std::fstream fs { "test.txt", std::fstream::in };
    if (fs.fail()) {
        std::cerr << "Failed to open 'test.txt'\n";
    }
    else {
        int c;
        while ((c = fs.get()) != EOF) {
            std::cout.put((char)c);
        }
        fs.close();
    }
}
