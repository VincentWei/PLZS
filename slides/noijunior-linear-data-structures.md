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

- 按需分配后背存储空间（back storage），避免了伪矢量类模板具有固定上限的问题。
- 增加成员变量跟踪后背空间的实际大小。
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
- 如果将元素打包到类似车厢的节点（node）当中，然后将这些节点链接（link）起来使用，插入和移除操作将变简单。
- 优点：
   1. 解决了线性表数据结构的插入、移除等操作性能低下的问题，时间复杂度变为 `$ O(1) $`。
   1. 避免了动态分配整块连续的存储空间，每个节点可以单独分配和释放。
- 缺点：
   1. 通过位置（索引）访问元素时，时间复杂度变高：`$ O(n) $`。
   1. 节点中需要保存用于链接节点的额外成员信息。

	
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

		
## 双向链表

		
## 循环链表

		
## 队列和栈

		
## 实用技巧

		
## 作业

	
1) 

```console
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
