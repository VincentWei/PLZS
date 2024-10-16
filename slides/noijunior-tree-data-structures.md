# 树形数据结构

1. 概览
1. 一般树
1. 二叉树
1. 特殊树
1. 树的应用
1. 实用技巧

		
## 概览

`Overview`

	
- 树是一种非线性（non-linear）数据结构，常用于表达具有从属关系的层次结构（hierarchy）：
  1. 某个国家的各级行政区划可以构成一颗树。
  1. 一个公司的组织结构可以构成一棵树。
  1. 一个家族成员可以构成一棵树。
- 树形数据结构在计算机中随处可见：
  1. 文件系统被组织成树形管理。
  1. 用于数据压缩（霍夫曼编码）。
  1. 常见的图文文档被解释为树形数据结构进行处理。
  1. 程序被编译器或解释器解析为语法树然后做进一步处理。
  1. 数据库管理系统中常用特殊的树来保存索引信息，用于快速查询符合特定条件的记录。

	
### 定义

- 树是由节点集合（collection）组成的非线性层次结构，树的每个节点都存储一个值以及对子节点的引用信息。

<img style="height:500px;width:auto;" src="assets/noijunior-tree-data-structure.png" />

	
### 术语

-  父（parent）节点：作为节点前身的节点称为该节点的父节点。
-  子（child）节点：节点的直接后继节点称为该节点的子节点。
-  根（root）节点：树的最顶端节点或没有父节点的节点称为根节点。
-  叶子（leaf）节点：没有任何子节点的节点称为叶子节点。
-  节点级别（level）：从根节点到该节点的路径（path）上的边数。根节点的级别为 `0`。

<img style="height:500px;width:auto;" src="assets/noijunior-tree-data-structure.png" />

	
-  节点的祖先（ancestor）：根到该节点的路径上的任何前任节点都称为该节点的祖先。
-  兄弟（sibling）节点：同一父节点的子节点称为兄弟节点。
-  内部（internal）节点：至少有一个子节点的节点称为内部节点。
-  外部（external）节点：即叶子节点。
-  节点的邻居（neighbour）：一个节点的父节点或子节点称为该节点的邻居。
-  子树（subtree）：树中任意一个节点及其后代（descendant）构成了子树。

<img style="height:500px;width:auto;" src="assets/noijunior-tree-data-structure.png" />

	
- 边（edge）数：边定义为两个节点之间的连接。如果一棵树有 `N` 个节点，那么它将有 `N-1` 条边。从每个节点到树的任何其他节点只有一条路径。
- 节点深度（depth）：节点的深度定义为从根到该节点的路径长度。每条边为路径增加 `1` 个单位的长度。因此，它也可以定义为从树根到节点的路径中的边数。
- 节点高度（height）：节点的高度可以定义为从节点到树的叶子节点的最长路径的长度。
- 树的高度（height）：树的高度是从树根到树叶节点的最长路径的长度。
- 节点的度（degree）：连接到一个节点的子树总数称为该节点的度。叶子节点的度数一定为 `0`。
- 树的度：树的度是树中所有节点的度的最大值。

	
### 实例

#### Linux 文件系统

```console
/
├── app
│   ├── cn.fmsoft.hvml.purc
│   ├── cn.fmsoft.hybridos.hibus
│   ├── cn.fmsoft.hybridos.inetd
│   ├── cn.fmsoft.hybridos.settings
│   ├── cn.fmsoft.hybridos.smartcontrolpanel -> /srv/devel/hybridos2/hbd-samples/smart-panel/
│   ├── com.example.foo
│   ├── index.html
│   ├── instrument -> /srv/devel/hybridos2/hbd-samples/instrument/
│   ├── share
│   └── smartbox -> /srv/devel/hybridos2/hbd-samples/smartbox/
├── bin -> usr/bin
├── bin.usr-is-merged
├── boot
├── cdrom
├── dev
├── etc
├── home
├── initrd.img -> boot/initrd.img-5.4.0-73-generic
├── initrd.img.old -> boot/initrd.img-5.4.0-72-generic
├── lib -> usr/lib
├── lib32 -> usr/lib32
├── lib64 -> usr/lib64
├── lib.usr-is-merged
├── libx32 -> usr/libx32
├── lost+found
├── media
├── mnt
├── opt
├── proc
├── root
├── run
├── sbin -> usr/sbin
├── sbin.usr-is-merged
├── snap
├── srv
├── swapfile
├── swapfile2
├── sys
├── tmp
├── usr
├── var
│   ├── backups
│   ├── cache
│   ├── crash
│   ├── games
│   ├── lib
│   ├── local
│   ├── lock -> /run/lock
│   ├── log
│   ├── mail
│   ├── metrics
│   ├── opt
│   ├── run -> /run
│   ├── snap
│   ├── spool
│   ├── tmp
│   └── www
├── vmlinuz -> boot/vmlinuz-5.4.0-73-generic
└── vmlinuz.old -> boot/vmlinuz-5.4.0-72-generic
```

	
#### HTML 文档

