# 经典编程题

数论相关

		
## 质数

- 质数（prime number）是指一个大于 1 的正整数，除了 1 和自身之外，没有第二个正整数可以整除它。最小的质数是 2。
- 编程找出尽可能多的质数。运行效果如下：

```console
$ ./prime-numbers
2
3
5
7
11
```

		
## 素数筛

- 素数（prime number）是指一个大于 1 的正整数，除了 1 和自身之外，没有第二个正整数可以整除它。最小的质数是 2。
- 素数筛（朴素筛、Eratosthenes 筛和 Euler 筛）的数学原理。
- 使用素数筛算法编程找出 16 位或 32 位无符号整数范围内的质数。运行效果如下：

	
```console
$ ./prime-numbers-sieve
2
3
5
7
11
13
17
19
23
29
...
65521
65519
65497
65479
65449
65447
65437
65423
65419
65413
Totally 6542 primes (0.000330209 seconds consumed).
```

		
## 素性测试

- 找出 64 位无符号整数范围内的所有质数。
   1. 根据质数分布定理 `$ \pi(n) \approx \frac{n}{\ln{n}} $`，在 64 位无符号整数范围内大致有 `415,828,534,307,635,072` 个素数，需要 `3,098,164,009` GB 存储空间。
   1. 在个人电脑上，试除法和素数筛算法都无法处理如此庞大数量的质数。
- 素性测试算法尝试在不分解给定自然数的情况下，确定给定的自然数是否为素数。分为确定性测试和概率测试两类。
- 确定性测试首先要找出合数的素因子，故而不具有编程实现的意义。
- 概率性测试的主要原理是利用质数的一些性质来测试给定自然数可能是质数的概率，当概率足够小时便认为其为质数。

	
- 问题：使用某种素性测试算法找出小于或大于等于 `$ 2^{32} $` 的前 `N` 个质数。运行效果如下：

```console
$ ./primality-test
<10>               # 指定要列出的质数数量
10
4294967291
4294967279
4294967231
4294967197
4294967189
4294967161
4294967143
4294967111
4294967087
4294967029
Totally 267 natural numbers tested (0.00195938 seconds consumed).
```

	
### 费马素性测试

- 依据费马（Fermat）小定理：若 `$ p $` 为素数，且 `$ \gcd (a, p) = 1 $`，则 `$ a^{p-1} \equiv 1 \ \pmod{p} $`。
或者，若 `$ p $` 为素数，对于任意整数 `$ a $`，有 `$ a^p \equiv a \ \pmod{p} $`。
- 关键代码（下页）

	
- `primality()` 函数对给定的自然数 `n` 执行费马素性测试。
- 在 `[2, n - 2]` 中随机取某个值作为底，然后调用 `quick_power_modulo()` 函数测试取模结果是否为 `1`。
- 执行至少 8 次测试，若任意一次不满足，则认为是合数，若都满足，则认为是素数。

```cpp
#define NR_TESTS        9

bool primality_fermat(uint32_t n)
{
    if (n <= UINT16_MAX)
        return check_prime(n);

    if ((n & 1) == 0)
        return false;

    // NR_TESTS 通常取 8 或以上。
    for (int i = 0; i < NR_TESTS; i++) {
        // 在 [2, n - 2] 中随机取某个值作为底进行测试。
        uint32_t base = static_cast<uint32_t>(random()) % (n - 2) + 2;
        if (quick_power_modulo(base, n - 1, n) != 1)
            return false;
    }

    return true;
}
```

	
- `quick_power_modulo()` 函数利用快速幂算法计算幂，为避免溢出，可同时执行取模操作，但需要使用更宽的整数类型。
- 其数学原理为：`$ ab \bmod p = \left( (a \bmod p) (b \bmod p) \right) \bmod p $`

```cpp
uint32_t quick_power_modulo(uint32_t base, uint32_t exp, uint32_t modulus)
{
    uint64_t ret = 1;
    uint64_t base_64 = base;

    while (exp) {
        if (exp & 1)
            ret = (ret * base_64) % modulus;
        base_64 = (base_64 * base_64) % modulus;
        exp >>= 1;
    }

    return static_cast<uint32_t>(ret);
}
```

	
### 米勒-拉宾素性测试

