# 线性数据结构

1. 链表的引入
1. 单向链表
1. 双向链表
1. 环形链表
1. 选择哪种链表？
1. 队列和栈
1. 实用技巧

		
## 链表的引入

`Linked List`

	
### 简单矢量类模板

- 按需分配后背存储空间（back storage），避免了伪矢量类模板具有固定上限的问题；增加成员变量跟踪后背空间的实际大小。
- [完整程序](https://gitee.com/vincentwei7/PLZS/blob/main/source/noi-csp-j/lesson-3/simple-vector.cpp)

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

- 火车（train，列车）是一个个车厢（coach）连接构成的，可非常方便地更换损坏的车厢或者重组。
- 如果将元素打包到类似车厢的数据结构当中，然后将这些数据结构通过某种方式连接起来使用，在已知位置处执行插入和移除操作将变得非常简单；时间复杂度：`$ O(1) $`。
- 链表是由节点（node）构成的一个链条式（chain）数据结构，其中每个节点都包含有数据以及相邻节点的引用信息。在 C/C++ 中，通常使用指针（pointer）作为相邻节点的引用信息。
- 链表的优点：
   1. 解决了线性表数据结构中执行插入、移除等操作性能低下的问题，时间复杂度大幅降低。
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
- 第二个节点：second node
- 倒数第二个节点：second last node
- 负载：payload；节点中保存的数据（data）。

		
## 单向链表

`Singly Linked List`

	
### 定义

1. 单向链表（亦称“单链表”）的每个节点有两个字段（field）：`data/payload` 和 `next` 指针。
1. 其中，`data` 存储节点的负载，`next` 指针指向链表的下一个节点。
1. 最后一个节点的 `next` 指针始终设定为 `nullptr`，因为它是链表的最后一个结点，没有下一个结点。
1. 单向链表中，由于每个节点都链接到下一个节点，因此只能前向（forward）遍历各个节点。

<img style="height:300px;width:auto;" src="assets/noijunior-singly-linked-list.webp" />

	
### 单向链表的节点类模板

- [完整程序](https://gitee.com/vincentwei7/PLZS/blob/main/source/noi-csp-j/lesson-3/singly-linked-list.cpp)
- 基本定义：

```cpp []
template <typename T>
struct node {

    T payload;      // 节点负载
    node* next;     // 指向下一个节点的指针

    // 节点的构造函数。
    node(const T& value) {
        this->payload = value;
        this->next = nullptr;
    }
};

// 测试是否为空链表。
template <typename node>
bool empty(node* head) {
    return (head == nullptr);
}

// 返回链表的节点数量。
template <typename node>
size_t size(node* head) {
    size_t sz = 0;

    while (head) {
        sz++;
        head = head->next;
    }

    return sz;
}
```

	
### 单向链表常见操作

- 使用单向链表时，维护一个指向链表第一个节点的指针（`head`），所有的操作通过该指针进行。
- 若同时维护指向最后一个节点的指针（`tail`）容易引入混乱。

	
1) 遍历（traverse）

```cpp []
// 遍历节点
template <typename node, typename visit_func>
void traverse(node* head, visit_func visitor)
{
    // Start from the head of the linked list
    node* current = head;

    // Traverse the linked list until reaching the end (nullptr)
    while (current != nullptr) {

        // call the call back function
        if (!visitor(current->payload))
            break;

        // Move to the next node
        current = current->next;
    }
}
```

	
2) 后置插入（insert after）

```cpp []
// 在给定节点之后插入新节点（不会修改头部）
template <typename node, typename T>
void insert_after(node* current, const T& value)
{
    // Create a new node with the given value
    node* newnode = new node(value);

    // Link the original next node to the new node.
    newnode->next = current->next;

    // Link the new node to the current last node
    current->next = newnode;
}
```

	
3) 后置删除（erase after）

```cpp []
// 移除给定节点之后的节点（不会修改头部）
template <typename node>
void erase_after(node* current)
{
    if (current->next) {
        node* next_next = current->next->next;

        // Delete last node
        delete (current->next);

        // Change the next of current
        current->next = next_next;
    }
}
```

	
4) 压入/弹出头部（push/pop front）

