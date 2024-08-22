# 基础算法和基础数据结构

1. 算法的重要性
1. 算法复杂度的衡量
1. 线性表数据结构及其操作
1. 常用简单算法
1. 递归
1. 二分法
1. 倍增法
1. 实用技巧

		
## 算法的重要性

- 以自然数的素性判定为例。
- [完整程序](https://gitee.com/vincentwei7/PLZS/blob/main/source/noi-csp-j/lesson-1/check-prime.cpp)

	
### 自然数的素性判定

朴素版本

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

	
### 自然数的素性判定

优化版本

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

	
### 自然数的素性判定

朴素素数筛

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

	
### 自然数的素性判定

事先准备的自然数素性数组

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
   1. `O(log(N))`：表示复杂度与数据项的个数之对数 `log(N)` 线性相关（无关对数的底到底是多少）。比如在事先筛好的有序素数矢量中用二分查找法查找给定的数，从而判定是否为素数的算法之时间复杂度。
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
#include <ctime>

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

		
## 线性表数据结构

- 线性表数据结构中的元素是顺序存放的，可通过索引值随机访问。
- 数组（array）、矢量（vector）、字符串（string）和 C 字符串是常见的几种线性数据结构。
- 数组具有固定的大小，而矢量的大小可变。
- 复习 STL array 和 vector 的区别。

	
### 翻转数组元素

- 将数组中的元素执行翻转（reverse）操作；比如将数组 `[1, 2, 3, 4, 5]` 翻转后 `[5, 4, 3, 2, 1]`。
- 时间复杂度：`O(N)`
- 空间复杂度：`O(1)`
- [完整程序](https://gitee.com/vincentwei7/PLZS/blob/main/source/noi-csp-j/lesson-1/reverse-array.cpp)

```cpp
template <class T>
void reverse_array(T* arr, size_t n)
{
    for (size_t i = 0; i < n / 2; i++) {
        T tmp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = tmp;
    }
}
```

	
### 轮转数组元素

- 将数组中的元素执行轮换（rotate）操作；比如将数组 `[1, 2, 3, 4, 5]` 轮转 2 次后 `[4, 5, 1, 2, 3]`。
- 时间复杂度：`O(N)`
- 空间复杂度：`O(N)`
- [完整程序](https://gitee.com/vincentwei7/PLZS/blob/main/source/noi-csp-j/lesson-1/rotate-array.cpp)

```cpp
template <class T>
void rotate_array(T* arr, size_t n, size_t m)
{
    assert(n > 0);
    if (m % n == 0)
        return;

    T tmp[n];
    for (size_t i = 0; i < n; i++) {
        tmp[i] = arr[i];
    }

    for (size_t i = 0; i < n; i++) {
        size_t j = (i + m) % n;
        arr[j] = tmp[i];
    }
}

```

	
### 打乱数组元素

- 打乱（shuffle）数组中的元素顺序；比如将数组 `[1, 2, 3, 4, 5]` 打乱后 `[4, 3, 1, 5, 2]`。
- 时间复杂度：`O(N)`
- 空间复杂度：`O(1)`
- [完整程序](https://gitee.com/vincentwei7/PLZS/blob/main/source/noi-csp-j/lesson-1/shuffle-array.cpp)

```cpp
#include <ctime>        // for time()
#include <cstdlib>      // for srandom() and random()

template <class T>
void shuffle_array(T* arr, size_t n)
{
    assert(sizeof(size_t) == sizeof(long));

    srandom(time(NULL));
    for (size_t i = 0; i < n; i++) {
        size_t a = static_cast<size_t>(random());
        size_t j = a % n;

        T tmp = arr[0];
        arr[0] = arr[j];
        arr[j] = tmp;
    }
}
```

	
### 伪矢量类模板

- 使用数组模拟矢量，可用空间有确定的上限。
- 使用成员变量跟踪矢量大小的变化。
- [完整程序](https://gitee.com/vincentwei7/PLZS/blob/main/source/noi-csp-j/lesson-1/pseudo-vector.cpp)

```cpp
#include <iostream>     // for cin and cout
#include <string>       // for stod()
#include <stdexcept>    // for std::out_of_range
#include <cassert>      // for assert()

#define PVSZ_MAX 100

template <class T>
struct pseudo_vector {
    T _buf[PVSZ_MAX];
    size_t _sz;

    pseudo_vector() {
        _sz = 0;
    }

    /* 根据索引值随机访问其中的元素。 */
    T& operator[] (size_t n) {
        if (n < _sz) {
            return _buf[n];
        }

        throw std::out_of_range("Out of range!");
    }

    /* 根据索引值随机访问其中的元素（const 版本）。 */
    const T& operator[] (size_t n) const {
        if (n < _sz) {
            return _buf[n];
        }

        throw std::out_of_range("Out of range!");
    }

    ...
};
```

	
### 在矢量的尾部追加元素

- 在矢量的尾部追加一个元素（push back)；比如在矢量 `[1, 2, 3, 4, 5]` 尾部追加 `6`：`[1, 2, 3, 4, 5, 6]`。
- 时间复杂度：`O(1)`
- 空间复杂度：`O(1)`

```cpp
    void push_back(const T& elem) {
        if (_sz < PVSZ_MAX) {
            _buf[_sz] = elem;
            _sz++;
        }
        else {
            throw std::overflow_error("Reached space limit.");
        }
    }
```

	
### 移除矢量尾部的元素

- 将矢量尾部的元素移除（pop back）；比如将矢量 `[1, 2, 3, 4, 5]` 尾部的 `5` 移除：`[0, 1, 2, 3, 4]`。
- 时间复杂度：`O(1)`
- 空间复杂度：`O(1)`

```cpp
    void pop_back() {
        if (_sz > 0) {
            _sz--;
        }
    }
```

	
### 在矢量的指定位置插入元素

- 在矢量的指定位置插入（insert）元素；比如在矢量 `[1, 2, 3, 4, 5]` 的第 0 个索引位置处插入元素 `0`：`[0, 1, 2, 3, 4, 5]`。
- 时间复杂度：`O(N)`
- 空间复杂度：`O(1)`

```cpp
    void insert(const T& elem, size_t pos) {
        if (_sz == PVSZ_MAX) {
            throw std::overflow_error("Reached space limit.");
        }

        if (pos < _sz) {
            for (size_t i = _sz; i > pos; i--) {
                _buf[i] = _buf[i - 1];
            }

            _buf[pos] = elem;
            _sz++;
        }
        else {
            throw std::out_of_range("Out of range!");
        }
    }
```

	
### 移除指定位置的矢量元素

- 将指定位置的元素从矢量中移除（erase）；比如将矢量 `[1, 2, 3, 4, 5]` 的第 0 个元素移除后 `[2, 3, 4, 5]`。
- 时间复杂度：`O(N)`
- 空间复杂度：`O(1)`

```cpp
    void erase(size_t pos) {
        if (pos < _sz) {
            for (size_t i = pos + 1; i < _sz; i++) {
                _buf[i - 1] = _buf[i];
            }
            _sz--;
        }
        else {
            throw std::out_of_range("Out of range!");
        }
    }
```

		
## 常用简单算法

	
### 计算 C 字符串长度

- 计算 C 字符串长度（count）；比如字符串 `"Hello"` 的长度为 `5`。
- 时间复杂度：`O(N)`
- 空间复杂度：`O(1)`

```cpp
size_t length_of_string(const char* str)
{
    size_t len = 0;
    while (*str) {
        str++;
        len++;
    }

    return len;
}
```

	
### 找到 C 字符串的尾部

- 计算 C 字符串的尾部指针
- 时间复杂度：`O(N)`
- 空间复杂度：`O(1)`

```cpp
const char* end_of_string(const char* str)
{
    while (*str) {
        str++;
    }

    return --str;
}
```

	
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

	
### 进制转换

- 特定进制数值的表达方式：<code>(ABCD)<sub>n</sub></code>
- [求给定进制字符串对应的数值](https://gitee.com/vincentwei7/PLZS/blob/main/source/cpp/lesson-3/strtoll.cpp#L39)
- [将特定数值转为给定进制的字符串](https://gitee.com/vincentwei7/PLZS/blob/main/source/cpp/lesson-3/show-number-in-different-base.cpp#L20)

	
### 巧用二进制运算

- 判断 `x` 的奇偶性：`(x & 1)`
- 使用移位优化乘除法：
   1. 左移 N 位相当于乘以 <code>2<sup>N</sup></code>：`x << N`
   1. 右移 N 位相当于除以 <code>2<sup>N</sup></code>：`x >> N`
- 判断 `n` 是否是 2 的正整数幂：`(~(n & (n - 1)))`
- 圆整为大于等于 `n` 的最小的 2 的正整数（N）幂：  
`x = ((n + (N - 1)) & -N)`
- 求中间值（防止溢出）：  
`mid = start + ((end - start) >> 1)`
- 最简单的加解密：`x ^ y ^ y = x`

		
## 递归

- 递推（recurrent）关系和递归（recursive）调用
- 递推的通项公式

	
### 在筑基班接触过的递归算法

1) 自然数次幂的递归实现

```cpp
double power_r(double f, unsigned long n)
{
    double r;
    if (n == 0)
        r = 1.0;
    else
        r = f * power_r(f, n - 1);
    return r;
}
```

	
2) 阶乘的递归实现

```cpp
unsigned long long factorial_r(unsigned long long n)
{
    if (n == 0)
        return 1;
    else
        return n * factorial_r(n - 1);
}
```

	
3) 斐波那契数列的递归实现

```cpp
unsigned long long fibonacci_nth_r(unsigned n)
{
    if (n < 2)
        return 1;
    return fibonacci_nth_r(n - 1) + fibonacci_nth_r(n - 2);
}
```

	
4) 欧几里得算法的递归实现

```cpp
long long gcd_r(long long a, long long b)
{
    if (b == 0)
        return a;
    return gcd_r(b, a % b);
}
```

	
### 递归的好处和坏处

- 易于理解，实现简单。
- 但时间复杂度较高，通常具有 `O(N)` 或以上的时间复杂度。
- 递归调用产生大量栈帧，空间复杂度也较高，通常具有 `O(N)` 或以上的空间复杂度。
- 几乎所有的递归实现都可以转为非递归（迭代）实现。
- 很多递推关系可以从数学上找到对应的通项公式。

	
1) 自然数次幂的迭代实现

```cpp
double power_i(double f, unsigned long n)
{
    double r = 1.0;
    for (unsigned long i = 0; i < n; i++) {
        r *= f;
    }

    return r;
}
```

	
2) 阶乘的迭代实现

