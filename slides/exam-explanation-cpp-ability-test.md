# C++ 编程语言能力测试

答题说明：

1. 开卷考试，考生可自由查阅课件或者互联网资料，但不得互相交流。
1. 请在自己的作业仓库中创建 `source/cpp/exam/` 目录，并在该目录中按要求作答，答题结束后将各文件提交并推送到自己的 Gitee 仓库。
1. 程序自动判卷，请使用规定的文件名称，程序源文件使用 `.cpp` 后缀名。
1. 规定答题时间之后提交的内容将被忽略。
1. 推荐答题时间：三个小时。

Copyright (C) 2024 FMSoft  
版权所有

		
## 单项选择题

共 40 题，每题 1.5 分，共 60 分。

	
### 第1题

C++ 编程语言的发明人是（ ）

   - A) Bjarne Stroustrup
   - B) Guido van Rossum
   - C) Linus Torvalds
   - D) Richard Stallman

	
### 第2题

C++ 编程语言的标准由（ ）制定

   - A) NASA（美国国家航天局）
   - B) ISO（国际标准化组织）
   - C) ANSI（美国国家标准学会）
   - D) ECMA（欧洲信息与通信系统标准化协会）

	
### 第3题

如下可以作为 C++ 变量名称的是（ ）

   - A) `0x01`
   - B) `张三`
   - C) `C_99`
   - D) `77`

	
### 第4题

如下可以作为 C++ 函数名称的是（ ）

   - A) `auto`
   - B) `面积`
   - C) `calc-area`
   - D) `calc_area`

	
### 第5题

C++ 中的 `int` 关键词用于（ ）

   - A) 声明一个有符号整型变量或函数的返回值类型，在常见的处理器架构上为 32 位。
   - B) 声明一个双精度浮点数。
   - C) 声明一个有符号整型变量或函数的返回值类型，其位宽可能有 64 位。
   - D) 声明一个字符变量。

	
### 第6题

C++ 中的 `long double` 关键词用于（ ）

   - A) 声明一个 32 位的整型变量或函数的返回值类型。
   - B) 声明一个 64 位双精度浮点数或函数的返回值类型。
   - C) 声明一个 128 位的长双精度浮点数或函数的返回值类型。
   - D) 声明一个长双精度浮点变量或函数的返回值类型，具体位宽和编译器有关。

	
### 第7题

在 C++ 程序中，用于定义一个无符号长长整数常量的正确写法是（ ）

   - A) `0x45ull`
   - B) `1234567890`
   - C) `-1234567890`
   - D) `(unsigned)-1`

	
### 第8题

在 C++ 程序中，如下用于定义字符串字面量的正确写法是（ ）

   - A) `'Hello, world!'`
   - B) `'Hello, world!\n'`
   - C) `"Hello, world!"`
   - D) `"Hello, "world!"`

	
### 第9题

在 C++ 程序中，如下用于定义字符常量的正确写法是（ ）

   - A) `"H"`
   - B) `"\n"`
   - C) `"\r"`
   - D) `'\x01'`

	
### 第 10 题

在 C++ 程序中，`int a = 0xFE;` 这条语句的效果是（ ）

   - A) 让变量 `a` 具有初始值 `254`。
   - B) 让变量 `a` 具有初始值 `33`。
   - C) 让变量 `a` 具有初始值 `0`。
   - D) 让变量 `a` 具有初始值 `-2`。

	
### 第11题

在 C++ 程序中，`int a = (n == 3) ? 100 : 50;` 这条语句的效果是（ ）

   - A) 让变量 `a` 具有初始值 `100`。
   - B) 让变量 `a` 具有初始值 `50`。
   - C) 让变量 `a` 具有初始值 `3`。
   - D) 变量 `a` 的初始值取决于 `n` 的值，要么是 `100`，要么是 `50`。

	
### 第12题

在 C++ 程序中，`int a = 0x01 << 3;` 这条语句的效果是（ ）

   - A) 让变量 `a` 具有初始值 `0x0100`。
   - B) 让变量 `a` 具有初始值 `0x0080`。
   - C) 让变量 `a` 具有初始值 `3`。
   - D) 让变量 `a` 具有初始值 `0`。

	
