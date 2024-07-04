# 任意精度计算的 C++ 实现

1. 任意精度计算要解决的问题
1. 实现原理和方法
1. 基于 `string` 的实现
1. 基于 `vector` 的实现

		
## 任意精度计算要解决的问题

- C/C++ 的整型数据表达范围有限，而浮点数的精度不足。
- C/C++ 的 `uint64_t` 类型的最大值为 `18446744073709551615`。
- 64 位的双精度浮点数只能精确表达 32 位整数。
- 128 位的长精度浮点数只能精确表达 64 位整数。
- Python 的 `int` 类型是无限精度的，可表达范围取决于计算机的内存。
- 任意精度或者高精度计算是信奥或者编程比赛的常见题型。

	
### 求阶乘

```cpp
#include <iostream>
#include <cstdint>
#include <cassert>

using namespace std;

uint64_t factorial(uint64_t n)
{
    if (n > 1) {
        return n * factorial(n - 1);
    }

    return 1;
}

int main()
{
    assert(factorial(3) == 6);

    uint64_t n = 0;
    uint64_t last = 1;
    while (++n) {
        uint64_t r = factorial(n);
        if (r / last != n) {
            cout << n << "! = Overflow" << endl;
            break;
        }

        last = r;
        cout << n << "! = " << last << endl;
    }
}
```

	
### 执行结果

```console
% ./factorial
1! = 1
2! = 2
3! = 6
4! = 24
5! = 120
6! = 720
7! = 5040
8! = 40320
9! = 362880
10! = 3628800
11! = 39916800
12! = 479001600
13! = 6227020800
14! = 87178291200
15! = 1307674368000
16! = 20922789888000
17! = 355687428096000
18! = 6402373705728000
19! = 121645100408832000
20! = 2432902008176640000
21! = Overflow
```

		
## 实现原理和方法

1. 直接使用十进制或者十六进制的字符数组或者字符串表述整数：
   - 若使用固定大小的字符数组，可提供高精度整数的表达，表达范围取决于字符数组的长度。
   - 若使用变长的 C++ 字符串，可提供任意精度整数的表达，表达范围取决于可用内存大小。
1. 使用多个字节表达任意整数，相当于将一个长整数按 256 进制分割表达：
   - 使用固定大小的字节数组时，可提供高精度整数的表达，表达范围取决于字节数组的长度。
   - 使用变长的字节矢量时，可提供任意精度整数的表达，表达范围取决于可用内存大小。
   - 更进一步，可使用多个 16/32 位整数表达任意整数，相当于将一个长整数按 2<sup>16</sup> 或 2<sup>32</sup> 进制分割表达。

	
### 挑战

- 需要自行实现各种算术基本运算功能。
- 负数、减法和除法的实现更为复杂。
- 性能无法和基于基本数据类型的计算比较；但第二种方法可充分利用基于基本数据类型的运算，性能更好。

		
## 基于 `string` 的实现

### 自然数加法

```cpp
void nap_add(string &result, const string &a, const string &b)
{
    size_t len_a = a.length();
    size_t len_b = b.length();
    size_t len_max = (len_a > len_b) ? len_a : len_b;

    result.clear();
    int c = 0;
    for (size_t i = 0; i < len_max; i++) {
        int n_a = ((i < len_a) ? a[len_a - i - 1] : '0') - '0';
        int n_b = ((i < len_b) ? b[len_b - i - 1] : '0') - '0';

        int r = n_a + n_b + c;
        if (r >= 10) {
            c = 1;
            r -= 10;
        }
        else
            c = 0;

        result.insert(0, 1, '0' + r);
    }

    if (c > 0) {
        result.insert(0, 1, '1');
    }
}

    string r;

    nap_add(r, "0", "1");
    assert(r == "1");
    nap_add(r, "1", "9");
    assert(r == "10");
    nap_add(r, "91", "10");
    assert(r == "101");
    nap_add(r, "101", "99");
    assert(r == "200");
```

	
### 课堂练习

（二十分钟内完成）

1) 复制上述 `nap_add()` 函数并实现 `nap_add_to()` 函数，保存为 `nap-arithmetic.cpp`。
2) 调试通过后提交到自己的作业仓库（`source/cpp/lesson-5/` 目录下，下同）。

	
### 自然数乘法

```cpp
void nap_mul(string &result, const string &a, const string &b)
{
    string times = "0";

    result = "0";
    while (b != times) {
        string tmp;
        nap_add(tmp, result, a);
        result = tmp;

        nap_add(tmp, times, "1");
        times = tmp;
    }
}

    string r;

    nap_mul(r, "2", "2");
    assert(r == "4");
    nap_mul(r, "2", "10");
    assert(r == "20");
    nap_mul(r, "20", "20");
    assert(r == "400");
    nap_mul(r, "11", "11");
    assert(r == "121");
```

	
### 课堂练习

（十分钟内完成）

1) 复制上述 `nap_mul()` 函数并调用 `nap_add_to()` 实现 `nap_mul_alt()` 函数，保存到 `nap-arithmetic.cpp` 文件中。
2) 调试通过后提交到自己的作业仓库。

	
### 竖式乘法

