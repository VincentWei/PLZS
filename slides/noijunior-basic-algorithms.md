# 基础算法

1. 算法的重要性
1. 算法复杂度的衡量
1. 常用简单算法
1. 递归
1. 二分法
1. 倍增法
1. 实用技巧

		
## 算法的重要性

- 自然数的素性判定（朴素版本）

```cpp
bool check_prime_plain(uint64_t n)
{
    if (n < 2)
        return false;

    for (uint64_t i = 2; i < n; i++) {
        if (n % i == 0)
            return false;
    }

    return true;
}
```

	
- 自然数的素性判定（优化版本）


```cpp
bool check_prime_opt(uint64_t n)
{
    if (n < 2)
        return false;
    else if (n == 2)
        return true;

    uint64_t max = llroundl(sqrtl(n));

    for (uint64_t i = 2; i <= max; i++) {
        if (n % i == 0)
            return false;
    }

    return true;
}
```

	
- 自然数的素性判定（素数筛）

```cpp
bool is_next_prime(uint64_t n, const uint64_v& primes_sieved)
{
    uint64_t mid = llroundl(sqrtl(n));

    for (uint64_t prime: primes_sieved) {
        if (prime > mid) {
            break;
        }

        if (n % prime == 0) {
            return false;
        }
    }

    return true;
}

uint64_v sieve_primes(uint64_t max)
{
    uint64_v primes_sieved;

    if (max < 2)
        goto done;

    primes_sieved.push_back(2);
    for (uint64_t n = 3; n <= max; n += 2) {
        if (is_next_prime(n, primes_sieved)) {
            primes_sieved.push_back(n);
        }
    }

done:
    return primes_sieved;
}

bool check_prime_sieved(const uint64_v& primes_sieved, uint64_t n)
{
    return binary_search(primes_sieved.begin(), primes_sieved.end(), n);
}

    // 作为示例，仅筛出 UINT16_MAX 及以下的素数。
    uint64_v primes_sieved = sieve_primes(UINT16_MAX);

    uint16_t n;
    cin >> n;
    cout << (check_prime_sieved(primes_sieved, n) ? "True" : "False") << endl;
```

	
- 自然数的素性判定（事先准备的自然数素性数组）
- [完整程序](https://gitee.com/vincentwei7/PLZS/blob/main/source/noi-csp-j/lesson-1/check-prime.cpp)

```cpp
// 作为示例，仅给出 UINT16_MAX 及以下自然数的素性值。
static bool primalities[UINT16_MAX + 1];

bool check_prime_linear(uint64_t n)
{
    if (n > UINT16_MAX) {
        assert(0);
    }

    return primalities[n];
}

    /* 使用素数筛中的素数初始化素性数组 */
    for (uint64_t prime: primes_sieved) {
        primalities[prime] = true;
    }

    uint16_t n;
    cin >> n;
    cout << (check_prime_sieved(primes_sieved, n) ? "True" : "False") << endl;
```

		
## 算法复杂度的衡量

- 衡量算法复杂度（complexity）的两个维度：
   1. 时间复杂度：用于衡量执行效率。
   1. 空间复杂度：用于衡量内存等资源的消耗。
- 大 O 复杂度表示法：用于表示代码执行时间或者内存占用随数据规模增长的变化趋势。
   1. `O(N)`：表示复杂度与数据项的个数 `n` 线性相关。比如素性判定的普通版本之时间复杂度。
   1. `O(sqrt(N))`：表示复杂度与数据项的个数之算术平方根 `sqrt(N)` 线性相关。比如素性判定的优化版本之时间复杂度。
   1. `O(log(N))`：表示复杂度与数据项的个数之对数 `log(N)` 线性相关（无关对数的底到底是多少）。比如在事先筛好的素数矢量中查找给定的数，从而判定是否为素数的算法之时间复杂度。
   1. `O(1)`：表示常量级的复杂度，比如基本的四则运算、取地址、反引用、访问数组中给定的单元等。比如将给定范围的自然数素性保存为数组，以给定自然数为数组下标直接返回对应的素性真假值的时间复杂度。

	
### 程序运行时间的测量

- 使用 Shell 命令 `time` 或者 `/usr/bin/time` 命令运行一个程序：

```console
$ time ./check-prime

real    0m0.036s
user    0m0.031s
sys     0m0.005s

$ /usr/bin/time -v ./check-prime
	Command being timed: "./check-prime"
	User time (seconds): 0.02
	System time (seconds): 0.00
	Percent of CPU this job got: 93%
	Elapsed (wall clock) time (h:mm:ss or m:ss): 0:00.03
	Average shared text size (kbytes): 0
	Average unshared data size (kbytes): 0
	Average stack size (kbytes): 0
	Average total size (kbytes): 0
	Maximum resident set size (kbytes): 3072
	Average resident set size (kbytes): 0
	Major (requiring I/O) page faults: 0
	Minor (reclaiming a frame) page faults: 158
	Voluntary context switches: 1
	Involuntary context switches: 4
	Swaps: 0
	File system inputs: 0
	File system outputs: 0
	Socket messages sent: 0
	Socket messages received: 0
	Signals delivered: 0
	Page size (bytes): 4096
	Exit status: 0
```

	
- 代码中，使用 STL `<chrono>` 头文件提供的接口：
   1. `std::chrono::system_clock`：系统时钟（墙钟）。
   1. `std::chrono::steady_clock`：单调增长时钟，更适合用来计算执行某段代码的时长，但会包含当前线程的休眠时间。

```cpp
#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>

    using namespace std::chrono;

    // 获取起始时间；
    // 这里的 steady_clock::now() 是 steady_clock 类的静态方法，无需实例化即可调用。
    steady_clock::time_point t1 = steady_clock::now();

    // TODO：这里调用算法相关代码或函数...

    // 获取终止时间。
    steady_clock::time_point t2 = steady_clock::now();

    // 计算间隔时间（默认计时单位为秒，使用 double 类型存储）。
    // 这里的 duration 是类模板；
    // duration_cast 是在不同 duration 单位间执行强制转换的函数模板。
    duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

    // time_span.count() 方法返回计时单位的表述值。
    std::cout << "It took me " << time_span.count() << " seconds." << std::endl;
```

	
- 在 Linux/macOS 上，使用 `<ctime>` 头文件提供的 `clock_gettime()` 操作系统接口，该接口提供如下时钟：
   1. `CLOCK_REALTIME`：系统实时时钟（墙钟）；`std::chrono::system_clock` 的实现基于该时钟。
   1. `CLOCK_MONOTONIC`：单调增长时钟；`std::chrono::steady_clock` 的实现基于该时钟。
   1. `CLOCK_PROCESS_CPUTIME_ID`：当前进程占用的 CPU 时间；可精确计算当前进程真正用于代码执行的时间。
   1. `CLOCK_THREAD_CPUTIME_ID`：当前线程占用的 CPU 时间；可精确计算当前线程真正用于代码执行的时间。

```c
#include <time.h>

struct timespec {
    time_t   tv_sec;        /* seconds */
    long     tv_nsec;       /* nanoseconds */
};

int clock_gettime(clockid_t clockid, struct timespec *tp);
```

	
- `clock_gettime()` 的用法：

```c
#include <time.h>

/* 计算间隔时间，以秒为单位。 */
double calc_elapsed_seconds(const struct timespec *ts_from,
        const struct timespec *ts_to)
{
    struct timespec ts_curr;
    time_t ds;
    long dns;

    if (ts_to == NULL) {
        clock_gettime(CLOCK_THREAD_CPUTIME_ID, &ts_curr);
        ts_to = &ts_curr;
    }

    ds = ts_to->tv_sec - ts_from->tv_sec;
    dns = ts_to->tv_nsec - ts_from->tv_nsec;
    return ds + dns * 1.0E-9;
}

    struct timespec t1;
    clock_gettime(CLOCK_THREAD_CPUTIME_ID, &t1);

    // TODO：这里调用算法相关代码或函数...

    struct timespec t2;
    clock_gettime(CLOCK_THREAD_CPUTIME_ID, &t2);

    double duration = calc_elapsed_seconds(&t1, &t2);
    std::cout << "It took me " << duration << " seconds." << std::endl;
```

		
## 常用简单算法

	
### 找最值

#### 两个值中找最大、最小值

- 朴素版本
- 时间复杂度：`O(1)`
- 空间复杂度：`O(1)`

```cpp
double max(double a, double b)
{
    return (a > b) ? b : a;
}

double min(double a, double b)
{
    return (a < b) ? b : a;
}
```

	
- 泛型版本（函数模板）
- 时间复杂度：`O(1)`
- 空间复杂度：`O(1)`
- [完整程序](https://gitee.com/vincentwei7/PLZS/blob/main/source/noi-csp-j/lesson-1/extrema-in-pair.cpp)

```cpp
template <class T>
const T& max(const T& a, const T& b)
{
    return (a > b) ? b : a;
}

template <class T>
const T& min(const T& a, const T& b)
{
    return (a < b) ? b : a;
}
```

	
#### 课堂练习

（十分钟内完成）

1. 实现从三个值中找最大、最小值的两个函数模板，并调用该函数模板实现一个完整的程序 `extrema-in-triple.cpp`。
1. 将 `extrema-in-triple.cpp` 文件添加到 `plzs-homework` 仓库的 `source/noi-csp-j/lesson-1/` 目录（下同），并推送到远程仓库。

	
#### 无序数组中找最大、最小值

- 朴素版本
- 时间复杂度：`O(N)`
- 空间复杂度：`O(1)`

```cpp
double max(const double* arr, size_t nr)
{
    assert(nr > 0);

    double max = arr[0];
    if (nr > 1) {
        for (size_t i = 1; i < nr; i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }
    }

    return max;
}

double min(const double* arr, size_t nr)
{
    assert(nr > 0);

    double min = arr[0];
    if (nr > 1) {
        for (size_t i = 1; i < nr; i++) {
            if (min > arr[i]) {
                min = arr[i];
            }
        }
    }

    return min;
}
```

	
- 泛型版本（函数模板）
- 时间复杂度：`O(N)`
- 空间复杂度：`O(1)`
- [完整程序](https://gitee.com/vincentwei7/PLZS/blob/main/source/noi-csp-j/lesson-1/extrema-in-array.cpp)

```cpp
template <class T>
const T& max(const T* arr, size_t nr)
{
    assert(nr > 0);

    const T* max = arr;
    for (size_t i = 1; i < nr; i++) {
        if (arr[i] > *max) {
            max = arr + i;
        }
    }

    return *max;
}

template <class T>
const T& min(const T* arr, size_t nr)
{
    assert(nr > 0);

    const T* min = arr;
    for (size_t i = 1; i < nr; i++) {
        if (*min > arr[i]) {
            min = arr + i;
        }
    }

    return *min;
}

    double a[5];
    cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];

    cout << max(a, 5) << endl;
    cout << min(a, 5) << endl;
```

	
### 求和

#### 一般数组求和

- 泛型版本（函数模板）
- 时间复杂度：`O(N)`
- 空间复杂度：`O(1)`
- [完整程序](https://gitee.com/vincentwei7/PLZS/blob/main/source/noi-csp-j/lesson-1/summary-of-array.cpp)

```cpp
template <class T>
T sum(const T* arr, size_t nr)
{
    T sum = 0;
    for (size_t i = 0; i < nr; i++) {
        sum += arr[i];
    }

    return sum;
}

    double a[5];
    cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];

    cout << sum(a, 5) << endl;
```

	
#### 等差数列求和

- 泛型版本（函数模板）
- 时间复杂度：`O(1)`
- 空间复杂度：`O(1)`
- [完整程序](https://gitee.com/vincentwei7/PLZS/blob/main/source/noi-csp-j/lesson-1/summary-of-arithmetic-sequence.cpp)

```cpp
template <class T>
T as_sum(const T& first, const T& diff, size_t n)
{
    assert(n > 0);

    T last = first + (n - 1) * diff;
    return (first + last) * n / 2;
}

    assert(as_sum(1, 1, 1) == 1);
    assert(as_sum(1.0, 2.0, 10.0) == 100.0);

    double first, diff;
    size_t n;
    cin >> first >> diff >> n;

    cout << as_sum(first, diff, n) << endl;
```

	
#### 等比数列求和

- 泛型版本（函数模板）
- 时间复杂度：`O(1)`
- 空间复杂度：`O(1)`
- [完整程序](https://gitee.com/vincentwei7/PLZS/blob/main/source/noi-csp-j/lesson-1/summary-of-geometric-sequence.cpp)

```cpp
#include <cmath>        // for pow() and fpclassify()

template <class T>
T gs_sum(const T& first, const T& ratio, size_t n)
{
    assert(n > 0);

    T denominator = static_cast<T>(1.0 - ratio);
    return first * (1.0 - pow(ratio, static_cast<T>(n))) / denominator;
}

    assert(gs_sum(1, 1, 5) == 5);
    assert(gs_sum(1.0, 2.0, 2) == 3.0);

    double first, ratio;
    size_t n;
    cin >> first >> ratio >> n;

    cout << gs_sum(first, ratio, n) << endl;
```

	
#### 课堂练习

（十五分钟内完成）

1. 实现两个函数模板，分别用于初始化一个等差数列构成的数组和等比数列构成的数组，并构成一个完整的程序 `init-two-sequences.cpp`；该程序根据用户输入的第一项、公差或公比以及项数，生成两个数组，并依次输出数组中的各项。
1. 调试通过后，将 `init-two-sequences.cpp` 文件添加到 `plzs-homework` 仓库，并推送到远程仓库。

	
### 翻转数组元素

- 将数组中的元素执行翻转（reverse）操作；比如将数组 `[1, 2, 3, 4, 5]` 翻转后 `[5, 4, 3, 2, 1]`。
- 时间复杂度：`O(N)`
- 空间复杂度：`O(1)`
- [完整程序](https://gitee.com/vincentwei7/PLZS/blob/main/source/noi-csp-j/lesson-1/reverse-array.cpp)

```cpp
```

	
### 轮转数组元素

- 将数组中的元素执行轮换（rotate）操作；比如将数组 `[1, 2, 3, 4, 5]` 轮转 2 次后 `[4, 5, 1, 2, 3]`。
- 时间复杂度：`O(N)`
- 空间复杂度：`O(1)`
- [完整程序](https://gitee.com/vincentwei7/PLZS/blob/main/source/noi-csp-j/lesson-1/rotate-array.cpp)

```cpp
```

	
### 打乱数组元素

- 打乱（shuffle）数组中的元素顺序；比如将数组 `[1, 2, 3, 4, 5]` 打乱后 `[4, 3, 1, 5, 2]`。
- 时间复杂度：`O(N)`
- 空间复杂度：`O(1)`
- [完整程序](https://gitee.com/vincentwei7/PLZS/blob/main/source/noi-csp-j/lesson-1/shuffle-array.cpp)

```cpp
```

	
### 在矢量的尾部追加元素

- 在矢量的尾部追加一个元素（push back)；比如在矢量 `[1, 2, 3, 4, 5]` 尾部追加 `6`：`[1, 2, 3, 4, 5, 6]`。
- 时间复杂度：`O(1)`
- 空间复杂度：`O(1)`
- [完整程序](https://gitee.com/vincentwei7/PLZS/blob/main/source/noi-csp-j/lesson-1/push-back-element.cpp)

```cpp
```

	
### 移除矢量尾部的元素

- 将矢量尾部的元素移除（pop back）；比如将矢量 `[1, 2, 3, 4, 5]` 尾部的 `5` 移除：`[0, 1, 2, 3, 4]`。
- 时间复杂度：`O(1)`
- 空间复杂度：`O(1)`
- [完整程序](https://gitee.com/vincentwei7/PLZS/blob/main/source/noi-csp-j/lesson-1/pop-back-element.cpp)

```cpp
```

	
### 在矢量的指定位置插入元素

- 在矢量的指定位置插入（insert）元素；比如在矢量 `[1, 2, 3, 4, 5]` 的第 0 个索引位置处插入元素 `0`：`[0, 1, 2, 3, 4, 5]`。
- 时间复杂度：`O(N)`
- 空间复杂度：`O(1)`
- [完整程序](https://gitee.com/vincentwei7/PLZS/blob/main/source/noi-csp-j/lesson-1/insert-element.cpp)

```cpp
```

	
### 移除指定位置的矢量元素

- 将指定位置的元素从矢量中移除（erase）；比如将矢量 `[1, 2, 3, 4, 5]` 的第 0 个元素移除后 `[2, 3, 4, 5]`。
- 时间复杂度：`O(N)`
- 空间复杂度：`O(1)`
- [完整程序](https://gitee.com/vincentwei7/PLZS/blob/main/source/noi-csp-j/lesson-1/erase-element.cpp)

```cpp
```

	
### 计算 C 字符串长度

- 计算 C 字符串长度（count）；比如字符串 `"Hello"` 的长度为 `5`。
- 时间复杂度：`O(N)`
- 空间复杂度：`O(1)`
- [完整程序](https://gitee.com/vincentwei7/PLZS/blob/main/source/noi-csp-j/lesson-1/string-length.cpp)

```cpp
```

		
## 递归

	
### 在筑基班接触过的递归算法

1) 自然数次幂的递归实现

```cpp
```

	
2) 阶乘的递归实现

```cpp
```

	
3) 斐波那契数列的递归实现

```cpp
```

	
4) 欧几里得算法的递归实现

```cpp
```

	
5) 扩展欧几里得算法的递归实现

```cpp
```

	
### 递归好处和坏处

- 易于理解，实现简单。
- 但时间复杂度较高，通常具有 `O(N)` 或以上的时间复杂度。
- 递归调用产生大量栈帧，空间复杂度也较高，通常具有 `O(N)` 或以上的空间复杂度。
- 所有的递归实现都可以转为非递归实现。

	
1) 自然数次幂的非递归实现

```cpp
```

	
2) 阶乘的非递归实现

```cpp
```

	
3) 斐波那契数列的非递归实现

```cpp
```

	
4) 欧几里得算法的非递归实现

```cpp
```

	
5) 扩展欧几里得算法的非递归实现

```cpp
```

		
## 二分法

- 二分法的基本思想

	
### 二分查找

	
### 二分逼近

		
## 倍增法

	
### 快速幂

	
1) 快速幂算法的递归实现

```cpp
```

	
2) 快速幂算法的非递归实现

```cpp
```

	
### 快速乘

	
1) 快速乘算法的递归实现