```html
<!DOCTYPE html>
<html>
    <head>
        <title>HTML DOM示例</title>
    </head>
    <body>
        <h1>一级标题</h1>
        <p>一个段落 &amp; 一个链接<a href="#">链接</a></p>
    </body>
</html>
```

解析后的 DOM 树

<img style="height:460px;width:auto;" src="assets/noijunior-html-dom-tree.png" />

	
### 树的分类

- 根据树中每个节点可以具有的子节点数量，树形数据结构可以分为三种类型：
  1. 二叉（binary）树：二叉树中的每个节点最多可以有两个子节点。
  1. 三元（ternary）树：三元树中的每个节点最多可以有三个子节点。
  1. N 元（N-ary）或一般（generic）树：一般树中，每个节点的子节点数量可以超过三个。

<img style="height:600px;width:auto;" src="assets/noijunior-tree-types.png" />

	
### 课堂思考

- 根节点的高度为 `1`，一根拥有 `2023` 个节点的三叉树高度至少多少？

	
### 树的基本操作

- 创建（create）：在数据结构中创建树。
- 插入（insert）：在树中插入数据。
- 删除（delete）：在树中移除数据。
- 搜索（search）：在树中搜索特定数据，以判断它是否存在。
- 遍历（traverse）：以特定的规则访问树中的每个节点：
  1. 深度优先遍历（depth-first traversal），亦称深度优先搜索（depth-first search，DFS）
  1. 广度优先遍历（breadth-first traversal），亦称广度优先搜索（breadth-first search，BFS）
  1. 广度优先遍历也称作级序遍历（level order traversal）。


		
## 一般树

`Generic Tree`

	
### 定义

- 一般树是具有以下属性的 N 元树：
  1. 每个节点可能会有很多子节点。
  1. 无法预测每个节点的子节点数量。

<img style="height:400px;width:auto;" src="assets/noijunior-generic-tree.png" />

	
### 实现

1) 泛型类声明

```cpp
#include <vector>       // for vector

template <typename T>
class tree_node {
  public:
    T payload;                          // 节点负载
    std::vector<tree_node*> children;   // 子节点矢量

    // 节点的构造函数
    tree_node(const T& value) {
        payload = value;
    }

    // 节点的析构函数
    ~tree_node() {
        for (size_t i = 0; i < this->children.size(); i++) {
            delete children[i];
            children[i] = nullptr;
        }
    }
};

template <typename T>
class tree_node_using_sgl_list {
public:
    T payload;

    // 在节点中保存第一个子节点指针以及下一个兄弟节点指针
    // 相当于使用单向链表表示同级节点。
    tree_node* firstChild;
    tree_node* nextSibling;
};

template <typename T>
class tree_node_using_dbl_list {
public:
    T payload;

    // 在节点中保存第一个子节点指针以及下一个和上一个兄弟节点指针
    // 相当于使用双向（循环）链表表示同级节点。
    tree_node* firstChild;
    tree_node* nextSibling;
    tree_node* prevSibling;
};
```

	
2) 创建（以矢量维护子节点为例，下同）

