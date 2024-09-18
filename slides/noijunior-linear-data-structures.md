# 线性数据结构

1. 链表的引入
1. 单向链表
1. 双向链表
1. 环形链表
1. 环形缓冲区
1. 队列和栈
1. 实用技巧

		
## 链表的引入

`Linked List`

	
### 简单矢量类模板

- 按需分配后背存储空间（back storage），避免了伪矢量类模板具有固定上限的问题；增加成员变量跟踪后背空间的实际大小。
- [完整程序](https://gitee.com/vincentwei7/PLZS/blob/main/source/noi-csp-j/lesson-3/my-vector.cpp)

```cpp
#define NR_EXTRA_SLOTS      4

template <class T>
class simple_vector {
    T* _back_array;
    size_t _sz_alloc;
    size_t _sz_actual;

    void expand() {
        T* space = new T[_sz_alloc + NR_EXTRA_SLOTS];
        for (size_t i = 0; i < _sz_actual; i++) {
            space[i] = std::move(_back_array[i]);
        }

        delete[] _back_array;
        _back_array = space;
        _sz_alloc += NR_EXTRA_SLOTS;
    }

public:
    simple_vector() {
        _back_array = nullptr;
        _sz_alloc = 0;
        _sz_actual = 0;
    }

    ~simple_vector() {
        if (_back_array != nullptr) {
            delete[] _back_array;
        }
    }

    ...
}
```

	
### 插入操作

```cpp
    void insert(const T& elem, size_t pos) {
        if (_sz_actual == _sz_alloc) {
            expand();
        }

        if (pos < _sz_actual) {
            for (size_t i = _sz_actual; i > pos; i--) {
                _back_array[i] = _back_array[i - 1];
            }

            _back_array[pos] = elem;
            _sz_actual++;
        }
        else {
            throw std::out_of_range("Out of range!");
        }
    }
```

	
### 移除操作

```cpp
    void erase(size_t pos) {
        if (pos < _sz_actual) {
            for (size_t i = pos + 1; i < _sz_actual; i++) {
                _back_array[i - 1] = _back_array[i];
            }
            _sz_actual--;
        }
        else {
            throw std::out_of_range("Out of range!");
        }
    }
```

	
### 线性表数据结构的优点和缺点

- 优点：
   1. 通过位置（索引）访问元素时，始终具有 `$ O(1) $` 的时间复杂度。
- 缺点：
   1. 某些操作的性能较差，如在指定位置插入元素，或者移除指定位置的元素时，时间复杂度为 `$ O(n) $`。
   1. 支持可变大小的矢量类线性表，在扩展后背存储的大小时，需要两倍的峰值存储空间。

	
### 链表的引入和优缺点

- 火车（train，列车）是一个个车厢（coach）连接构成的。
- 如果将元素打包到类似车厢的数据结构当中，然后将这些数据结构通过某种方式连接起来使用，在已知位置处执行插入和移除操作将变简单；时间复杂度：`$ O(1) $`。
- 链表是由节点（node）构成的一个链条式（chain）数据结构，其中每个节点都包含有数据以及相邻节点的引用信息。在 C/C++ 中，通常使用指针（pointer）作为相邻节点的引用信息。
- 链表的优点：
   1. 解决了线性表数据结构的插入、移除等操作性能低下的问题，时间复杂度大幅降低。
   1. 避免了动态分配整块的连续存储空间，每个节点可以单独分配和释放，可有效提高内存的使用效率。
- 链表的缺点：
   1. 通过位置（索引）访问元素时，时间复杂度将变高：`$ O(n) $`。
   1. 节点中需要保存用于引用相邻节点的额外成员信息。

	
### 链表相关术语

- 链表：linked list
- 链表头：head
- 链表尾：tail
- 节点：node
- 下一个节点：next node
- 上一个节点：previous node
- 第一个节点：first node
- 最后一个节点：last node
- 负载：payload；节点中保存的数据（data）。

		
## 单向链表

`Singly Linked List`

	
### 定义

1. 单向链表（亦称“单链表”）的每个节点有两个字段（field）：`data/payload` 和 `next` 指针。
1. 其中，`data` 存储节点的负载，`next` 指针指向链表的下一个节点。
1. 最后一个节点的 `next` 指针始终设定为 `nullptr`，因为它是链表的最后一个结点，没有下一个结点。
1. 单向链表中，由于每个节点都链接到下一个节点，因此只能前向（forward）遍历各个节点。

	
### 单向链表的节点类模板

- [完整程序](https://gitee.com/vincentwei7/PLZS/blob/main/source/noi-csp-j/lesson-3/singly-linked-list.cpp)
- 基本定义：

```cpp
template <class T>
struct node {
public:
    // 节点负载
    T payload;
    // 指向下一个节点的指针
    node* next;

    // 节点的构造函数。
    node(const T& payload) {
        this->payload = payload;
        this->next = nullptr;
    }
};
```

	
### 单向链表常见操作

1) 遍历（travese）

```cpp
// Traverse and print the elements of the linked list
void travese(node* head)
{
    // Start from the head of the linked list
    node* current = head;

    // Traverse the linked list until reaching the end (nullptr)
    while (current != nullptr) {

        // Print the data of the current node
        cout << current->payload << " ";

        // Move to the next node
        current = current->next;
    }

    cout << std::endl;
}
```

	
2) 插入头部（push front）

