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

		
## 最简单的 C++ 程序

```cpp
// my first program in C++
#include <iostream>

int main()
{
    std::cout << "Hello World!";
}
```

1. 注释
1. 预处理指令和头文件
1. 空行。
1. `main()` 函数
1. 由一对花括号（brace）`{}` 定义的函数体。
1. C++ 语句。

	
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
    std::endl;                  // prints Hello World!
  std::cout
    << "I'm a C++ program."
    << std::endl;               // prints I'm a C++ program.
}
```

		
## 编译器和 C++ 程序的构建

	
### 课堂练习

		
## 整数、浮点数和四则运算表达式

	
### 课堂练习

		
## 函数的概念

	
### 课堂练习

		
## 标准库常用接口

	
### 课堂练习

		
## 参考链接

		
## 作业