```cpp []
// 在头部压入新节点，返回新的头部节点
template <typename node, typename T>
node* push_front(node* head, const T& value)
{
    // Create a new node with the given value
    node* newnode = new node(value);

    // Set the next pointer of the new node to the current head
    newnode->next = head;

    // Move the head to point to the new node
    head = newnode;

    // Return the new head of the linked list
    return head;
}

// 弹出头部节点，返回新的头部节点
template <typename node>
node* pop_front(node* head)
{
    if (head == nullptr)
        return nullptr;

    // Move the head pointer to the next node
    node* temp = head;
    head = head->next;

    delete temp;

    return head;
}
```

	
5) 压入/弹出尾部（push/pop back）

```cpp []
// 在尾部压入新节点，返回新的头部节点
template <typename node, typename T>
node* push_back(node* head, const T& value)
{
    // Create a new node with the given value
    node* newnode = new node(value);

    // If the list is empty, make the new node the head
    if (head == nullptr)
        return newnode;

    // Traverse the list until the last node is reached
    node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }

    // Link the new node to the current last node
    current->next = newnode;
    return head;
}

// 弹出尾部节点，返回新的头部节点
template <typename node>
node* pop_back(node* head)
{
    if (head == nullptr)
        return nullptr;

    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }

    // Find the second last node
    node* second_last = head;
    while (second_last->next->next != nullptr)
        second_last = second_last->next;

    // Delete last node
    delete (second_last->next);

    // Change next of second last
    second_last->next = nullptr;

    return head;
}
```

	
6) 清空（clear）

```cpp []
// 清空链表，返回新的头部节点（始终为 nullptr）
template <typename node>
node* clear(node* head)
{
    while (head) {
        node* next = head->next;
        delete head;
        head = next;
    };

    return nullptr;
}
```

	
7) 使用示例

思考：如果将第 30 行的 `push_back()` 修改为 `push_front()`，则当输入为 `-1 0 1 2 3 4 end` 时，结果如何？

```cpp []
using namespace std;

bool print_positive_value(double payload)
{
    if (payload > 0)
        cout << payload << endl;

    return true;
}

int main()
{
    node<double>* head = nullptr;

    // 此循环将持续读取用户的输入，直到 stod() 函数
    // 无法正常将空格分隔的字符串解析为浮点数而抛出异常为止。
    do {
        string buf;
        cin >> buf;

        double d;
        try {
            size_t sz;
            d = stod(buf, &sz);
        }
        catch (std::exception& e) {
            break;
        }

        head = push_back(head, d);
    } while (true);

    traverse(head, print_positive_value);
    clear(head);
}
```

	
8) 其他操作
   - 获取节点数量并使用索引值访问并执行在指定位置插入节点或移除节点的操作。
   - 铰接（splice）两个单向链表。
   - 查找（find）和给定数据相等的第一个节点。
   - 移除重复值（unique）。
   - 排序（sort）。

	
### 单向链表的特点

- 只能前向遍历。
- `push_front()` 和 `pop_front()` 的执行效率很高；时间复杂度：`$ O(1) $`。
- `push_back()` 和 `pop_back()` 的执行效率较低；虽然可以通过维护 `tail` 指针提升，但容易导致混乱。
- 无法高效实现前置插入（insert before）和前置移除（erase before）操作。

	
### 课堂练习

（十五分钟内完成）

1. 基于 [singly-linked-list.cpp](https://gitee.com/vincentwei7/PLZS/blob/main/source/noi-csp-j/lesson-3/singly-linked-list.cpp) 文件，补充实现针对单向链表的 `at()` 函数并使用索引值遍历该单向链表，并编写展示该功能的完整程序。
1. 将 `singly-linked-list.cpp` 文件添加到 `plzs-homework` 仓库的 `source/noi-csp-j/lesson-3/` 目录（下同），并推送到远程仓库。
1. 思考使用 `at()` 函数遍历单向链表的时间复杂度。

		
## 双向链表

`Doubly Linked List`

	
### 定义

1. 双向链表的每个节点有三个字段（field）：`data/payload`、`next` 指针和 `prev` 指针。
1. 其中，`data/payload` 存储数据（节点的负载），`next` 指针指向链表的下一个节点，而 `prev` 指针指向链表的上一个节点。
1. 第一个节点的 `prev` 指针始终设定为 `nullptr`，因为它是链表的第一个结点，没有上一个结点。
1. 最后一个节点的 `next` 指针始终设定为 `nullptr`，因为它是链表的最后一个结点，没有下一个结点。
1. 在双向链表中，由于每个节点都同时链接到下一个节点和上一个节点，因此可以在两个方向上（前向或向后）遍历各个节点。

<img style="height:300px;width:auto;" src="assets/noijunior-doubly-linked-list.webp" />

	
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
};

