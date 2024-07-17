# C++ 数据类型（上）

1. C++ 基础数据类型
1. 数组和指针
1. 引用
1. 字符串
1. 实用技巧

		
## C++ 基础数据类型

1) 数据类型（data type）：编程语言用来表达（represent）现实世界中不同种类数据的方法。
2) 我们已经接触过若干种 C++ 基础数据类型：
   - 布尔型（`bool`）
   - 各种长度/有无符号的整型（`int`、`unsigned int`）
   - 三种精度的浮点数（`float`、`double`、`long double`）
3) 本质上，所有的 C++ 基础数据类型为单字节、双字节、四字节、八字节的二进制数据。

	
### 字符

- C++ 字符类型（`char`）来自 C 语言，主要用于表达 ASCII 字符，本质上是单字节数值，默认为带有符号位，取值范围 `-127 ~ 128`。
- 命令 `man ascii` 可获得 ASCII 字符的定义；ASCII 码的取值范围：`0x00 ~ 0x7F`。

	
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
- 专用于表示大小的整数类型：`size_t` 和 `ssize_t`：
   1. 其位宽（bit-width）通常和计算机架构的自然位宽相同，可用来表示系统支持的最大内存块、文件长度等。
   1. `ssize_t` 是带有符号的，其值小于零时通常表示错误。
   1. `sizeof` 运算符的返回值类型为 `size_t`。

	
- 可使用 `<climits>` 中定义的整数类型位宽以及极值：

```cpp
/* Number of bits in a `char'.    */
#  define CHAR_BIT    8

/* Minimum and maximum values a `signed char' can hold.  */
#  define SCHAR_MIN    (-128)
#  define SCHAR_MAX    127

/* Maximum value an `unsigned char' can hold.  (Minimum is 0.)  */
#  define UCHAR_MAX    255

/* Minimum and maximum values a `char' can hold.  */
#  ifdef __CHAR_UNSIGNED__
#   define CHAR_MIN    0
#   define CHAR_MAX    UCHAR_MAX
#  else
#   define CHAR_MIN    SCHAR_MIN
#   define CHAR_MAX    SCHAR_MAX
#  endif

/* Minimum and maximum values a `signed short int' can hold.  */
#  define SHRT_MIN    (-32768)
#  define SHRT_MAX    32767

/* Maximum value an `unsigned short int' can hold.  (Minimum is 0.)  */
#  define USHRT_MAX    65535

/* Minimum and maximum values a `signed int' can hold.  */
#  define INT_MIN    (-INT_MAX - 1)
#  define INT_MAX    2147483647

/* Maximum value an `unsigned int' can hold.  (Minimum is 0.)  */
#  define UINT_MAX    4294967295U

/* Minimum and maximum values a `signed long int' can hold.  */
#  if __WORDSIZE == 64
#   define LONG_MAX    9223372036854775807L
#  else
#   define LONG_MAX    2147483647L
#  endif
#  define LONG_MIN    (-LONG_MAX - 1L)

/* Maximum value an `unsigned long int' can hold.  (Minimum is 0.)  */
#  if __WORDSIZE == 64
#   define ULONG_MAX    18446744073709551615UL
#  else
#   define ULONG_MAX    4294967295UL
#  endif

#  ifdef __USE_ISOC99

/* Minimum and maximum values a `signed long long int' can hold.  */
#   define LLONG_MAX    9223372036854775807LL
#   define LLONG_MIN    (-LLONG_MAX - 1LL)

/* Maximum value an `unsigned long long int' can hold.  (Minimum is 0.)  */
#   define ULLONG_MAX    18446744073709551615ULL