### 第13题

在 C++ 程序中，表达式 `(0.1 + 0.2 == 0.3)` 的结果是（ ）

   - A) 布尔值 `false`。
   - B) 浮点数 `0.3`。
   - C) 整数 `0`。
   - D) 布尔值 `true`。

	
### 第14题

在 C++ 程序中，对语句 `#include <iostream>` 的正确解释是（ ）

   - A) 这是一条预处理指令，用于包含头文件 `iostream`。
   - B) 这是一条注释语句。
   - C) 这是一条 C++ 语句，用于包含头文件 `iostream`。
   - D) 这是一条赋值语句。

	
### 第15题

在 C++ 程序中，对语句 `#define PI 3.14` 的正确解释是（ ）

   - A) 这是一条预处理指令，定义了一个名为 `PI` 的宏；所有其后源代码中出现的 `PI` 都将被替换为 `3.14`。
   - B) 这是一条 C++ 语句，声明了一个名为 `PI` 的变量。
   - C) 这是一条注释语句。
   - D) 这是一条赋值语句，将 `3.14` 赋值给了变量 `PI`。

	
### 第16题

在 C++ 程序中，对语句 `using namespace std;` 的正确解释是（ ）

   - A) 这是一条预处理指令，用于包含标准库。
   - B) 这是一条 C++ 语句，表示使用 `std` 作为默认名字空间。
   - C) 这是一条 C++ 语句，声明了一个 `std` 变量。
   - D) 这是一条 C++ 语句，声明了一个 `namespace` 变量。

	
### 第17题

对只有一条语句 `int main() {}` 的 C++ 程序所做的正确解释是（ ）

   - A) 语法错误，无法编译。
   - B) 可以编译生成可执行程序，但无法执行。
   - C) 定义了一个空的 `main` 函数，对应的程序可正常执行。
   - D) 定义了一个空的 `main` 函数，对应的程序将错误退出。

	
### 第18题

`auto foo = 1uLL; decltype(foo) bar;` 语句声明的 `bar` 变量，其真实类型应该为（ ）

   - A) 不确定。
   - B) `int`
   - C) `unsigned long long`
   - D) `long long`

	
### 第19题

执行 `unsigned u = (unsigned)-1; u++;` 语句后，变量 `u` 的值为（ ）

   - A) 不确定。
   - B) `1`
   - C) `0x100000000`
   - D) `0`

	
### 第20题

在 C++ 程序中，标准库的 `string` 类可用于（ ）

   - A) 定义一个内容可变、长度不可变的字符串对象。
   - B) 定义一个内容和长度均不可变的字符串对象。
   - C) 定义一个内容可变、长度可变的整数对象。
   - D) 定义一个内容和长度均不可变的整数对象。

	
### 第21题

在 C++ 程序中，对标准库的 `array` 描述正确的是（ ）

   - A) 它是一个类模板，可用于定义任何类型的数组。
   - B) 它是一个类，可用于定义任何基础数据类型的数组。
   - C) 它是一个函数模板，可用于生成任何类型的数组。
   - D) 它是一个函数，可用于生成任何基础数据类型的数组。

	
### 第22题

在 C++ 程序中，对标准库的 `vector` 描述正确的是（ ）

   - A) 它是一个类，可用于定义任何基础数据类型的矢量数据结构。
   - B) 它是一个函数模板，可用于生成任何类型的矢量容器。
   - C) 它是一个函数，可用于生成任何基础数据类型的矢量容器。
   - D) 它是一个类模板，可用于定义任何类型的可变长度的矢量容器，且可如数组一样通过下标访问其成员。

	
### 第23题

要使用 `std::cout` 对象向标准输出写入一个字符串（`std::string name`）以及一个换行符，正确的用法是（ ）

   - A) `std::cout >> name >> std::endl;`
   - B) `std::cout << name << std::endl;`
   - C) `std::cout << name + std::endl;`
   - D) `std::cout << name >> std::endl;`

	