```cpp
class tree_node {
    ...

    // 在当前节点的子节点头部压入新节点，返回新节点
    tree_node* push_front(const T& value)
    {
        // Create a new node with the given value
        tree_node* child = new tree_node(value);
        // Push the pointer to the front of children
        children.insert(children.begin(), child);
        return child;
    }

    // 弹出当前节点头部的子节点
    void pop_front()
    {
        if (children.size() > 0) {
            delete children.front();
            children.erase(children.begin());
        }
    }

    // 在当前节点的子节点尾部压入新节点，返回新节点
    tree_node* push_back(const T& value)
    {
        // Create a new node with the given value
        tree_node* child = new tree_node(value);
        // Push the pointer to the front of children
        children.push_back(child);
        return child;
    }

    // 弹出当前节点尾部的子节点
    void pop_back()
    {
        if (children.size() > 0) {
            delete children.back();
            children.pop_back();
        }
    }

    ...
};
```

	
3) 遍历

```cpp
#include <queue>        // for queue

class tree_node {
    ...

    // 深度优先（depth-first）遍历（递归实现）
    template <typename context, typename visitor_func>
    void dfs_r(context* ctxt, visitor_func visitor) const
    {
        // call the visitor for the current node
        // 前序（preorder）遍历
        visitor(ctxt, payload);

        size_t nr_children = children.size();
        for (size_t i = 0; i < nr_children; i++) {
            children[i]->dfs_r(ctxt, visitor);
        }
    }

    // 深度优先（depth-first）遍历（迭代实现）
    template <typename context, typename visitor_func>
    void dfs_i(context* ctxt, visitor_func visitor) const
    {
        std::stack<const tree_node*> stack;
        stack.push(this);

        while (!stack.empty()) {
            const tree_node* node = stack.top();
            stack.pop();

            // call the visitor for current node
            visitor(ctxt, node->payload);

            size_t nr_children = node->children.size();
            for (size_t i = 0; i < nr_children; i++) {
                // XXX 倒序压栈
                stack.push(node->children[nr_children - i - 1]);
            }
        }
    }

    // 广度优先（breadth-first）遍历（迭代实现）
    template <typename context, typename visitor_func>
    void bfs(context* ctxt, visitor_func visitor) const
    {
        std::queue<const tree_node*> queue;
        queue.push(this);

        while (!queue.empty()) {
            const tree_node* node = queue.front();
            queue.pop();

            // call the visitor for current node
            visitor(ctxt, node->payload);

            size_t nr_children = node->children.size();
            for (size_t i = 0; i < nr_children; i++) {
                queue.push(node->children[i]);
            }
        }
    }

    ...
};
```

	
4) 示例

```cpp
#include <iostream>     // for cin and cout
#include <sstream>      // for ostringstream
#include <string>       // for stod()
#include <cassert>      // for assert()

using namespace std;

void test_tree_node()
{
    struct context_print {
        ostream& os;
    };

    struct visitor_print {
        void operator() (context_print* ctxt, const int& value) {
            ctxt->os << value << " ";
        }
    };

    ostringstream oss;
    context_print ctxt = { oss };
    using my_tree_node = tree_node<int>;
    my_tree_node *level_0, *level_1, *level_2;

    level_0 = new my_tree_node(0);

    oss.str("");
    level_0->dfs_r(&ctxt, visitor_print{});
    assert(oss.str() == "0 ");

    oss.str("");
    level_0->dfs_i(&ctxt, visitor_print{});
    assert(oss.str() == "0 ");

    oss.str("");
    level_0->bfs(&ctxt, visitor_print{});
    assert(oss.str() == "0 ");

    level_0->push_front(-1);
    level_0->push_front(-2);
    level_1 = level_0->push_back(0);
    level_0->push_back(1);
    level_0->push_back(2);

    oss.str("");
    level_0->dfs_r(&ctxt, visitor_print{});
    clog << oss.str() << endl;
    assert(oss.str() == "0 -2 -1 0 1 2 ");

    oss.str("");
    level_0->dfs_i(&ctxt, visitor_print{});
    clog << oss.str() << endl;
    assert(oss.str() == "0 -2 -1 0 1 2 ");

    oss.str("");
    level_0->bfs(&ctxt, visitor_print{});
    clog << oss.str() << endl;
    assert(oss.str() == "0 -2 -1 0 1 2 ");

    level_1->push_front(-10);
    level_1->push_front(-20);
    level_2 = level_1->push_back(0);
    level_1->push_back(10);
    level_1->push_back(20);

    oss.str("");
    level_0->dfs_r(&ctxt, visitor_print{});
    clog << oss.str() << endl;
    assert(oss.str() == "0 -2 -1 0 -20 -10 0 10 20 1 2 ");

    oss.str("");
    level_0->dfs_i(&ctxt, visitor_print{});
    clog << oss.str() << endl;
    assert(oss.str() == "0 -2 -1 0 -20 -10 0 10 20 1 2 ");

    oss.str("");
    level_0->bfs(&ctxt, visitor_print{});
    clog << oss.str() << endl;
    assert(oss.str() == "0 -2 -1 0 1 2 -20 -10 0 10 20 ");

    level_2->push_front(-100);
    level_2->push_front(-200);
    level_2->push_front(-300);
    level_2->push_back(0);
    level_2->push_back(100);
    level_2->push_back(200);
    level_2->push_back(300);

    oss.str("");
    level_0->dfs_r(&ctxt, visitor_print{});
    clog << oss.str() << endl;
    assert(oss.str() == "0 -2 -1 0 -20 -10 0 -300 -200 -100 0 100 200 300 10 20 1 2 ");

    oss.str("");
    level_0->dfs_i(&ctxt, visitor_print{});
    clog << oss.str() << endl;
    assert(oss.str() == "0 -2 -1 0 -20 -10 0 -300 -200 -100 0 100 200 300 10 20 1 2 ");

    oss.str("");
    level_0->bfs(&ctxt, visitor_print{});
    clog << oss.str() << endl;
    assert(oss.str() == "0 -2 -1 0 1 2 -20 -10 0 10 20 -300 -200 -100 0 100 200 300 ");

    delete level_0;
}
```

	
### 课堂练习