#  endif /* ISO C99 */
```

	
- 亦可使用 `<cstdint>` 中定义的具有确定位宽的整数类型：
   1. `int8_t`/`uint8_t`：8 位整数。
   1. `int16_t`/`uint16_t`：16 位整数。
   1. `int32_t`/`uint32_t`：32 位整数。
   1. `int64_t`/`uint64_t`：64 位整数。
   1. `intmax_t`/`uintmax_t`：当前架构支持的最大位宽整数。

	
- `<cstdint>` 中还定义了这些固定位宽整型数的最大值和最小值：

```cpp
/* Minimum of signed integral types.  */
# define INT8_MIN       (-128)
# define INT16_MIN      (-32767-1)
# define INT32_MIN      (-2147483647-1)
# define INT64_MIN      (-__INT64_C(9223372036854775807)-1)
/* Maximum of signed integral types.  */
# define INT8_MAX       (127)
# define INT16_MAX      (32767)
# define INT32_MAX      (2147483647)
# define INT64_MAX      (__INT64_C(9223372036854775807))

/* Maximum of unsigned integral types.  */
# define UINT8_MAX      (255)
# define UINT16_MAX     (65535)
# define UINT32_MAX     (4294967295U)
# define UINT64_MAX     (__UINT64_C(18446744073709551615))

/* Minimum for largest signed integral type.  */
# define INTMAX_MIN     (-__INT64_C(9223372036854775807)-1)
/* Maximum for largest signed integral type.  */
# define INTMAX_MAX     (__INT64_C(9223372036854775807))

/* Maximum for largest unsigned integral type.  */
# define UINTMAX_MAX    (__UINT64_C(18446744073709551615))
```

	
- 我们直接输入到代码中的数值称为立即数（immediate value），可用于整型变量的初始化，亦可直接参与算术运算：

```cpp
    int i = 100;
    unsigned int u;

    u = 100;                        // 十进制
    u = 0124;                       // 0 作为前缀，八进制
    u = 0x80000000U;                // 0x 作为前缀，十六进制
    u = (unsigned int)-1;           // 强制转换为无符号整数使用：0xFFFFFFFF
    u = (unsigned int)-2;           // 强制转换为无符号整数使用：0xFFFFFFFE

    long l = 0x80000000L;           // 后缀：l/L
    unsigned ul = 0x80000000UL;     // 后缀：U、L，后缀的顺序和大小写无关

    long long ll = 0x8000000000000000LL;
    unsigned long long ull = 0x8000000000000000ull;
```

	
- 整数类型的用途
   1. 用于算术或数学运算。
   1. 用于数组下标（索引值）。
   1. 用于循环计数。
   1. 表示字符；ASCII 只能用于表达 128 个字符，当用于表达中文等复杂语言的字符时，使用 16 位或者 32 位整数。
   1. 表示颜色。
   1. 表示定点数。
   1. 表示标识符（identifier），如学号。

	
- 无符号整数类型用于循环计数时，要特别小心向下溢出（underflow）现象。

```cpp
    // 当 i 等于 0 时，执行 i-- 后，i 的值将变成 UINT_MAX (4294967295U)，
    // 从而导致死循环。
    for (unsigned i = 100; i >= 0; i--) {
        cout << i << endl;
    }

    // 正确写法
    for (unsigned i = 101; i > 0; i--) {
        cout << (i - 1) << endl;
    }

    // 或者
    unsigned i = 101;
    while (true) {
        i--;

        // 此处正常使用 i
        cout << i << endl;

        // 若 i 等于 0，跳出循环
        if (i == 0)
            break;
    }
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
    float f1 = 0.1F;                // 使用 F/f 后缀定义单精度浮点数。
    double f2 = 0.1;                // 没有后缀！
    double f3 = 2.99E10;            // 科学记数法
    long double f4 = 0.1L;          // 使用 L/l 后缀定义长双精度浮点数。
```

	
- 浮点数数值类型的用途：主要用于科学或者工程计算。
- 使用 `<cmath>` 中定义的数学函数接口，可完成相应的数学初等函数计算，如幂、对数、三角函数等；使用这些接口，需要在命令行指定 `-lm` 选项。
- 注意每个初等函数对应三个版本，分别用于单精度浮点数、双精度浮点数和长双精度浮点数：

```cpp
#include <math.h>

