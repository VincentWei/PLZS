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
- 稳定性（stability）：排序中的稳定性是指，排序算法是否会影响多个大小相同元素的原本顺序。

		
## 选择排序

`Selection Sort`

	
### 原理

1. 找到线性表数据结构中的最小值并将其和第一个元素交换。
1. 在剩余元素中，找到最小值并将其和剩余元素中的第一个元素交换。
1. 重复步骤 2 直到只剩一个元素。

	
### 动画演示

<img style="height:70%;width:auto;" src="assets/selection-sort-animation.svg" />

	
### 参考实现

- [完整程序](https://gitee.com/vincentwei7/PLZS/blob/main/source/noi-csp-j/lesson-2/selection-sort-asc.cpp)
- 注意 `std::swap()` 的使用；该函数模板用于交换两个对象，需引入 `<utility>` 头文件。

```cpp
template <class T>
size_t minimum_index(T* t, size_t len)
{
    assert(len > 0);

    size_t min = 0;
    for (size_t i = 1; i < len; i++) {
        if (t[i] < t[min])
            min = i;
    }

    return min;
}

template <class T>
void selection_sort_asc(T* t, size_t len)
{
    size_t start = 0;
    while (true) {
        if (start + 1 == len)
            break;
        size_t min = minimum_index(t + start, len - start);
        min += start;       // XXX
        if (min != start) {
            swap(t[start], t[min]);
        }

        start++;
    }
}
```

	
### 算法复杂度分析

- 时间复杂度：`$ O(n^2) $`
- 空间复杂度：`$ O(1) $`
- 排序方式：原地（in-place）
- 稳定性：不稳定

	
### 课堂练习

（十分钟内完成）

1. 实现一个函数模板 `selection_sort_desc()` 可用于内置数组的降序排序，并完成展示该函数模板功能的完整程序 `selection-sort-desc.cpp`。
1. 将 `selection-sort-desc.cpp` 文件提交到 `plzs-homework` 仓库的 `source/noi-csp-j/lesson-2/` 目录（下同），并推送到远程仓库。

		
## 冒泡排序

`Bubble Sort`

	
### 原理

1. 依次对比线性表数据结构中的两个相邻元素，若不满足顺序要求，则交换这两个元素。
1. 重复步骤 1，交换次数为 0。

	
### 参考实现

- [完整程序](https://gitee.com/vincentwei7/PLZS/blob/main/source/noi-csp-j/lesson-2/bubble-sort-asc.cpp)

```cpp
template <class T>
void bubble_sort_asc(T* t, size_t len)
{
    size_t i, j;
    for (i = 0; i < len - 1; i++) {
        for (j = 0; j < len - 1 - i; j++) {
            if (t[j] > t[j + 1])
                swap(t[j], t[j + 1]);
        }
    }
}

```

	
### 算法复杂度分析

- 时间复杂度：`$ O(n^2) $`（最好情况下：`$ O(n) $`）
- 空间复杂度：`$ O(1) $`
- 排序方式：原地（in-place）
- 稳定性：稳定

	
### 课堂练习

（十分钟内完成）

1. 实现一个函数模板 `bubble_sort_desc()` 可用于内置数组的降序排序，并完成展示该函数模板功能的完整程序 `bubble-sort-desc.cpp`。
1. 将 `bubble-sort-desc.cpp` 文件提交到作业仓库并推送到远程仓库。

		
## 插入排序

`Insertion Sort`

	
### 原理

- 将待排列元素划分为「已排序」和「未排序」两部分，每次从「未排序的」元素中选择一个插入到「已排序的」元素中的正确位置。
- 一个与插入排序相同的操作是打扑克牌时，从牌桌上抓一张牌，按牌面大小插到手牌后，再抓下一张牌。

	
### 动画演示

<img style="height:auto;width:100%;" src="assets/insertion-sort-animation.svg" />

	
### 参考实现

- 注意代码中的注释。
- [完整程序](https://gitee.com/vincentwei7/PLZS/blob/main/source/noi-csp-j/lesson-2/insertion-sort-asc.cpp)

```cpp
template <class T>
void insertion_sort_asc(T* t, size_t len)
{
    // i 的左侧是已经排好序的部分，右侧是未排好序的部分。
    // i 从 1 开始，此时左侧只有一个元素，无需排序。
    for (size_t i = 1; i < len; i++) {

        // 要将 i 右侧的第一个元素插入到左侧，
        // 但插入操作将覆盖该位置，故而先保存起来。
        T key = t[i];

        // 接下来在 i 的左侧寻找用来插入 key 位置。
        // XXX: j 可能会变为 -1，故而使用 ssize_t 类型。
        ssize_t j = i - 1;
        while (j >= 0 and key < t[j]) {
            t[j + 1] = t[j];
            j--;
        }

        // 找到了插入位置，将 key 存入。
        t[j + 1] = key;
    }
}
```

	
### 算法复杂度分析

- 时间复杂度：`$ O(n^2) $`（最好情况下：`$ O(n) $`）
- 空间复杂度：`$ O(1) $`
- 排序方式：原地（in-place）
- 稳定性：稳定

	
### 课堂练习

（十分钟内完成）

1. 实现一个函数模板 `insertion_sort_desc()` 可用于内置数组的降序排序，并完成展示该函数模板功能的完整程序 `insertion-sort-desc.cpp`。
1. 将 `insertion-sort-desc.cpp` 文件提交到作业仓库并推送到远程仓库。

		
## 归并排序

`Merge Sort`

	
### 原理

- 合并两个已经排好序的数组很容易实现，而且速度很快。
- 基于以上思路，按二分思路递归执行较小部分的排序，然后合并成较大部分。
- 但需要额外的空间，所以该算法适合异地排序。

	
### 参考实现（递归版本）

```cpp
```

	
### 算法复杂度分析

- 时间复杂度：`$ O(n\log{n}) $`
- 空间复杂度：`$ O(n) $`
- 排序方式：异地（out-place）
- 稳定性：稳定

		
## 快速排序

`Quick Sort`

	
### 原理

- 快速排序由东尼·霍尔（Tony Hoare）发明，本质上是一种对冒泡排序的改进。
- 执行步骤：
   1. 将表划分为两部分，保证前一个子表中的元素都小于后一个子表中的元素；可随机选取或者选表中第一个元素作为比较“基准（pivot）”。
   1. 递归到两个子表中分别进行快速排序；直到子表长度为零。
   1. 无需合并，终止时表已经完全有序。
- 又称分区交换排序（partition-exchange sort）。

	
### 参考实现

- 递归版本

```cpp
template <typename T>
size_t paritition(T A[], size_t low, size_t high)
{
    size_t pivot = A[low];
    while (low < high) {
        while (low < high && pivot <= A[high])
            --high;
        A[low] = A[high];
        while (low < high && A[low] <= pivot)
            ++low;
        A[high] = A[low];
    }
    A[low] = pivot;
    return low;
}

template <typename T>
void quick_sort(T A[], size_t low, size_t high)
{
    if (low < high) {
        size_t pivot = partition(A, low, high);
        quick_sort(A, low, pivot - 1);
        quick_sort(A, pivot + 1, high);
    }
}

template <typename T>
void quick_sort(T A[], size_t len)
{
    quick_sort(A, 0, len - 1);
}
```

	
### 算法复杂度分析

- 时间复杂度：`$ O(n\log{n}) $`（最坏情况下：`$ O(n^2) $`）
- 空间复杂度：`$ O(\log{n}) $`
- 排序方式：原地（in-place）
- 稳定性：不稳定

		
## 分治法

`Divide and Conquer`

	
### 原理

分而治之

- 把一个复杂的问题分成两个或更多的相同或相似的子问题，直到最后子问题可以简单地直接求解，原问题的解即子问题的解的合并。
- 归并排序和快速排序体现了分治思想的精髓。

	
### 其他应用


		
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

	
1) 使用函数模板实现归并排序算法的迭代版本。运行效果如下：

```console
$ ./merge-sort-iteration
<11 -9 10 -13 14 15 9 -7 5>
-13 -9 -7 5 10 11 14 15
```

	
2) 使用函数模板实现快速排序算法的迭代版本。运行效果如下：

```console
$ ./quick-sort-iteration
<11 -9 10 -13 14 15 9 -7 5>
-13 -9 -7 5 10 11 14 15
```

	
### 参考链接

