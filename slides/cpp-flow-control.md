# C++ 流程控制

1. 流程控制的来由
1. 布尔运算快速入门
1. C++ 的逻辑表达式和逻辑运算符
1. C++ 的流程控制语句
1. 函数的递归调用
1. 作业

		
## 流程控制的来由

1. 现实中存在很多逻辑判断：
   - 判断用户输入的合法性。
   - 判断三条线段是否可以构成三角形。
1. 计算机最擅长执行重复性工作。
   - 人生就是一天一天重复吃饭、干活/学习、睡觉。
   - 计算机的重复方法：重复执行一个程序；程序中重复执行某段代码。
   - 优秀的程序员始终追求最大程度重复利用已有的代码；爱炫耀的程序员喜欢写一些软件包给别人使用：开源的原动力。
1. 所有的编程语言都支持流程控制（flow-control）；流程控制建立在逻辑判断的基础之上。

		
## 布尔逻辑运算快速入门

1. 布尔代数是计算机底层技术的数学基石（二进制）。
1. 英国数学家 George Boole 在其著作《逻辑的数学分析》中首次系统阐述了“布尔代数”，揭示了逻辑运算及其规律。
1. 用于表示命题（proposition）真假的值称为布尔值，只有两种取值：真（true）、假（false）。
1. 我们对布尔值可以执行三种基本的运算，称为“逻辑运算”：与（and）、或（or）、非（not）。

	
### 逻辑运算及其定律

1. 计算机科学文献或者文档中，通常用 `|` 表示“或”，`&` 表示“与”，`!` 表示“非”，`0` 表示假，`1` 表示真。
1. 基本运算（真值表）

	
<img class="r-frame" style="height:auto;width:100%;" src="assets/plzs-true-values-table.svg" />

	
1) 互补律
   - `!!A = A`
   - `A & !A = 0`
   - `A | !A = 1`

	
2) 重言律：别说废话
   - `A & A = A`
   - `A | A = A`
   - `A & 1 = A`
   - `A | 1 = 1`
   - `A & 0 = 0`
   - `A | 0 = A`

	
3) 交换律和结合律：很像算术加法和乘法
   - `A & B = B & A`
   - `A | B = B | A`
   - `(A & B) & C = A & (B & C)`
   - `(A | B) | C = A | (B | C)`

	
4) 吸收律：B 没啥存在感
   - `A & (A | B) = A`
   - `A | (A & B) = A`

	
5) 程序中使用较多的
   - `!(A & B) = !A | !B`
   - `!(A | B) = !A & !B`

		
## C++ 的逻辑表达式和逻辑运算符

1. 计算机程序中的命题来自哪里？算术表达式的值、数值比较的结果、逻辑表达式、函数的返回值等等。
1. C++ 中的布尔类型（`bool`）、真值（`true`）、假值（`false`）。
1. C++ 中用于比较数值的运算符：
   - 等于（`==`）
   - 不等于（`!=`）
   - 大于（`>`）
   - 小于（`<`）
   - 大于或等于（`>=`）
   - 小于或等于（`<=`）
1. C++ 中的逻辑运算符：
   - 逻辑与：`&&` 或 `and`
   - 逻辑或：`||` 或 `or`
   - 逻辑非：`!` 或 `not`

	
### 判断逻辑表达式的真假

```cpp
int a = 2, b = 3, c = 6;

(a == 5)
(a*b >= c)
(b+4 > a*c)
((b=2) == a)

!(c == 6)
!(a <= 4)
!true
!false

((a == 2) && (c > b))
((a == 3) || (b > c))
```

		
## C++ 的流程控制语句

1. 流程控制语句的分类：
   - 条件（condition）语句或分支（branch）
   - 循环（loop）语句
   - 异常处理

	
### 实例分析

1. `if` 语句的用途和写法；`else` 分句。
1. `switch` 语句的用途和写法；`case` 分句。
1. `while` 语句的用途和写法。
1. `do-while` 语句的用途和写法。
1. `for` 语句的用途和写法。
1. `break` 语句和 `continue` 语句。

	
### `if` 语句

