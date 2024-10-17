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

#include <iostream>
#include <string>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

using namespace std;

// 为支持自定义的 ostream 操作器（manipulator）indent()
// 而定义一个新的结构类型。
struct _Spaces { unsigned n; };

// 该操作器可以如此使用：cout << indent(3) << endl;
inline _Spaces indent(unsigned level) {
    return { level };
}

// 重载 ostream 的 << 运算符，其左值类型为 ostream&，右值类型为 _Space。
// 从而支持 cout << indent(3) 这样的用法。
inline ostream& operator<<(ostream& os, _Spaces _s) {
    for (unsigned i = 0; i < _s.n; i++) {
        os << ' ';
    }

    return os;
}

/*
  该函数递归读取目录中的目录项并列出，效果如下：

  ./lesson-4/
   in.txt
   out.txt
   Makefile
   generic-tree.cpp
   students.bin
   fstream-binary.cpp
   binary-tree.cpp
   readdir.cpp
   iostream-rdbuf.cpp
  ./lesson-3/
   Makefile
   simple-vector.cpp
   doubly-linked-list.cpp
   singly-linked-list.cpp
   singly-circular-linked-list.cpp
*/
void list_dir_entries(unsigned level, const string& path)
{
    DIR*    dir;
    struct  dirent* dir_ent;

    dir = ::opendir(path.c_str());
    if (dir == nullptr) {
        cerr << "Failed to open directory: " << path << endl;
        return;
    }

    cout << indent(level * 2) << path << "/" << endl;

    while ((dir_ent = ::readdir(dir)) != nullptr) {
        // 跳过 . 和 .. 否则会无限递归
        if (strcmp(dir_ent->d_name, ".") == 0
                || strcmp(dir_ent->d_name, "..") == 0)
            continue;

        // 组装完整文件路径
        string full_path = path + "/" + dir_ent->d_name;

        struct stat my_stat;
        if (::stat(full_path.c_str(), &my_stat) < 0 ){
            cerr << "Failed to stat file: " << full_path << endl;
            continue;
        }

        if (S_ISDIR(my_stat.st_mode)) {
            list_dir_entries(level + 1, full_path);
        }
        else {
            cout << indent(level * 2 + 1) << dir_ent->d_name << endl;
        }

        // XXX struct stat 结构中的 st_size 字段包含有文件的大小（字节为单位）。
        // XXX struct stat 结构中的 st_mtim 字段包含有文件的最后修改时间。
    }

    ::closedir(dir);
}

/*
  这里展示了 main() 的另一种形式。
  使用这一形式时，通过形参 argc 和 argv 获得执行该程序时的命令行参数信息。
  系统会将执行该程序时的命令行字符串按空格分隔并传入 main() 函数。其中，

  argc 表示参数的数量（包括程序名称在内）。
  argv 包含各个参数对应的字符串指针。

  如对命令行：

    $ ./readdir /etc

  有：

    argc: 2
    argv: ["./directory-tree", "/etc"]
*/
int main(int argc, const char* argv[])
{
    string start;
    if (argc > 1)
        start = argv[1];
    else
        start = ".";

    list_dir_entries(0, start);
    return 0;
}