```cpp
void nap_mul_alt(string &r, const string &a, const string &b)
{
    r.clear();

    size_t len_a = a.length();
    size_t len_b = b.length();
    size_t len_r = 0;

    for (size_t i = 0; i < len_a; i++) {
        int digit_a = a[len_a - i - 1] - '0';

        int carry = 0;
        for (size_t j = 0; j < len_b; j++) {
            int digit_b = b[len_b - j - 1]  - '0';

            int p = digit_a * digit_b + carry;
            if (p >= 10) {
                carry = p / 10;
                p %= 10;
            }
            else {
                carry = 0;
            }

            size_t k = j + i;
            if (k >= len_r) {
                r.insert(0, 1, '0' + p);
                len_r++;
            }
            else {
                int digit_r = r[len_r - k - 1]  - '0';
                digit_r += p;
                if (digit_r >= 10) {
                    carry++;
                    digit_r -= 10;
                }

                r[len_r - k - 1] = '0' + digit_r;
            }
        }

        if (carry > 0) {
            r.insert(0, 1, '0' + carry);
            len_r++;
            carry = 0;
        }

        assert(len_r == r.length());
    }
}
```

	
### 阶乘

```cpp
void nap_factorial(string &r, const string &n)
{
    if (n.empty() or n == "0") {
        r = "1";
        return;
    }

    string times = "1";

    r = n;
    while (n != times) {
        string tmp;
        nap_mul_alt(tmp, r, times);
        r = tmp;

        nap_add_to(times, "1");
    }
}

    string r;

    nap_factorial(r, "0");
    assert(r == "1");
    nap_factorial(r, "1");
    assert(r == "1");
    nap_factorial(r, "2");
    assert(r == "2");
    nap_factorial(r, "3");
    assert(r == "6");
    nap_factorial(r, "4");
    assert(r == "24");
    nap_factorial(r, "5");
    assert(r == "120");
```

	
### 课堂练习

（十分钟内完成）

1) 复制上述代码并实现 `nap_factorial_recursive()` 函数，即阶乘的递归函数。
2) 编译调试通过后提交到自己的作业仓库（`source/cpp/lesson-4/` 目录下）。

		
## 基于 `vector` 的实现

- 用一个 `int8_t` 表示十进制的两位数字。
- 使用 `vector<int8_t>` 从数值的低位开始存储，每个单元表示两位十进制数字。
- 设计为 `BigInt` 类，以方便提供多种构造方法以及运算符重载等能力。

		
### 类的定义

```cpp
#include <vector>
#include <string>
#include <cstdint>

using namespace std;

class BigInt {
    bool _sign;
    vector<int8_t> _bytes;

  public:
    // 默认构造器
    BigInt() {
        _sign = false;
        _bytes.push_back(0);
    }

    // 构造器
    BigInt(intmax_t ll);
    BigInt(const std::string& str);
    BigInt(const BigInt &other);            // 复制构造器

    // 属性获取器
    bool sign() const { return _sign; }
    const vector<int8_t>& bytes() const { return _bytes; }

    // 重载运算符
    BigInt& operator+ (const BigInt& other) const;
    BigInt& operator- (const BigInt& other) const;
    BigInt& operator- () const;             // -bi

    BigInt& operator++ ();                  // ++bi
    BigInt& operator++ (int);               // bi++

    BigInt& operator-- ();                  // --bi
    BigInt& operator-- (int);               // bi--

    BigInt& operator* (const BigInt& other) const;
    BigInt& operator*= (const BigInt& other);

    BigInt& operator/ (const BigInt& other) const;
    BigInt& operator/= (const BigInt& other);

    BigInt& operator= (const BigInt& other) const;
    BigInt& operator+= (const BigInt& other);
    BigInt& operator-= (const BigInt& other);

    bool operator== (const BigInt& other) const;
    bool operator!= (const BigInt& other) const;
    bool operator> (const BigInt& other) const;
    bool operator>= (const BigInt& other) const;
    bool operator< (const BigInt& other) const;
    bool operator<= (const BigInt& other) const;
};
```

		
### 构造器

```cpp
BigInt::BigInt(intmax_t ll) {
    if (ll < 0) {
        _sign = true;
        ll = -ll;
    }
    else
        _sign = false;

    for (size_t i = 0; i < sizeof(intmax_t); i++) {
        if (ll == 0)
            break;

        int8_t r = ll % 100;
        _bytes.push_back(r);
        ll /= 100;
    }
}

BigInt::BigInt(const string& str) {
    size_t len = str.length();
    if (len == 0) {
        _sign = false;
        _bytes.push_back(0);
        return;
    }

    if (str[0] == '-')
        _sign = true;
    else
        _sign = false;

    size_t left = _sign ? len - 1 : len;
    while (left > 0) {
        string digits;
        size_t pos = len - left;
        if (left > 1) {
            digits = str.substr(pos, 2);
            left -= 2;
        }
        else {
            digits = str.substr(pos, 1);
            left -= 1;
        }

        int r = stoi(digits);
        _bytes.push_back(r);
    }
}

BigInt::BigInt(const BigInt &other)
{
    _sign = other.sign();
    _bytes = other.bytes();
}
```

	
### 重载 `<<` 运算符

```cpp
ostream& operator<< (ostream& os, const BigInt& bi) {
    if (bi.sign()) {
        os << "-";
    }

    auto bytes = bi.bytes();
    for (auto it = end(bytes); ; --it) {
        if (it == end(bytes))
            continue;

        os << (int)*it;
        if (it == begin(bytes))
            break;
    }

    return os;
}
```

	
### 重载 `+` 运算符

```cpp
```

		
## 作业

1) 给定正整数 `n`，给出 `0! + 1! + 2! + ... + n!` 的结果（阶乘之和）。运行效果如下：

```console
$ ./summary-of-factorials
<100>
94269001683709979260859834124473539872070722613982672442938359305624678223479506023400294093599136466986609124347432647622826870038220556442336528920420940313
```

2) 给定任意小数（正值），给出其最简分数表达。运行效果如下：

```console
$ ./rational-number-to-fraction
<0.3 1>        # 第二个数字表示循环位
1/3

$ ./rational-number-to-fraction
<48.8260869565217391304347 22>
1123/23
```