// 测试是否为空链表。
template <typename node>
bool empty(node* head) {
    return (head == nullptr);
}

// 返回链表的节点数量。
template <typename node>
size_t size(node* head) {
    size_t sz = 0;

    while (head) {
        sz++;
        head = head->next;
    }

    return sz;
}
```

	
### 双向链表常见操作

- 使用双向链表时，维护指向链表头部的指针（`head`），操作通过这个指针进行。
- 若同时维护 `head` 和 `tail` 指针，容易引入混乱。

	
1) 前向遍历或后向遍历（traverse forward/backward）

```cpp
// 前向遍历节点
template <typename node, typename visit_func>
size_t traverse_forward(node* head, visit_func visitor)
{
    size_t nr_visited = 0;

    // Start from the head of the linked list
    node* current = head;

    // Traverse the linked list until reaching the end (nullptr)
    while (current != nullptr) {

        // call the visitor
        if (!visitor(current->payload))
            break;

        nr_visited++;

        // Move to the next node
        current = current->next;
    }

    return nr_visited;
}

// 定位尾部
template <typename node>
node* locate_tail(node* current) {
    node *tail = current;
    while (tail && tail->next) {
        tail = tail->next;
    }
    return tail;
}

// 后向遍历节点
template <typename node, typename visit_func>
size_t traverse_backward(node* head, visit_func visitor)
{
    size_t nr_visited = 0;

    // Start from the tail of the linked list
    node* current = locate_tail(head);

    // Traverse the linked list until reaching the head (nullptr)
    while (current != nullptr) {

        // call visitor
        if (!visitor(current->payload))
            break;

        nr_visited++;

        // Move to the previous node
        current = current->prev;
    }

    return nr_visited;
}
```

	
2) 后置插入/删除（insert/erase after）

```cpp
// 在给定节点之后插入新节点（不会修改头部）
template <typename node, typename T>
void insert_after(node* current, const T& value)
{
    // Create a new node with the given value
    node* newnode = new node(value);

    // Set the previous of new node to current
    newnode->prev = current;
    // Set the next of new node to next of current
    newnode->next = current->next;

    // Update the next of current node to new node
    current->next = newnode;

    // If the new node is not the tail, update previous of next node to new node
    if (newnode->next != nullptr)
        newnode->next->prev = newnode;
}

// 移除给定节点之后的节点（不会修改头部）
template <typename node>
void erase_after(node* current)
{
    if (current->next) {
        node* next_next = current->next->next;

        // Delete last node
        delete (current->next);

        // Change the next of current
        current->next = next_next;

        if (next_next) {
            // Update the previous of next of next to current
            next_next->prev = current;
        }
    }
}
```

	
3) 前置插入/移除（inseret/erase before）

```cpp []
// 定位头部
template <typename node>
node* locate_head(node* current) {
    node *head = current;
    while (head && head->prev) {
        head = head->prev;
    }
    return head;
}

// 在给定节点之前插入新节点；可能修改头部，返回新的头部
template <typename node, typename T>
node* insert_before(node* current, const T& value)
{
    // Create a new node with the given value
    node* newnode = new node(value);

    node* head = locate_head(current);
    if (head == nullptr) {
        // make newnode the head
        return newnode;
    }

    // Set previous of new node to previous of given node
    newnode->prev = current->prev;
    // Set next of new node to given node
    newnode->next = current;

    // Update next of given node's previous to new node
    if (current->prev != nullptr) {
        newnode->prev->next = newnode;
    }
    else {
        // If the current node is the head, update the head
        head = newnode;
    }

    // Update previous of given node to new node
    current->prev = newnode;

    // Return the head of the doubly linked list
    return head;
}

// 移除给定节点之前的节点；可能修改头部，返回新的头部
template <typename node>
node* erase_before(node* current)
{
    node* head = locate_head(current);
    if (head == nullptr) {
        // If it is an empty list
        return nullptr;
    }

    if (current->prev) {
        node* prev_prev = current->prev->prev;

        // If the deleted node is head, update head to the current
        if (current->prev == head)
            head = current;

        // Delete previous node
        delete (current->prev);

        // Change the next of current
        current->prev = prev_prev;

        if (prev_prev) {
            // Update next of previous of previous to current
            prev_prev->next = current;
        }

    }

    return head;
}
```

	
4) 压入/弹出头部（push/pop front）

```cpp
// 在头部压入新节点，返回新的头部节点
template <typename node, typename T>
node* push_front(node* head, const T& value)
{
    // Create a new node with the given value
    node* newnode = new node(value);

    // Set the next pointer of the new node to the current head
    newnode->next = head;

    // Return the new head of the linked list
    return newnode;
}

