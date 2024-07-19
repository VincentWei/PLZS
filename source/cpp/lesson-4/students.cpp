#include <iostream>
#include <string>

using namespace std;

struct student {
    string  id;
    string  name;
    string  birthday;
    char    gender;         // 'M' for male, 'F' for female
    int     height;
    float   weight;
};

int main()
{
    struct student s1 { "20240101", "Julia", "2010-09-03", 'F', 160, 50.3f };
    struct student *p = &s1;

    /* 使用 . 访问结构体变量的成员。 */
    cout << s1.name << endl;

    /* 使用 -> 访问结构体指针变量的成员。 */
    cout << p->id << endl;

    /* 定义结构体数组 */
    struct student students[] = {
        { "20240101", "Julia", "2010-09-03", 'F', 160, 50.3f },
        { "20240102", "Lisa",  "2010-08-15", 'F', 158, 45.5f },
        { "20240103", "Tom",   "2010-07-10", 'M', 166, 65.5f },
    };

    p = students;
    for (size_t i = 0; i < sizeof(students)/sizeof(students[0]); i++) {
#if 1
        cout << "Student " << p->id << ": " << p->name << endl;
        p++;
#else
        cout << "Student " << p[i].id << ": " << p[i].name << endl;
#endif
    }

}