1. 费马素性测试存在的问题：费马小定理的逆定理并不成立。
   - 如果`$ a^{n−1} \equiv 1 \pmod n $` 但 `$ n $` 不是素数，则 `$ n $` 被称为以 `$ a $` 为底的 `伪素数`。比如 `$ n = 341 $` 且 `$ a = 2 $` 时，满足 `$ 2^{340}\equiv 1 {\pmod {341}} $`，但 `$ 341 = 11 \times 31 $` 是个合数。事实上，`$ 341 $` 是底最小的伪素数。
   - 甚至有些合数 `$ n $`，对任意满足 `$ a\perp n $` 的整数 `$ a $`，均有 `$ a^{n−1} \equiv 1 \pmod n $`，这样的数称为卡迈克尔（Carmichael）数。最小的卡迈克尔数是 `$ 561 = 3 \times 11 \times 17 $`。
1. 米勒-拉宾（Miller–Rabin）素性测试是对费马素性测试的改进，使用了二次探测定理：  
如果 `$ p $` 是奇素数，则 `$ x^2 \equiv 1 \pmod p $` 的解为 `$ x \equiv 1 \pmod p $` 或者 `$ x \equiv p - 1 \pmod p $`。
1. 提示：`$ x^2 \equiv 1 \pmod p $` 等价于 `$ (x+1)(x-1) \equiv 0 \bmod p $`。同余方程 `$ x^2 \equiv 1 \pmod n $` 除 `$ x \equiv 1 \bmod n $` 的任何根称为以 `n` 为模的 `1` 的非平凡平方根；若 `n` 存在以 `n` 为模的 `1` 的非平凡平方根，则 `n` 是合数。
1. 费马素性测试通常用于测试 32 位自然数，而米勒-拉宾素性测试可用于 64 位自然数和大整数。

	
- 实现原理：将 `$ a^{n-1} \equiv 1 \pmod n $` 中的指数 `$ n−1 $` 分解为 `$ n−1=u \times 2^t $`，在每轮测试中对随机选择的 `$ a $` 先求出 `$ v = a^{u} \bmod n $`，之后对这个值执行最多 `$ t $` 次平方操作，若发现非平凡平方根时即可判断出其不是素数，否则再使用费马素性测试判断。
- 通常使用米勒-拉宾素性测试对 `$ [1, 2^{64}) $` 范围内的数进行素性检验。对于 `$ [1, 2^{32}) $` 范围内的数，可选取 `$ \{2, 7, 61\} $` 三个数作为基底进行素性检验就可以确定素性；对于 `$ [1, 2^{64}) $` 范围内的数，选取 `$ \{2, 325, 9375, 28178, 450775, 9780504, 1795265022\} $` 七个数作为基底进行素性检验就可以确定素性。
- 也可以选取 `$ \{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37\} $`（即前 12 个素数）检验 `$ [1, 2^{64}) $` 范围内的素数。
- 注意：若广义黎曼猜想（generalized Riemann hypothesis, GRH）成立，则对数 `$ n $` 最多只需要测试 `$ [2, \min\{n-2, \lfloor 2\ln^2 n \rfloor\}] $` 中的全部整数即可确定数 `$ n $` 的素性。此时，米勒-拉宾素性测试就成了确定性素性测试。

	

```cpp
bool primality_miller_rabin(uint64_t n)
{
    static const uint64_t bases_32[] = {
        2, 7, 61,
    };

    static const uint64_t bases_64[] = {
        2, 325, 9375, 28178, 450775, 9780504, 1795265022ULL,
    };


    if (n < 3 || (n & 1) == 0)
        return n == 2;

    if (n % 3 == 0)
        return n == 3;

    uint64_t u = n - 1, t = 0;
    while (u % 2 == 0) {
        u /= 2, ++t;
    }

    const uint64_t *bases;
    int nr_tests;
    if (n <= UINT32_MAX) {
        bases = bases_32;
        nr_tests = sizeof(bases_32)/sizeof(bases_32[0]);
    }
    else {
        bases = bases_64;
        nr_tests = sizeof(bases_64)/sizeof(bases_64[0]);
    }

    for (int i = 0; i < nr_tests; i++) {
        uint64_t a = bases[i];
        uint64_t v = quick_power_modulo(a, u, n);
        if (v == 1)
            continue;

        uint64_t s;
        for (s = 0; s < t; ++s) {
            // 若得到平凡平方根 n-1，则通过此轮测试
            if (v == n - 1)
                break;
            v = v * v % n;
        }

        // 如果找到了非平凡平方根，则会由于无法提前 break; 而运行到 s == t
        // 如果费马素性测试无法通过，则一直运行到 s == t 前 v 都不会等于 -1
        if (s == t)
            return false;
    }

    return true;
}
```

	
- 选择固定的素数作为基数，溢出风险降低，但仍存在，故而需要改进 `quick_power_modulo()` 函数的实现。
- 使用了 G++ 和 Clang++ 在 64 位平台上的 `__int128` 非标准整数类型。