// 弹出头部节点，返回新的头部节点
template <typename node>
node* pop_front(node* head)
{
    if (head == nullptr)
        return nullptr;

    // Move the head pointer to the next node
    node* temp = head;
    head = head->next;

    delete temp;

    return head;
}
```

	
5) 压入/弹出尾部（push/pop back）

```cpp
// 在尾部压入新节点，返回新的头部节点
template <typename node, typename T>
node* push_back(node* head, const T& value)
{
    // Create a new node with the given value
    node* newnode = new node(value);

    // Locate the tail
    node* tail = locate_tail(head);
    if (tail == nullptr) {
        // If the list is empty, make the new node the head
        head = newnode;
        goto done;
    }

    // Link the new node to the current last node
    tail->next = newnode;
    newnode->prev = tail;

done:
    return head;
}

// 弹出尾部节点，返回新的头部节点
template <typename node>
node* pop_back(node* head)
{
    if (head == nullptr)
        return nullptr;

    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }

    node* tail = locate_tail(head);

    // Change next of second last
    if (tail->prev)
        tail->prev->next = nullptr;

    // Delete last node
    delete (tail);

    // If tail is head, the list is empty
    if (head == tail)
        return nullptr;

    return head;
}
```

	
8) 清空（clear）

```cpp
// 清空链表，返回新的头部节点（始终为 nullptr）
template <typename node>
node* clear(node* head)
{
    while (head) {
        node* next = head->next;
        delete head;
        head = next;
    };

    return nullptr;
}
```

	
9) 其他操作
   - 获取节点数量并使用索引值访问并执行在指定位置插入节点或移除节点的操作。
   - 铰接（splice）两个双向链表。
   - 查找（find）和给定数据相等的第一个节点。
   - 移除重复值（unique）。
   - 排序（sort）。

	
### 双向链表的特点

- 可执行前向或者后向遍历。
- `push_front()/pop_front()` 的执行效率很高；时间复杂度：`$ O(1) $`。
- `push_back()/pop_back()` 的执行效率较低；虽然可以通过维护 `tail` 指针提升，但容易导致混乱。
- 可高效实现前置/后置插入（insert before/after）操作以及前置/后置移除（erase before/after）操作。

	
### 课堂练习

（十分钟内完成）

1. 基于 [doubly-linked-list.cpp](https://gitee.com/vincentwei7/PLZS/blob/main/source/noi-csp-j/lesson-3/doubly-linked-list.cpp) 文件，补充实现针对双向链表的 `splice()` 函数，并编写展示该功能的完整程序。
1. 调试通过后添加到作业仓库并提交、推送。

		
## 环形链表

`Circular Linked List`

	
### 定义

- 不论是单向链表还是双向链表，将链表的首尾节点链接起来，可构成环形（或循环）链表（circular linked list 或 loop list）：
   1. 将链表最后一个节点的 `next` 字段指向第一个节点；将链表第一个节点的 `prev` 字段指向最后一个节点。
   1. 通过 `next` 指针，链表的所有节点构成一个前向环；而通过 `prev` 指针，链表的所有节点构成一个后向环。

<img style="height:300px;width:auto;" src="assets/noijunior-circular-linked-list.webp" />

	
- 环形链表的好处：
   1. 从任意一个节点出发，可遍历所有节点。
   1. 使用环形单向链表时，对头部、尾部的操作都要顾忌尾部或者倒数第二个节点的 `next` 指针，故而并不能提高在头部和尾部的操作性能。
   1. 使用环形双向链表时，仅通过指向头部的 `head` 指针即可快速定位头部或尾部（`head->prev`），从而使得 `push_back()/pop_back()` 方法的时间复杂度降为 `$ O(1) $`。

<img style="height:300px;width:auto;" src="assets/noijunior-doubly-circular-linked-list.webp" />

	
### 环形链表的实现：以单向环形链表为例

- [完整程序](https://gitee.com/vincentwei7/PLZS/blob/main/source/noi-csp-j/lesson-3/singly-circula-linked-list.cpp)
- 类模板的定义：

```cpp
template <class T>
class forward_loop_list {
private:
    struct context_sizing {
        size_t nr;
    };

