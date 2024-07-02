# C++ 快速入门

1. C++ 的发展历史及现状
1. 最简单的 C++ 程序
1. C++ 编译器和 C++ 程序的构建
1. 变量、数值和算术运算表达式
1. 二进制位运算
1. 函数、形参和实参
1. 基本输入输出
1. C++ 标准库和常用接口
1. C++ 和 Python 的异同
1. 作业

		
## C++ 的发展历史及现状

- 1979 年，Bjarne Stroustrup 为 C 语言提供了类（class）的支持，四年后改名为 C++。
- C++ 是一种通用编程语言，支持多种编程范式，包括：
   1. 过程式编程（procedural programming，PP）
   1. 面向对象编程（object-oriented programming，OOP）
   1. 基于模板的泛型编程（generic programming，GP）
- C++ 继承了 C 的特色，可同时作为系统和应用编程语言，广泛应用于服务器软件、桌面应用、游戏、实时系统、高性能计算、嵌入式系统等领域。
- C++ 标准：
   1. 于 1998 年被接纳为 ISO（国际标准化组织）标准，称为 `C++98`。
   1. 最新的 C++ 标准为 `C++20`（ISO/IEC 14882:2020）。
   1. 现阶段被业界广泛认可的标准为 `C++14`，而 `C++17` 刚开始被业界接纳。

	
<img class="r-frame" style="height:auto;width:100%;" src="assets/cpp-stroustrup.jpg" />

