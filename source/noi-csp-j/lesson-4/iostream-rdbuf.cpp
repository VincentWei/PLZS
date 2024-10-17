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
    // 备份 cin 和 cout 的默认 filebuf 对象
    streambuf *cin_backup, *cout_backup;
    cin_backup = cin.rdbuf();
    cout_backup = cout.rdbuf();

    // 打开要参与重定向的文件
    fstream in, out;
    in.open("in.txt", ios::in | ios::out | ios::trunc);
    out.open("out.txt", ios::out | ios::app);
    if (in.fail() || out.fail())
        return -1;

    // 向 `in.txt` 文件写入一个整数
    in << 1000 << endl;

    in.seekg(0, in.beg);

    // 将 `in` 的 filebuf 对象设置给 cin 使用
    cin.rdbuf(in.rdbuf());

    // 将 `out` 的 filebuf 对象设置给 cout 使用
    cout.rdbuf(out.rdbuf());

    // 此后在 cin 和 cout 上的读取和写入，
    // 相当于从 in.txt 中读取，向 out.txt 写入。
    int n;
    cin >> n;
    cout << n << endl;

    // 恢复 cin 和 cout 的 filebuf 对象
    cin.rdbuf(cin_backup);
    cout.rdbuf(cout_backup);

    // 关闭 in 和 out 流
    in.close();
    out.close();

    return 0;
}