    struct visitor_sizing {
        bool operator() (context_sizing* ctxt, const T& /* value */) {
            ctxt->nr++;
            return true;
        }

        size_t nr;
    };

    struct node {
        T payload;      // 节点负载
        node* next;     // 指向下一个节点的指针

        // 节点的构造函数。
        node(const T& value) {
            this->payload = value;
            this->next = nullptr;
        }
    };

    node* _head;

public:
    // 构造函数
    forward_loop_list() {
        _head = nullptr;
    }

    // 析构函数
    ~forward_loop_list() {
        clear();
    }

    // 测试是否为空链表
    bool empty() {
        return (_head == nullptr);
    }

    // 获取大小（节点数量）
    size_t size() {
        context_sizing ctxt = { 0 };
        traverse(&ctxt, visitor_sizing{});
        return ctxt.nr;
    }

    // （只读）遍历链表节点
    template <typename context, typename visitor_func>
    const node* traverse(context* ctxt, visitor_func visitor) const
    {
        // Start from the tail of the linked list
        node* current = _head;

        // Traverse the linked list until reaching the tail
        while (current) {
            // call the visitor
            if (!visitor(ctxt, current->payload))
                break;

            // Move to next node
            current = current->next;

            // Test if reached the tail
            if (current == _head)
                break;
        }

        return current;
    }

    // 访问头部负载
    T& front() {
        if (empty())
            throw std::out_of_range(__func__);
        return _head->payload;
    }

    const T& front() const {
        if (empty())
            throw std::out_of_range(__func__);
        return _head->payload;
    }

    // 访问尾部负载
    T& back() {
        if (empty())
            throw std::out_of_range(__func__);

        // Find the tail
        node* tail = _head;
        while (tail->next != _head)
            tail = tail->next;
        return tail->payload;
    }

    const T& back() const {
        if (empty())
            throw std::out_of_range(__func__);

        // Find the tail
        node* tail = _head;
        while (tail->next != _head)
            tail = tail->next;
        return tail->payload;
    }

    // 压入头部
    void push_front(const T& value)
    {
        // Create a new node with the given value
        node* newnode = new node(value);

        // Check if the list is empty before pushing
        if (_head == nullptr) {
            _head = newnode;
            _head->next = _head;
            return;
        }

        // Find the tail
        node* tail = _head;
        while (tail->next != _head)
            tail = tail->next;

        // Set the next of the tail new node
        tail->next = newnode;
        // Set the next of the new node to the current head
        newnode->next = _head;
        // Reset head
        _head = newnode;
    }

    // 弹出头部
    void pop_front()
    {
        if (empty())
            return;             // Return silently

        // Save original head temporarily
        node *org_head = _head;

        // Find the tail
        node* tail = _head;
        while (tail->next != _head)
            tail = tail->next;

        // Set the next of the tail new head
        tail->next = _head->next;

        // Move the head pointer to the next node
        _head = _head->next;

        // Delete the original head
        delete org_head;

        // Check if there was only one node before popping
        if (_head == org_head) {
            _head = nullptr;
        }
    }

    // 压入尾部
    void push_back(const T& value)
    {
        // Create a new node with the given value
        node* newnode = new node(value);

        // If the list is empty, make the new node the head/tail
        if (_head == nullptr) {
            _head = newnode;
            newnode->next = newnode;
            return;
        }

        // Find the tail
        node* tail = _head;
        while (tail->next != _head)
            tail = tail->next;

        // Link the new node to the current tail
        newnode->next = tail->next;
        tail->next = newnode;
    }

    // 弹出尾部
    void pop_back()
    {
        if (empty())
            return;

        // If there is only one node in the list
        if (_head->next == _head) {
            delete _head;
            _head = nullptr;
            return;
        }

        // Find the second last
        node* second_last = _head;
        while (second_last->next->next != _head)
            second_last = second_last->next;

        // Remove tail from list
        node *tail = second_last->next;
        second_last->next = _head;

        // Delete tail
        delete tail;
    }