（十五分钟内完成）

1. 复制一般树的源文件 [generic-tree.cpp](https://gitee.com/vincentwei7/PLZS/blob/main/source/noi-csp-j/lesson-4/generic-tree.cpp)，在 `dfs_r()` 和 `dfs_i()` 遍历方法的基础上实现后序遍历方法 `dfs_postorder_r()` 和 `dfs_postorder_i()`，并添加对应的测试用例。
1. 将 `generic-tree.cpp` 文件添加到 `plzs-homework` 仓库的 `source/noi-csp-j/lesson-4/` 目录（下同），并推送到远程仓库。

		
## 二叉树

`Binary Tree`

	
### 定义

- 二叉树是一种最多有两个子树的树。
- 二叉树中一个节点左侧的子节点被称为“左子节点”，右侧的子节点称为“右子节点”。
- 二叉树中一个节点左侧的子树称为“左子树”，右侧的子树则称为“右子树”。

<img style="height:600px;width:auto;" src="assets/noijunior-binary-tree-representation.webp" />

	
### 课堂思考

- `L` 级二叉树的最大节点数为？
- 高度为 `H` 的二叉树，其最大节点数为？
- 二叉树中的叶节点总数和具有 `2` 个子节点的节点总数的关系？
- 在具有 `N` 个节点的二叉树中，最小的可能高度或最小层数为？
- 具有 `L` 个叶节点的二叉树至少有多少个级别？

	
### 遍历

- 二叉树的深度深度优先遍历有三种形式：
  1. 前序遍历（preorder traversal，当前、左、右）：首先访问节点，然后访问左子树，然后访问右子树。
  1. 中序遍历（inorder traversal，左、当前、右）：首先访问左子树，然后访问节点，然后访问右子树。
  1. 后序遍历（postorder traversal，左、右、当前）：访问左子树，然后访问右子树，然后是节点。

	
### 课堂思考

- 给定一棵二叉树，其前序遍历结果为 `ABDECFG`，中序遍历结果为 `DEBACFG`。请问这棵树的正确后序遍历结果是什么？

	
### 实现

1) 泛型类声明

```cpp
#include <stack>        // for stack
#include <queue>        // for queue

template <typename T>
class bin_tree_node {
  public:
    T payload;                          // 节点负载
    bin_tree_node *left;                // 左子节点
    bin_tree_node *right;               // 右子节点

    // 节点的构造函数
    bin_tree_node(const T& value) {
        payload = value;
        left = nullptr;
        right = nullptr;
    }

    // 节点的析构函数
    ~bin_tree_node() {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};
```
	
