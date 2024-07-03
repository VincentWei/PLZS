# C++ 数据类型（下）

1. 深入理解函数调用
1. 结构体
1. 多维数组
1. 联合体
1. 枚举量
1. 类型别名
1. 作业

		
## 引用

		
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


	
- C++ 提供了引用类型，用于在函数调用中传递变量本身而不需要传递其值。
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

（五分钟内完成）

1) 复制上面的示例代码，使用指针遍历 `students` 数组。
2) 保存为 `students.cpp` 并提交到自己的作业仓库。

		
## 多维数组

- 通常用于数学上的矩阵运算（二维数组）。
- 其他情况下较少使用。

```cpp
    double matrix[4][5] = [
        [1., 2., 3., 4.],
        [2., 3., 4., 1.],
        [3., 4., 1., 2.],
        [4., 1., 2., 3.],
    ];

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 5; j++) {
            matrix[i][j] *= 100.0;
        }
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

```
enum rainbow_color {
    red = 1,
    orange,
    yellow,
    green,
    cyan,
    blue,
    purple,
};

const char *rainbow_color_name(enum rainbow_color c)
{
    const char *name = NULL;

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

		
## 类型别名

	
### 使用 `typedef`

```cpp
typedef char BYTE;
typedef unsigned short WORD;
typedef unsigned long long ULL;

typedef enum rainbow_color {
    red = 1,
    orange,
    yellow,
    green,
    cyan,
    blue,
    purple,
} rainbow_color_k;
```

	
### 使用 `using`

```cpp
using BYTE = char;
using WORD = unsigned int;
using ULL = unsigned long long;
using rainbow_color_k = enum rainbow_color;
```

	
### 使用预处理宏（不推荐）

```cpp
#define BYTE unsigned char
#define WORD unsigned short
#define ULL  unsigned long long
```

		
## 作业

1) 生成小于用户指定的正整数的斐波那契（Fibonacci）数列，然后计算相邻两个数的比值。运行效果如下：

```console
$ ./fibonacci-improved
<11>
1 / 1: 1.0
1 / 2: 0.5
2 / 3: 0.6666666666666666
3 / 5: 0.6
5 / 8: 0.625
```

	
2) 编写一个程序，该程序可以将用户输入的一个自然数转换为 -36 到 36 进制展示出来。运行效果如下：

```console
$ ./show-number-in-different-bases
<15 2>      # 第一个数值指定一个十进制的一个正整数，第二个数字指定进制，两者用空格分隔。
1111
```

	
3) 编写一个函数，该函数可以将用户输入的一个特定进制的数用十进制展示出来，并使用 `<cstdlib>` 中的 `strtoll()` 接口进行测试。运行效果如下：

```console
$ ./strtoll
<56ABC 20>  # 第一个数值指定一个字符串，第二个数字指定该数值的进制，两者用空格分隔。
852232
```

	
4) 求解给定的同余方程组，要求给出至少十个解。运行效果如下：

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

	
5) 给定任意正整数，给出其所有质因子（重复的质因子只保留一个）。

```console
$ ./prime-factors
<12>
12: 2 3
$ ./prime-factors
<11>
1: 11
```

	
6) 给定任意整数 `n`，列出用于计算 `D(n)` 和 `O(n)` 的所有可能形式。

```console
$ ./dn-on
<3>
3
2 1
---
3
1 1 1
```

	
7) 编程找到尽可能多的亲和数。运行效果如下：

```console
$ ./amicable-pairs
220 284
1184 1210
2620 2924
5020 5564
6232 6368
10744 10856
12285 14595
17296 18416
63020 76084
66928 66992
67095 71145
69615 87633
79750 88730
100485 124155
122265 139815
122368 123152
141664 153176
142310 168730
171856 176336
180848 176272
185368 203432
196724 202444
280540 365084
308620 389924
319550 430402
356408 399592
437456 455344
469028 486178
503056 514736
522405 525915
600392 669688
609928 686072
624184 691256
635624 712216
643336 652664
667964 783556
726104 796696
802725 863835
879712 901424
898216 980984
947835 1125765
9980104 1043096
9363544 9437056
...
```

	
### 作业回顾

