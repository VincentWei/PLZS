# C++ 数据类型

1. C++ 基础数据类型
1. 数组和指针
1. 字符串
1. 结构体
1. 其他数据类型
1. 深入理解函数调用
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


	
- 浮点数精度：`x * 2 ^ E`

| 总位数 | 符号位 | 指数位（e） | 底数（x） |  精度                     |
| ---    | ---    | ---         | ---       | ---                       |
| 16     | 1      | 5           | 10        | 低精度                    |
| 32     | 1      | 8           | 23        | 单精度（`float`）         |
| 64     | 1      | 11          | 52        | 双精度 （`double`)        |
| 96     | 1      | 15          | 64        | 双精度扩展                |
| 128    | 1      | 15          | 112       | 长双精度（`long double`） |

	
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

	
- 数学运算可能出现计算溢出（无穷或无限接近零）的情形或者对负数开方的情形。
- 使用 `<cmath>` 中的接口（实际定义为宏）可判断浮点数类型：
   1. `FP_INFINITE`：是一个无穷值。
   1. `FP_NAN`：不是一个数（NaN）。
   1. `FP_NORMAL`：规范化的数值（表示这个数值可以用浮点数表达）。
   1. `FP_SUBNORMAL`：非规范化的数值（通常表示一个数值因为太小或接近于 0 而无法规范化表达）。
   1. `FP_ZERO`：表示零（0 或者 -0）。

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
   1. `<cmath>` 中的接口提供了将浮点数圆整为整数的接口：

	
```cpp
#include <math.h>

/* 圆整为不大于 x 的最大整数。 */
double floor(double x);
float floorf(float x);
long double floorl(long double x);

/* 圆整为不小于 x 的最小整数。 */
double ceil(double x);
float ceilf(float x);
long double ceill(long double x);

/* 圆整到最近的整数（远离 0 的方向）；
   round(0.5) 结果为 1.0，round(-0.5) 的结果为 -1.0。 */
double round(double x);
float roundf(float x);
long double roundl(long double x);

/* 圆整到最近的整数（远离 0 的方向）；
   lround(0.5) 结果为 1L，lround(-0.5) 的结果为 -1L。 */
long int lround(double x);
long int lroundf(float x);
long int lroundl(long double x);

long long int llround(double x);
long long int llroundf(float x);
long long int llroundl(long double x);
```

	
- 对比两个浮点数的大小时，应考虑表达误差。
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

		
## 数组和指针

- C/C++ 中的数组（array）用来表达可使用索引（index）值引用的一组有序（ordered）数据。
- 数组中的一个项（item）也会被称为一个单元（unit）或一个成员（member）。
- 字符串本质上是由字符构成的数组。

	
### 数组

1. C/C++ 中的数组使用成对出现的中括号（square brackets，`[]`）定义。
1. 一旦初始化，C/C++ 数组的长度（单元个数）就是固定的。
1. C/C++ 数组中的数据项具有相同的数据类型。
1. 初始化数组时，使用 `[]` 包围数组单元，各个单元之间使用逗号（comma，`,`）分隔。

```cpp
    // 未明确初始化的单元将默认初始化为 0
    int fibonacci[100] = [ 1, 1, 2, 3, 5, 8 ];

    int i = 0;
    while (fibonacci[i] > 0) {
        cout << fibonacci[i] << endl;
    }

    for (int i = 0; i < sizeof(fibonacci)/sizeof(int); i++) {
        if (fibonacci[i] == 0) {
            fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
        }
        cout << fibonacci[i] << endl;
    }
```

	
### 指针

- 指针（pointer）用于指代某项数据在进程地址空间中的地址值，本质上是一个无符号整数，其位宽通常和计算机架构位宽相等。
- 对指针变量做加减运算，其值将按照指针类型的字节数成倍增减。

```cpp
    int a;
    int *p = &a;

    cout << p << endl;
    cout << p + 1 << endl;

    *p = 3;
    cout << sizeof(p) << endl;
    cout << a << endl;
```

	
- 数组变量可看成是指向该数组第一个单元的指针。

```cpp
    int fibonacci[] = [ 1, 1, 2, 3, 5, 8 ];
    int *p = fibonacci;

    for (int i = 0; i < sizeof(fibonacci)/sizeof(int); i++) {
        cout << p[i] << endl;
    }

    for (int i = 0; i < sizeof(fibonacci)/sizeof(int); i++) {
        cout << *p << endl;
        p++;
    }
```

	
## 字符串

- 计算机程序中的字符串主要用来表达构成自然语言的文本或者文本片段。
- 字符串字面值（literal）的概念。
- C/C++ 的字符串字面值使用成对出现的双引号（double-quote，`""`）定义。
- 转义（escape）字符：
   1. 如果文本本身包含双引号（`"`）怎么办？
   1. 如果文本中需要包含一些特殊字符，如换行符、回车符怎么办？
- C/C++ 字符串字面值本质上是不可更改的字符数组，对应类型为 `const char *`。

	
### C 字符串

