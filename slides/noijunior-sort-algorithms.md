# 排序算法

1. 排序的需求
1. 选择排序
1. 冒泡排序
1. 插入排序
1. 归并排序
1. 快速排序
1. 分治法
1. 动态内存管理
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

	
- `minimum_index()` 函数模板。

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
```

	
### 算法复杂度分析

- 时间复杂度：`$ O(n^2) $`
- 空间复杂度：`$ O(1) $`
- 排序方式：原地（in-place）
- 稳定性：不稳定

	
### 课堂练习

（十五分钟内完成）

1. 实现一个函数模板 `selection_sort()` 可用于内置数组的降序或升序排序，并完成展示该函数模板功能的完整程序 `selection-sort.cpp`。
1. 将 `selection-sort.cpp` 文件提交到 `plzs-homework` 仓库的 `source/noi-csp-j/lesson-2/` 目录（下同），并推送到远程仓库。

		
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

1. 实现一个函数模板 `bubble_sort()` 可用于内置数组的降序或升序排序，并完成展示该函数模板功能的完整程序 `bubble-sort.cpp`。
1. 将 `bubble-sort.cpp` 文件提交到作业仓库并推送到远程仓库。

		
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

		
## 归并排序

`Merge Sort`

	
### 原理

- 合并两个已经排好序的数组很容易实现，而且速度很快。
- 基于以上思路，按二分思路递归执行较小部分的排序，然后合并成较大部分。
- 但需要额外的空间，所以该算法适合异地排序。

	
### 参考实现（递归版本）

- `merge_sort_asc()` 执行递归处理；注意代码中的注释。
- [完整程序](https://gitee.com/vincentwei7/PLZS/blob/main/source/noi-csp-j/lesson-2/merge-sort-asc.cpp)


```cpp
template <class T>
void merge_sort_asc(T *t, size_t start, size_t stop)
{
    // 递归终止条件：只有一个元素或者没有元素时终止
    if (stop - start <= 1)
        return;

    // 将数组从中间分开，然后递归对两个分区执行合并排序。
    size_t mid = start + ((stop - start) >> 1);
    merge_sort_asc(t, start, mid);
    merge_sort_asc(t, mid, stop);

    // 临时空间，用于保存合并结果
    T tmp[stop - start];

    // 合并到 tmp 数组中。
    merge(t + start, mid - start, t + mid, stop - mid, tmp);

    // 将合并后的 tmp 放到 t 中。
    for (size_t i = start; i < stop; ++i)
        t[i] = tmp[i - start];
}
```

	

- `merge()` 是真正完成排序功能的地方。

```cpp
template <class T>
void merge(const T* src_a, size_t len_a, const T* src_b, size_t len_b, T* dst)
{
    size_t i = 0, j = 0, k = 0;

    while (i < len_a && j < len_b) {
        // XXX 先判断 src_b[j] < src_a[i]，保证稳定性
        if (src_b[j] < src_a[i]) {
            dst[k] = src_b[j];
            ++j;
        }
        else {
            dst[k] = src_a[i];
            ++i;
        }
        ++k;
    }

    // 此时可能有一个数组已空，而另一个数组非空，将非空的数组直接并入 dst 中
    for (; i < len_a; ++i, ++k)
        dst[k] = src_a[i];
    for (; j < len_b; ++j, ++k)
        dst[k] = src_b[j];
}
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
   1. 将表划分为两部分，保证前一个子表中的元素都小于后一个子表中的元素；可随机选取或者选表中第一个元素作为比较`基准（pivot）`。
   1. 递归到两个子表中分别进行快速排序；直到子表长度为零。
   1. 无需合并，终止时表已经完全有序。
- 又称分区交换排序（partition-exchange sort）。

	
### 参考实现