### 第24题

要使用 `std::cin` 对象从标准输入中完整读取一行中可能包含空格的姓名（如 `Linus Torvalds`）时，不正确的用法是（ ）

   - A) `string name; std::getline(std::cin, name);`
   - B) `string name; std::getline(std::cin, name, '\n');`
   - C) `char buf[100]; std::cin.getline(buf, 100); string name = buf;`
   - D) `string name; std::cin >> name;`

	
### 第25题

要判断一个 `std::string` 类的对象 `str` 是否为空（不包含任何内容），不正确的逻辑表达式是（ ）

   - A) `(str.empty())`
   - B) `(str == nullptr)`
   - C) `(str.size() == 0)`
   - D) `(str.length() == 0)`

	
### 第26题

C++ 中不能被重载的运算符是（ ）

   - A) `sizeof`
   - B) `+`
   - C) `>>`
   - D) `<<`

	
### 第27题

下面有关 C++ 类中纯虚函数的描述正确的是（ ）

   - A) 子类必须重载纯虚函数并提供一个有效实现。
   - B) 若存在未被重载的纯虚函数，则这个类不能被实例化。
   - C) C++ 不支持纯虚函数。
   - D) 纯虚函数是指不能被子类重载的虚函数。

	
### 第28题

下面有关 C++ 类的构造函数和析构函数的描述正确的是（ ）

   - A) 必须定义和实现类的构造函数。
   - B) 类的构造函数可以有多个。
   - C) 定义了构造函数就必须同时定义析构函数。
   - D) 在实例化一个类时，如果这个类有多个构造函数，则所有的构造函数都会被调用一次。

	
### 第29题

下面有关 C++ STL 迭代器的说法正确的是（ ）

   - A) 提供了以某种方向遍历容器或数组中特定范围内元素的抽象方法。
   - B) 迭代器对应的英文术语是 `iteration`。
   - C) 迭代器只能用于 STL 定义的容器。
   - D) 迭代器只能用于数组。

	
### 第30题

下面有关 C++ STL 算法函数的说法正确的是（ ）

   - A) 算法函数通常被定义为模板，只能用于 STL 容器。
   - B) 算法函数通常被定义为模板，只能用于 C++ 基础数据类型。
   - C) 算法函数的性能较差，不推荐使用。
   - D) 算法函数通常被定义为模板，结合迭代器使用时，可用于 STL 容器或其他数据类型以及用户自定义类。

	
### 第31题

下面的程序清单给出的 C++ 程序的输出结果为（ ）

   - A) 程序无法编译通过。
   - B) `Hello, world!`
   - C) `Hello`
   - D) 没有输出。

```cpp
#include <iostream>

int main()
{
    std::cout << "Hello\0, world!" << endl;
}
```

	
### 第32题

下面的程序清单给出的 C++ 程序的输出结果为（ ）

   - A) `2 4`
   - B) `2 3`
   - C) `2 5`
   - D) `1 5`

```cpp
#include <iostream>
#include <cmath>

long int rounded_addition(long int a, long int b = 0)
{
    int r;
    r = a + b;
    return r;
}

long int rounded_addition(double a, double b = 0)
{
    return lround(a) + lround(b);
}

int main()
{
    std::cout << std::rounded_addition(1) << " " << std::rounded_addition(1.7, 2.6) << std::endl;
}
```

	
### 第33题

下面的程序清单给出的 C++ 程序的输出结果为（ ）

   - A) `julia lisa tom`
   - B) `JULIA LISA TOM`
   - C) `j l t`
   - D) `Julia Lisa Tom`

```cpp
#include <iostream>
#include <ctype>

using namespace std;

int main()
{
    const char *names[] = {
        "Julia",
        "Lisa",
        "Tom",
    };

    for (size_t i = 0; i < sizeof(names)/sizeof(names[0]); i++) {
        for (int j = 0; true; j++) {
            if (names[i][j] == '\0')
                break;

            char c = (char)tolower(names[i][j]);
            cout << c;
        }

        cout << " ";
    }

    cout << endl;
}
```

	
### 第34题

