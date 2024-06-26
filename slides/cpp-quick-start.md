# C++ 快速入门

1. C++ 的发展历史及现状
1. 最简单的 C++ 程序
1. 编译器和 C++ 程序的构建
1. 整数、浮点数和四则运算表达式
1. 函数的概念
1. 标准库常用接口

		
## C++ 的发展历史及现状

- 1979 年，Bjarne Stroustrup 为 C 语言提供了类（class）的支持，四年后改名为 C++。
- C++ 是一种通用编程语言，支持多种编程范式，包括：
   1. 过程式编程（procedural programming，PP）
   1. 面向对象编程（object-oriented programming，OOP）
   1. 基于模板的泛型编程（generic programming，GP）
- C++ 继承了 C 的特色，可同时作为系统和应用编程语言，广泛应用于服务器软件、桌面应用、游戏、实时系统、高性能计算、嵌入式系统等领域。
- C++ 标准：
   1. 于 1998 年被接受为 ISO 标准，称为 `C++98`。
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
   - `std::cout` 对象
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

		
## 编译器和 C++ 程序的构建

- C/C++ 程序的构建（build）过程：
   1. 预处理（preprocess）。
   1. 编译（compile）。
   1. 链接（link）。
- Linux 上常用的 C++ 编译器：
   1. GCC（GNU Compiler Collection）
   1. Clang（Apple 主持的 C/C++/Objective C 编译器，基于 LLVM）
- LLVM（Low Level Virtual Machine）是一个使用 C++ 开发的编译器和工具链基础函数库，主要用于现代编程语言的编译器开发。

```console
# 安装 g++ 和 Clang
$ sudo apt install gcc g++ clang

# 编译单个 C++ 源文件
$ g++ -std=c++14 -Wall hello-world.cpp -o hello-world

# 或者
$ clang++ -std=c++14 -Wall hello-world.cpp -o hello-world
```

	
### 课堂演示

1. 录入 `Hello, world1` 程序并构建最终的可执行程序。
1. 将 `hello-world.cpp` 文件添加到 `plzs-homework` 仓库并推送到远程仓库。

	
### 课堂练习

十分钟内完成：

1. 手工键入 `Hello world!` 程序，命名为 `hello-world.cpp`，并保存在自己的 `plzs-homework` 仓库中（`source/cpp/lesson-1/` 目录下）。
1. 使用上面的命令行（可复制）编译成可执行程序并运行。
1. 运行正常后，将 `hello-world.cpp` 添加到 Git 仓库中进行管理，并推送到自己的远程 Gitee 仓库上。

	
### 问题探讨

1. C++ 源文件（source file）一定要具有 `cpp` 后缀吗？
1. `main()` 函数的返回值到底起什么作用，为何可以省略 `return 0` 语句？
1. C++ 中有没有类似 Python `print()` 的函数？

		
## 字符、整数、浮点数和四则运算表达式

	
### 课堂练习

		
## C++ 中的函数

	
### 课堂练习

		
## C++ 标准库和常用的接口

	
### 课堂练习

		
## C++ 和 Python 的异同

		
## 参考链接

		
## 作业