- `quick_sort_asc()` 执行递归处理；注意代码中的注释。
- [完整程序](https://gitee.com/vincentwei7/PLZS/blob/main/source/noi-csp-j/lesson-2/quick-sort-asc.cpp)


```cpp
template <class T>
void quick_sort_asc(T t[], size_t low, size_t high)
{
    if (low < high) {
        // 以分区找到的 pivot 位置将数组一分为二，然后递归执行快速排序。
        size_t pos_pivot = partition(t, low, high);
        quick_sort_asc(t, low, pos_pivot - 1);
        quick_sort_asc(t, pos_pivot + 1, high);
    }
}

template <class T>
void quick_sort_asc(T t[], size_t len)
{
    // 调用另一个形式的 quick_sort_asc() 函数。
    // XXX 注意 high 是排序范围的尾部元素的索引值。
    quick_sort_asc(t, 0, len - 1);
}
```

	
- `partition()` 是快速排序的关键代码。

```cpp
template <class T>
size_t partition(T t[], size_t low, size_t high)
{
    // 选择数组中的第一个元素作为基准，并保存到临时变量；
    // XXX 注意 low 的值在后续操作中会不断变化。
    T pivot = t[low];

    // 在数组中不断将大于 pivot 的值放到右边，将小于 pivot 的值放到左边。
    // 同时调整 pivot 所在位置，也就是 low 的值。
    while (low < high) {
        // 注意在整个循环中 low 在逐步变大，high 在逐步变小。

        // 此循环将从数组尾部开始找比 pivot 还小的元素。
        while (low < high && pivot < t[high])
            --high;
        t[low] = t[high];   // 将找到的比 pivot 还小的元素放到头部。

        // 此循环将从数组头部开始找比 pivot 还大的元素。
        while (low < high && t[low] < pivot)
            ++low;
        t[high] = t[low];   // 将找到的比 pivot 还大的元素放到尾部。
    }

    // low 中包含的是 pivot 的新位置，将保存的 pivot 值放到这个位置。
    t[low] = pivot;

    // 返回 pivot 的位置（索引值）。
    return low;
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

```cpp
template <class T>
void quick_sort_asc(T t[], size_t low, size_t high)
{
    if (low < high) {
        // 以分区找到的 pivot 位置将数组一分为二，然后递归执行快速排序。
        size_t pos_pivot = partition(t, low, high);
        quick_sort_asc(t, low, pos_pivot - 1);
        quick_sort_asc(t, pos_pivot + 1, high);
    }
}
```

	
### 分治法在生活中的应用

<img class="r-frame" style="height:auto;width:100%;" src="assets/noijunior-divide-and-conquer.svg" />

		
## 动态内存管理

- 动态分配内存的需求
- 堆和栈的区别

	
- C++ 使用 `new/delete` 或者 `new[]/delete[]` 语句在堆中分配/释放内存。
- C 使用 `malloc()/calloc()/realloc()` 或者 `free()` 语句在堆中分配/释放内存。

```cpp
    string* str_a = new string;
    delete str_a;

    // XXX 这种方式分配的类对象未被初始化，不能使用。
    string* str_b = static_cast<string *>(malloc(sizeof(string)));
    free(str_b);

    int* b = new int[20];
    // XXX 必须用 delete[] 释放。
    delete[] b;

    // 要使用 static_cast<> 执行指针类型转换
    int* c = static_cast<int *>(malloc(sizeof(*c) * 20));
    free(c);

    // 使用 calloc() 可初始化分配后的内存区域为全零。
    int* d = static_cast<int *>(calloc(20, sizeof(*d)));
    d = static_cast<int *>(realloc(c, sizeof(*d) * 40));
    free(d);
```

	
### 使用动态内存优化归并排序

- 在归并排序的递归实现中，若使用变长数组分配临时归并用数组，将导致空间复杂度极大提高。
- [完整程序](https://gitee.com/vincentwei7/PLZS/blob/main/source/noi-csp-j/lesson-2/merge-sort-asc-alloc.cpp)

```cpp
template <class T>
void merge_sort_asc(T *t, size_t start, size_t stop, T* buf)
{
    // 递归终止条件：只有一个元素或者没有元素时终止
    if (stop - start <= 1)
        return;

    // 将数组从中间分开，然后递归对两个分区执行合并排序。
    size_t mid = start + ((stop - start) >> 1);
    merge_sort_asc(t, start, mid, buf);
    merge_sort_asc(t, mid, stop, buf);

    // 合并到 buf 数组中。
    merge(t + start, mid - start, t + mid, stop - mid, buf + start);

    // 将合并后的 buf 数组中的元素放回 t 中。
    for (size_t i = start; i < stop; ++i)
        t[i] = buf[i];
}

#define NR_REALS 5

    double a[NR_REALS];
    for (size_t i = 0; i < NR_REALS; i++) {
        cin >> a[i];
    }

    double* buf = new double[NR_REALS];
    merge_sort_asc(a, 0, sizeof(a)/sizeof(a[0]), buf);
    delete[] buf;
```

	
### C++ 和 C 的在动态内存管理上的异同

- 用于基础类型时，`new` 等同于 `malloc()`，`delete` 等同于 `free()`。
- 用于基础类型时，`new[]` 等同于 `calloc()`，会负责初始化为全零，`delete[]` 等同于 `free()`。
- 若使用 `malloc()/calloc()/realloc()` 分配 C++ 类对象，则只会分配成员变量（类似结构体一样处理），而不会主动调用对应的构造函数。
- 使用 `new` 分配的类对象，会调用构造函数，只能使用 `delete` 释放，且在释放时，会调用类的析构函数。
- 使用 `new[]` 分配的类对象数组，会依次调用其中所有元素的构造函数，且只能使用 `delete[]` 释放，且在释放时，会对每个元素调用类的析构函数。
- C++ 的 `new/new[]` 和 `delete/delete[]` 运算符可被重载。

	
### 类对象的动态创建和销毁

- 使用 `new` 可动态创建一个类的对象，此时获得一个指针类型。
- 对使用指针表达的类对象，我们使用 `->` 运算符引用其成员变量或成员函数。

```cpp
class Rectangle {
    double width, height;

  public:
    // Rectangle 类的构造器（constructor)
    Rectangle(double w, double h) {
        width = w; height = h;
    }

    // Rectangle 类的 perimeter 方法（method)，用于计算周长。
    double perimeter() {
        return (width + height) * 2.0;
    }

    // Rectangle 类的 area 方法，用于计算面积。
    double area() {
        return width * height;
    }
};

    // 使用 new/delete 创建/销毁一个类对象
    Rectangle *rc = new Rectangle { 20.0, 20.0 };
    cout << rc->perimeter() << endl;
    cout << rc->area() << endl;
    delete rc;
```

	
### `this` 指针和静态成员

- C++ 的 `this` 关键词用于指代当前类对象，其类型是这个类的指针；`this` 关键词只能在类的非静态成员函数中使用。
   1. 类的非静态成员函数，必须通过这个类的一个对象调用。
   1. 类的静态成员函数，可在没有类对象的情况下调用，从而不能在静态成员函数中使用 `this` 指针。
   1. 我们可以认为 C++ 为所有非静态成员函数 `隐式` 传入了 `this` 指针作为第一个形参。

	
- [完整程序](https://gitee.com/vincentwei7/PLZS/blob/main/source/noi-csp-j/lesson-2/dynamic-class-object.cpp)

```cpp
class Rectangle {
    // 该静态成员变量可用于统计 Rectangle 实例的个数。
    // 注意：
    // 下面这条语句只是声明了该静态成员变量，
    // 在使用前，还必须在 C++ 源文件中显式定义这一静态成员变量。
    static unsigned _nr_rectangles;

    double width, height;

  public:
    // Rectangle 类的构造器（constructor)
    Rectangle(double width, double height) {
        _nr_rectangles++;

        this->width = width;
        this->height = height;
    }

    // Rectangle 类的析构函数（denstructor)
    ^Rectangle() {
        _nr_rectangles--;
    }

    /* 我们可以认为 C++ 编译器为非静态成员函数传入了调用该成员函数时
       对应的那个类对象的指针，而该指针作为一个隐式的形参存在，
       其名称为 `this`：

        double area(Rectangle *this) {
            return this->width * this->height;
        }
     */
    // Rectangle 类的 area 方法，用于计算面积。
    double area() {
        return this->width * this->height;
    }

    /* 为方便书写，在不引起歧义的情形下，在成员函数中无需使用 this
       来引用当前类的成员函数或者成员变量。
     */
    // Rectangle 类的 perimeter 方法（method)，用于计算周长。
    double perimeter() {
        return (width + height) * 2.0;
    }

    // 在静态成员函数中，只能访问静态成员变量，不能使用 this 指针。
    static unsigned quantity() {
        return _nr_rectangles;
    }
};

// 必须在 C++ 源文件中显式定义类的静态成员变量
unsigned Rectangle::_nr_rectangles;

int main()
{
    // 使用 new/delete 创建/销毁一个类对象
    Rectangle *rc = new Rectangle { 20.0, 20.0 };

    // 调用静态成员函数时，不需要通过某个特定的类对象
    cout << Rectangle::quantity() << endl;

    cout << rc->area() << endl;

    delete rc;

    cout << Rectangle::quantity() << endl;
}
```

		
## 实用技巧

	
### C++ STL 提供的排序接口

- `sort()` 和 `stable_sort()` 函数模板，可用于支持随机访问迭代器的容器，如内置数组、`array`、`vector`：

```cpp
template <class RandomAccessIterator>
void sort(RandomAccessIterator first, RandomAccessIterator last);

template <class RandomAccessIterator, class Compare>
void sort(RandomAccessIterator first, RandomAccessIterator last, Compare comp);

template <class RandomAccessIterator>
void stable_sort(RandomAccessIterator first, RandomAccessIterator last);

template <class RandomAccessIterator, class Compare>
void stable_sort( RandomAccessIterator first, RandomAccessIterator last, Compare comp);
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
- 这些运算包括算术运算、比较运算、逻辑运算等。[参考链接](https://cplusplus.com/reference/functional/)。

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

	
1) 实现一个函数模板 `insertion_sort()` ，该函数使用外部对比函数实现内置数组的降序或升序排序，并完成展示该函数模板功能的完整程序 `insertion-sort.cpp`。运行效果如下：

```console
% ./insertion-sort
<12 344 8 234 23>
Ascending order:
8 12 23 234 344
Descending order:
344 234 23 12 8
```

	
2) 使用函数模板实现归并排序算法的迭代版本。运行效果如下：