[Bjarne Stroustrup](https://stroustrup.com/bio.html)

		
## 最简单的 C++ 程序

```cpp
// my first program in C++
#include <iostream>

int main()
{
    std::cout << "Hello World!" << std::endl;
}
```

1. 注释
1. 预处理指令和头文件
1. 空行
1. `main()` 函数
1. 由一对花括号（brace）`{}` 定义的函数体
1. C++ 语句
   - `std::cout` 对象及命名空间。
   - `<<` 运算符
   - 字符串字面量（literal）
   - `std::endl` 常量

	
### 不同的写法

```cpp
#include <iostream>
int main () { std::cout << "Hello World!"; }
```

```cpp
/* my second program in C++
   with more comments */
#include <iostream>
int main ()
{
  std::cout <<
    "Hello World!" <<
    std::endl;                  // prints Hello World!\n
  std::cout
    << "I'm a C++ program."
    << std::endl;               // prints I'm a C++ program.\n
  return 0;                     // return 0 explicitly
}
```

		
## C++ 和 C 的关系

- C++ 的基本语法和基础数据类型来自 C。
- C++ 是 C 的超集，C++ 程序中可以直接调用 C 的接口。
- C++ 的功能丰富，演进快速；C 的特性稳定，更加简洁。

		
## 编译器和 C++ 程序的构建

- C/C++ 程序的构建（build）过程：
   1. 预处理（preprocess）。
   1. 编译（compile）。
   1. 链接（link）。
- Linux 上常用的 C++ 编译器（compiler）：
   1. GCC（GNU Compiler Collection）
   1. Clang（Apple 主持的 C/C++/Objective C 编译器，基于 LLVM）
- LLVM（Low Level Virtual Machine）是一个使用 C++ 开发的编译器和工具链（toolchain）基础函数库，主要用于现代编程语言的编译器开发。

```console
# 安装 g++ 和 Clang
$ sudo apt install gcc g++ clang

# 编译单个 C++ 源文件
$ g++ -std=c++14 -Wall hello-world.cpp -o hello-world

# 或者
$ clang++ -std=c++14 -Wall hello-world.cpp -o hello-world
```

	
### 课堂演示

1. 录入 `Hello, world!` 程序并构建最终的可执行程序。
1. 常见编译错误及处理。
1. 将 `hello-world.cpp` 文件添加到 `plzs-homework` 仓库并推送到远程仓库。
1. 查看源文件在经过预处理之后的源代码。

	
### 课堂练习

（十分钟内完成）

1. 手工键入 `Hello world!` 程序，命名为 `hello-world.cpp`，并保存在自己的 `plzs-homework` 仓库中（`source/cpp/lesson-1/` 目录下）。
1. 使用上面的命令行（可复制）编译成可执行程序并运行。
1. 运行正常后，将 `hello-world.cpp` 添加到 Git 仓库中进行管理，并推送到自己的远程 Gitee 仓库上。

	
### 问题探讨

1. C++ 源文件（source file）一定要具有 `cpp` 后缀吗？
1. `main()` 函数的返回值到底起什么作用，为何可以省略 `return 0` 语句？
1. C++ 中有没有类似 Python 的 `print()` 函数？

		
## 变量、数值和算术运算表达式

- C++ 是一种强类型编程语言，所有的变量、函数参数及函数返回值均需要事先声明（declare）其类型。
- C++ 中常用于表示数值的基本数据类型：
   1. 字符（`char`）、无符号字符（`unsigned char`）
   1. 短整数（`short`）、无符号短整数（`unsigned short`）
   1. 整数（`int`）、无符号整数（`unsigned int`）
   1. 长整数（`long`）、无符号长整数（`unsigned long`）
   1. 长长整数（`long long`）、无符号长长整数（`unsigned long long`）
   1. 浮点数（`float`）
   1. 双精度浮点数（`double`）
   1. 长双精度浮点数（`long double`）

	
- 使用 `auto` 关键词可自动推导数据类型。
- 使用 `decltype` 运算符可获得特定变量的类型。
- `sizeof` 运算符可用于计算常量、字符串字面量、变量的尺寸（字节数）。

	
### 变量的声明及初始化

1. 声明变量类型并给变量一个名称（标识符）。
1. 使用赋值语句初始化变量；或者，
1. 使用 `std::cin` 的 `>>` 运算符从用户输入中转换。

```cpp
#include <iostream>

int main()
{
    int a = 10, b;

    std::cout << "Please input an integer: ";
    std::cin >> b;

    auto sum = a + b;
    std::cout << "Th summary of `" << a << "` and `" << b << "` is `" << sum << "`." << std::endl;
    std::cout << "The size of `" << sum << "` is `" << sizeof(sum) << "`." << std::endl;
}
```

	
### C++ 特有的初始化方法

1. 构造器（constructor）初始化
1. 统一（uniform）初始化

```cpp
    int c (10);     // constructor initialization.
    int d {10};     // uniform initialization.
```

	
### 常量：字符

```cpp
    char ch;
    unsigned char uch;

    ch = 'a';       // 字符字面量
    ch = 0x20;      // 直接使用整数常量初始化字符变量
    ch = '\xFF';    // 十六进制
    ch = '\024';    // 八进制，一到三个小于 8 的数字组成，很少用到

    uch = '\xFF';   // 十六进制
    uch = '\124';   // 八进制，一到三个小于 8 的数字组成，很少用到
```

	
### 常量：整数

```cpp
    int i = 100;
    unsigned int u;

    u = 100;                        // 十进制
    u = 0124;                       // 0 作为前缀，八进制
    u = 0x80000000U;                // 0x 作为前缀，十六进制
    u = (unsigned int)-1;           // 0xFFFFFFFF
    u = (unsigned int)-2;           // 0xFFFFFFFE

    long l = 0x80000000L;           // 后缀：l/L
    unsigned ul = 0x80000000UL;     // 后缀：U、L，顺序和大小写无关

    long long ll = 0x8000000000000000LL;
    unsinged long long ull = 0x8000000000000000ULL;
```

	
### 常量：浮点数

```cpp
    float f1 = 0.1F;
    double f2 = 0.1;                // 没有后缀！
    double f3 = 2.99E10;            // 科学记数法
    long double f4 = 0.1L;
```

	
### 字符串字面量及 `string` 类

```cpp
#include <iostream>
#include <string>

using namespace std;

int main ()
{
    string mystring ("This is a string");
    cout << mystring << endl;
    return 0;
}
```

1. 默认使用 `std` 命名空间：  
`using namespace std;`
1. 不再添加名字空间前缀：  
`cout << mystring << endl;`
1. 用双引号定义字符串字面量：  
`"This is a string"`
1. 使用构造器初始化 `string` 类：  
`string mystring ("This is a string");`

	
### 算术运算表达式

- 算术运算符
   1. `a + b`：求 `a` 和 `b` 的和。
   1. `a += b`：求左值（lvalue） `a` 和右值（rvalue）`b` 的和并赋值给左值（lvalue ）`a`。
   1. `a++`：相当于 `a += 1`。
   1. `a - b`：求 `a` 和 `b` 的差。
   1. `a -= b`：求左值 `a` 和右值 `b` 的和并赋值给左值 `a`。
   1. `a --`：相当于 `a -= 1`。
   1. `a * b`：求 `a` 和 `b` 的积。
   1. `a *= b`：求左值 `a` 和右值 `b` 的积并赋值给左值`a`。
   1. `a / b`：求 `a` 和 `b` 的商（整数的商始终为整数）。
   1. `a /= b`：求左值 `a` 和右值 `b` 的商并赋值给左值 `a`。
   1. `a % b`：求 `a` 被 `b` 除时的余数（取模）。
   1. `a %= b`：求 `a` 被 `b` 除时的余数（取模）并赋值给左值 `a`。

	
- 二进制位运算符
   1. 位与：`&`
   1. 位与并赋值：`&=`
   1. 位或：`|`
   1. 位或并赋值：`|=`
   1. 位非：`~`
   1. 位亦或：`^`
   1. 位亦或并赋值：`^=`
   1. 右移：`<<`
   1. 左移：`>>`
   1. 右移并赋值：`<<=`
   1. 左移并赋值：`>>=`

	
### 优先级及类型转换

- 算术运算中的优先级。
- 使用小括号指定算术运算的优先级。
- 混合运算中的隐式类型转换。
- 除数为零时会产生被零除错误。

	
### C/C++ 的取模规则

从 C99 和 C++11 起，规定商向零取整（舍弃小数部分），取模的符号与被除数相同（注意和数学上的取模定义不同）：

```cpp
5 % 3 == 2;
5 % -3 == 2;
-5 % 3 == -2;
-5 % -3 == -2;
```

	
### 课堂练习

（十分钟内完成）

1. 试试对浮点数执行 `++` 运算、零作为除数时的编译和执行效果。
1. 编写计算圆面积的程序 `circle-area.cpp`。该程序接受一个用户输入的浮点数或整数作为半径，计算对应的圆面积，然后输出计算结果。
1. 编译成可执行程序并运行。
1. 测试正常后，将 `circle-area.cpp` 添加到 Git 仓库中进行管理，并推送到自己的远程 Gitee 仓库上。

		
## 函数、形参及实参

- 函数返回值、参数等均应定义明确的数据类型。
- 可定义形参的默认值。
- 函数的签名由函数返回值类型、函数名称、各参数的类型构成；故而可定义同名但参数类型不同的函数，编译器将根据调用时的参数类型确定具体调用哪个函数。
- 在使用函数前，应首先通过包含头文件或者给出函数签名来声明函数的原型。
- 在 C++ 中调用 C 函数，应使用前缀 `::`，用于指定全局命名空间。
- 全局变量、静态变量以及局部变量。

	
### 实例

```cpp
#include <iostream>

using namespace std;

int rounded_addition(int a, int b = 0)
{
    int r;
    r = a + b;
    return r;
}

int rounded_addition(double a, double b = 0)
{
    return (int)(a + 0.5) + (int)(b + 0.5);
}

int main()
{
    auto rz = rounded_addition(5, 3);
    cout << "The result is " << rz << endl;

    auto rf = rounded_addition(5.4, (double)3.6);
    cout << "The result is " << rf << endl;
}
```

	
### 课堂练习

（十分钟内完成）

1. 将 `circle-area.cpp` 改造为调用函数 `calc_circle_area()` 函数的形式。
1. 编译成可执行程序并运行。
1. 测试正常后，将 `circle-area.cpp` 的改进版提交到 Git 仓库，并推送到自己的远程 Gitee 仓库上。

		
## 基本输入输出

- `std::cout`：标准输出，默认为屏幕（终端）。

```cpp
using namespace std;
...

int x = 230;

cout << "Hello, world!";    // prints `Hello, world!` on screen
cout << 120;                // prints number 120 on screen
cout << x;                  // prints the value of x on screen 

cout << "First sentence." << endl;
cout << "Second sentence." << endl;

cout << "First sentence.\n" << "Second sentence.\n";
```

	
- `cin`：标准输入，默认为键盘。

```cpp
int age;
cin >> age;

double a, b;
cin >> a >> b;

string mystring;
cin >> mystring;
```

		
## C++ 标准库和常用接口

- C++ 标准库分为如下几个组成部分：
   1. C 标准函数库。
   1. 容器模板类库（如数组、矢量、列表、栈、队列、集合、映射等）。
   1. 输入输出库，提供基于流的文件读写、控制台输入输出功能。
   1. 多线程支持。
   1. 其他（如算法、时间、复数、异常处理等）。
- C++ 通过模板类实现了绝大部分常用的数据结构和算法，并使这些实现和具体的类型无关（泛型）。
- C++ 标准模板库简称为 STL（Standard Template Library）。

	
### 常用 C 标准函数库接口

1. 格式化输入输出：`<cstdio> (stdio.h)`，执行格式化输入及输出的 C 函数接口，如 `printf()` 和 `scanf()` 函数。
1. 通用工具：`<cstdlib> (stdlib.h)`，C 标准通用函数，如字符串转换 `atoi()` 等。
1. 字符串操作：`<cstring> (string.h)`，C 字符串函数，如 `strcmp()` 等。
1. 时间操作：`<ctime> (time.h)`，C 时间操作及转换函数，如 `time()` 等。
1. 数学库：`<cmath> (math.h)`，包含了常用的数学常量（圆周率、自然常数等）以及常用的数学函数（三角函数、双曲线函数、指数和对数函数、幂次及求根函数等），如 `sin()`、`power()` 和 `sqrt()` 等。

	
### 课堂演示

1. 使用 C 数学函数计算给定数值的平方根。

	
### 课堂练习

（十分钟内完成）

1. 复制文件为 `circle-area.cpp` 为 `square-area.cpp`。
1. 修改其中的 `calc_circle_area()` 函数为 `calc_square_area()` 函数，并调用 `<cmath>` 中的 `power()` 函数计算正方形面积。
1. 编译成可执行程序并运行。
1. 测试正常后，将 `square-area.cpp` 的改进版提交到 Git 仓库，并推送到自己的远程 Gitee 仓库上。

		
## C++ 和 Python 的异同

1. C++ 程序需要经过编译和链接构建成可执行程序后才能运行，而 Python 程序可直接运行；C++ 程序的执行效率远高于 Python。
1. C++ 程序的入口函数为 `main()`，而Python 从程序的第一行开始顺序执行。
1. C++ 是强类型语言，变量的类型一经确定就无法改变，而 Python 是弱类型语言，变量的类型在初始化时决定且可随时改变。
1. Python 3 的整型数据是无限精度的，而 C++ 的整型数据的精度是有限的；在 C++ 代码中，要特别注意整型计算的溢出问题。
1. Python 和 C++ 中的浮点数本质上事一样的，C++ 提供了不同精度的浮点数类型供应用程序选择，Python 始终使用双精度浮点数。
1. Python 中进行浮点数计算的功能由解释器调用 C 的函数实现，C++ 中可直接调用 C 函数。

		
## 作业

1) 编写一个 C++ 程序，该程序可计算给定无符号长长整数对质数 `2^31 - 1` 的模。要求使用 Vim 编辑源文件，使用命令行编译。运行效果如下所示：