    // 清空链表
    void clear()
    {
        // Start from the head of the linked list
        node* current = _head;

        // Traverse the linked list until reaching the tail
        while (current) {
            // Save next node temporarily.
            node* next = current->next;

            // Delete current node
            delete current;

            // Check if reached the tail
            if (next == _head)
                break;

            // Move to next
            current = next;
        }

        _head = nullptr;
    }
};
```

	
### 使用示例

```cpp
void test()
{
    struct context_print {
        ostream& os;
    };

    struct visitor_print {
        bool operator() (context_print* ctxt, const double& value) {
            ctxt->os << value << endl;
            return true;
        }

        size_t nr;
    };

    forward_loop_list<double> list;

    assert(list.empty() == true);

    list.push_front(0);

    context_print ctxt = { cout };
    list.traverse(&ctxt, visitor_print{});

    assert(list.empty() == false);
    assert(list.size() == 1);
    assert(list.front() == 0);
    assert(list.back() == 0);

    list.push_back(1);
    list.traverse(&ctxt, visitor_print{});

    assert(list.size() == 2);
    assert(list.front() == 0);
    assert(list.back() == 1);

    list.clear();
    assert(list.empty());
    cout << "clear() passed\n";

    list.push_front(0);
    list.traverse(&ctxt, visitor_print{});
    assert(list.size() == 1);
    cout << "#1 push_front() passed\n";

    list.push_front(1);
    list.traverse(&ctxt, visitor_print{});
    assert(list.size() == 2);
    cout << "#2 push_front() passed\n";

    list.push_front(2);
    list.traverse(&ctxt, visitor_print{});
    assert(list.size() == 3);
    cout << "#3 push_front() passed\n";

    list.push_front(3);
    assert(list.size() == 4);
    cout << "#4 push_front() passed\n";

    list.push_back(-1);
    list.traverse(&ctxt, visitor_print{});
    assert(list.size() == 5);
    cout << "#1 push_back() passed\n";

    list.push_back(-2);
    list.traverse(&ctxt, visitor_print{});
    assert(list.size() == 6);
    cout << "#2 push_back() passed\n";

    list.push_back(-3);
    list.traverse(&ctxt, visitor_print{});
    assert(list.size() == 7);
    cout << "#3 push_back() passed\n";

    assert(list.front() == 3);
    assert(list.back() == -3);
    cout << "push_front() and push_back() passed\n";

    list.pop_front();
    list.traverse(&ctxt, visitor_print{});
    assert(list.size() == 6);
    assert(list.front() == 2);
    assert(list.back() == -3);
    cout << "#1 pop_front() passed\n";

    list.pop_front();
    list.traverse(&ctxt, visitor_print{});
    assert(list.size() == 5);
    assert(list.front() == 1);
    assert(list.back() == -3);
    cout << "#2 pop_front() passed\n";

    list.pop_front();
    list.traverse(&ctxt, visitor_print{});
    assert(list.size() == 4);
    assert(list.front() == 0);
    assert(list.back() == -3);
    cout << "#3 pop_front() passed\n";

    list.pop_back();
    list.traverse(&ctxt, visitor_print{});
    assert(list.size() == 3);
    assert(list.front() == 0);
    assert(list.back() == -2);
    cout << "#1 pop_back() passed\n";

    list.pop_back();
    list.traverse(&ctxt, visitor_print{});
    assert(list.size() == 2);
    assert(list.front() == 0);
    assert(list.back() == -1);
    cout << "#2 pop_back() passed\n";

    list.pop_back();
    list.traverse(&ctxt, visitor_print{});
    assert(list.size() == 1);
    assert(list.front() == 0);
    assert(list.back() == 0);
    cout << "#3 pop_back() passed\n";

    list.clear();
    assert(list.empty());
}
```

	
### 课堂练习

（十分钟内完成）

1. 基于 [singly-circular-linked-list.cpp](https://gitee.com/vincentwei7/PLZS/blob/main/source/noi-csp-j/lesson-3/singly-circular-linked-list.cpp) 文件，在 `main()` 函数中补充实现一个完整的程序功能，该程序从标准输入读取浮点数构造一个单向循环链表，直到读取到 `END` 为止，并利用 `traverse()` 方法输出其内容。
1. 调试通过后添加到作业仓库并提交、推送。

		
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

- `std::forward_list` 类模板：前向链表（使用单向链表实现）。
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

	
- `std::forward_list` 类模板（续）：
   - 方法 `remove()`：移除链表中的指定值。
   - 方法 `unique()`：移除链表中的重复值。
   - 方法 `merge()`：合并两个已排序的链表。
   - 方法 `sort()`：执行排序操作。
   - 方法 `reverse()`：执行反序操作。
   - [更多接口](https://cplusplus.com/reference/forward_list/)

	
### C++ STL 提供的双向链表类模板

- `std::list` 类模板：前后向链表（使用双向链表实现）。
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

	
- `std::list` 类模板（续）：
   - 方法 `remove()`：移除链表中的指定值。
   - 方法 `unique()`：移除链表中的重复值。
   - 方法 `merge()`：合并两个已排序的链表。
   - 方法 `sort()`：执行排序操作。
   - 方法 `reverse()`：执行反序操作。
   - [更多接口](https://cplusplus.com/reference/list/)

	
### C++ STL 提供的队列类模板

- `std::queue` 类模板；基于支持 FIFO 操作的容器实现。
   - `#include <queue>`
   - 方法 `empty()`：判断队列是否为空。
   - 方法 `size()`：返回队列中的元素数量。
   - 方法 `front()`：返回队列中下一个元素的引用；使用底层容器的 `front()` 方法实现。
   - 方法 `back()`：返回队列中最后一个元素的引用；使用底层容器的 `back()` 方法实现。
   - 方法 `push()`：在队列尾部插入一个新元素；使用底层容器的 `push_back()` 方法实现。
   - 方法 `pop()`：移除队列中的下一个元素；使用底层容器的 `pop_front()` 方法实现。
   - [更多接口](https://cplusplus.com/reference/queue/)

	
### C++ STL 提供的栈类模板

- `std::stack` 类模板；基于支持 LIFO 操作的容器实现。
   - `#include <stack>`
   - 方法 `empty()`：判断栈是否为空。
   - 方法 `size()`：返回栈中的元素数量。
   - 方法 `top()`：返回栈顶元素的引用；使用底层容器的 `back()` 方法实现。
   - 方法 `push()`：在栈顶部压入一个新元素；使用底层容器的 `push_back()` 方法实现。
   - 方法 `pop()`：移除栈顶的元素；使用底层容器的 `pop_back()` 方法实现。
   - [更多接口](https://cplusplus.com/reference/queue/)

		
## 作业

	
1) 针对单向链表实现 `unique()` 方法，该函数可移除单向链表中所有重复的值，然后编写用来展示该功能的程序：用户每行输入一个浮点数，直到输入 `END` 为止，最后给出经 `unique()` 方法处理后的链表内容。运行效果如下：

```console
$ ./unique-values
<100>
<101>
<100>
<END>
100 101
```

	
2) 参照单向环形链表实现双向环形链表，并针对双向链表实现 `sort()` 方法，然后编写用来展示该功能的程序：用户每行输入一个浮点数，直到输入 `END` 为止，最后给出经 `sort()` 方法处理后的链表内容。运行效果如下：

