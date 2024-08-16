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


    uint64_v primes_sieved = sieve_primes(UINT32_MAX);

    uint64_t n;
    cin >> n;
    cout << (check_prime_sieved(primes_sieved, n) ? "True" : "False") << endl;
```

		
## 算法复杂度的衡量

- 衡量算法复杂度的两个维度：
   1. 时间复杂度（complexity）：用于衡量执行效率。
   1. 空间复杂度：用于衡量内存等资源的消耗。
- 大 O 时间复杂度表示法：用于表示代码执行时间随数据规模增长的变化趋势。
   1. `O(1)`：表示常量级的时间复杂度，比如基本的四则运算、取地址、反引用、访问数组中给定的单元等。
   1. `O(N)`：表示时间复杂度与数据项的个数 `n` 线性相关。比如素性判定的普通版本。
   1. `O(sqrt(N))`：表示时间复杂度与数据项的个数之算术平方根 `sqrt(N)` 线性相关。比如素性判定的优化版本。
   1. `O(log(N))`：表示时间复杂度与数据项的个数之对数 `log(N)` 线性相关（无关对数的底到底是多少）。比如在事先筛好的素数矢量中查找给定的数，从而判定是否为素数的算法。

	
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
        clock_gettime(CLOCK_MONOTONIC, &ts_curr);
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

	
### 求和

		
## 递归

		
## 二分法

		
## 倍增法

		
## 实用技巧

		
## 作业

	
### 参考链接