```cpp
bool is_even_or_odd_0(int n)
{
    if (n % 2 == 0)
        return true;
    else {
        if (n % 2 == 1) {
            return false;
        }
    }

    return false;
}

bool is_even_or_odd_1(int n)
{
    if (n % 2 == 0)
        return true;
    else if (n % 2 == 1)
        return false;

    return false;
}

bool is_even_or_odd_2(int n)
{
    if (n % 2 == 0)
        return true;
    else
        return false;
}

bool is_even_or_odd_3(int n)
{
    if (n % 2 == 0)
        return true;

    return false;
}

bool is_even_or_odd_4(int n)
{
    if (n % 2)
        return false;

    return true;
}

bool is_even_or_odd_best(int n)
{
    return (n & 0x01) == 0;
}

bool can_make_a_triangle(int d1, int d2, int d3)
{
    if (d1 <= 0 or d2 <= 0 or d3 <= 0) {
        return false;
    }
    else if (((d1 + d2) > d3) and ((d1 + d3) > d2) and ((d2 + d3) > d1)) {
        return true;
    }

    return false;
}
```

	
### `switch` 语句

```cpp
using namespace std;

string day_of_week(int weekday)
{
    switch (weekday) {
        case 0:
            return "Sunday";
        case 1:
            return "Monday";
        case 2:
            return "Tuesday";
        case 3:
            return "Wednesday";
        case 4:
            return "Thursday";
        case 5:
            return "Friday";
        case 6:
            return "Saturday";
        default:
            return "<Wrong Weekday Value>";
    }

    return "<NeverGetHere>";
}

bool is_prime_less_than_10(unsigned n)
{
    if (n < 2 || n > 10)
        return false;

    switch (n) {
    case 2:
    case 3:
    case 5:
    case 7:
        return true;
    }

    return false;
}
```

	
### `while` 或 `for` 循环

```cpp
void list_even_numbers_less_than_v0(unsigned n)
{
    unsigned a = 0;
    while (a < n) {
        if ((a % 2) == 0)
            cout << a << " ";
        a = a + 1;
    }

    cout << endl;
}

void list_even_numbers_less_than_v1(unsigned n)
{
    unsigned a = 0;
    bool flag = true;
    while (true) {
        if (a >= n)
            break;

        if (flag)
            cout << a << " ";

        a = a + 1;
        flag = !flag;
    }

    cout << endl;
}

void list_even_numbers_less_than_v2(unsigned n)
{
    unsigned a = 0;
    do {
        if ((a & 0x01) == 0)
            cout << a << " ";
    } while (++a < n);

    cout << endl;
}

void list_even_numbers_less_than_v3(unsigned n)
{
    for (unsigned i = 0; i < n; i += 2) {
        cout << i << " ";
    }

    cout << endl;
}

void list_even_numbers_less_than_v4(unsigned n)
{
    n /= 2;
    for (unsigned i = 0; i < n; i++) {
        cout << i * 2 << " ";
    }

    cout << endl;
}

void list_even_numbers_less_than_v5(unsigned n)
{
    n >>= 1;
    for (unsigned i = 0; i < n; i++) {
        cout << (i << 1) << " ";
    }

    cout << endl;
}
```

	
### 课堂练习

（十分钟内完成）

1. 编写程序判断给定的三个浮点数是否可以构成一个三角形；命名为 `can-make-a-triangle.cpp`，并保存在自己的 `plzs-homework` 仓库中（`source/cpp/lesson-2/` 目录下）。
1. 使用上面的命令行（可复制）编译成可执行程序并运行。
1. 运行正常后，将 `can-make-a-triangle.cpp` 添加到 Git 仓库中进行管理，并推送到自己的远程 Gitee 仓库上。

	
### 浮点数比较陷阱

- 对上面的程序，试试三个值：`0.1 0.2 0.3`

```cpp
bool can_make_a_triangle_bad(double d1, double d2, double d3)
{
    if (d1 <= 0 or d2 <= 0 or d3 <= 0) {
        return false;
    }
    else if (((d1 + d2) > d3) and ((d1 + d3) > d2) and ((d2 + d3) > d1)) {
        return true;
    }

    return false;
}
```

	
折中方案

1. 将浮点数比较转换为为整数比较。
1. 使用 `<cstdint>` 头文件中定义的 `uint64_t` 类型以及 `UINT32_MAX` 等常量宏。

