# 任意精度计算的 C++ 实现

1. 任意精度计算要解决的问题
1. 实现原理和方法
1. 基于 `string` 的实现
1. 基于 `vector` 的实现
1. 实用技巧

		
## 任意精度计算要解决的问题

- C/C++ 的整型数据表达范围有限，而浮点数的精度不足。
- C/C++ 的 `uint64_t` 类型的最大值为 `18446744073709551615`。
- 64 位的双精度浮点数只能精确表达 32 位整数。
- 128 位的长精度浮点数只能精确表达 64 位整数。
- Python 的 `int` 类型是无限精度的，可表达范围取决于计算机的内存。
- 任意精度或者高精度计算是信奥或者编程比赛的常见题型。

	
### 低精度计算的问题：以阶乘为例

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

- 需要自行实现各种基本的算术运算功能（加、减、乘、除、模）。
- 性能无法和基于基本数据类型的计算比较；但第二种方法可充分利用基于基本数据类型的运算，性能更好。

		
## 基于 `string` 的实现

### 自然数加法

```cpp
/* 结果通过第一个引用参数返回 */
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

/* 直接返回临时变量；将启用 string 的移动构造器 */
string nap_add(const string &a, const string &b)
{
    string result;
    size_t len_a = a.length();
    size_t len_b = b.length();
    size_t len_max = (len_a > len_b) ? len_a : len_b;

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

    return result;
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

    r = nap_add("0", "1");
    assert(r == "1");
    r = nap_add("1", "9");
    assert(r == "10");
    r = nap_add("91", "10");
    assert(r == "101");
    r = nap_add("101", "99");
    assert(r == "200");
```

	
### 课堂练习

（二十分钟内完成）

1) 复制上述 `nap_add()` 函数并实现 `nap_add_to()` 函数，保存为 `nap-arithmetic.cpp`。
2) 调试通过后提交到自己的作业仓库（`source/cpp/lesson-6/` 目录下，下同）。

	
### 自然数乘法

```cpp
string nap_mul(const string &a, const string &b)
{
    string result = "0";
    string times = "0";

    while (b != times) {
        result = nap_add(result, a);
        times = nap_add(times, "1");
    }

    return result;
}

    string r;

    r = nap_mul("2", "2");
    assert(r == "4");
    r = nap_mul("2", "10");
    assert(r == "20");
    r = nap_mul("20", "20");
    assert(r == "400");
    r = nap_mul("11", "11");
    assert(r == "121");
```

	
### 课堂练习

（十分钟内完成）

1) 复制上述 `nap_mul()` 函数并调用 `nap_add_to()` 实现 `nap_mul_op()` 函数，保存到 `nap-arithmetic.cpp` 文件中。
2) 调试通过后提交到自己的作业仓库。

	
### 竖式乘法

```cpp
/* Use vertical multiplication method */
string nap_mul_alt(const string &a, const string &b)
{
    string r;

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

    return r;
}
```

	
### 阶乘

```cpp
// Use vector<string> to cache the factorial result
static vector<string> cached_factorial(50);

string nap_factorial(const string &n)
{
    string r;
    size_t native_n;
    string times = "1";

    native_n = (size_t)stoul(n);
    if (native_n < cached_factorial.size() &&
            cached_factorial[native_n] != "") {
        r = cached_factorial[native_n];
        goto done;
    }

    if (n.empty() or n == "0") {
        r = "1";
        goto done;
    }

    r = n;
    while (n != times) {
        r = nap_mul_alt(r, times);
        nap_add_to(times, "1");
    }

    // cached the result
    if (native_n < cached_factorial.size()) {
        cached_factorial[native_n] = r;
    }
    else {
        cached_factorial.resize(native_n + 1, "");
        cached_factorial[native_n] = r;
    }

done:
    return r;
}

    string r;

    r = nap_factorial("0");
    assert(r == "1");
    r = nap_factorial("1");
    assert(r == "1");
    r = nap_factorial("2");
    assert(r == "2");
    r = nap_factorial("3");
    assert(r == "6");
    r = nap_factorial("4");
    assert(r == "24");
    r = nap_factorial("5");
    assert(r == "120");
```

	
### 课堂练习