```cpp
```

	
3) 删除头节点（pop front）

```cpp
```

	
4) 插入尾部（push back）

```cpp
```

	
5) 删除尾节点（pop back）

```cpp
```

	
6) 清空（clear）

```cpp
```

	
7) 其他操作
   - 获取节点数量并使用索引值访问并执行在指定位置插入节点或移除节点的操作。
   - 串接（concatenate）两个单向链表。
   - 查找（find）和给定数据相等的第一个节点。
   - 移除重复值（unique）。
   - 排序（sort）。

	
### 课堂练习

（十五分钟内完成）

1. 在 `singly-linked-list.cpp` 文件中实现针对单向链表的 `size()` 和 `at()` 方法并使用索引值遍历该单向链表，并编写展示该功能的完整程序。
1. 将 `singly-linked-list.cpp` 文件添加到 `plzs-homework` 仓库的 `source/noi-csp-j/lesson-3/` 目录（下同），并推送到远程仓库。
1. 思考使用 `at()` 方法遍历单向链表的时间复杂度。

		
## 双向链表

`Doubly Linked List`

	
### 定义

1. 双向链表的每个节点有三个字段（field）：`data/payload`、`next` 指针和 `prev` 指针。
1. 其中，`data/payload` 存储数据（节点的负载），`next` 指针指向链表的下一个节点，而 `prev` 指针指向链表的上一个节点。
1. 第一个节点的 `prev` 指针始终设定为 `nullptr`，因为它是链表的第一个结点，没有上一个结点。
1. 最后一个节点的 `next` 指针始终设定为 `nullptr`，因为它是链表的最后一个结点，没有下一个结点。
1. 在双向链表中，由于每个节点都同时链接到下一个节点和上一个节点，因此可以在两个方向上（前向或向后）遍历各个节点。

	
### 双向链表的节点类模板

