/*
 * One example for NOI CSP-J Lesson 4:
 * <https://courses.fmsoft.cn/plzs/noijunior-tree-data-structures.html>
 *
 * Author: Vincent Wei
 *  - <https://github.com/VincentWei>
 *  - <https://gitee.com/vincentwei7>
 *
 * Copyright (C) 2024 FMSoft <https://www.fmsoft.cn>.
 * License: GPLv3
 */
#include <iostream>     // std::cout and std::cerr
#include <fstream>      // std::ofstream and std::ifstream

using namespace std;

int main()
{
    std::fstream fs { "test.txt", std::fstream::in };
    if (fs.fail()) {
        cerr << "Failed to open 'test.txt'\n";
    }
    else {
        char c;
        while ((c = fs.get()) != EOF) {
            cout << c;
        }
        fs.close();
    }
    return 0;
}