```console
$ ./sort-loop-list
<100>
<101>
<99>
<102>
<END>
99 100 101 102
```

	
3) 使用`std::vector` 类模板解析前缀表达式（仅支持加减乘除四种运算）并求值。运行效果如下：

```console
$ evaluate-postfix-expression-vector
<- / + 6 * 2 3 4 5>
-2
```

	
4) 使用 STL 的 `std::stack` 类模板解析后缀表达式（仅支持加减乘除四种运算）并求值。运行效果如下：

```console
$ evaluate-postfix-expression-stack
<500 100 200 + ->
200
```

	
5) 使用 STL 的 `std::queue` 类模板使用队列实现一个批处理程序。该程序不停地从标准输入读取前缀表达式（每行一个），并在队列中暂存这些前缀表达式，当读取到四个表达式时，统一进行求值并输出结果，之后继续从标准输入读取新的前缀表达式，直到读入 `END` 为止。运行效果如下：

```console
$ evaluate-postfix-expression-batch
<+ 500 100>
<- 500 100>
<* 500 100>
</ 500 100>
600
400
50000
5
<+ 5 1>
<END>
6
```

	
6) 经典比赛题（思考）
   - [Luogu B3968/成绩排序](https://www.luogu.com.cn/problem/B3968)
   - [Luogu P1628/合并序列](https://www.luogu.com.cn/problem/P1628)
   - [Luogu P1716/双调序列](https://www.luogu.com.cn/problem/P1716)
   - [Luogu B3630/排队顺序](https://www.luogu.com.cn/problem/B3630)

	
### 参考链接

（无）
