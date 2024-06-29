# C++ 数据类型

1. C++ 基础数据类型
1. 数组、字符串和指针
1. 枚举量
1. 结构体
1. 内存的动态分配及释放
1. 函数调用中的数组、指针和引用
1. 深入理解递归调用
1. 作业

		
## C++ 基础数据类型

1) 数据类型（data type）：编程语言用来表达（represent）现实世界中不同种类数据的方法。
2) 我们已经接触过若干种 C++ 基础数据类型：
   - 布尔型（`bool`）
   - 字符型（`char`）
   - 各种长度/有无符号的整型（`int`）
   - 三种精度的浮点数（`float`）
3) 本质上，所有的 C++ 基础数据类型为单字节、双字节、四字节、八字节的二进制数据。

	
### 字符

- C++ 字符类型（`char`）来自 C 语言，主要用于表达 ASCII 字符，本质上是单字节数值，取值范围 `-127 ~ 128`。
- 命令 `man ascii` 可获得 ASCII 字符的定义；ASCII 码的取值范围：0x00 ~ 0x7F。

	
- 字符的分类：
   - 数字（digit）：`'0 ~ '9'`；
   - 字母（alphabetic character）：`'A' ~ 'Z'`（upper letters）和 `'a' ~ 'z'`（lower letters）；
   - 空格（blank character）：`' ', '\t'`；
   - 空白（white-space character）：`' ', '\t', '\f', '\n', '\r', '\t', '\v'`；
   - 控制字符（control character）：大于等于 0x00，小于 0x20 的字符，如 `\0`、`\n`、`\r`、`\t`、`\f` 等；
   - 可打印字符（printable character）：包括空白字符在内的所有可显示在屏幕上的字符；
   - 标点字符（punctuation）：除了字母、数字、空白之外的可打印字符，如 `,`、`.` 等。

	
- 使用 `<cctype>` 中定义的接口，可判断字符类型：
   1. `isascii()`：是否合法的 ASCII 字符。
   1. `isalnum()`：是否为字母数字。
   1. `isalpha()`：是否为字母。
   1. `isdigit()`：是否为数字。
   1. `isblank()`：是否为空格。
   1. `islower()`：是否为小写字母。
   1. `isupper()`：是否为大写字母。
   1. `isxdigit()`：是否为十六进制数字（数字及 `'a ~ 'f'` 或 `'A' ~ 'F'`）。
   1. ...

```cpp
#include <cctype>
#include <cassert>

...

    char digit = '0';
    assert(isdigit(digit));
```

	
- 字符的常见运算

```cpp
    char digit = '0';       // '0'
    digit += '5' - '0';     // digit now is '5'

    char letter = 0x42;     // letter now is 'B';
    letter += 'a' - 'A';    // letter now is 'b';

    letter -= 'a';          // letter now is `\x01'
    letter += 2;            // letter now is '\x03'
    letter %= 26;           // letter now is '\x03'
    letter += 'a';          // letter now is 'c'
```

	
- `unsigned char`：本质上是一个单字节非负整数，表达范围 0 ~ 255。
- 要谨防运算溢出。

```cpp
#include <cctype>
#include <cassert>

...

    unsigned char uc = 0;
    for (; uc < 256; uc++) {
        // dead loop
    }
```

	
### 布尔值

1. 计算机程序中的数值（number）用来表达数学上的数值。
1. 在 C++ 中布尔值被视作等同于整数；算术表达式中使用布尔值时，`false` 等同于 0，`true` 等同于 1。
1. 我们直接输入到代码中的数值称为立即数（immediate value）；所有带有小数点的立即数被视作浮点数。
1. 可以用类似科学计数法的方式书写一个立即数：`1E10` 或者 `33E2`，此时该立即数始终是浮点数。

		
## 数组、字符串和指针

- C++ 中的数组（array）用来表达可使用索引（index）值引用的一组有序（ordered）数据。
- 数组中的一个项（item）也会被称为一个单元（unit）或一个成员（member）。
- 在其他编程语言中，可能使用列表（list）这一术语（term）。
- 字符串本质上是由多个字符构成的数组。
- 指针用于指代某个数据在进程地址空间中的地址值，本质上是一个无符号整数。

	
### 数组

1. C++ 中的数组使用成对出现的中括号（square brackets，`[]`）定义。
1. 一旦初始化，C++ 数组的长度（单元个数）就是固定的。
1. C++ 数组中的数据项具有相同的数据类型。
1. 初始化数组时，使用 `[]` 包围数组单元，各个单元之间使用逗号（comma，`,`）分隔。

	
### 字符串

- 计算机程序中的字符串主要用来表达构成自然语言的文本或者文本片段。
- 字符串字面值（literal）的概念。
- C/C++ 的字符串字面值使用成对出现的双引号（double-quote，`""`）定义。
- 转义（escape）字符：
   1. 如果文本本身包含双引号（`"`）怎么办？
   1. 如果文本中需要包含一些特殊字符，如换行符、回车符怎么办？
