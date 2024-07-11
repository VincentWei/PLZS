# C++ 数据类型（下）

1. 深入理解函数调用
1. 结构体
1. 多维数组
1. 联合体
1. 枚举量

		
## 深入理解函数调用

- C/C++ 函数调用过程
- 栈（stack）和栈帧（stack frame）
- 通过递归调用理解函数的调用过程

```cpp
#include <iostream>
#include <string>

using namespace std;

string make_indent(unsigned n)
{
    string indent = "";
    for (unsigned i = 0; i < n; i++) {
        indent += ' ';
    }

    return indent;
}

double my_power(double f, unsigned n, unsigned i = 0)
{
    string indent = make_indent(i);
    cout << indent << "Call #" << i << " my_power(" << f << ", " << n << ")" << endl;

    double r;
    if (n == 0)
        r = 1;
    else
        r = f * my_power(f, n - 1, i + 1);

    cout << indent << "Return " << r << " for Call #" << i << "." << endl;
    return r;
}

int main()
{
    double r = my_power(2.0, 8);
    cout << "The value of 2 raised to the power of 8 is " << r << endl;
}
```

	
### 函数参数的传递：值、指针和引用

- 当函数参数中包括数组或者大型结构体、类的实例时，传递值将导致栈帧过大且需要参数值的复制过程。
- 当函数返回数组或者大型结构体、类的实例时，将产生额外的返回值的复制过程。

```cpp
#include <cctype>

void strtoupper(char dst[10])
{
    for (int i = 0; i < sizeof(dst); i++) {
        dst[i] = toupper(dst[i]);
    }
}

void strtoupper(char *dst)
{
    while (*dst) {
        *dst = toupper(*dst);
        dst++;
    }
}
```


	
- 使用 C++ 的引用类型，可在函数调用中传递变量本身而不需要传递其值。
- C++ 的引用本质上通过指针实现，但提供了更好的代码书写效果。

```cpp
void make_indent(string &indent, unsigned n)
{
    for (unsigned i = 0; i < n; i++) {
        indent += ' ';
    }
}
```

	
- 如果不使用引用而使用指针，上述代码将变成：

```cpp
void make_indent(string *indent, unsigned n)
{
    for (unsigned i = 0; i < n; i++) {
        *indent += ' ';         // 或者 indent->push_back(' ');
    }
}

string make_indent(unsigned n)
{
    string indent;
    while (n--) {
        indent += ' ';
    }

    return indent;
}
```

	
### 课堂练习

（十分钟内完成）

1) 复制上面的示例代码，保存为 `recursive-calls.cpp`，
2) 编译运行，注意观察程序的输出。
3) 通过后提交到自己的作业仓库（`source/cpp/lesson-4/` 目录下，下同）。

		
## 结构体

- C++ 程序中的结构体（struct）通常用来表达具有多重属性的复杂对象，比如一名学生的学号、姓名、性别、生日、身高、体重等。

```cpp
struct student {
    string  id;
    string  name;
    string  birthday;
    char    gender;         // 'M' for male, 'F' for female
    int     height;
    float   weight;
};

    struct student s1 { "20240101", "Julia", "2010-09-03", 'F', 160, 50.3f };
    struct student *p = &s1;

    /* 使用 . 访问结构体变量的成员。 */
    cout << s1.name << endl;

    /* 使用 -> 访问结构体指针变量的成员。 */
    cout << p->id << endl;

    /* 定义结构体数组 */
    struct student students = [
        { "20240101", "Julia", "2010-09-03", 'F', 160, 50.3f },
        { "20240102", "Lisa",  "2010-08-15", 'F', 158, 45.5f },
        { "20240103", "Tom",   "2010-07-10", 'M', 166, 65.5f },
    ];

    for (size_t i = 0; i < sizeof(students)/sizeof(students[0]); i++) {
        cout << "Student " << students[i].id << ": " << students[i].name << endl;
    }
```

	
### 课堂练习

（十分钟内完成）

1) 复制上面的示例代码，使用指针遍历 `students` 数组。
2) 保存为 `students.cpp` 并提交到自己的作业仓库。

		
## 多维数组

- 用于数学上的矩阵运算（二维数组）。

