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

struct _Spaces { unsigned n; };

inline _Spaces indent(unsigned level) {
    return { level };
}

inline ostream& operator<<(ostream& os, _Spaces _s) {
    for (unsigned i = 0; i < _s.n; i++) {
        os << ' ';
    }

    return os;
}

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
        // 跳过 . 和 ..
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

    $ ./directory-tree /etc

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