下面的程序清单给出的 C++ 程序的输出结果为（ ）

   - A) `24` 开头的一个字符串，其后内容不确定。
   - B) `241`
   - C) `24 1`
   - D) `3 1`

```cpp
#include <iostream>

using namespace std;

union parameters {
    double one;
    double two[2];
    double three[3];
};

int main()
{
    cout << sizeof(union parameters);

    union parameters params;
    params.one = 1.0;

    cout << params.two[1] << endl;
}
```

	
### 第35题

下面的程序清单给出的 C++ 程序的输出结果为（ ）

   - A) `20240101: Julia; 20240102: Lisa; 20240103: Tom; `
   - B) `20240101: Julia; 20240103: Tom; `
   - C) `20240101: Julia; 20240103: Tom; 20240102: Lisa; `
   - D) 输出 `20240101: Julia; 20240103: Tom; `后程序会崩溃退出或者死循环。

```cpp
#include <iostream>
#include <string>

using namespace std;

struct student {
    string  id;
    string  name;
    string  birthday;
    char    gender;         // 'M' for male, 'F' for female
    int     height;
    float   weight;
};

int main()
{
    struct student students[] = {
        { "20240101", "Julia", "2010-09-03", 'F', 160, 50.3f },
        { "20240102", "Lisa",  "2010-08-15", 'F', 158, 45.5f },
        { "20240103", "Tom",   "2010-07-10", 'M', 166, 65.5f },
    };

    struct student *p = students;
    for (size_t i = 0; i < sizeof(students)/sizeof(students[0]); i++) {
        cout << "Student " << p[i]id << ": " << p[i]name << "; ";
        p++;
    }

    cout << endl;
}
```

	
### 第36题

若给下面的程序清单给出的 C++ 程序以输入 `< 4 5`，则其输出结果为（ ）

   - A) `true`
   - B) `false`
   - C) `True`
   - D) `False`

```cpp
#include <iostream>
#include <iostream>

using namespace std;

bool largerthan(int a, int b)
{
    return a > b;
}

bool lessthan(int a, int b)
{
    return a < b;
}

bool equalto(int a, int b)
{
    return a == b;
}

bool compare(char symbol, int a, int b)
{
    bool (*op)(int, int);

    switch (symbol) {
        case '>':
            op = largerthan;
            break;
        case '<':
            op = lessthan;
            break;
        case '=':
            op = equalto;
            break;
        default:
            op = nullptr;
            break;
    }


    if (op)
        return op(a, b);

    return false;
}

int main()
{
    char symbol;
    int a, b;

    cin >> symbol >> a >> b;

    cout << (compare(symbol, a, b) ? "true" : "false") << endl;
}
```


	
### 第37题

下面的程序清单给出的 C++ 程序的输出结果为（ ）

   - A) `Khoor,&zruog!`
   - B) `hello,&world!`
   - C) `HELLO,&WORLD!`
   - D) `olleH,&dlrow!`

```cpp
#include <iostream>
#include <cctype>
#include <cassert>

using namespace std;

int main()
{
    const char *p = "Hello, world!";

    string encrypted;

    while (*p) {
        char en;

        if (islower(*p)) {
            en = (*p + 3);
            if (en > 'z') {
                en = 'a' + en - 'z' - 1;
            }
        }
        else if (isupper(*p)) {
            en = *p - 'A';
            en += 3;
            en %= 26;
            en += 'A';
        }
        else if (*p == ' ') {
            en = '&';
        }
        else {
            en = *p;
        }

        encrypted.push_back(en);
        p++;
    }

    cout << encrypted << endl;
}
```

	
### 第38题

下面的程序清单给出的 C++ 程序的输出结果为（ ）

   - A) `20`
   - B) `10`
   - C) `5`
   - D) 不确定。

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
    b = addition(a, b);
    int c = addition(b, a, b);
    cout << c << endl;
}
```

	
### 第39题

下面的程序清单给出的 C++ 程序的输出结果为（ ）

   - A) 编译出错。
   - B) 不确定。
   - C) `48`
   - D) `6`

```cpp
#include <iostream>
#include <cstdint>