```cpp
unsigned long long factorial_i(unsigned long long n)
{
    unsigned long long r = 1ULL;
    for (unsigned long i = 2; i <= n; i++) {
        r *= i;
    }

    return r;
}
```

	
3) 斐波那契数列的迭代实现

```cpp
unsigned long long fibonacci_nth_i(unsigned n)
{
    if (n == 0)
        return 1;
    else if (n == 1)
        return 1;

    unsigned long long a = 1, b = 1;
    unsigned long long r = a + b;
    for (unsigned i = 2; i < n - 2; i++) {
        r = a + b;  // 2, 3
        a = b;      // 1, 2
        b = r;      // 2, 3
    }

    return r;
}
```

	
4) 欧几里得算法的迭代实现

```cpp
long long gcd_i(long long a, long long b)
{
    while (b != 0) {
        long long tmp = a;
        a = b;
        b = tmp % b;
    }
    return a;
}
```

		
## 二分法

- 二分法的基本思想
- 时间复杂度：`O(log(N))`

	
### 二分查找

- 只能在有序容器上执行二分查找（binary search）算法
- 示例代码仅可用于从小到大排序（升序，ascending sorted order）的数组

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

	
### 二分逼近

- 只能在单调增长或下降的数学函数上使用二分逼近法（bisection method）
- [完整程序](https://gitee.com/vincentwei7/PLZS/blob/main/source/noi-csp-j/lesson-1/estimate-square-root.cpp)

```cpp
double estimate_square_root(double a, unsigned scale)
{
    if (a < 0)
        return NAN;

    double tolerance = 1;
    while (scale != 0) {
        tolerance *= 0.1;
        scale--;
    }

    double start, end;
    if (a >= 1.0) {
        start = 1.0;
        end = a;
    }
    else {
        start = 0;
        end = 1.0;
    }

    double mid = NAN;
    while (start <= end) {
        mid = start + ((end - start) / 2.0);

        if (isclose(start, end))
            break;

        double errors = mid * mid - a;
        if (fabs(errors) <= tolerance) {
            break;
        }
        else if (errors < 0) {
            start = mid;
        }
        else {
            end = mid;
        }
    }

    return mid;
}
```

		
## 倍增法

- 倍增法（binary lifting）的基本思想
- 时间复杂度：`O(log(N))`

	
### 快速幂

1) 快速幂算法的递归实现

