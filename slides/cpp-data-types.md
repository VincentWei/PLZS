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

	
- ASCII 字符的分类：
   - 数字（digit）：`'0 ~ '9'`；
   - 字母（alphabetic character）：`'A' ~ 'Z'`（upper letters）和 `'a' ~ 'z'`（lower letters）；
   - 空格（blank character）：`' ', '\t'`；
   - 空白（white-space character）：`' ', '\t', '\f', '\n', '\r', '\t', '\v'`；
   - 控制字符（control character）：大于等于 0x00，小于 0x20 的字符，如 `\0`、`\n`、`\r`、`\t`、`\f` 等；
   - 可打印字符（printable character）：包括空白字符在内的所有可显示在屏幕上的字符；
   - 标点字符（punctuation）：除了字母、数字、空白之外的可打印字符，如 `,`、`.` 等。

	
- 使用 `<cctype>` 中定义的接口，可判断字符类型，或实现大小写转换：
   1. `int isascii(int c)`：是否合法的 ASCII 字符。
   1. `int isalnum(int c)`：是否为字母数字。
   1. `int isalpha(int c)`：是否为字母。
   1. `int isdigit(int c)`：是否为数字。
   1. `int isblank(int c)`：是否为空格。
   1. `int islower(int c)`：是否为小写字母。
   1. `int tolower(int c)`：转换为小写字母。
   1. `int isupper(int c)`：是否为大写字母。
   1. `int toupper(int c)`：转换为大写字母。
   1. `int isxdigit(int c)`：是否为十六进制数字（数字及 `'a ~ 'f'` 或 `'A' ~ 'F'`）。
   1. ...

```cpp
#include <cctype>
#include <cassert>

...

    char digit = '0';
    assert(isdigit(digit));

    char letter = 'a';
    assert(isupper(toupper(letter)));
```

	
- 字符的常见运算

```cpp
    char digit = '0';       // '0'
    digit += '5' - '0';     // digit now is '5'

    // 大小写转换
    char letter = 0x42;     // letter now is 'B';
    letter += 'a' - 'A';    // letter now is 'b';

    // 字母的循环转换
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

	
- 字符类型的用途
  1. 构成字符串的基础数据类型。
  1. 用特定字符表示标志（如性别）、级别（如成绩等级）等。
  1. 使用字节位作为标志。
  1. 单字节范围内的算术运算（容易溢出，不推荐使用）。

```cpp
int count_one_bits(unsigned char byte)
{
    int n = 0;

    for (int i = 0; i < 8; i++) {
        if ((byte >> i) & 0x01) {
            n++;
        }
    }

    return n;
}
```

	
### 布尔值

1. C/C++ 中的 `bool` 型以及 `true` 和 `false` 在 C99 中引入，成为 C/C++ 的保留字。
1. C/C++ 中的 `bool` 占用一个字节，在逻辑表达式中，所有非零数值被视作真值。
1. 在算术表达式中使用布尔值时，`true` 等同于 1，`false` 等同于 0。
1. 在 C99 之前，业界通常使用预处理宏将 `int` 定义为 `BOOL` 使用，而 `TRUE` 和 `FALSE` 分别被定义为 `1` 和 `0`。

```cpp
#ifndef BOOL
#   define BOOL     int
#   define TRUE     1
#   define FALSE    0
#else
#   error "Duplicate definition of `BOOL`"
#endif
```

	
### 整数类型

- 整数类型
   1. 字符（`char`）、无符号字符/字节（`unsigned char`）；8 位二进制。
   1. 短整数（`short`）、无符号短整数（`unsigned short`）；16 位二进制。
   1. 整数（`int`）、无符号整数（`unsigned int`）：32 位二进制。
   1. 长整数（`long`）、无符号长整数（`unsigned long`）：32 位/64 位二进制（具体位数和架构、编译器相关）。
   1. 长长整数（`long long`）、无符号长长整数（`unsigned long long`）：64 位二进制。

	
- 可使用 `<cstdint>` 中定义的具有确定位宽（bit-width）的整数类型：
   1. `int8_t/uint8_t`：8 位整数。
   1. `int16_t/uint16_t`：16 位整数。
   1. `int32_t/uint32_t`：32 位整数。
   1. `int64_t/uint64_t`：64 位整数。
   1. `intmax_t/uintmax_t`：当前架构支持的最大位宽整数。
- `<cstdint>` 中还定义了这些固定位宽整型数的最大值和最小值：

```cpp
/* Minimum of signed integral types.  */
# define INT8_MIN▷⋯⋯▷⋯⋯⋯(-128)
# define INT16_MIN▷⋯▷⋯⋯⋯(-32767-1)
# define INT32_MIN▷⋯▷⋯⋯⋯(-2147483647-1)
# define INT64_MIN▷⋯▷⋯⋯⋯(-__INT64_C(9223372036854775807)-1)
/* Maximum of signed integral types.  */
# define INT8_MAX▷⋯⋯▷⋯⋯⋯(127)
# define INT16_MAX▷⋯▷⋯⋯⋯(32767)
# define INT32_MAX▷⋯▷⋯⋯⋯(2147483647)
# define INT64_MAX▷⋯▷⋯⋯⋯(__INT64_C(9223372036854775807))