- [完整程序](https://gitee.com/vincentwei7/PLZS/blob/main/source/noi-csp-j/lesson-3/doubly-linked-list.cpp)
- 基本定义：

```cpp
template <class T>
struct node {
    T payload;      // 节点负载
    node* next;     // 指向下一个节点的指针
    node* prev;     // 指向上一个节点的指针

    // 节点的构造函数。
    node(const T& value) {
        this->payload = value;
        this->next = nullptr;
        this->prev = nullptr;
    }
```

		
## 环形链表

`Circular Linked List`

	
### 定义

- 不论是单向链表还是双向链表，将链表的首尾节点链接起来，可构成环形链表（circular linked list 或 loop list）：
   1. 将链表最后一个节点的 `next` 字段指向第一个节点；将链表第一个节点的 `prev` 字段指向最后一个节点。
   1. 通过 `next` 指针，链表的所有节点构成一个前向环；而通过 `prev` 指针，链表的所有节点构成一个后向环。
- 结构图

	
- 环形链表的好处：
   1. 从任意一个节点出发，可遍历所有节点。
   1. 可用来实现环形缓冲区、队列或者栈。
   1. 使用环形单向链表时，通过保存指向头部和尾部的 `head`、`tail` 指针，可以快速定位头部或尾部，从而使得 `push_back()/pop_back()` 方法的时间复杂度降为 `$ O(1) $`。
   1. 使用环形双向链表时，仅通过指向头部的 `head` 指针即可快速定位头部或尾部，从而使得 `push_back()/pop_back()` 方法的时间复杂度降为 `$ O(1) $`。

	
### 环形单向链表的节点类模板

- [完整程序](https://gitee.com/vincentwei7/PLZS/blob/main/source/noi-csp-j/lesson-3/circula-singly-linked-list.cpp)
- 基本定义：

```cpp
template <class T>
struct node {
    T payload;      // 节点负载
    node* next;     // 指向下一个节点的指针

    // 节点的构造函数。
    node(const T& value) {
        this->payload = value;
        this->next = this;
    }

    static bool empty(const node *) {
        return (node->next == node);
    }
```

	
### 环形双向链表的节点类模板

- [完整程序](https://gitee.com/vincentwei7/PLZS/blob/main/source/noi-csp-j/lesson-3/circula-doubly-linked-list.cpp)
- 基本定义：

```cpp
template <class T>
struct node {
    T payload;      // 节点负载
    node* next;     // 指向下一个节点的指针
    node* prev;     // 指向上一个节点的指针

    // 节点的构造函数。
    node(const T& value) {
        this->payload = value;
        this->next = this;
        this->prev = this;
    }

    static bool empty(const node *) {
        return (node->next == node);
    }
```

		
## 队列和栈

`Queue and Stack`

	
### 队列和栈的基本概念

- 队列（Queue）：先进先出（first in first out/FIFO）
- 栈（Stack）：先进后出（last in first out/LIFO）

	
### 队列和栈的实现

- 数组
- 矢量
- 链表

	
### 环形缓冲区

- `Ring/Loop Buffer`

		
## 实用技巧

	
### C++ STL 提供的单向链表类模板

- 类模板 `std::forward_list`：前向链表（使用单向链表实现）。
   - `#include <forward_list>`
   - 方法 `empty()`： 判断链表是否为空。
   - 方法 `clear()`： 清空链表。
   - 方法 `front()`：访问第一个元素。
   - 方法 `push_front()`：在链表头部插入一个元素。
   - 方法 `pop_front()`：删除链表头部的元素。
   - 方法 `begin()/cbegin()`：返回指向链表头部的迭代器。
   - 方法 `end()/cend()`：返回指向链表尾部的迭代器。
   - 方法 `insert_after()`：在迭代器所在位置的后面插入一个元素。
   - 方法 `erase_after()`：移除迭代器所在位置后面的元素。
   - 方法 `assign()`：修改迭代器指向位置的元素内容。
   - 方法 `splice_after()`：将一个前向链表铰接到迭代器所在位置的后面。
   - 方法 `remove()`：移除链表中的指定值。
   - 方法 `unique()`：移除链表中的重复值。
   - 方法 `merge()`：合并两个已排序的链表。
   - 方法 `sort()`：执行排序操作。
   - 方法 `reverse()`：执行反序操作。
   - [更多接口](https://cplusplus.com/reference/forward_list/)

	
### C++ STL 提供的双向链表类模板

- 类模板：`std::list`：前后向链表（使用双向链表实现）。
   - `#include <list>`
   - 方法 `empty()`：判断链表是否为空。
   - 方法 `size()`：返回链表中的元素数量。
   - 方法 `clear()`：清空链表。
   - 方法 `front()/back()`：访问第一个/最后一个元素。
   - 方法 `push_front()/push_back()`：在链表头部/尾部插入一个元素。
   - 方法 `pop_front()/pop_back()`：删除链表头部/尾部的元素。
   - 方法 `begin()/cbegin()`：返回指向链表头部的前向迭代器。
   - 方法 `end()/cend()`：返回指向链表尾部的前向迭代器。
   - 方法 `rbegin()/crbegin()`：返回指向链表头部的后向迭代器。
   - 方法 `rend()/crend()`：返回指向链表尾部的后向迭代器。
   - 方法 `insert()`：在迭代器所在位置插入一个元素。
   - 方法 `erase()`：移除迭代器所在位置的元素。
   - 方法 `assign()`：修改迭代器指向位置的元素内容。
   - 方法 `splice()`：将一个前后向链表铰接到迭代器所在位置。
   - 方法 `remove()`：移除链表中的指定值。
   - 方法 `unique()`：移除链表中的重复值。
   - 方法 `merge()`：合并两个已排序的链表。
   - 方法 `sort()`：执行排序操作。
   - 方法 `reverse()`：执行反序操作。
   - [更多接口](https://cplusplus.com/reference/list/)

	
### C++ STL 提供的队列类模板

- `std::queue`：队列类模板；基于支持 FIFO 操作的容器实现。
   - `#include <queue>`
   - 方法 `empty()`：判断队列是否为空。
   - 方法 `size()`：返回队列中的元素数量。
   - 方法 `front()`：返回队列中下一个元素的引用；使用底层容器的 `front()` 方法实现。
   - 方法 `back()`：返回队列中最后一个元素的引用；使用底层容器的 `back()` 方法实现。
   - 方法 `push()`：在队列尾部插入一个新元素；使用底层容器的 `push_back()` 方法实现。
   - 方法 `pop()`：移除队列中的下一个元素；使用底层容器的 `pop_front()` 方法实现。
   - [更多接口](https://cplusplus.com/reference/queue/)

	
### C++ STL 提供的栈类模板

- `std::stack`：栈类模板；基于支持 LIFO 操作的容器实现。
   - `#include <stack>`
   - 方法 `empty()`：判断栈是否为空。
   - 方法 `size()`：返回栈中的元素数量。
   - 方法 `top()`：返回栈顶元素的引用；使用底层容器的 `back()` 方法实现。
   - 方法 `push()`：在栈顶部压入一个新元素；使用底层容器的 `push_back()` 方法实现。
   - 方法 `pop()`：移除栈顶的元素；使用底层容器的 `pop_back()` 方法实现。
   - [更多接口](https://cplusplus.com/reference/queue/)

		
## 作业

	
1) 针对单向链表实现 `unique()` 函数模板，该函数可移除单向链表中所有重复的值，然后编写用来展示该功能的程序：用户每行输入一个浮点数，直到输入 `END` 为止，最后给出经 `unique()` 函数处理后的链表内容。运行效果如下：

```console
$ unique-values
<100>
<101>
<100>
<END>
100 101
```

	
2) 参照环形单向链表实现环形双向链表，并实现一个环形缓冲区。运行效果如下：

```console
```

	
3) 使用 STL 的 `vector` 解析后缀表达式（仅支持加减乘除四种运算）并求值。运行效果如下：

```console
$ evaluate-postfix-expression
<500 100 200 + ->
200
```

	
5) 经典比赛题（思考）
   - [Luogu B3968/成绩排序](https://www.luogu.com.cn/problem/B3968)
   - [Luogu P1628/合并序列](https://www.luogu.com.cn/problem/P1628)
   - [Luogu P1716/双调序列](https://www.luogu.com.cn/problem/P1716)
   - [Luogu B3630/排队顺序](https://www.luogu.com.cn/problem/B3630)

	
### 参考链接

（无）