```cpp
double binary_power_r(double base, unsigned exp)
{
    if (exp == 0)
        return 1.0;

    double res = binary_power_r(base, exp >> 1);
    if (exp % 2)
        return res * res * base;

    return res * res;
}
```

	
2) 快速幂算法的非递归实现

```cpp
double binary_power_i(double base, unsigned exp)
{
    double res = 1.0;

    while (exp > 0) {
        if (exp & 1)
            res = res * base;
        base = base * base;
        exp >>= 1;
    }

    return res;
}
```

	
### 快速乘

1) 快速乘算法的递归实现

```cpp
intmax_t binary_mul_r(intmax_t a, intmax_t b)
{
    assert(b >= 0);

    if (b == 0)
        return 0;

    intmax_t res = binary_mul_r(a, b >> 1);
    if (b % 2)
        return res + res + a;

    return res + res;
}
```

	
2) 快速乘算法的非递归实现

```cpp
intmax_t binary_mul_i(intmax_t a, intmax_t b)
{
    int sign = 1;
    if (b < 0) {
        b = -b;
        sign = -1;
    }

    intmax_t res = 0;

    while (b > 0) {
        if (b & 1)
            res += a;
        a += a;
        b >>= 1;
    }

    return sign * res;
}
```

		
## 实用技巧

	
### C++ STL 提供的简单算法接口

