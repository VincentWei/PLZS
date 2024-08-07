# C++ 数据类型（下）

1. 深入理解函数调用
1. 结构体
1. 多维数组
1. 联合体
1. 枚举量
1. 综合示例
1. 实用技巧

		
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

	
### 执行结果

```console
$ ./recursive-calls
Call #0 my_power(2, 8)
 Call #1 my_power(2, 7)
  Call #2 my_power(2, 6)
   Call #3 my_power(2, 5)
    Call #4 my_power(2, 4)
     Call #5 my_power(2, 3)
      Call #6 my_power(2, 2)
       Call #7 my_power(2, 1)
        Call #8 my_power(2, 0)
        Return 1 for Call #8.
       Return 2 for Call #7.
      Return 4 for Call #6.
     Return 8 for Call #5.
    Return 16 for Call #4.
   Return 32 for Call #3.
  Return 64 for Call #2.
 Return 128 for Call #1.
Return 256 for Call #0.
The value of 2 raised to the power of 8 is 256
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
string& make_indent(string &indent, unsigned n)
{
    for (unsigned i = 0; i < n; i++) {
        indent += ' ';
    }

    return indent;
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
```

- 如果返回对象，上述代码将变成：

```cpp
string make_indent(unsigned n)
{
    string indent;
    while (n--) {
        indent += ' ';          // 或者 indent.push_back(' ');
    }

    return indent;
}
```

	
### 课堂练习

（十分钟内完成）

1) 基于上面的示例代码选择一个自己喜欢的 `make_indent()` 函数编写 `recursive-calls.cpp` 程序。
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
    struct student students[] = {
        { "20240101", "Julia", "2010-09-03", 'F', 160, 50.3f },
        { "20240102", "Lisa",  "2010-08-15", 'F', 158, 45.5f },
        { "20240103", "Tom",   "2010-07-10", 'M', 166, 65.5f },
    };

    for (size_t i = 0; i < sizeof(students)/sizeof(students[0]); i++) {
        cout << "Student " << students[i].id << ": " << students[i].name << endl;
    }
```

	
### 课堂练习

（十分钟内完成）

1) 基于上面的示例代码编写完整的 `students.cpp` 程序，并使用指针遍历 `students` 数组。
2) 调试通过后提交到自己的作业仓库。

		
## 多维数组

- 二维数组较为常用，更多维的数组很少使用。
- 二维数组可以视作矩阵，其中的数据项按先行再列的顺序保存。

```cpp
    // 定义一个 4 行、5 列的矩阵（二维数组）
    double matrix[4][5] = {
        {1., 2., 3., 4., 5.},
        {2., 3., 4., 5., 1.},
        {3., 4., 5., 1., 2.},
        {4., 5., 1., 2., 3.},
    };

    // 使用双重循环遍历二维数组中的每个单元
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            matrix[i][j] *= 100.0;
        }
    }

    // 获取行指针并按照一维数组访问行内每个单元
    for (int i = 0; i < 4; i++) {
        double *row = matrix[i];
        for (int j = 0; j < 5; j++) {
            row[j] *= 100.0;
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

		
## 综合示例

- 将常见二维几何形状封装（encapsulate）为单个数据结构。
- 为这些形状的周长和面积计算函数定义统一的原型。

```cpp
using namespace std;

enum shape_type {
    st_circle,
    st_square,
    st_rectangle,
    st_triangle,
};

struct shape {
    enum shape_type type;
    const char *name;
    union {
        double one;
        double two[2];
        double three[3];
    };
};

bool prompt_for_circle(struct shape &shape)
{
    cout << "Please input the radius of a circle:";
    cin >> shape.one;

    if (shape.one < 0)
        return false;

    shape.type = st_circle;
    return true;
}

double calc_perimeter_circle(const struct shape &shape)
{
    return 2 * M_PI * shape.one;
}

double calc_area_circle(const struct shape &shape)
{
    return M_PI * shape.one * shape.one;
}

/* functions for square, rectangle, and triangle here */
...

static struct formula {
    const char *name;

    bool (*prompt_f)(struct shape &);
    double (*calc_perimeter_f)(const struct shape &);
    double (*calc_area_f)(const struct shape &);
} formulas[] = {
    { "Circle",     prompt_for_circle, calc_perimeter_circle, calc_area_circle },
    { "Square",     prompt_for_square, calc_perimeter_square, calc_area_square },
    { "Rectangle",  prompt_for_rectangle, calc_perimeter_rectangle, calc_area_rectangle },
    { "Triangle",   prompt_for_triangle, calc_perimeter_triangle, calc_area_triangle },
};

int main()
{
    struct shape shape;
    struct formula &formula = formulas[st_circle];

    formula.prompt_f(shape);
    cout << "Perimeter: " << formula.calc_perimeter_f(shape) << endl;
    cout << "Area: " << formula.calc_area_f(shape) << endl;
}
```

		
## 实用技巧

### 编程的中层境界：解耦数据和代码

- 使用恰当的数据结构来表达现实中的事物和对象，可以让程序的逻辑结构更加清晰，也能获得更好的运行性能。
- 在编程中，将立即数、字符串字面值等数据混合在代码中，不利于代码的维护，也容易引入缺陷（bug）。
- 将数据和代码解耦将获得意想不到的好处。

	
- 使用数组定义单元测试用例

```cpp
    /* 原始代码
    assert(check_prime(2));
    assert(check_prime(3));
    assert(!check_prime(4));
    assert(check_prime(5));
    assert(!check_prime(9));
    assert(check_prime(1973));
    assert(check_prime(2024));
    */

    // 将数据和代码解耦
    static struct test_case {
        int     n;
        bool    expected;
    } cases = {
        {2, true},
        {3, true},
        {4, talse},
        {5, true},
        {9, false},
        {1973, true},
        {2024, false},
    };

    for (size_t i = 0; i < sizeof(cases)/sizeof(cases[0]); i++) {
        bool result = check_prime(cases[i].n);
        assert(result == cases[i].expected);
    }
```

		
## 作业

1) 杨辉三角是一个由数字排列成的三角形表。编写一个程序，输入一个正整数 `n`，表示杨慧三角的行数，输出对应的杨辉三角。运行效果如下：

```console
$ ./yanghui-triangle
<5>
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
```

	
2) 求解给定的线性同余方程组，要求给出至少十个解。运行效果如下：

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

	
3) 给定任意正整数，给出其所有质因子（重复的质因子只保留一个）。运行效果如下：

```console
$ ./prime-factors
<12>
12: 2 3
$ ./prime-factors
<11>
1: 11
```

	
4) 判定形如 `ax + by = d` 的不定方程是否有整数解，若有，用二维数组保存 10 个解，并验证是否满足该不定方程。运行效果如下：

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

	
5) 使用结构体定义一个二维几何形状（三角形、正方形、圆），其中包含几何形状类型、名称、通过函数指针定义的初始化函数、周长和面积计算函数等，最终实现 `areas-refactored.cpp` 程序。运行效果如下：

```console
$ ./areas-refactored
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
- [乘法逆元](https://oi-wiki.org/math/number-theory/inverse/)
- [线性同余方程](https://oi-wiki.org/math/number-theory/linear-equation/)