```cpp
uint64_t quick_power_modulo(uint64_t base, uint64_t exp, uint64_t modulus)
{
    uint64_t ret = 1;
    __int128 base_128 = base;

    while (exp) {
        if (exp & 1)
            ret = (ret * base_128) % modulus;
        base_128 = (base_128 * base_128) % modulus;
        exp >>= 1;
    }

    return ret;
}
```

		
## 亲和数

- 亲和数（amicable pair）是指一对正整数，第一个正整数的所有真因子之和等于第二个正整数，而第二个正整数的所有真因子之和等于第一个正整数。
- 编程找出尽可能多的亲和数。运行效果如下：

	
```console
$ ./amicable-numbers
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
176272 180848
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
```

		
## 亲和数的欧拉方法

- 亲和数（amicable pair）是指一对正整数，第一个正整数的所有真因子之和等于第二个正整数，而第二个正整数的所有真因子之和等于第一个正整数。
- 欧拉方法的数学原理。
- 使用欧拉方法编程找出尽可能多的亲和数。运行效果如下：

	
```console
$ ./amicable-numbers-euler
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
176272 180848
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
```

		
## 完美数

- 完美数（perfect number）是指其所有真因子之和等于自己的正整数。
- 编程找出尽可能多的完美数。运行效果如下：

```console
$ ./perfect-numbers
6
28
496
8128
```

		
## 自恋数/水仙花数

- 广义上的自恋数（narcissistic number）是指一个 `n` 位数（`n >= 3`）的十进制数，它每位上的数字的 `n` 次幂之和等于它本身。如 <code>371 = 3<sup>3</sup> + 7<sup>3</sup> + 1<sup>3</sup></code>，则 `371` 是一个三位的自恋数。
- 编程找出尽可能多的自恋数（水仙花数）。运行效果如下：

```console
$ ./narcissistic-numbers
153
370
371
407
1634
8208
9474
54748
92727
93084
548834
1741725
4210818
9800817
9926315
24678050
24678051
```

		
## 线性同余方程组和中国剩余定理

- 线性同余方程组的定义。
- 编程求解给定的线性同余方程组（各模数两两互质），要求给出至少十个解。运行效果如下：

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

		
## 裴蜀定理和扩展欧几里得算法

- 买菜的故事。
- 编程判定形如 `ax + by = d` 的不定方程（其中，`a, b, d` 为整数，均不等于 `0`）是否有整数解，若有解，给出 10 个解。运行效果如下：

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

	
裴蜀（Bezout）定理

- 若 `$ a, b $` 是不全为零的整数，且 `$ gcd(a, b) = d $`，则 `$ ax + by = m $` 有正整数解，当且仅当 `$ m $` 是 `$ d $` 的整数倍；若有解，则有无穷多个解。
- 设 `$ ax + by = d $` 的一个解是 `$ x_0, y_0 $`，且，`$ m_0 = \frac{m}{d} $`，则上述方程的解集为：

`$$
\left \{ \left( m_0 x_0 + \frac{kb}{d}, m_0 y_0 - \frac{ka}{d} \right) \vert k \in \mathbb{Z} \right \}
$$`

	
- 利用扩展欧几里得算法，在求最大公约数的同时求出 `$ x_0, y_0 $`：

```cpp
intmax_t ex_gcd(intmax_t a, intmax_t b, intmax_t& x, intmax_t& y)
{
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    intmax_t gcd = ex_gcd(b, a % b, x, y);
    intmax_t temp = x;
    x = y;
    y = temp - a / b * y;
    return gcd;
}
```

		
## 进制转换

- 进制转换有两种形式：
  1. 解析特定进制表达的字符串并转换为对应的整数。
  1. 将一个整数转换成指定进制表达的字符串。
- 进制转换的数学原理

	
- 编程将将用户输入的一个特定进制表达的数用十进制展示出来。运行效果如下：