（十分钟内完成）

1) 在 `nap_factorial()` 函数基础上实现 `nap_factorial_recursive()` 函数，即阶乘的递归实现，并保留缓存功能。
2) 编译调试通过后提交到自己的作业仓库。

		
## 基于 `vector` 的实现

- 用一个 `int8_t` 表示十进制的两位数字（相当于提供基于 100 进制的整数运算）。
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
    BigInt() {
        _sign = false;
    }

    BigInt(intmax_t native_int);
    BigInt(const std::string& str);
    BigInt(const BigInt& other);            // copy constructor
    BigInt(BigInt&& other);                 // move constructor

    // getters
    bool sign() const { return _sign; }
    const vector<int8_t>& bytes() const { return _bytes; }

    // customized operators
    BigInt& operator= (const BigInt& other);    // copy assignment operator
    BigInt& operator= (BigInt&& other);         // move assignment operator
    BigInt& operator= (intmax_t other);

    BigInt  operator+  (const BigInt& other) const;
    BigInt& operator+= (const BigInt& other);
    BigInt  operator+  (intmax_t other) const;
    BigInt& operator+= (intmax_t other);

    BigInt  operator-  () const;             // -bi

    BigInt  operator-  (const BigInt& other) const;
    BigInt& operator-= (const BigInt& other);
    BigInt  operator-  (intmax_t other) const;
    BigInt& operator-= (intmax_t other);

    BigInt& operator++ ();                  // ++bi
    BigInt& operator++ (int);               // bi++

    BigInt& operator-- ();                  // --bi
    BigInt& operator-- (int);               // bi--

    BigInt  operator*  (const BigInt& other) const;
    BigInt& operator*= (const BigInt& other);
    BigInt  operator*  (intmax_t other) const;
    BigInt& operator*= (intmax_t other);

    BigInt  operator/  (const BigInt& other) const;
    BigInt& operator/= (const BigInt& other);
    BigInt  operator/  (intmax_t other) const;
    BigInt& operator/= (intmax_t other);

    BigInt  operator%  (const BigInt& other) const;
    BigInt& operator%= (const BigInt& other);
    BigInt  operator%  (intmax_t other) const;
    BigInt& operator%= (intmax_t other);

    bool operator== (const BigInt& other) const;
    bool operator!= (const BigInt& other) const;
    bool operator>  (const BigInt& other) const;
    bool operator>= (const BigInt& other) const;
    bool operator<  (const BigInt& other) const;
    bool operator<= (const BigInt& other) const;

    bool operator== (intmax_t other) const;
    bool operator!= (intmax_t other) const;
    bool operator>  (intmax_t other) const;
    bool operator>= (intmax_t other) const;
    bool operator<  (intmax_t other) const;
    bool operator<= (intmax_t other) const;

  private:
    BigInt absadd(const BigInt& other) const;
    void   absaddto(const BigInt& other);
    int    abscmp(const BigInt& other) const;
    ...
};

void factorial(BigInt& result, unsigned n)
{
    if (n > 1) {
        factorial(result, n - 1);
        result *= n;
    }
    else
        result = 1;
}

    BigInt a(1234567890);
    BigInt b("2345");

    a += b;
    cout << a / b << endl;

    BigInt fact;
    factorial(fact, 100);       // 100!
    cout << fact << endl;
```

		
### 构造器

```cpp
BigInt::BigInt(intmax_t native_int)
{
    if (native_int < 0) {
        _sign = true;
        native_int = -native_int;
    }
    else
        _sign = false;

    for (size_t i = 0; i < sizeof(intmax_t); i++) {
        if (native_int == 0)
            break;

        int8_t r = native_int % 100;
        _bytes.push_back(r);
        native_int /= 100;
    }
}