```console
% ./ull-mode
<100000000000000000000>
3
```

2) 编写一个 C++ 程序，该程序可计算正方形、圆和三角形（使用海伦公式）的面积。程序提示用户输入需要的参数，调用相应的函数计算并打印对应的结果。要求使用 Vim 编辑源文件，使用命令行编译。运行效果如下所示：

```console
$ ./areas
To calculate the area of a square, please input the length of one side: <11>
area_of_square(11): 121.000000
To calculate the area of a circle, please input the length of the radio: <10>
area_of_circle(10): 31.415926.
To calculate the area of a triangle, please input the lengthes of three sides (separated with space): <3> <4> <5>
area_of_triangle(3, 4, 5): 6.000000
```

	
### 参考链接

1. [海伦公式](https://www.cnblogs.com/jiahuafu/p/4596962.html)
1. [大质数表](https://www.cnblogs.com/ljxtt/p/13514346.html)
1. [C++标准库参考](https://cplusplus.com/reference/)

	
### 作业回顾

- 为常用常量定义一个宏可防止键入错误，同时提高代码的可读性。

```cpp
#define PI 3.14159265

...
    area = PI * r * r;
```

- 或者使用 `const` 修饰词（modifier）定义一个变量作为常量（通常为全局变量）。

```cpp
const double pi = 3.14159265;

...
    area = pi * r * r;
```

	
- 