2) 创建

```cpp
class bin_tree_node {
    ...

    // 获取左子节点（const 版本）
    const bin_tree_node* left_child() const
    {
        return left;
    }

    // 获取左子节点（非 const 版本）
    bin_tree_node* left_child()
    {
        return left;
    }

    // 设置当前节点的左子节点，返回新节点；已有左子节点时返回 nullptr
    bin_tree_node* left_child(const T& value)
    {
        if (left)
            return nullptr;

        // Create a new node with the given value
        left = new bin_tree_node(value);
        return left;
    }

    // 移除当前节点的左子树
    bool erase_left_subtree()
    {
        if (left == nullptr)
            return false;

        delete left;
        left = nullptr;
        return true;
    }

    // 获取右子节点（const 版本）
    const bin_tree_node* right_child() const
    {
        return right;
    }

    // 获取右子节点（非 const 版本）
    bin_tree_node* right_child()
    {
        return right;
    }

    // 设置当前节点的右子节点，返回新节点；已有右子节点时返回 nullptr
    bin_tree_node* right_child(const T& value)
    {
        if (right)
            return nullptr;

        // Create a new node with the given value
        right = new bin_tree_node(value);
        return right;
    }

    // 移除当前节点的右子树
    bool erase_right_subtree()
    {
        if (right == nullptr)
            return false;

        delete right;
        right = nullptr;
        return true;
    }

    ...
};
```

	
3) 遍历

```cpp
class bin_tree_node {
    ...

    // 深度优先（depth-first）前序遍历
    template <typename context, typename visitor_func>
    void dfs_preorder(context* ctxt, visitor_func visitor) const
    {
        // call the visitor for the current node
        visitor(ctxt, payload);

        if (left)
            left->dfs_preorder(ctxt, visitor);
        if (right)
            right->dfs_preorder(ctxt, visitor);
    }

    // 深度优先（depth-first）中序遍历
    template <typename context, typename visitor_func>
    void dfs_inorder(context* ctxt, visitor_func visitor) const
    {
        if (left)
            left->dfs_inorder(ctxt, visitor);

        // call the visitor for the current node
        visitor(ctxt, payload);

        if (right)
            right->dfs_inorder(ctxt, visitor);
    }

    // 深度优先（depth-first）后序遍历
    template <typename context, typename visitor_func>
    void dfs_postorder(context* ctxt, visitor_func visitor) const
    {
        if (left)
            left->dfs_postorder(ctxt, visitor);
        if (right)
            right->dfs_postorder(ctxt, visitor);

        // call the visitor for the current node
        visitor(ctxt, payload);
    }

    // 深度优先（depth-first）前序遍历（迭代实现）
    template <typename context, typename visitor_func>
    void dfs_preorder_i(context* ctxt, visitor_func visitor) const
    {
        std::stack<const bin_tree_node*> stack;
        stack.push(this);

        while (!stack.empty()) {
            const bin_tree_node* node = stack.top();
            stack.pop();

            // call the visitor for the current node
            visitor(ctxt, node->payload);

            // XXX 先压右子节点，再压左子节点
            if (node->right)
                stack.push(node->right);
            if (node->left)
                stack.push(node->left);
        }
    }

    // 广度优先（breadth-first）级序遍历（迭代实现）
    template <typename context, typename visitor_func>
    void bfs(context* ctxt, visitor_func visitor) const
    {
        std::queue<const bin_tree_node*> queue;
        queue.push(this);

        while (!queue.empty()) {
            const bin_tree_node* node = queue.front();
            queue.pop();

            // call the visitor for the current node
            visitor(ctxt, node->payload);

            if (node->left)
                queue.push(node->left);
            if (node->right)
                queue.push(node->right);
        }
    }

    ...
};
```

	
4) 示例