double sqrt(double x);
float sqrtf(float x);
long double sqrtl(long double x);
```

	
- `<cmath>` 中还定义有常用的数学常量：

```cpp
# define M_E        2.7182818284590452354   /* e */
# define M_LOG2E    1.4426950408889634074   /* log_2 e */
# define M_LOG10E   0.43429448190325182765  /* log_10 e */
# define M_LN2      0.69314718055994530942  /* log_e 2 */
# define M_LN10     2.30258509299404568402  /* log_e 10 */
# define M_PI       3.14159265358979323846  /* pi */
# define M_PI_2     1.57079632679489661923  /* pi/2 */
# define M_PI_4     0.78539816339744830962  /* pi/4 */
# define M_1_PI     0.31830988618379067154  /* 1/pi */
# define M_2_PI     0.63661977236758134308  /* 2/pi */
# define M_2_SQRTPI 1.12837916709551257390  /* 2/sqrt(pi) */
# define M_SQRT2    1.41421356237309504880  /* sqrt(2) */
# define M_SQRT1_2  0.70710678118654752440  /* 1/sqrt(2) */

/* The above constants are not adequate for computation using `long double's.
   Therefore we provide as an extension constants with similar names as a
   GNU extension.  Provide enough digits for the 128-bit IEEE quad.  */
#ifdef __USE_GNU
# define M_El       2.718281828459045235360287471352662498L /* e */
# define M_LOG2El   1.442695040888963407359924681001892137L /* log_2 e */
# define M_LOG10El  0.434294481903251827651128918916605082L /* log_10 e */
# define M_LN2l     0.693147180559945309417232121458176568L /* log_e 2 */
# define M_LN10l    2.302585092994045684017991454684364208L /* log_e 10 */
# define M_PI       3.141592653589793238462643383279502884L /* pi */
# define M_PI_2l    1.570796326794896619231321691639751442L /* pi/2 */
# define M_PI_4l    0.785398163397448309615660845819875721L /* pi/4 */
# define M_1_PIl    0.318309886183790671537767526745028724L /* 1/pi */
# define M_2_PIl    0.636619772367581343075535053490057448L /* 2/pi */
# define M_2_SQRTPIl    1.128379167095512573896158903121545172L /* 2/sqrt(pi) */
# define M_SQRT2l   1.414213562373095048801688724209698079L /* sqrt(2) */
# define M_SQRT1_2l 0.707106781186547524400844362104849039L /* 1/sqrt(2) */
#endif
```

	
- 数学运算可能出现计算溢出（无穷或无限接近零）的情形或者对负数开方的情形。
- 使用 `<cmath>` 中的接口（`fpclassify()`，实际定义为宏）可判断浮点数类型：
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

	
### 浮点数大小的比较

- 对比两个浮点数的大小时，应考虑表达误差。
   1. 使用单精度浮点数表示十进制 `0.1`，实际得到：`0.100000001490116119384765625`。
   1. `0.1` 的平方 `0.01`：`0.010000000298023226097399174250313080847263336181640625`。
   1. `<cfloat>` 中包含有浮点数表达相关的常数。`xxx_EPSILON` 常量定义了对应类型的两个浮点数之间的最小间歇值。

	
```cpp
#include <cmath>
#include <cfloat>

bool isclose(double a, double b)
{
    double max_val = fabs(a) > fabs(b) ? fabs(a) : fabs(b);
    return (fabs(a - b) <= max_val * DBL_EPSILON);
}

bool isclosef(float a, float b)
{
    float max_val = fabsf(a) > fabsf(b) ? fabsf(a) : fabsf(b);
    return (fabs(a - b) <= max_val * FLT_EPSILON);
}