```cpp
#include <cstdint>

bool can_make_a_triangle_workaround(double d1, double d2, double d3)
{
    if (d1 > UINT32_MAX or d2 > UINT32_MAX or d3 > UINT32_MAX) {
        return false;
    }

    if (d1 <= 0 or d2 <= 0 or d3 <= 0)
        return false;

    uint64_t ull1 = uint64_t(d1 * UINT32_MAX);
    uint64_t ull2 = uint64_t(d2 * UINT32_MAX);
    uint64_t ull3 = uint64_t(d3 * UINT32_MAX);

    if (((ull1 + ull2) > ull3) and ((ull1 + ull3) > ull2) and
            ((ull2 + ull3) > ull1))
        return true;

    return false;
}
```

		
## 函数的递归调用

- 数学上的很多计算满足递推（recurrence）公式。
- 如求解某个数值的正整数次幂：
   1. `P(n) = n * P(n - 1)`；
   1. 当 n 为 0 时递推终止：`P(0) = 1`。
- 类似的还有阶乘：
   1. `n! = n * (n - 1)!`；
   1. 当 n 为 0 时递推终止：`0! = 1`。
- 故而我们可以编写调用自己的函数，也就是递归（recursively）调用。

	
整数次幂函数的递归实现：

```cpp
double power(double f, unsigned n)
{
    double r;

    if (n == 0)
        r = 1.0;
    else
        r = f * power(f, n - 1);

    return r;
}
```

	
### 课堂练习

（十分钟内完成）

1. 递归实现阶乘程序，命名为 `factorial-recursively.cpp`，并保存在自己的 `plzs-homework` 仓库中（`source/cpp/lesson-2/` 目录下）。
1. 使用上面的命令行（可复制）编译成可执行程序并运行。
1. 运行正常后，将 `factorial-recursively.cpp` 添加到 Git 仓库中进行管理，并推送到自己的远程 Gitee 仓库上。

		
## 要点回顾

1. 布尔运算的基本概念。
1. C++ 布尔类型及运算符。
1. C++ 的逻辑表达式和逻辑运算符。
1. C++ 的流程控制语句。
1. 函数的递归调用。

		
## 作业

1) 输出小于指定正整数的斐波那契（Fibonacci）数列。运行效果如下：

```console
$ ./fibonacci
<11>
1, 1, 2, 3, 5, 8.
```

1) 使用递归输出小于指定正整数的斐波那契（Fibonacci）数列。运行效果如下：

```console
$ ./fibonacci-recursively
<11>
1, 1, 2, 3, 5, 8.
```

	
2) 用辗转相除法求两个正整数的最大公约数以及最小公倍数。运行效果如下：

```console
$ ./gcd-lcm
<11 13>
1 143
$ ./gcd-lcm
<12 15>
3 60
```

	
3) 判断给定正整数是否为一个质数。运行效果如下：

```console
$ ./check-prime
<11>
True
$ ./check-prime
<12>
False
```

	
4) 判定形如 `ax + by = d` 的不定方程是否有整数解，若有，给出至少十个解。运行效果如下：

```console
$ ./bezout
<23 7 1>
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

	
### 参考链接

- [信奥生的数学素养课第二讲“数系上的运算和进制”]()
- [信奥生的数学素养课第三讲“数论基础：整数的性质”]()
- [信奥生的数学素养课第四讲“质数的有趣性质及初等数论四大定理”]()
- [信奥生的数学素养课第五、六讲“初等数论主要定理及应用”]()

		
## 作业回顾

### 使用 `Makefile` 方便构建 C++ 程序的构建

```makefile
TARGETS = can-make-a-triangle power-recursively

CXXFLAGS = -Wall -Wextra -Werror -O2 -g -std=c++14

ifeq ($(CXX), g++)
    CXXFLAGS += -fmax-errors=10
else ifeq ($(CXX), clang++)
    CXXFLAGS += -ferror-limit=10
endif

all:$(TARGETS)

$(TARGETS):%:%.o
	$(CXX) -o $@ $<

%.o:%.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@

.PHONY: clean

clean:
	rm -f *.o $(TARGETS)
```

	
### 巧用 `assert()` 函数协助调试

- 使用 `<cassert>` 中定义的宏 `assert()` 可在参数的求值（evaluate）结果为非真时终止（abort）程序的运行，方便调试。

```cpp
#include <iostream>
#include <cassert>

using namespace std;

double power(double f, unsigned n)
{
    double r;

    if (n == 0)
        r = 1.0;
    else
        r = f * power(f, n - 1);

    return r;
}


int main()
{
    assert(power(3, 2) == 9);
}
```

