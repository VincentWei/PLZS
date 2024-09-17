# 线性数据结构

1. 链表的引入
1. 单向链表
1. 双向链表
1. 循环链表
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
- 如果将元素打包到类似车厢的数据结构当中，然后将这些数据结构通过某种方式连接起来使用，插入和移除操作将变简单。
- 链表是由节点（node）构成的一个链条式式（chain）数据结构，其中每个节点都包含有数据以及相邻节点的引用信息。在 C/C++ 中，通常使用指针（pointer）作为相邻节点的引用信息。
- 链表的优点：
   1. 解决了线性表数据结构的插入、移除等操作性能低下的问题，时间复杂度变为 `$ O(1) $`。
   1. 避免了动态分配整块的连续存储空间，每个节点可以单独分配和释放，这可有效提高内存空间的使用效率。
- 链表的缺点：
   1. 通过位置（索引）访问元素时，时间复杂度变高：`$ O(n) $`。
   1. 节点中需要保存用于引用相邻节点的额外成员信息。

	
### 链表相关术语

- 链表：linked list
- 链表头：head
- 节点：node
- 下一个节点：next node
- 上一个节点：previous node
- 第一个节点：first node
- 最后一个节点：last node
- 负载：payload；节点中保存的数据（data）。

		
## 单向链表

`Singly Linked List`

	
### 结构图

	
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

	
4) 插入尾部（push front）

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

（十分钟内完成）

1. 在 `singly-linked-list.cpp` 文件中实现针对单向链表的 `size()` 和 `at()` 函数模板并使用索引值遍历该单向链表，并编写展示该功能的完整程序。
1. 将 `singly-linked-list.cpp` 文件添加到 `plzs-homework` 仓库的 `source/noi-csp-j/lesson-3/` 目录（下同），并推送到远程仓库。
1. 思考使用 `at()` 函数遍历单向链表的时间复杂度。

		
## 双向链表

`Doubly Linked List`

		
## 循环链表

`Circular Linked List`

		
## 队列和栈

`Queue and Stack`

		
## 实用技巧

		
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

	
2) 

```console
```
	
5) 经典比赛题（思考）
   - [Luogu B3968/成绩排序](https://www.luogu.com.cn/problem/B3968)
   - [Luogu P1628/合并序列](https://www.luogu.com.cn/problem/P1628)
   - [Luogu P1716/双调序列](https://www.luogu.com.cn/problem/P1716)
   - [Luogu B3630/排队顺序](https://www.luogu.com.cn/problem/B3630)

	
### 参考链接

（无）