bool isclosel(long double a, long double b)
{
    long double max_val = fabsl(a) > fabsl(b) ? fabsl(a) : fabsl(b);
    return (fabsl(a - b) <= max_val * LDBL_EPSILON);
}
```

	
### 浮点数和整数间的转换

- 64 位的双精度浮点数只能精确表达 32 位整数。
- 长长整数在转换为浮点数时，将丢失精度。
- `<cmath>` 中的接口提供了将浮点数圆整为整数的接口：

	
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

	
### 浮点数比较的折中方案

1. 将浮点数比较转换为整数比较。
1. 使用 `<cstdint>` 头文件中定义的 `uint64_t` 类型以及 `UINT32_MAX` 等常量宏。

```cpp
#include <cstdint>

bool can_make_a_triangle_workaround(double d1, double d2, double d3)
{
    if (d1 <= 0 or d2 <= 0 or d3 <= 0)
        return false;

    if (d1 > UINT32_MAX and d2 > UINT32_MAX and d3 > UINT32_MAX) {
        d1 -= UINT32_MAX;
        d2 -= UINT32_MAX;
        d3 -= UINT32_MAX;
    }
    else if (d1 > UINT32_MAX or d2 > UINT32_MAX or d3 > UINT32_MAX) {
        return (((d1 + d2) > d3) and ((d1 + d3) > d2) and
            ((d2 + d3) > d1));
    }

    uint64_t ull1 = uint64_t(d1 * UINT32_MAX);
    uint64_t ull2 = uint64_t(d2 * UINT32_MAX);
    uint64_t ull3 = uint64_t(d3 * UINT32_MAX);

    if (((ull1 + ull2) > ull3) and ((ull1 + ull3) > ull2) and
            ((ull2 + ull3) > ull1))
        return true;

    return false;
}
```

		
## 数组和指针

- C/C++ 中的数组（array）用来表达可使用索引（index）值引用的一组有序（ordered）数据。
- 数组中的一个项（item）也会被称为一个单元（unit）或一个成员（member）。
- 字符串本质上是由字符构成的数组。

	
### 数组

1. C/C++ 中的数组使用成对出现的中括号（square brackets，`[]`）定义；可通过整型常量指定数组大小。
1. C99 开始，C/C++ 支持变长数组（variable length array，VLA），可用变量定义数组的大小（单元个数）。
1. 一旦初始化，C/C++ 数组的长度就是固定的。
1. C/C++ 数组中的数据项具有相同的数据类型。
1. 初始化数组时，使用 `{}` 包围数组单元，各个单元之间使用逗号（comma，`,`）分隔。

	
```cpp
    // 未明确初始化的单元将默认初始化为 0
    uint64_t fibonacci[100] = { 1, 1, 2, 3, 5, 8 };

    int i = 0;
    while (fibonacci[i] > 0) {
        cout << fibonacci[i] << endl;
        i++;
    }

    for (size_t i = 0; i < sizeof(fibonacci)/sizeof(uint64_t); i++) {
        if (fibonacci[i] == 0) {
            fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
        }
        cout << fibonacci[i] << endl;
    }
```

	
### 指针

- 指针（pointer）用于指代某项数据在进程地址空间中的地址值，本质上是一个无符号整数，其位宽通常和计算机架构的位宽相等。
- 指针变量使用 `<typename> *` 的方式定义，亦可使用 `void *` 定义不和具体类型关联的指针。
- 对指针变量做加减运算，其值将按照指针类型的字节数成倍增减；但 `void *` 指针上的算术运算，其行为不确定。
- C++ 使用 `nullptr` 关键词指代一个空（NULL）指针，而 C 使用 `NULL` 宏；访问空指针将导致程序异常终止，大部分情况下，函数返回空指针表示错误或失败的情形。

```cpp
    int a = 2;
    int *p = &a;

    cout << p << endl;      // 输出 p 指针中包含的地址值。
    cout << p + 1 << endl;  // 如果上面的 p 输出值为 0x10000，则 p + 1 是多少？
    cout << *p << endl;     // 输出 p 指向的地址处的整数值。

    *p = 3;                     // 修改 p 指向的地址处的整数值。
    cout << sizeof(p) << endl;  // 这行将输出多少？
    cout << a << endl;          // 这行将输出多少？
