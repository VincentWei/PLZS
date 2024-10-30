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
    struct student {
        int id;
        int age;
        float height;
        float weight;
        char  name[16];
    } students[] = {
        { 10001, 10, 159.0f, 55.5f, "Tom" },
        { 10002, 11, 160.0f, 58.5f, "Jerry" },
    };

    ofstream ofs;
    ofs.open("students.bin", ofstream::out | ofstream::binary | std::ostream::app);
    for (size_t i = 0; i < sizeof(students)/sizeof(students[0]); i++) {
        ofs.write((const char*)(students + i), sizeof(struct student));
    }
    ofs.close();

    ifstream ifs("students.bin", ofstream::in | ofstream::binary);
    if (ifs) {
        // 调用 seekg() 将读取位置置于文件尾。
        ifs.seekg(0, ifs.end);
        // 然后调用 tellg() 确定文件长度。
        size_t length = ifs.tellg();

        // 确定文件中保存的学生记录数
        size_t nr_students = length/sizeof(struct student);

        // XXX 改变流中的读取位置到文件头
        ifs.seekg(0, ifs.beg);

        // 依次读取学生记录并输出基本信息
        for (size_t i = 0; i < nr_students; i++) {
            struct student student;

            ifs.read((char*)(&student), sizeof(struct student));
            cout << "Got a student: " << student.id
                << " (" << student.name << ")\n";
        }

        ifs.close();
    }
    else {
        cerr << "Failed to open students.bin file\n";
    }
}