- C/C++ 字符串字面值本质上是不可更改的字符数组。

	
#### C 字符串

- C 字符串本质上是一个字符数组。
- C 字符串的尾部始终包含一个空字符（`\0`）表示字符串的结尾。

```cpp
```

	
#### C++ 标准库字符串

- C++ 标准库定义的字符串是一个类（`string`），可通过 C 字符串来初始化。
- `string` 类的实例是可动态修改的，其长度可变化。
- 通过 `string` 类的 `.c_str()` 方法，可将 `string` 类对象转换为 C 字符串进行只读访问。

	
### 指针

		
## 结构体

1. C++ 程序中的结构体（struct）通常用来表达具有多重属性的复杂对象，比如一名学生的学号、姓名、性别、生日、身高、体重等。

```console
struct type_name {
    member_type1 member_name1;
    member_type2 member_name2;
    member_type3 member_name3;
    ...
} object_name;
```

如，

```cpp
struct student {
    string  id;
    string  name;
    string  birthday;
    bool    gender;
    int     height;
    float   weight;
};

struct student s1 { "20240101", "Amy", "2010-09-03", false, 160, 50.3f };
```

		
## 其他数据类型

	
### 联合体

```
union type_name {
    member_type1 member_name1;
    member_type2 member_name2;
    member_type3 member_name3;
    ...
} object_name;
```

	
### 枚举量

```
enum type_name {
  value1,
  value2,
  value3,
  .
  .
} object_names;
```

	
### 类型别名

- 使用 `typedef`

```cpp
typedef char BYTE;
typedef unsigned int WORD;
typedef unsigned long long ULL;

typedef enum rainbow_color {
    red = 1,
    orange,
    yellow,
    green,
    cyan,
    blue,
    purple,
} rainbo_color_k;
```

- 使用 `using`

```cpp
using BYTE = char;
using WORD = unsigned int;
using ULL = unsigned long long;
```

		
## 内存的动态分配及释放

		
## 函数调用中的数组、指针和引用

		
## 要点回顾

1. 定义或者构造字符串的方法以及相关运算符，以及遍历字符串中字符的方法。
1. 定义或者构造列表、元组的方法以及相关运算符，以及遍历列表及元组中成员的方法。
1. 定义或者构造字典数据的方法以及相关运算符，以及遍历字典中值的方法。
1. 了解解耦数据和代码的概念并积极实践。

		
## 作业

1) 生成小于用户指定的正整数的斐波那契（Fibonacci）数列（使用动态分配的数组），然后计算相邻两个数的比值。运行效果如下：

```console
$ ./fibonacci-improved
<11>
1 / 1: 1.0
1 / 2: 0.5
2 / 3: 0.6666666666666666
3 / 5: 0.6
5 / 8: 0.625
```

	
2) 编写一个程序，该程序可以将用户输入的一个自然数转换为 2 到 36 进制展示出来。运行效果如下：

```console
$ ./show-number-in-different-bases
<15 2>      # 第一个数值指定一个十进制的一个正整数，第二个数字指定进制，两者用空格分隔。
1111
```

	
3) 求解给定的同余方程组，要求给出至少十个解。运行效果如下：

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

	
4) 给定任意正整数，给出其所有质因子（重复的质因子只保留一个）。

```console
$ ./prime-factors
<12>
2: 2 3
$ ./prime-factors
<11>
1: 11
```

	
5) 给定任意整数 `n`，列出用于计算 `D(n)` 和 `O(n)` 的所有可能形式。

```console
$ ./dn-on
<3>
3
2 1
---
3
1 1 1
```

	
6) 编程找到尽可能多的亲和数。运行效果如下：

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