```console
$ ./convert-string-in-specific-base
<56ABC 20>  # 第一个数值指定一个用于表达某个数值的字符串，第二个数字指定该字符串所表达的数值的进制，两者用空格分隔。
852232
```

	
- 编程将用户输入的一个自然数转换为 -36 到 36 的进制展示出来。运行效果如下：

	
```console
$ ./show-number-in-different-bases
<1900>
(11101101100)2
(1100010111100)-2
(2121101)3
(120102101)-3
(131230)4
(1203310)-4
(30100)5
(30100)-5
(12444)6
(24524)-6
(5353)7
(12423)-7
(3554)8
(15634)-8
(2541)9
(17651)-9
(1900)10
(19900)-10
(1478)11
(1A548)-11
(1124)12
(1B2A4)-12
(B32)13
(CA2)-13
(99A)14
(A5A)-14
(86A)15
(99A)-15
(76C)16
(8AC)-16
(69D)17
(78D)-17
(5FA)18
(63A)-18
(550)19
(6E0)-19
(4F0)20
(550)-20
(46A)21
(5FA)-21
(3K8)22
(428)-22
(3DE)23
(4AE)-23
(374)24
(4H4)-24
(310)25
(4O0)-25
(2L2)26
(352)-26
(2GA)27
(3BA)-27
(2BO)28
(3HO)-28
(27F)29
(3MF)-29
(23A)30
(3RA)-30
(1U9)31
(219)-31
(1RC)32
(25C)-32
(1OJ)33
(29J)-33
(1LU)34
(2DU)-34
(1JA)35
(2GA)-35
(1GS)36
(2KS)-36
```

		
## 高精度算术：求阶乘之和

- 给定自然数 `$ n \ (0 \le n \le 2^{32}-1) $`，给出 `$ 0! + 1! + 2! + \cdots + n! $` 的结果（阶乘之和）。运行效果如下：

```console
$ ./summary-of-factorials
<100>
94269001683709979260859834124473539872070722613982672442938359305624678223479506023400294093599136466986609124347432647622826870038220556442336528920420940314
```

	
### 高精度算术（字符串实现）：求和

```cpp
void nap_add_to(string &r, const string &a)
{
    size_t len_r = r.length();
    size_t len_a = a.length();
    size_t len_max = (len_r > len_a) ? len_r : len_a;

    int carry = 0;
    for (size_t i = 0; i < len_max; i++) {
        int value_r = ((i < len_r) ? r[len_r - i - 1] : '0') - '0';
        int value_a = ((i < len_a) ? a[len_a - i - 1] : '0') - '0';

        value_r += value_a + carry;
        if (value_r >= 10) {
            carry = 1;
            value_r -= 10;
        }
        else
            carry = 0;

        if (i >= len_r)
            r.insert(0, 1, '0' + value_r);
        else
            r[len_r - i - 1] = '0' + value_r;
    }

    if (carry > 0) {
        r.insert(0, 1, '1');
    }
}
```

		
## 高精度算术：求小于平方根的最大整数

- 给定一个任意长度的自然数，求小于等于其平方根的最大整数。运行效果如下：

```console
$ ./maximum-le-sqrt
<100>
10
$ ./maximum-le-sqrt
<1234567890>
35136
$ ./maximum-le-sqrt
<123456789098765432101234567890123456789>
11111111064999999904
```

	
### 二分搜索的典型实现

```cpp
template <class T>
const T* binary_search(const T* arr, const T& needle, size_t start, size_t end)
{
    const T* found = nullptr;

    size_t mid;
    while (start <= end) {
        mid = start + ((end - start) >> 1);
        if (arr[mid] < needle)
            start = mid + 1;
        else if (arr[mid] > needle)
            end = mid - 1;
        else {
            found = arr + mid;
            break;
        }
    }

    return found;
}
```

		
## 高精度算术：求商及余数

- 给定两个任意长度的正整数，计算相除的结果（整数商及余数）。运行效果如下：

```console
$ ./division-with-remainder
<11 13>
0 11
$ ./division-with-remainder
<78260869565217391304347826086956521 4347826086956521739130434782608695>
18 11
$ ./division-with-remainder
<100 0>
NO SOLUTION
```

		
## 整数的和式分解

- 整数（特指正整数）的和式分解指将给定的整数分解为若干个整数之和。
- 欧拉证明了将一个整数分解为不同的整数之和的方法数等于将该整数分解为可以相同的奇数之和的方法数。
- 给定任意正整数 `n`，列出用于计算 `D(n)` 和 `O(n)` 的所有可能形式。运行效果如下：