```console
$ ./merge-sort-iteration
<11 -9 10 -13 14 15 9 -7 5>
-13 -9 -7 5 10 11 14 15
```

	
3) 使用函数模板实现快速排序算法的迭代版本。运行效果如下：

```console
$ ./quick-sort-iteration
<11 -9 10 -13 14 15 9 -7 5>
-13 -9 -7 5 10 11 14 15
```

	
4) 生成一个给定长度的随机数组，分别使用本讲学过的排序算法之迭代实现进行排序，使用 `assert()` 测试正确性并测量各算法的实际运行时间。运行效果如下：

```console
$ ./compare-five-sort-algorithms
<1000>      # 指定数组长度
0.001s consumed when using selection sort.
0.001s consumed when using bubble sort.
0.001s consumed when using insertion sort.
0.001s consumed when using merge sort
0.001s consumed when using quick sort.
```

	
5) 经典比赛题（思考）
   - [Luogu B3968/成绩排序](https://www.luogu.com.cn/problem/B3968)
   - [Luogu P1628/合并序列](https://www.luogu.com.cn/problem/P1628)
   - [Luogu P1716/双调序列](https://www.luogu.com.cn/problem/P1716)
   - [Luogu B3630/排队顺序](https://www.luogu.com.cn/problem/B3630)

	
### 参考链接

（无）