```cpp
```

	
2) 快速乘算法的非递归实现

```cpp
```

		
## 实用技巧

		
## 作业

	
1) 构造一个浮点数构成的等差数列数组，然后使用逐项匹配法、二分搜索法（自己的实现）、二分搜索法（调用 `<algorithm>` 中定义的 `binary_search()`）、通项公式法寻找给定数值是否存在于该数列中，并给出各方法的执行时间。运行效果如下所示：

```console
% ./find-value-in-arithmetic-sequence
<0 3 500>     # 三个浮点数，分别为等差数列初始值、公差以及要寻找的数值。
False: compared sequentially in 0.001s.
False: using my binary search implementation in 0.001s.
False: using binary_search() in 0.001s.
False: using formula in 0.0001s.
```

	
2) 使用十进制字符串表示任意精度自然数，给定两个初始的正整数以及一个索引值 `N`，给出以这两个整数开始的广义斐波那契数列数列的第 `N` 个自然数。

```console
% ./nth-fibonacii-number
<20 31 500>     # 前两个数值为任意精度的正整数，第三个数值为索引值 N (0 < N < 2^16)
```

	
3) 使用十进制字符串表示任意精度自然数，分别使用连加、竖式乘和快速乘算法实现乘法运算。运行效果如下：

```console
$ ./nap-multiple
<11 11>
121: using summation in 0.001s.
121: using vertical multiplication in 0.001s.
121: using binary lifting summary in 0.001s.

$ ./nap-multiple
<78260869565217391304347826086956521 * 4347826086956521739130434782608695>
340264650283553875236294896030245692438563327032136105860113421550095
```

	
4) 基于 `bigint` 类提供的接口实现：给定任意自然数 `a` 和 `n`，使用快速幂（二进制取幂，Binary Exponentiation）算法计算 <code>a<sup>n</sup></code>。运行效果如下：

```console
$ ./binary-power
<23 50>
122008981252869411022491112993141891091036959856659100591281395343249
```

	
5) 基于 `bigint` 类提供的接口实现：给定任意小数（正值），给出其最简分数表达。运行效果如下：

```console
$ ./rational-number-to-fraction
<0.3 1>        # 第二个数字表示循环位；指小数部分循环位的位数。
1/3

$ ./rational-number-to-fraction
<48.8260869565217391304347 22>
1123/23
```

	
### 参考链接