```console
$ ./dn-on
<3>
3
2 1
---
3
1 1 1
```

		
## 整数的因子分解

- 整数的因子分解（factorization）在计算机技术中有至关重要的意义。
- 挑战：性能和内置整数类型的有限范围。
- 实现方法：朴素算法及其优化版本、Pollard Rho 算法及其优化版本。
- 给定任意大于 1 的正整数，给出其所有质因子（重复的质因子只保留一个）。运行效果如下：

```console
$ ./prime-factors
<12>
2, 3.
$ ./prime-factors
<11>
11.
```

	
### 朴素算法

- 类似质数判定的试除法，在 `$ \left[ 2, \sqrt{n} \right] $` 中遍历。
- 找到一个因子再判断是否是质数？

	
### Pollard Rho 算法

- 

		
## 斐波那契数列

- 斐波那契数列（Fibonacci sequence）的定义及其神奇性质。
- 挑战：性能和整数溢出。
- 实现方法：递归、迭代、倍增法、通项公式。
- 计算指定序号（第一个的序号为 0）的斐波那契数值。运行效果如下：

```console
$ ./nth-fibonacci-number
<50>
12586269025

$ ./nth-fibonacci-number
<100>
OVERFLOWED
```

	
### 神奇性质之卡西尼恒等式

`$$
  F_{n+1}F_{n-1} -F^2_n = (-1)^n
$$`

- 此等式由意大利天文学家卡西尼于 1680 年发现，如 `$ 13 \times 5 - 8^2 = 1 $`。
- 一个几何障眼法。

	
### 倍增法

- 倍增法利用如下斐波那契数列的性质：

`$$
\begin{align}
  F_{2k}   & = F_k(2F_{k+1} - F_{k}) \\
  F_{2k+1} & = F^2_{k+1} + F^2_k
\end{align}
$$`

	
### 通项公式

- 通项公式（Binet's Formula）

`$$
F_{n} = \frac{\left( \frac{1 + \sqrt{5}}{2} \right)^n - \left( \frac{1 - \sqrt{5}}{2} \right)^n}{\sqrt{5}}
$$`

- 或，

`$$
F_{n} = \left[ \frac{\left( \frac{1 + \sqrt{5}}{2} \right)^n}{\sqrt{5}} \right]
$$`

		
## 有理数的最简分数表达

- 任意有理数（无限循环小数）都可以表达成两个整数的商，若这个两个整数互质，则构成一个最简分数表达。
- 给定一个十进制小数表达的有理数 `$ q $`（`$ q \ge 0 $`），给出其最简分数表达。运行效果如下：

```console
$ ./rational-number-to-fraction
<0.3 1>        # 第二个数字表示循环位
1/3

$ ./rational-number-to-fraction
<48.8260869565217391304347 22>
1123/23
```

		
## 平方根

- 给定正实数 `d`，给出其平方根小数点后 `n` 位上的数字。运行效果如下：

```console
$ ./nth-digit-after-decimal-point-of-sqrt
4 1000
0
```

		
## 彻底搞懂扩展欧几里得算法

- 扩展欧几里得算法的主要用途：
   1. 求 `ax + by = m` 不定方程之基础解。
   1. 求乘法逆元。
- 扩展欧几里得算法的递归实现：

```cpp
intmax_t ex_gcd(intmax_t a, intmax_t b, intmax_t& x, intmax_t& y)
{
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    intmax_t gcd = ex_gcd(b, a % b, x, y);
    intmax_t temp = x;
    x = y;
    y = temp - a / b * y;
    return gcd;
}
```

	
### 扩展欧几里得算法的数学基础

- 裴蜀（Bezout）定理
   1. 若 `$ a, b $` 是不全为零的整数，且 `$ gcd(a, b) = d $`，则 `$ ax + by = m $` 有正整数解，当且仅当 `$ m $` 是 `$ d $` 的整数倍；若有解，则有无穷多个解。
   1. 设 `$ ax + by = d $` 的一个解是 `$ x_0, y_0 $`，且，`$ m_0 = \frac{m}{d} $`，则上述方程的解集为：

`$$
\left \{ \left( m_0 x_0 + \frac{kb}{d}, m_0 y_0 - \frac{ka}{d} \right) \vert k \in \mathbb{Z} \right \}
$$`

