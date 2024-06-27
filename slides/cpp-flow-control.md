# C++ 流程控制

1. 流程控制的来由
1. 布尔运算快速入门
1. C++ 的逻辑表达式和逻辑运算符
1. C++ 的流程控制语句
1. C++ 异常处理
1. 作业
1. 参考资料

		
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
1. C++ 中的布尔类型（`bool`）、真假值。
1. C++ 中用于比较数值的运算符（等于、不等于、大于、小于、大于等于、小于等于）。
1. C++ 中的逻辑运算符。

		
## C++ 的流程控制语句

1. 流程控制语句的分类：
   - 条件（condition）语句或分支（branch）
   - 循环（loop）语句
   - 异常处理

	
### 课堂演示

1. `if` 语句的用途和写法；`else` 分句。
1. `else if` 分句的来由。
1. `switch` 语句的用途和写法；`case` 分句。
1. `while` 语句的用途和写法。
1. `do-while` 语句的用途和写法。
1. `for` 语句的用途和写法。
1. `break` 语句和 `continue` 语句。

	
### 实例：`if` 语句

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
}

bool is_even_or_odd_1(int n)
{
    if (n % 2 == 0)
        return true
    elif (n % 2 == 1)
        return false
}

bool is_even_or_odd_2(int n)
{
    if (n % 2 == 0)
        return true;
    else:
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
        return false

    return true

bool is_even_or_odd_best(int n)
{
    return n & 0x01 == 0;
}

bool can_make_a_triangle(double d1, double d2, double d3)
{
    if (d1 <= 0 or d2 <= 0 or d3 <= 0) {
        return false;
    }
    else if ((d1 + d2) > d3) and ((d1 + d3) > d2) and ((d2 + d3) > d1) {
        return true;
    }

    return false;
}
```

	
### 实例：`switch` 语句

```cpp
string day_of_week(int weekday)
{
    switch (weekday) {
        case 0:
            return "Sunday"
        case 1:
            return "Monday"
        case 2:
            return "Tuesday"
        case 3:
            return "Wednesday"
        case 4:
            return "Thursday"
        case 5:
            return "Friday"
        case 6:
            return "Saturday"
        default:
            return "<Wrong Weekday Value>"
    }

    return "<NeverGetHere>";
}

bool is_prime_less_than_10(unsigned n)
{
    if (n < 2 || n > 10)
        return false;

    switch (n) {
        case 3:
        case 5:
        case 7:
            return true;
    }

    return false;
}
```

	
### 实例：`while` 或 `for` 循环

```cpp
void list_even_numbers_less_than_v0(unsigned n)
{
    int a = 0;
    while (a < n) {
        if a % 2 == 0:
            cout << a << endl;
        a = a + 1;
    }
}

void list_even_numbers_less_than_v1(unsigned n)
{
    int a = 0
    bool flag = true;
    while (true) {
        if (a >= n)
            break;

        if flag:
            cout << a << endl;

        a = a + 1;
        flag = !flag;
    }
}

void list_even_numbers_less_than_v2(unsigned n)
{
    for (int i = 0; i < n; i += 2 {
        cout << a << endl;
    }
}

void list_even_numbers_less_than_v3(unsigned n)
{
    n /= 2;
    for (int i = 0; i < n; i++) {
        cout << i * 2 << endl;
    }
}

void list_even_numbers_less_than_v4(unsigned n)
{
    n >>= 1;
    for (int i = 0; i < n; i++) {
        cout << (i << 1) << endl;
    }
}
```

	
### 浮点数比较陷阱！

- 试试逻辑表达式：`0.1 + 0.2 == 0.3`

```cpp
#include <cstdint>

// 直接对比浮点数会得到不正确的结果
bool can_make_a_triangle_bad(double d1, double d2, double d3)
{
    if (d1 <= 0 or d2 <= 0 or d3 <= 0)
        return false;
    else if ((d1 + d2) > d3) and ((d1 + d3) > d2) and ((d2 + d3) > d1)
        return true;
    else
        return false;
}

// 折中方案
bool can_make_a_triangle_workaround(double d1, doubled2, double d3)
{
    if (d1 > UINT32_MAX or d2 > UINT32_MAX or d3 > UINT32_MAX) {
        return false;
    }

    if (d1 <= 0 or d2 <= 0 or d3 <= 0)
        return false;

    uint64_t ull1 = uint64_t(d1 * UINT32_MAX);
    uint64_t ull2 = uint64_t(d2 * UINT32_MAX);
    uint64_t ull3 = uint64_t(d3 * UINT32_MAX);

    if ((ull1 + ull2) > ull3) and ((ull1 + ull3) > ull2) and
            ((ull2 + ull3) > ull1)
        return true;
    else:
        return false;
}
```

		
## 要点回顾

1. 布尔运算的基本概念。
1. C++ 的逻辑表达式和逻辑运算符。
1. C++ 的流程控制语句。
1. 浮点数对比陷阱。

		
## 作业

1) 输出小于指定正整数的斐波那契（Fibonacci）数列。运行效果如下：

```console
$ ./fibonacci
<11>
1, 1, 2, 3, 5, 8.
```

	
2) 用辗转相除法求两个正整数的最大公约数以及最小公倍数。运行效果如下：

```console
$ ./gcd-lcm
<11> <13>
1 143
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

		
## 参考链接