/* Maximum of unsigned integral types.  */
# define UINT8_MAX▷⋯▷⋯⋯⋯(255)
# define UINT16_MAX▷▷⋯⋯⋯(65535)
# define UINT32_MAX▷▷⋯⋯⋯(4294967295U)
# define UINT64_MAX▷▷⋯⋯⋯(__UINT64_C(18446744073709551615))

/* Minimum for largest signed integral type.  */
# define INTMAX_MIN▷▷⋯⋯⋯(-__INT64_C(9223372036854775807)-1)
/* Maximum for largest signed integral type.  */
# define INTMAX_MAX▷▷⋯⋯⋯(__INT64_C(9223372036854775807))

/* Maximum for largest unsigned integral type.  */
# define UINTMAX_MAX▷⋯⋯⋯▷⋯⋯⋯(__UINT64_C(18446744073709551615))
```

	
- 我们直接输入到代码中的数值称为立即数（immediate value），可用于整型变量的初始化，亦可直接参与算术运算：

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

	
- 整数类型的用途
   1. 用于算术或数学运算。
   1. 用于循环计数。
   1. 表示字符；ASCII 只能用于表达 128 个字符，当用于表达中文等复杂语言的字符时，使用 16 位或者 32 位整数。
   1. 表示颜色。
   1. 表示定点数。
   1. 表示标识符（identifier）或索引值。

```cpp
```

	
### 浮点数

- 浮点数类型
   1. 浮点数（`float`）：32 位/4 字节。
   1. 双精度浮点数（`double`）；64 位/8 字节。
   1. 长双精度浮点数（`long double`）：64 或 128 位（具体位数和架构、编译器相关）。
- 科学记数法和浮点数：
   1. 数学上的科学计数法：`x * 10 ^ E`，其中 `abs(x) >= 1 && abs(x) < 10`。
   1. 如光速（299792458 m/s）的科学计数法表示为：`2.99792458E8`。
   1. 计算机中的浮点数：`x * 2 ^ E`，其中 `abs(x) >= 1 && abs(x) < 2`。


	
- 浮点数类型

```
     sign    e      base
 16   1      5       10
 32   1      8       23     (Single)
 64   1      11      52     (Double)
 96   1      15      64     (Double-Extended)
 128  1      15      112    (Quadruple)
```

	
- 浮点数立即数
   1. 可以用类似科学计数法的方式书写一个立即数：`1E10` 或者 `33E2`，此时该立即数始终是浮点数。
   1. 浮点数立即数的默认精度为双精度；使用 `f/F` 后缀时为单精度，使用 `l/L` 后缀时为长双精度。

```cpp
    float f1 = 0.1F;
    double f2 = 0.1;                // 没有后缀！
    double f3 = 2.99E10;            // 科学记数法
    long double f4 = 0.1L;