```

	
- 数组变量可看成是指向该数组第一个单元的指针。

```cpp
    int fibonacci[] = { 1, 1, 2, 3, 5, 8 };
    int *p = fibonacci;

    for (size_t i = 0; i < sizeof(fibonacci)/sizeof(int); i++) {
        cout << p[i] << endl;
    }

    for (size_t i = 0; i < sizeof(fibonacci)/sizeof(int); i++) {
        cout << *p << endl;
        p++;
    }
```

	
- 声明指针变量时使用 `const` 限定词（qualifier），表示指针指向的内容不可更改；编译器将据此检查可能的逻辑错误。

```cpp
    int fibonacci[20] = { 1, 1, 2, 3, 5, 8 };

    int* p = fibonacci;
    for (size_t i = 0; i < sizeof(fibonacci)/sizeof(int); i++) {
        if (p[i] == 0) {
            p[i] = p[i - 1] + p[i - 2];
        }

        cout << p[i] << endl;
    }

    // 添加 const 限定词之后，不能通过 cp 修改对应地址中的内容。
    int a = 3;
    const int *cp = &a;
    *cp = 5;                    // 将报编译错误。

    cp = fibonacci;
    assert(cp == p);            // assert 会否报错？

    for (size_t i = 0; i < sizeof(fibonacci)/sizeof(int); i++) {
        cout << *cp << endl;    // 将报编译错误。
        cp++;
    }
```

	
### 课堂练习

（十分钟内完成）

1) 复制并修改上页代码（`fibonacci.cpp`），将斐波那契数组的大小设置为 `90` 并查看结果。
2) 调整代码使之可输出正常结果，最后提交到自己的作业仓库（`source/cpp/lesson-3/` 目录下）。

		
## 引用

- 引用（reference）是 C++ 引入的数据类型，可以理解为给一个已有的变量取个别名。
- 定义引用变量时，使用 `<typename>&` 的语法。
- 通过引用，可将变量传递给函数；在函数中修改引用的值，将直接修改实参的值。

	
- 引用的用法

```cpp
#include <iostream>

using namespace std;

int addition(const int &a, const int &b)
{
    return a + b;
}

int &addition(int &r, const int &a, const int &b)
{
    r = a + b;
    return r;
}

