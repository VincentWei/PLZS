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

1. 找到线性表数据结构中的最小值并将其和第一个元素交换。
1. 在剩余元素中，找到最小值并将其和剩余元素中的第一个元素交换。
1. 重复步骤 2 直到只剩一个元素。

	
### 参考实现

```cpp
```

	
### 课堂练习

（十分钟内完成）

1. 实现一个函数模板 `selection_sort_desc()` 可用于内置数组的降序排序，并完成展示该函数模板功能的完整程序 `selection-sort-desc.cpp`。
1. 将 `selection-sort-desc.cpp` 文件提交到 `plzs-homework` 仓库的 `source/noi-csp-j/lesson-2/` 目录（下同），并推送到远程仓库。

		
## 冒泡排序

`Bubble Sort`

	
### 原理

1. 依次对比线性表数据结构中的两个相邻元素，若不满足顺序要求，则交换这两个元素，并记录交换次数。
1. 重复步骤 1，交换次数为 0。

	
### 参考实现

```cpp
```

	
### 课堂练习

（十分钟内完成）

1. 实现一个函数模板 `bubble_sort_desc()` 可用于内置数组的降序排序，并完成展示该函数模板功能的完整程序 `bubble-sort-desc.cpp`。
1. 将 `bubble-sort-desc.cpp` 文件提交到作业仓库并推送到远程仓库。

		
## 插入排序

`Insertion Sort`

	
### 原理

	
### 参考实现

```cpp
```

	
### 课堂练习

（十分钟内完成）

1. 实现一个函数模板 `insertion_sort_desc()` 可用于内置数组的降序排序，并完成展示该函数模板功能的完整程序 `insertion-sort-desc.cpp`。
1. 将 `insertion-sort-desc.cpp` 文件提交到作业仓库并推送到远程仓库。

		
## 归并排序

`Merge Sort`

	
### 原理

	
### 参考实现

		
## 快速排序

`Quick Sort`

	
### 原理

	
### 参考实现

		
## 分治法

`Divide and Conquer`

	
### 原理

1. 分而治之

	
### 实例

1. 分而治之

		
## 实用技巧

	
### C++ STL 提供的排序接口

- 函数模板，可用于支持随机访问迭代器的容器，如内置数组、`array`、`vector`：

```cpp
template <class RandomAccessIterator>
void sort(RandomAccessIterator first, RandomAccessIterator last);

template <class RandomAccessIterator, class Compare>
void sort(RandomAccessIterator first, RandomAccessIterator last, Compare comp);
```

	
#### 用于内置数组并使用回调函数

- 注意：STL 迭代器无法在可变长度数组（variable length array）上工作

```cpp
#include <iostream>     // for cin and cout
#include <algorithm>    // for sort()
#include <cassert>      // for assert()

using namespace std;

bool my_compare_desc(double a, double b)
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

    sort(begin(a), end(a), my_compare_desc);

    cout << "Descending order:" << endl;
    for (size_t i = 0; i < NR_REALS; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

```

	
#### 用于 STL 矢量并使用函数对象

- 函数对象的目的是，像使用函数一样使用某个类对象。

```cpp
#include <iostream>     // for cin and cout
#include <vector>       // for vector
#include <algorithm>    // for sort()
#include <cassert>      // for assert()

using namespace std;

struct my_greater_function {
    // 支持函数对象的类通过重载 () 运算符实现像函数一样使用这个类的对象的效果：
    //
    //  my_greater_function func_obj;
    //  assert(func_obj(0.1, 0.2) == false);
    //
    // 当在该类的实例 func_obj 上使用 () 运算符时，将调用下面这个函数。
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

    my_greater_function my_compare_desc;
    sort(begin(a), end(a), my_compare_desc);

    cout << "Descending order:" << endl;
    for (size_t i = 0; i < NR_REALS; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
```

	
### STL 函数对象

- C++ STL 通过 `<functional>` 头文件提供了针对常见运算的函数对象（类模板）；在需要传递简单回调函数的场合，可利用这些函数对象。
- 这些运算包括算术运算、比较运算、逻辑运算等。
- [参考链接](https://cplusplus.com/reference/functional/)。

```cpp
#include <iostream>     // for cin and cout
#include <algorithm>    // for sort()
#include <functional>   // for greater()
#include <cassert>      // for assert()

using namespace std;

int main()
{
    size_t n;
    cin >> n;

    double a[n];
    for (size_t i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    cout << "Ascending order:" << endl;
    for (size_t i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    sort(a, a + n, greater<double>());

    cout << "Descending order:" << endl;
    for (size_t i = 0; i < n; i++) {
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
```

	
#### 对元素具有固定尺寸且连续存储的数组排序

```c
#include <iostream>     // for cin and cout
#include <cstdlib>      // for assert()
#include <cassert>      // for assert()

using namespace std;

int my_compare_asc(const void* a, const void* b)
{
    const double* pa = static_cast<const double *>(a);
    const double* pb = static_cast<const double *>(b);
    return (int)(*pa - *pb);
}

int my_compare_desc(const void* a, const void* b)
{
    const double* pa = static_cast<const double *>(a);
    const double* pb = static_cast<const double *>(b);
    return (int)(*pb - *pa);
}

int main()
{
    size_t n;
    cin >> n;

    if (n == 0)
        return 1;

    double a[n];
    for (size_t i = 0; i < n; i++) {
        cin >> a[i];
    }

    qsort(a, n, sizeof(double), my_compare_asc);

    cout << "Ascending order:" << endl;
    for (size_t i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    qsort(a, n, sizeof(double), my_compare_desc);

    cout << "Descending order:" << endl;
    for (size_t i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
```

		
## 作业

	
### 参考链接