```

	
- 浮点数数值类型的用途：主要用于科学或者工程计算。
- 使用 `<cmath>` 中定义的数学函数接口，可完成相应的数学初等函数计算，如幂、对数、三角函数等。注意每个初等函数对应三个版本，分别用于单精度浮点数、双精度浮点数和长双精度浮点数：

```cpp
#include <math.h>

double sqrt(double x);
long double sqrtl(long double x);
float sqrtf(float x);
```

	
- `<cmath>` 中还定义有常用的数学常量：

```cpp
# define M_E▷⋯⋯⋯▷⋯⋯⋯2.7182818284590452354▷⋯⋯/* e */
# define M_LOG2E▷⋯⋯⋯1.4426950408889634074▷⋯⋯/* log_2 e */
# define M_LOG10E▷⋯⋯0.43429448190325182765▷⋯/* log_10 e */
# define M_LN2▷⋯▷⋯⋯⋯0.69314718055994530942▷⋯/* log_e 2 */
# define M_LN10▷▷⋯⋯⋯2.30258509299404568402▷⋯/* log_e 10 */
# define M_PI▷⋯⋯▷⋯⋯⋯3.14159265358979323846▷⋯/* pi */
# define M_PI_2▷▷⋯⋯⋯1.57079632679489661923▷⋯/* pi/2 */
# define M_PI_4▷▷⋯⋯⋯0.78539816339744830962▷⋯/* pi/4 */
# define M_1_PI▷▷⋯⋯⋯0.31830988618379067154▷⋯/* 1/pi */
# define M_2_PI▷▷⋯⋯⋯0.63661977236758134308▷⋯/* 2/pi */
# define M_2_SQRTPI▷1.12837916709551257390▷⋯/* 2/sqrt(pi) */
# define M_SQRT2▷⋯⋯⋯1.41421356237309504880▷⋯/* sqrt(2) */
# define M_SQRT1_2▷⋯0.70710678118654752440▷⋯/* 1/sqrt(2) */
```

	
- 数学运算可能出现计算溢出情形，或者对负数开方的情形；浮点数表达中包含有是否合法、是否表示无限大等信息。
   1. `FP_INFINITE`：是一个无穷值。
   1. `FP_NAN`：不是一个数（NaN）。
   1. `FP_NORMAL`：规范化的数值（表示这个数值可以用浮点数表达）。
   1. `FP_SUBNORMAL`：非规范化的数值（通常表示一个数值因为太小或接近于 0 而无法规范化表达）。
   1. `FP_ZERO`：表示零（0 或者 -0）。
- 使用 `<cmath>` 中的接口（实际定义为宏）可判断浮点数类型：

```cpp
#include <math.h>

int fpclassify(x);
int isfinite(x);
int isnormal(x);
int isnan(x);
int isinf(x);
```

	
- 浮点数和整数间的转换：
   1. 64 位的双精度浮点数只能精确表达 32 位整数。
   1. 大整数在转换为浮点数时，将丢失精度。

	
- 两个浮点数对比大小时，应考虑表达误差。
   1. 使用单精度浮点数表示十进制 0.1，实际得到：`0.100000001490116119384765625`。
   1. 0.1 的平方 0.01：`0.010000000298023226097399174250313080847263336181640625`。
   1. `<cfloat>` 中包含有浮点数表达相关的常数。`xxx_EPSILON` 常量定义了对应类型的两个浮点数之间的最小间歇值。

```cpp
#include <cmath>
#include <cfloat>

static inline bool is_close_floats(float a, float b)
{
    float max_val = fabsf(a) > fabsf(b) ? fabsf(a) : fabsf(b);
    return (fabs(a - b) <= max_val * FLT_EPSILON);
}

static inline bool is_close_doubles(double a, double b)
{
    double max_val = fabs(a) > fabs(b) ? fabs(a) : fabs(b);
    return (fabs(a - b) <= max_val * DBL_EPSILON);
}

static inline bool is_close_longdoubles(long double a, long double b)
{
    long double max_val = fabsl(a) > fabsl(b) ? fabsl(a) : fabsl(b);
    return (fabsl(a - b) <= max_val * LDBL_EPSILON);
}
```

		
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