int main()
{
    int a;
    int &b = a;

    b = 5;
    cout << a << endl;

    b = addition(a, b);
    cout << a << endl;

    c = addition(b, a, b);
    cout << a << endl;
    cout << c << endl;
}
```

	
- 不能在立即数上定义引用。
- 不能以引用的方式返回局部变量。
- 不能给使用 `const` 限定词的引用赋值。

```cpp
int &addition(const int &a, const int &b)
{
    a = 5;              // 将报编译错误。
    int &c = 4;         // 将报编译错误。
    int r = a + b;
    return r;
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
- C 字符串字面量本质上具有 `const char *` 类型，且不可更改该指针指向地址处的内容。

```cpp
    char hello1[200] = { 'H', 'e', 'l', 'l', 'o', ',', 'w', 'o', 'r', 'l', 'd', '!', '\0' };
    cout << hello1 << endl;

    cout << sizeof(hello1) << endl;
    cout << sizeof("0123456789") << endl;

    // 使用字符串字面量初始化字符数组（包括空字符在内）
    // 字符数组的尺寸为字符串长度加 1）。
    char hello2[] = "Hello, world!";
    cout << hello2 << endl;
    cout << sizeof(hello2)  << endl;

    hello1[100] = 'M';
    cout << hello1 << endl;     // 将输出什么内容？

    hello2[100] = 'M';          // 将会导致什么结果？
    cout << hello2 << endl;

    const char *hello3 = "Hello, world!";

    hello3[0] = 'h';            // 编译报错。
    cout << hello3 << endl;
```

	
- `<cstring>` 中声明了操作 C 字符串的常用接口：

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

	
### C++ 标准库字符串

- C++ 标准库定义的字符串是一个类（`string`），可通过 C 字符串来初始化。
- `string` 类的实例是可动态修改的，其长度可变化。
- `string` 类的对象上可使用 `+`、`+=` 等运算符。
- 通过 `string` 类的 `.c_str()` 方法，可将 `string` 类对象转换为 C 字符串进行只读访问。

	
```cpp
#include <string>
#include <cctype>

    string str("Hello, world!");
    str += '\n';                    // 串接（concatenate）一个换行符
    str += "-- By Vincent";         // 串接一个字符串

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

	
- C++ 标准库字符串通过 `<string>` 头文件暴露了常用接口，如：
  1. `size_t length()` 或 `size_t size()`：获取字符串长度（不包括结尾的空字符）。
  1. `void clear()` ：清空字符串内容。
  1. `bool empty()`：测试是否为空字符串。
  1. `char &operator[]`：返回给定索引位置的单元之引用，可用于左值（lvalue）或右值（rvalue）。
  1. `char &at(size_t pos)`：返回给定索引位置的单元之引用。
  1. `char &back()`：返回最后面字符之引用。
  1. `char &front()`：返回最前面字符之引用。

	
- C++ 标准库字符串通过 `<string>` 头文件暴露的常用接口（续）：
  1. `string &operator+= ()`：追加内容到字符串。
  1. `string &append()`：追加内容（单个字符、C 字符串、另一个 `string` 对象内容）到字符串。
  1. `string &insert()`：插入内容到字符串的指定位置（长度变长）。
  1. `string &erase()`：擦除字符串内的指定内容（长度变短）。
  1. `const char *c_str()`：返回只读的 C 字符串等价指针。
- [参考链接](https://cplusplus.com/reference/string/string/)

	
### 课堂练习

（十分钟内完成）

1) 复制并修改上面的示例代码，要求：
   - 名字 `Vincent` 使用 `cin` 读入。
   - 将字符串中的字符全部转换为小写。
2) 保存为 `test-string.cpp`，调试通过后提交到自己的作业仓库。

		
## 实用技巧

### 类型别名

- 在 C/C++ 代码中，可以为数据类型取个别名（aliase）。
- 类型别名主要用于方便代码的书写。

	
- 使用 `typedef`（C 语言也支持）

```cpp
typedef char BYTE;
typedef unsigned short WORD;
typedef unsigned long long ULL;
```

	
- 使用 `using`

```cpp
using BYTE = char;
using WORD = unsigned int;
using ULL = unsigned long long;
```

	
- 使用预处理宏（不推荐）

```cpp
#define BYTE unsigned char
#define WORD unsigned short
#define ULL  unsigned long long
```

	
### Vim 默认设置

编辑 `~/.vimrc` 文件，添加如下设置：

```vim
set expandtab
set tabstop=4
set shiftwidth=4
set cindent
set list
set listchars=tab:▷⋯,trail:◇
set cc=80
set ruler
syntax on
```

	
### 使用 `?` 运算符

- `?` 运算符和 `:` 运算符一起构成了一个非此即彼的表达式。
- `<condition> ? <expression if condition is true> : <expression if condition is false>`。
- 和其他运算符混合时，最好用小括号包围起来。

```cpp
    double a, b, c;
    cin >> a >> b >> c;

    cout << (can_make_a_triangle(a, b, c) ? "True" : "False") << endl;

    /* 以上使用 ? 运算符的简化写法相当于如下代码：
    if (can_make_a_triangle(a, b, c)) {
        cout << "True";
    }
    else {
        cout << "False";
    }

    cout << endl; */
```

		
## 作业

1) 使用本讲提到的 `isclose()` 函数完成程序 `check-triangle.cpp`，判断用户输入的三角形三个边是否可以构成一个三角形，并确认是否彻底绕开了浮点数对比的陷阱。运行效果如下：

```console
$ ./check-triangle
<3.0 4.0 5.0>
True

$ ./check-triangle
<0.1 0.2 0.3>
False
```

	
2) 生成个数等于用户指定的正整数（不大于 30）的斐波那契（Fibonacci）数列（使用数组保存），然后计算相邻两个数的比值。运行效果如下：

```console
$ ./fibonacci-improved
<5>
1 / 1: 1.0
1 / 2: 0.5
2 / 3: 0.6666666666666666
3 / 5: 0.6
5 / 8: 0.625
```

	
3) 实现如下程序中空白的三个函数，保存为 `strings.cpp`。

```cpp
#include <cctype>
#include <cassert>
#include <cstring>
#include <strings.h>

/* Copy a string from src to dest, returning a pointer to
   the end of the resulting string at dest. */
char *mystpcpy(char *dest, const char *src)
{
    ...
}

/* Compare the strings s1 and s2 ignoring case. */
int mystrcasecmp(const char *s1, const char *s2)
{
    ...
}

/* Compare the first n bytes of the strings s1 and s2 ignoring case. */
int mystrncasecmp(const char *s1, const char *s2, size_t n)
{
    ...
}

int main()
{
    char buf1[100], buf2[100];
    const char *hello1 = "Hello, world!";

    char *result = mystpcpy(buf1, hello1);
    char *expected = ::stpcpy(buf2, hello1);

    assert(result == (buf1 + strlen(hello1)));
    assert(expected == (buf2 + strlen(hello1)));
    assert(::strcmp(buf1, buf2) == 0);

    const char *hello2 = "hello, world.";
    assert(mystrcasecmp(hello1, hello2) == ::strcasecmp(hello1, hello2));
    assert(mystrncasecmp(hello1, hello2, 5) == ::strncasecmp(hello1, hello2, 5));
}
```

	
4) 某人发明了一种简单的文本加密方法，将 `a-z`、`A-Z` 字母循环转移七个顺序，比如 `a` 转换为 `g`，`z` 转换为 `f`，以此类推，并将空格转换为 `&`，标点符号保持不变。请编写程序用于解密对应的密文，运行效果如下：

```console
$ ./decrypt
<P&Svcl&Fvb!>
I Love You!
```

5) 给定任意长度的十进制自然数，给出其补数。运行效果如下：

```console
$ ./decimal-complement
<123456789098765432101234567890987654321>
876543210901234567898765432109012345678
```

	
6) 编写一个函数，该函数可以将用户输入的一个特定进制的数用十进制展示出来，并使用 `<cstdlib>` 中的 `strtoll()` 接口进行对比测试。运行效果如下：

```console
$ ./strtoll
<56ABC 20>  # 第一个数值指定一个用于表达某个数值的字符串，第二个数字指定该字符串所表达的数值的进制，两者用空格分隔。
852232
```

	
7) 编写一个程序，该程序可以将用户输入的一个自然数转换为 -36 到 36 的进制展示出来，并使用 `<cstdlib>` 中的 `strtoll()` 接口进行对比测试。运行效果如下：

```console
$ ./show-number-in-different-bases
<15 2>      # 第一个数值指定一个十进制的一个自然数，第二个数字指定进制，两者用空格分隔。
1111
```

	
### 参考链接

- 信奥生的数学素养课第二讲“数系上的运算及进制”
- [进位制](https://oi-wiki.org/math/base/)
- [进制转换原理](https://blog.51cto.com/u_16579730/10163127)
- [负进制](https://baike.baidu.com/item/%E8%B4%9F%E8%BF%9B%E5%88%B6%E6%95%B0/3054702)

