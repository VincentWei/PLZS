# 排序算法

1. 排序的需求
1. 选择排序
1. 冒泡排序
1. 插入排序
1. 归并排序
1. 快速排序
1. 分治法
1. 实用技巧

		
## 排序的需求

- 排序（sort）是各类软件的基本功能：
   1. 按顺序处理（比如展现）数据结构中的各元素。
   1. 在已排序（sorted）的线性表数据结构中执行快速搜索（search）。
- 常见的排序需求：
   1. 对已有的线性表数据结构进行排序。
   1. 对已有数据结构中的元素进行排序并生成一个新的已排序线性数据结构。
   1. 将生成的数据插入数据结构时执行排序操作，以确保数据结构内的元素始终是已排序的。

	
### 排序相关术语

- 升序（ascending order）：将各元素按从小到大的顺序排列。
- 降序（descending order）：将各元素按从大到小的顺序排列。
- 比较（compare）：用于对比元素大小的动作。

		
## 选择排序

`Selection Sort`

	
### 原理

	
### 步骤

	
### 参考实现

		
## 冒泡排序

`Bubble Sort`

	
### 原理

	
### 步骤

	
### 参考实现

		
## 插入排序

`Insertion Sort`

	
### 原理

	
### 步骤

	
### 参考实现

		
## 归并排序

`Merge Sort`

	
### 原理

	
### 步骤

	
### 参考实现

		
## 快速排序

`Quick Sort`

	
### 原理

	
### 步骤

	
### 参考实现

		
## 分治法

`Divide and Conquer`

		
## 实用技巧

	
### C++ STL 提供的排序接口

- 函数模板，可用于支持随机访问迭代器的容器，如内置数组、`array`、`vector`：

```cpp
template <class RandomAccessIterator>
void sort(RandomAccessIterator first, RandomAccessIterator last);

template <class RandomAccessIterator, class Compare>
void sort(RandomAccessIterator first, RandomAccessIterator last, Compare comp);
```

	
1) 用于内置数组并使用回调函数

- 注意：STL 迭代器无法在可变长度数组（variable length array）上工作

```cpp
#include <iostream>     // for cin and cout
#include <algorithm>    // for sort()
#include <cassert>      // for assert()

using namespace std;

bool my_compare(double a, double b)
{
    return (a > b);
}

#define NR_REALS   5

int main()
{
    double a[NR_REALS];
    for (size_t i = 0; i < NR_REALS; i++) {
        cin >> a[i];
    }

    sort(begin(a), end(a));

    cout << "Ascending order:" << endl;
    for (size_t i = 0; i < NR_REALS; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    sort(begin(a), end(a), my_compare);

    cout << "Descending order:" << endl;
    for (size_t i = 0; i < NR_REALS; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

```

	
2) 用于矢量并使用函数对象

```cpp
#include <iostream>     // for cin and cout
#include <vector>       // for vector
#include <algorithm>    // for sort()
#include <cassert>      // for assert()

using namespace std;

struct my_compare_class {
    bool operator() (double a, double b) {
        return a > b;
    }
};

#define NR_REALS   5

int main()
{
    vector<double> a;

    for (size_t i = 0; i < NR_REALS; i++) {
        a.push_back(0);
        cin >> a[i];
    }

    sort(begin(a), end(a));

    cout << "Ascending order:" << endl;
    for (size_t i = 0; i < NR_REALS; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    my_compare_class my_compare;
    sort(begin(a), end(a), my_compare);

    cout << "Descending order:" << endl;
    for (size_t i = 0; i < NR_REALS; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

```

	
### C 标准库提供的排序接口

```c
#include <stdlib.h>

void qsort(void *base, size_t nmemb, size_t size,
        int (*compar)(const void *, const void *));

void qsort_r(void *base, size_t nmemb, size_t size,
        int (*compar)(const void *, const void *, void *),
        void *arg);
```

	
### 比较回调函数

		
## 作业

	
### 参考链接