- 裴蜀定理的几个推论
   1. 若方程 `$ ax + by = m $` 有整数解，则 `$ bx + \left( a \bmod b \right)y = m $` 亦有整数解。
   1. 若方程 `$ ax + by = d $` 有整数解，且 `$ b \mid a $`，亦即 `$ a \bmod b = 0 $`，则有 `$ b = d $`，且 `$ \left( x = 1, y = 1 - \frac{a}{b} \right) $` 是该方程的一个解。
   1. 若对方程 `$ bx + \left( a \bmod b \right) y = d $` 可求得一个整数解 `$ \left(\phi, \psi \right) $`，且 `$ \left( a \bmod b \right) = \left( a - qb \right) $`，则 `$ \left( \psi, (\phi - q\psi) \right) $` 是方程 `$ ax + by = d $` 的一对整数解。

	
### 欧几里得算法

- 欧几里得算法（辗转相除法）可用来求最大公约数。
- 数学基础：`$ \gcd (a, b) = \gcd (b, b \bmod a) $`

```cpp
intmax_t gcd_r(intmax_t a, intmax_t b)
{
    if (b == 0) {
        return a;
    }

    return gcd_r(b, a % b);
}

intmax_t gcd_i(intmax_t a, intmax_t b)
{
    while (b != 0) {
        intmax_t tmp = a;
        a = b;
        b = tmp % b;
    }

    return a;
}
```

	
### 扩展欧几里得算法的递归实现

- 按推论 2，在欧几里得算法的递归终止时，可求得最大公约数 `$ d $`，且可针对方程 `$ ax + by = d $`，求得在 `$ b \mid a $`，亦即 `$ a \bmod b = 0 $` 时的一对解：`$ \left( x = 1, y = 1 - \frac{a}{b} \right) $` 是该方程的一对解。
- 按推论 3，在欧几里得算法递归的过程中，根据上一轮迭代的结构，可求得本一轮方程 `$ ax + by = d $` 的一对解。
- 欧几里得算法最终返回时，就求得了 `$ ax + by = d $` 的基础解：`$ \left( x_0, y_0 \right) $`。

```cpp
intmax_t ex_gcd_r(intmax_t a, intmax_t b, intmax_t& x, intmax_t& y)
{
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    intmax_t gcd = ex_gcd_r(b, a % b, x, y);
    intmax_t temp = x;
    x = y;
    y = temp - a / b * y;
    return gcd;
}
```

	
### 扩展欧几里得算法的迭代实现

- 辗转相除法的每个步骤，确保了方程 `$ ax + by = r_{i} $` 有一对整数解，直到 `$ r_{i} $` 等于 `$ \gcd(a, b) $` 为止。比如对第一步有整数解 `$ \left( 1, -q \right) $`，其中 `$ q = \left[ \frac{a}{b} \right] $`。
- 辗转相除法的每个步骤，都在为下一步确定一个新的余数（`$ r_{i+1} $`），使得前一步的余数（`$ r_{i-1} $`）和当前步骤的余数（`$ r_{i} $`）满足：`$ r_{i+1} = qr_{i} + r_{i-1} $`。因此有：

`$$
\begin{align}
x_{i+1} & = x_{i} − qx_{i-1} \\
y_{i+1} & = y_{i} − qy_{i-1}
\end{align}
$$`

- 辗转相除法终止时，即可求得最大公约数 `$ \gcd(a, b) $` 以及满足 `$ ax + by = d $` 的一对解。
- 而方程 `$ ax + by = a $` 始终有一对整数解 `$ (1, 0) $`；而方程 `$ ax + by = b $` 始终有一对整数解 `$ (0, 1) $`，可作为前一步骤的解和当前步骤的解。

	

```cpp
intmax_t ex_gcd_i(intmax_t a, intmax_t b, intmax_t& x, intmax_t& y)
{
    intmax_t prev_x, prev_y;

    prev_x = 0; prev_y = 1;
    x = 1; y = 0;
    while (b != 0) {
        intmax_t q = a / b;

        intmax_t tmp;
        tmp = prev_x; prev_x = prev_x - q * x; prev_x = x;
        tmp = prev_y; prev_y = prev_y - q * y; prev_y = y;
        tmp = b; b = a % b; a = tmp;
    }

    x = prev_x; y = prev_y;
    return a;
}
```