```cpp
#include <iostream>     // for cin and cout
#include <sstream>      // for ostringstream
#include <string>       // for stod()
#include <cassert>      // for assert()

using namespace std;

void test_binary_tree_node()
{
    struct context_print {
        ostream& os;
    };

    struct visitor_print {
        void operator() (context_print* ctxt, const int& value) {
            ctxt->os << value << " ";
        }
    };

    ostringstream oss;
    context_print ctxt = { oss };
    using my_bin_tree_node = bin_tree_node<int>;
    my_bin_tree_node *level_0, *level_1, *level_2;

    level_0 = new my_bin_tree_node(0);

    oss.str("");
    level_0->dfs_preorder(&ctxt, visitor_print{});
    assert(oss.str() == "0 ");

    oss.str("");
    level_0->bfs(&ctxt, visitor_print{});
    assert(oss.str() == "0 ");

    level_0->left_child(-1);
    level_1 = level_0->right_child(1);
    assert(level_0->left_child()->payload == -1);
    assert(level_0->right_child()->payload == 1);

    oss.str("");
    level_0->dfs_preorder(&ctxt, visitor_print{});
    clog << oss.str() << endl;
    assert(oss.str() == "0 -1 1 ");

    oss.str("");
    level_0->bfs(&ctxt, visitor_print{});
    clog << oss.str() << endl;
    assert(oss.str() == "0 -1 1 ");

    level_1->left_child(-10);
    level_2 = level_1->right_child(10);
    assert(level_1->left_child()->payload == -10);
    assert(level_1->right_child()->payload == 10);

    oss.str("");
    level_0->dfs_inorder(&ctxt, visitor_print{});
    clog << oss.str() << endl;
    assert(oss.str() == "-1 0 -10 1 10 ");

    oss.str("");
    level_0->bfs(&ctxt, visitor_print{});
    clog << oss.str() << endl;
    assert(oss.str() == "0 -1 1 -10 10 ");

    level_2->left_child(-100);
    level_2->right_child(100);
    assert(level_2->left_child()->payload == -100);
    assert(level_2->right_child()->payload == 100);

    oss.str("");
    level_0->dfs_preorder(&ctxt, visitor_print{});
    clog << oss.str() << endl;
    assert(oss.str() == "0 -1 1 -10 10 -100 100 ");

    oss.str("");
    level_0->dfs_preorder_i(&ctxt, visitor_print{});
    clog << oss.str() << endl;
    assert(oss.str() == "0 -1 1 -10 10 -100 100 ");

    oss.str("");
    level_0->dfs_inorder(&ctxt, visitor_print{});
    clog << oss.str() << endl;
    assert(oss.str() == "-1 0 -10 1 -100 10 100 ");

    oss.str("");
    level_0->dfs_postorder(&ctxt, visitor_print{});
    clog << oss.str() << endl;
    assert(oss.str() == "-1 -10 -100 100 10 1 0 ");

    oss.str("");
    level_0->bfs(&ctxt, visitor_print{});
    clog << oss.str() << endl;
    assert(oss.str() == "0 -1 1 -10 10 -100 100 ");

    delete level_0;
}
```

	
### 课堂练习

（十五分钟内完成）