- `#include <algorithm>`
- 函数模板 `std::max()` 返回两个值中较大的那个。
- 函数模板 `std::min()`，返回两个值中较小的那个。
- 函数模板 `std::max_element(first, last)`，返回给定范围 `[first, last)` 内指向最小元素的迭代器。
- 函数模板 `std::min_element(first, last)`，返回给定范围 `[first, last)` 内指向最大元素的迭代器。
- 函数模板 `std::reverse(first, last)`，翻转给定范围 `[first, last)` 内的元素。
- 函数模板 `std::rotate(first, middle, last)`，轮转给定范围 `[first, last)` 内的元素，使 `middle` 成为该范围内的第一个元素。
- [更多接口](https://cplusplus.com/reference/algorithm/)

	
### C++ STL 提供的二分查找接口

- `#include <algorithm>`
- 函数模板 `std::lower_bound()` 用于在有序容器中查找首个不小于给定值的元素。
- 函数模板 `std::upper_bound()`，用于在有序容器中查找首个大于给定值的元素。
- 函数模板 `std::binary_search()`，用于测试有序容器中是否存在给定的值。

	
### C 标准库实现的二分查找接口

- `#include <cstdlib>`
- 函数 `bsearch()` 用于在有序数组中查找给定的值，若匹配，则返回对应元素的地址（`void *`）。

		
## 作业

	
1) 构造一个足够长的浮点数构成的等差数列数组，然后使用逐项匹配法、二分搜索法（自己的实现）、二分搜索法（调用 `<algorithm>` 中定义的 `binary_search()`）、二分逼近法（使用通项公式）寻找给定的数值是否存在于该数列中，并给出各方法的执行时间。运行效果如下所示：

```console
% ./find-value-in-arithmetic-sequence
<0 3 500>     # 三个浮点数，分别为等差数列初始值、公差以及要寻找的数值。
False

0.001s consumed when comparing sequentially.
0.001s consumed when using my binary search implementation.
0.001s consumed when using binary_search().
0.001s consumed when using bisection method.
```

	
2) 使用十进制字符串表示任意精度自然数，给定两个初始的正整数以及一个索引值 `N`，给出以这两个整数开始的广义斐波那契数列数列的第 `N` 个自然数。

```console
% ./nth-fibonacii-number
<20 31 500>     # 前两个数值为任意精度的正整数，第三个数值为索引值 N (0 <= N < 2^16)
```

	
3) 使用十进制字符串表示任意精度自然数，分别使用连加、竖式乘和快速乘算法实现乘法运算。运行效果如下：

```console
$ ./nap-multiple
<11 11>
121

0.001s consumed when using summation.
0.001s consumed when using vertical multiplication.
0.001s consumed when using binary lifting summation.

$ ./nap-multiple
<78260869565217391304347826086956521 * 4347826086956521739130434782608695>
340264650283553875236294896030245692438563327032136105860113421550095

0.001s consumed when using summation.
0.001s consumed when using vertical multiplication.
0.001s consumed when using binary lifting summation.
```

	
4) 基于 `bigint` 类提供的接口实现：给定任意非零整数，求出其最大公约数和最小公倍数。运行效果如下：

```console
$ ./bigint-gcd-lcm
<1111 3333>        # 均为任意精度非零整数。
1111
3333
```

	
5) 基于 `bigint` 类提供的接口实现：给定任意精度整数 `a` 和 任意精度自然数 `n`，使用快速幂算法计算 <code>a<sup>n</sup></code>。运行效果如下：

```console
$ ./bigint-binary-power
<23 50>
122008981252869411022491112993141891091036959856659100591281395343249
```

	
6) 给定任意浮点数以及精度（按十进制小数部分位数给出），估算其立方根。运行效果如下：

```console
$ ./estimate-cubic-root
<21 20>     # 第一个数是一个浮点数，第二个数给定了结果小数部分的位数 K（0 < K < 20）
2.75889617783466134816
```

	
### 参考链接

- [bigint.hpp](https://gitee.com/vincentwei7/PLZS/blob/main/source/cpp/lesson-6/bigint.hpp)
- [bigint.cpp](https://gitee.com/vincentwei7/PLZS/blob/main/source/cpp/lesson-6/bigint.cpp)
- 基本用法：

```cpp
#define NTEST
#include "bigint.cpp"

/*
 * bigint_power:
 *
 * @base: the base in bigint.
 * @exp: the exponent in unsigned.
 *
 * returns: The power of @base raised to @exp.
 */
bigint bigint_power(bigint &base, unsigned exp)
{
    bigint r(1);

    while (exp--) {
        r *= base;
    }

    return r;
}
```