```cpp
    double matrix[4][5] = {
        {1., 2., 3., 4.},
        {2., 3., 4., 1.},
        {3., 4., 1., 2.},
        {4., 1., 2., 3.},
    };

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            matrix[i][j] *= 100.0;
        }
    }
```

	
- 多维数组的另一种表现形式：指针数组

```cpp
    const char *names[] = {
        "Julia",
        "Lisa",
        "Tom",
    };

    for (size_t i = 0; i < sizeof(names)/sizeof(names[0]); i++) {
        for (int j = 0; true; j++) {
            if (names[i][j] == '\0')
                break;

            char c = (char)toupper(names[i][j]);
            cout << c;
        }

        cout << endl;
    }
```

		
## 联合体

- 联合体（union）在 C/C++ 中有妙用。
- 相当于给某个变量取个不同位宽数据类型的别名。

```cpp
union natural {
    unsigned int    natural;
    unsigned short  half[2];
    unsigned char   bytes[4];
};

cout << sizeof(union natural) << endl;

union natural n;

n.natural = 0x13141314u;
cout << n.half[0] << ", " << n.half[1] << endl;
cout << n.bytes[0] << ", " << n.bytes[1] << ", " << n.bytes[2] << ", " << n.bytes[3] << endl;
```

		
## 枚举量

- C 的枚举量本质上是整数；相当于给一组整数取了一个符号化的名称，以方便代码的编写。
- 在枚举量上执行 `switch` 语句时，编译器可对 `case` 的取值进行一些逻辑上的判断。

```cpp

enum rainbow_color {
    red = 1,
    orange,
    yellow,
    green,
    cyan,
    blue,
    purple,
};

// typedef enum rainbow_color rainbow_color_k;
using rainbow_color_k = enum rainbow_color;

const char *rainbow_color_name(rainbow_color_k c)
{
    const char *name = nullptr;

    switch (c) {
    case red:
        name = "red";
        break;
    case orange:
        name = "orange";
        break;
    case yellow:
        name = "yellow";
        break;
    case cyan:
        name = "cyan";
        break;
    case blue:
        name = "blue";
        break;
    case purple:
        name = "purple";
        break;
    case 10:    /* 警告：10 不是 rainbow_color 的有效取值。 */
        break;
    }

    return name;
}
```

		
## 作业

1) 求解给定的线性同余方程组，要求给出至少十个解。运行效果如下：

```console
$ ./crt
<3>
<3 2>
<5 3>
<7 2>
23
128
233
338
443
548
653
758
863
968
```

	
2) 给定任意正整数，给出其所有质因子（重复的质因子只保留一个）。运行效果如下：

```console
$ ./prime-factors
<12>
12: 2 3
$ ./prime-factors
<11>
1: 11
```

	
3) 给定任意整数 `n`，列出用于计算 `D(n)` 和 `O(n)` 的所有可能形式。运行效果如下：

```console
$ ./dn-on
<3>
3
2 1
---
3
1 1 1
```

	
4) 判定形如 `ax + by = d` 的不定方程是否有整数解，若有，给出至少十个解。运行效果如下：

```console
$ ./bezout
<23 7 1>            # 三个数，分别是 ax + by = d 不定方程中的 a, b, d
-3 10
4  -23
11 -36
18 -59
25 -82
32 -105
39 -128
46 -151
53 -174
60 -197
$ ./bezout
<12 15 4>
No solution
```

	
5) 使用结构体定义一个二维几何形状（三角形、正方形、圆），其中包含几何形状名称、构造该几何形状的参数数量、通过函数指针定义的面积计算函数等，最终实现 `calc-areas.cpp` 程序。运行效果如下：

```console
$ ./calc-area
To calculate the area, please choose a geometrical shape:
1. Triange
2. Square
3. Circle
0. Exit
Your choice:<1>
Please input the lengthes of three sides of a triangle: <3 4 5>
The area of your triangle is: 6.0
To calculate the area, please choose a geometrical shape:
1. Triange
2. Square
3. Circle
0. Exit
Your choice:<2>
Please input the side of your square: <4>
The area of your square is: 16.0
```

	
### 参考链接

- 信奥生的数学素养课第六讲“初等数论主要定理及应用（续）”
- [扩展欧几里得算法](https://www.cnblogs.com/fusiwei/p/11775503.html)
- [线性同余方程](https://oi-wiki.org/math/number-theory/linear-equation/)

	
### 作业回顾