1. 复制二叉树的源文件 [binary-tree.cpp](https://gitee.com/vincentwei7/PLZS/blob/main/source/noi-csp-j/lesson-4/binary-tree.cpp)，参照 `dfs_preorder_i()` 遍历方法实现 `dfs_inorder_i()` 和 `dfs_postorder_i()` 方法，并添加测试用例。
1. 将增强后的 `binary-tree.cpp` 文件添加到 `plzs-homework` 仓库。

		
## 特殊树

`Special Trees`

	
### 完美二叉树

- 定义：完美（perfect）二叉树是一种特殊类型的二叉树，其中所有叶子节点的深度相同，所有非叶子节点都有两个子节点。简单来说，这意味着所有叶子节点都位于树的最大深度，树完全被填满，没有间隙。

<img style="height:500px;width:auto;" src="assets/noijunior-perfect-binary-tree.jpg" />

	
- 性质
  1. 叶节点数：如果完美二叉树的高度为 `$ h $`，则叶节点数将为 `$ 2^h $`，因为最后一级已完全填充。
  1. 叶节点数（`$ N_l $`）与非叶节点数（`$ N_{nl} $`）的关系：`$ N_l = N_{nl} + 1 $`。
  1. 节点总数：高度为 `$ h $` 的树的节点总数为 `$ 2^{h + 1} – 1 $`。树的每个节点都被填充。因此，节点总数可以计算为 `$ 2^0 + 2^1 + \cdots + 2^h = 2^h + 1 $`。
  1. 树的高度：具有 `N` 个节点的完美二叉树的高度为 `$ \log_2{N+1} - 1 $`。

	
- 完美二叉树的数组表达

	
### 完全二叉树

- 定义：完全（complete）二叉树是一种特殊类型的二叉树，除了最大级别之外，其中所有的级别都被完全填充，且所有叶子节点均具有相同深度。

<img style="height:500px;width:auto;" src="assets/noijunior-complete-binary-tree.jpg" />

	
- 性质
  1. 除最后一级外，所有级别都被填满。
  1. 深度为 `$ d $` 的完全二叉树，其节点数量为 `$ 2^d $`。
  1. 在一个有 `$ N $` 个节点的完全二叉树中，树的高度是 `$ log_2{N + 1} $`。

	
- 完全二叉树的数组表达

	
### 霍夫曼树

- 设二叉树具有 `$ n $` 个带权重（weight）的叶结点，从根结点到各叶结点的路径长度与相应叶节点权值的乘积之和称为该二叉树的带权路径长度（Weighted Path Length of Tree，WPL）：`$ WPL = \sum_{i=1}^n w_i l_i $`。
- 对于一组具有确定权值的叶结点，可以构造出不同的二叉树，其中，WPL 最小的二叉树称为霍夫曼/哈夫曼树（Huffman Tree）。
- 霍夫曼树的特点：
  1. 叶结点的权值越小，离根越远。
  1. 叶结点的权值越大，离根越近。
  1. 所有叶结点的度为 `0`，其他结点的度均为 `2`。

	
<img style="height:700px;width:auto;" src="assets/noijunior-wpl-of-binary-tree.svg" />

	
### 霍夫曼算法

- 霍夫曼算法可用于构造霍夫曼树：
  1. 初始化：由给定的 `n` 个权值构造 `n` 棵只有一个根节点的二叉树，得到一个二叉树集合 `F`。
  1. 选取与合并：从二叉树集合 `F` 中选取根节点权值最小的两棵二叉树分别作为左右子树构造一棵新的二叉树，这棵新二叉树的根节点的权值为其左、右子树根结点的权值和。
  1. 删除与加入：从 `F` 中删除被合并的两棵二叉树，并将新建立的二叉树加入到 `F` 中。
  1. 重复 2、3 步，当集合中只剩下一棵二叉树时，这棵二叉树就是霍夫曼树。

	
<img style="height:700px;width:auto;" src="assets/noijunior-creation-of-huffman-tree.svg" />

	
### 霍夫曼编码

- 等长编码和不等长编码
- 在设计不等长编码时，要考虑解码的唯一性，如果一组编码中任一编码都不是其他任何一个编码的前缀，那么称这组编码为前缀编码，这保证了编码的唯一性。
- 霍夫曼树可用于构造最短的前缀编码，即霍夫曼编码（Huffman Code）：
  1. 设需要编码的字符集为：`$ d_1,d_2, \dots, d_n $`，这些字符在字符串中出现的频率为：`$ w_1,w_2,\dots,w_n $`。
  1. 以 `$ d_1,d_2,\dots,d_n $` 作为叶结点，`$ w_1,w_2,\dots,w_n $` 作为叶结点的权值，构造一棵霍夫曼树。
  1. 规定哈夫曼编码树的左分支代表 `0`，右分支代表 `1`，则从根结点到每个叶结点所经过的路径组成的 `0、1` 序列即为该叶结点对应字符的编码。

	
<img style="height:700px;width:auto;" src="assets/noijunior-huffman-code.svg" />

	
- 假设有一组字符 `{a, b, c, d, e, f}`，对应的频率分别为 `5%, 9%, 12%, 13%, 16%, 45%`。请问以下哪个选项是字符 `a, b, c, d, e, f` 分别对应的一组哈夫曼编码？（ ）

   - A. `1111, 1110, 101, 100, 110, 0`
   - В. `1010, 1001, 1000, 011, 010, 00`
   - С. `000, 001, 010, 011, 10, 11`
   - D. `1010, 1011, 110, 111, 00, 01`

		
## 实用技巧

	
### Linux 上的文件系统操作

		
## 作业

	
### 参考链接

