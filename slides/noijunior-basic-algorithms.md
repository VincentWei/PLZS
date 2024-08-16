# 基础算法

1. 算法的重要性
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
bool check_prime_sieved(uint64_t n, const uint64_v& primes_sieved)
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

    result.push_back(2);
    for (uint64_t n = 3; n <= max; max += 2) {
        if (check_prime_sieved(n, prime_sieved)) {
            result.push_back(number);
        }
    }

done:
    return result;
}

    uint64_v primes = prime_sieve(UINT32_MAX);

    uint64_t n;
    cin >> n;
    cout << (binary_search(primes.begin(), primes.end(), n) ? 'True' : 'False') << endl;
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