using namespace std;

int main()
{
    uint64_t fibonacci[] = { 1, 1, 2, 3, 5, 8 };

    cout << sizeof(fibonacci) << endl;
}
```

	
### 第40题

若给下面的程序清单给出的 C++ 程序以输入 `4 2`，则其输出结果为（ ）

   - A) `assert` 失败，程序异常终止。
   - B) 程序死循环，很快会因为耗尽内存而异常终止。
   - C) `16`
   - D) 以上都不正确。

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
        r = f * power(f, n);

    return r;
}

int main()
{
    assert(power(3, 0) == 1);
    assert(power(3, 2) == 9);
    assert(power(-3, 3) == -27);

    double d;
    unsigned n;
    cin >> d >> n;

    cout << power(d, n) << endl;
}
```

		
## 编程题

请按题目要求创建相应的 C++ 源程序，完成后提交到仓库并推送到 Gitee 仓库。判卷标准如下：

- 程序自动判卷，请使用规定的文件名称，源文件使用 `.cpp` 后缀名。
- 无法编译通过的不得分。
- 按通过的测试数据集计算得分；注意严格按照要求输出结果，不要有任何多余输出。

	
### 第41题

【10分】打印一个由 `*` 号构成的三角形图形；输入一个正整数 `n`，表示该三角形的行数（`0<n<40`），输出对应的三角形。运行效果如下：

```console
$ ./star-triangle
<6>
     *
    * *
   * * *
  * * * *
 * * * * *
* * * * * *
```

	
### 第42题

【10分】编写程序计算全班各科目成绩的平均分以及总平均分。运行效果如下：

```console
$ ./average-score
<3 5>                   # 输入：空格分隔的两个正整数，第一个正整数表示班级人数，第二个正整数表示科目数量。
<90 80 75 99 100>       # 输入：空格分隔的若干浮点数，分别表示第一名同学的各科成绩；以此类推。
<69 79 83 89 70>        # 输入
<90 78 59 63 89>        # 输入
83 79 72 84 86          # 输出：各科目的平均分，结果四舍五入取整。
81                      # 输出：总平均分，结果四舍五入取整。
```

	
### 第43题

【10分】广义上的水仙花数是指一个 `n` 位数（`n >= 3`）的十进制数，它每位上的数字的 `n` 次幂之和等于它本身。如 <code>371 = 3<sup>3</sup> + 7<sup>3</sup> + 1<sup>3</sup></code>，则 `371` 是一个三位的水仙花数。编写程序 `narcissistic-numbers.cpp` 找出所有给定位数的水仙花数，从小到大，每行输出一个。运行效果如下：

```console
$ ./narcissistic-numbers
<3>     # 输入：十进制位数（2<n<10）
153
370
371
407
```

	
### 第44题

【10分】给定任意长度的两个十进制自然数，输出其和。运行效果如下：

```console
$ ./natural-summary
<1234567890987654321 987654321>     # 输入：两个任意长度的十进制自然数，用空格分隔
1234567891975308642
```

		
## 附加题

	
### 第45题

【10分】输入一行英文句子（最长 4096 个字符），找出其中最长的单词并输出其长度（提示：使用 `string` 类的 `.substr()` 方法分割句子中的一个个单词，并使用 `vector` 保存分割后的单词）。运行效果如下：

```console
$ ./find-longest-word
<I Love China.>
China 5
```

	
### 第46题

【10分】判定形如 `ax + by = d` 的不定方程（其中，`a, b, d` 为整数，均不等于 `0`）是否有整数解，若有解，给出 10 个解。运行效果如下：

```console
$ ./bezout
<23 7 1>            # 三个非零整数（32 位有符号整数），分别是 ax + by = d 不定方程中的 a, b, d
-3 10
4 -13
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
NO SOLUTION
```