BigInt::BigInt(const string& str)
{
    size_t len = str.length();
    if (len == 0) {
        _sign = false;
        _bytes.clear();
        return;
    }

    if (str[0] == '-')
        _sign = true;
    else
        _sign = false;

    size_t left = len;
    size_t two_digits = _sign ? 2 : 1;
    size_t one_digit = _sign ? 1 : 0;
    while (left > 0) {
        string digits;
        if (left > two_digits) {
            digits = str.substr(left - 2, 2);
            left -= 2;
        }
        else if (left > one_digit) {
            digits = str.substr(left - 1, 1);
            left -= 1;
        }

        if (digits.empty()) {
            break;
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

	
### 重载 `=` 运算符

```cpp
BigInt& BigInt::operator= (const BigInt& other)
{
    _sign = other._sign;
    _bytes = other._bytes;
    return *this;
}

BigInt& BigInt::operator= (intmax_t native_int)
{
    BigInt tmp(native_int);
    _sign = tmp._sign;
    _bytes = std::move(tmp._bytes);
    return *this;
}
```

	
### 重载 `==` 运算符

```cpp
int BigInt::abscmp(const BigInt& other) const
{
    size_t len_a = this->_bytes.size();
    size_t len_b = other._bytes.size();
    size_t len_max = (len_a > len_b) ? len_a : len_b;

    size_t i = len_max;
    while (i > 0) {
        int n_a = (i - 1 < len_a) ? this->_bytes[i - 1] : 0;
        int n_b = (i - 1 < len_b) ? other._bytes[i - 1] : 0;

        int cmp = n_a - n_b;
        if (cmp != 0)
            return cmp;

        i--;
    }

    return 0;
}

bool BigInt::operator== (const BigInt& other) const
{
    if (_sign == other._sign && abscmp(other) == 0)
        return true;

    return false;
}
```

		
## 实用技巧

		
## 作业

1) 给定正整数 `n`，给出 `0! + 1! + 2! + ... + n!` 的结果（阶乘之和）。运行效果如下：

```console
$ ./summary-of-factorials-nap
<100>
94269001683709979260859834124473539872070722613982672442938359305624678223479506023400294093599136466986609124347432647622826870038220556442336528920420940314
```

	
2) 给定两个任意长度的正整数，计算相除的结果（整数商及余数）。运行效果如下：

```console
$ ./nap-divide
<11 13>
0 11
$ ./nap-divide
<78260869565217391304347826086956521 4347826086956521739130434782608695>
18 11
$ ./nap-divide
<100 0>
Bad
```

	
3) 给定任意小数（正值），给出其最简分数表达。运行效果如下：

```console
$ ./rational-number-to-fraction
<0.3 1>        # 第二个数字表示循环位
1/3

$ ./rational-number-to-fraction
<48.8260869565217391304347 22>
1123/23
```

	
4) 给定任意自然数 `a` 和 `n`，使用快速幂（二进制取幂，Binary Exponentiation）算法计算 <code>a<sup>n</sup></code>。运行效果如下：

```console
$ ./binary-power
<23 50>
122008981252869411022491112993141891091036959856659100591281395343249
```

	
5) 实现 `BigInt` 类的 `+`、`+=`、`++`、`*` 和 `*=` 运算符，并使用 `BigInt` 实现阶乘之和。运行效果如下：

```console
$ ./summary-of-factorials-bigint
<500>
1222581999810786173488382263893486121736784649845260488587055662127413631697914209099541725989446667613701624271378831210621838417780811766002473336942870600195037012201905233810236995284666050368045972495314286948596890492959045138704466475196055082304091214424335155644013903958356823605973150159110295578782843348252925883263557585556478987722745938465211447729783160621865568392455888286712354379272785542107324774997192436923989074655546365212898701875799458234466791378320221140358905721655475503366304295011345436395868843079546378053608723961924505161575921825309198649451288200312309059880509012275371359184552944166761037071150384173845166703990330636505622758303549033598720775172343137459008549361297203752431405977559950082400276439557196120290170551660607313565028810793747453185145183036587639267895948090547733582550623337958494636037989666434209666688780729576638277517618320396232253506068607096479320263132522604054741925038640750661849690108363701190203548476572823422774327197718781800269558204647391176582851167312182026188795156620056856503340092247479478684738621107994804323593105039052556442336528920420940314
```

	
### 参考链接

- [高精度计算](https://oi-wiki.org/math/bignum/)
- [快速幂](https://oi-wiki.org/math/binary-exponentiation/)