- C 字符串本质上是一个字符数组。
- C 字符串的尾部始终包含一个空字符（`\0`）表示字符串的结尾。

```cpp
    char hello1[200] = { 'H', 'e', 'l', 'l', 'o', ',', 'w', 'o', 'r', 'l', 'd', '!', '\0' };
    cout << hello1 << endl;

    cout << sizeof(hello1) << endl;
    cout << sizeof("0123456789") << endl;

    char hello2[] = "Hello, world!";
    cout << hello2 << endl;

    hello1[100] = 'M';
    cout << hello1 << endl;

    hello2[100] = 'M';
    cout << hello2 << endl;

    const char *hello3 = "Hello, world!";

    hello3[0] = 'h';
    cout << hello3 << endl;
```

	
- `<cstring>` 中定义了操作 C 字符串的常用接口：

```cpp
#include <string.h>

/* 计算字符串长度（不包括末尾的空字符）。 */
size_t strlen(const char *s);
size_t strnlen(const char *s, size_t maxlen);

/* 串接两个 C 字符串。 */
char *strcat(char *dest, const char *src);
char *strncat(char *dest, const char *src, size_t n);

/* 复制字符串。*/
char *strcpy(char *dest, const char *src);
char *strncpy(char *dest, const char *src, size_t n);

/* 复制字符串。*/
int strcmp(const char *s1, const char *s2);
int strncmp(const char *s1, const char *s2, size_t n);

/* 查找字符。 */
char *strchr(const char *s, int c);

/* 从尾部反向查找字符。 */
char *strrchr(const char *s, int c);

/* 查找子字符串 */
char *strstr(const char *haystack, const char *needle);
```

	
### 课堂练习

（十五分钟内完成）

1) 尝试实现如下三个函数，调试通过后，将其保存为 `strings.cpp` 文件并提交到自己的作业仓库（`source/cpp/lesson-3/` 目录下）。

```cpp
/* Copy a string from src to dest, returning a pointer to
   the end of the resulting string at dest. */
char *stpcpy(char *dest, const char *src);

/* Compare the strings s1 and s2 ignoring case. */
int strcasecmp(const char *s1, const char *s2);

/* Compare the first n bytes of the strings s1 and s2 ignoring case. */
int strncasecmp(const char *s1, const char *s2, size_t n);
```

	
2) 测试用代码：

```cpp
#include <cstring>
#include <strings.h>

/* Copy a string from src to dest, returning a pointer to
   the end of the resulting string at dest. */
char *stpcpy(char *dest, const char *src)
{
    ...
}

/* Compare the strings s1 and s2 ignoring case. */
int strcasecmp(const char *s1, const char *s2)
{
    ...
}

/* Compare the first n bytes of the strings s1 and s2 ignoring case. */
int strncasecmp(const char *s1, const char *s2, size_t n)
{
    ...
}

int main()
{
    char buf[100];
    const char *hello1 = "Hello, world!";

    char *result = stpcpy(buf, hello1));
    char *expected = ::stpcpy(buf, hello1));

    assert(r0 == r1);
    assert(strcmp(r0, r1) == 0);

    const char *hello2 = "hello, world.";
    assert(strcasecmp(hello1, hello2) == ::strcasecmp(hello1, hello2));
    assert(strncasecmp(hello1, hello2, 5) == ::strncasecmp(hello1, hello2, 5));
}
```

	
### C++ 标准库字符串

- C++ 标准库定义的字符串是一个类（`string`），可通过 C 字符串来初始化。
- `string` 类的实例是可动态修改的，其长度可变化。
- 通过 `string` 类的 `.c_str()` 方法，可将 `string` 类对象转换为 C 字符串进行只读访问。

```cpp
#include <string>
#include <cctype>

    string str ("Hello, world!");
    str += '\n';
    str += "-- By Vincent";

    cout << str << endl;
    cout << str.c_str() << endl;

    /* 将字符全部转成大写。 */
    const char *p = str.c_str();
    i = 0;
    while (*p) {
        str[i] = toupper(*p);
        p++;
        i++;
    }

    cout << str << endl;
```

	
### 课堂练习

1) 复制并修改上面的示例代码，要求：
   - 名字 `Vincent` 使用 `cin` 读入。
   - 将字符串中的字符全部转换为小写。
2) 保存为 `string.cpp` 并提交到自己的作业仓库。

		
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

		
## 其他数据类型

	
### 多维数组

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

	
### 联合体

- 联合体在 C/C++ 中有妙用。
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

	
### 枚举量

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

	
### 类型别名

- 使用 `typedef`

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

	
- 使用 `using`

```cpp
using BYTE = char;
using WORD = unsigned int;
using ULL = unsigned long long;
using rainbow_color_k = enum rainbow_color;
```

- 使用预处理宏（不推荐）

```cpp
#define BYTE unsigned char
#define WORD unsigned short
#define ULL  unsigned long long
```

		
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

