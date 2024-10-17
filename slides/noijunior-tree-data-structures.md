# 树形数据结构

1. 概览
1. 一般树
1. 二叉树
1. 特殊树
1. 实用技巧

		
## 概览

`Overview`

	
- 树是一种非线性（non-linear）数据结构，常用于表达具有从属关系的层次结构（hierarchy）：
  1. 某个国家的各级行政区划可以构成一颗树。
  1. 一个公司的组织结构可以构成一棵树。
  1. 一个家族成员可以构成一棵树。
- 树形数据结构在计算机中随处可见：
  1. 文件系统被组织成树形管理。
  1. 可用于数据压缩，如霍夫曼编码。
  1. 常见的图文文档被解释为树形数据结构进行处理。
  1. 程序被编译器或解释器解析为语法树然后做进一步处理。
  1. 可用于搜索。数据库管理系统中常用特殊的树来保存索引信息，用于快速查询符合特定条件的记录。

	
### 定义

- 树是由节点集合（collection）组成的非线性层次结构，树的每个节点都存储一个值以及对子节点的引用信息。

<img style="height:500px;width:auto;" src="assets/noijunior-representation-of-tree-data-structure.png" />

	
### 术语

-  父（parent）节点：作为节点前任的节点称为该节点的父节点。
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

```cpp []
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

```cpp []
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

- 一般树的深度优先遍历有两种形式：
  1. 前序遍历（preorder traversal，先节点后子树）：首先访问节点，然后访问各个子树。
  1. 后序遍历（postorder traversal，先子树后节点）：首先遍历各个子树，然后访问节点。

```cpp []
#include <queue>        // for std::queue

class tree_node {
    ...

    // 深度优先（depth-first）前序（preorder）遍历（递归实现）
    template <typename context, typename visitor_func>
    void dfs_r(context* ctxt, visitor_func visitor) const
    {
        // call the visitor for the current node
        visitor(ctxt, payload);

        size_t nr_children = children.size();
        for (size_t i = 0; i < nr_children; i++) {
            children[i]->dfs_r(ctxt, visitor);
        }
    }

    // 深度优先（depth-first）前序（preorder）遍历（迭代实现）
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

```cpp []
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

	
### 一般树的数组表达

<img style="height:600px;width:auto;" src="assets/noijunior-generic-tree-by-arrays.svg" />

		
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

- 二叉树的深度优先遍历有三种形式：
  1. 前序遍历（preorder traversal，先节点，次左树，再右树）：首先访问节点，然后遍历左子树，然后遍历右子树。
  1. 中序遍历（inorder traversal，先左树，次节点，再右树）：首先遍历左子树，然后访问节点，然后遍历右子树。
  1. 后序遍历（postorder traversal，先左树，次右树，再节点）：首先遍历左子树，然后遍历右子树，然后访问节点。

	
### 课堂思考

- 给定一棵二叉树，其前序遍历结果为 `ABDECFG`，中序遍历结果为 `DEBACFG`。请问这棵树的正确后序遍历结果是什么？

	
### 实现

1) 泛型类声明

```cpp []
#include <stack>        // for std::stack
#include <queue>        // for std::queue

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

```cpp []
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

```cpp []
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

```cpp []
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

	
### 二叉树的数组表达

<img style="height:600px;width:auto;" src="assets/noijunior-binary-tree-by-array.svg" />

		
## 特殊树

`Special Trees`

	
### 完美二叉树

- 定义：完美（perfect）二叉树是一种特殊类型的二叉树，其中所有叶子节点的深度相同，所有非叶子节点都有两个子节点。简单来说，这意味着所有叶子节点都位于树的最大深度，树完全被填满，没有间隙。

<img style="height:500px;width:auto;" src="assets/noijunior-perfect-binary-tree.jpg" />

	
- 性质
  1. 叶节点数：如果完美二叉树的高度为 `$ h $`，则叶节点数将为 `$ 2^h $`，因为最后一级已完全填充。
  1. 叶节点数（`$ N_l $`）与非叶节点数（`$ N_{nl} $`）的关系：`$ N_l = N_{nl} + 1 $`。
  1. 节点总数：高度为 `$ h $` 的完美二叉树的节点总数为 `$ 2^{h + 1} – 1 $`。树的每个级别都被完全填充，因此，节点总数为 `$ 2^0 + 2^1 + \cdots + 2^h = 2^h + 1 $`。
  1. 树的高度：具有 `N` 个节点的完美二叉树的高度为 `$ \log_2{(N+1)} - 1 $`。

	
- 完美二叉树的数组表达

<img style="height:600px;width:auto;" src="assets/noijunior-perfect-binary-tree-by-array.svg" />

	
### 完全二叉树

- 定义：完全（complete）二叉树是一种特殊类型的二叉树，除了最大级别之外，其中所有的级别都被完全填充，且所有叶子节点均具有相同深度。

<img style="height:500px;width:auto;" src="assets/noijunior-complete-binary-tree.jpg" />

	
- 性质
  1. 除最后一级外，所有级别都被填满。
  1. 深度为 `$ d $` 的完全二叉树，其节点数量为 `$ 2^d $`。
  1. 在一个有 `$ N $` 个节点的完全二叉树中，树的高度是 `$ log_2{(N + 1)} $`。

	
- 完全二叉树的数组表达

<img style="height:600px;width:auto;" src="assets/noijunior-complete-binary-tree-by-array.svg" />

	
### 霍夫曼树

- 设二叉树具有 `$ n $` 个带权重（weight）的叶结点，从根结点到各叶结点的路径长度与相应叶节点权值的乘积之和称为该二叉树的带权路径长度（Weighted Path Length of Tree，WPL）：`$ WPL = \sum_{i=1}^n w_i l_i $`。
- 对于一组具有确定权值的叶结点，可以构造出不同的二叉树，其中，WPL 最小的二叉树称为霍夫曼/哈夫曼树（Huffman Tree）。
- 霍夫曼树的特点：
  1. 叶结点的权值越小，离根越远。
  1. 叶结点的权值越大，离根越近。
  1. 所有叶结点的度为 `0`，其他结点的度均为 `2`。

	
### 霍夫曼算法

- 霍夫曼算法可用于构造霍夫曼树：
  1. 初始化：由给定的 `n` 个权值构造 `n` 棵只有一个根节点的二叉树，得到一个二叉树集合 `F`。
  1. 选取与合并：从二叉树集合 `F` 中选取根节点权值最小的两棵二叉树分别作为左右子树构造一棵新的二叉树，这棵新二叉树的根节点的权值为其左、右子树根结点的权值和。
  1. 删除与加入：从 `F` 中删除被合并的两棵二叉树，并将新建立的二叉树加入到 `F` 中。
  1. 重复 2、3 步，当集合中只剩下一棵二叉树时，这棵二叉树就是霍夫曼树。

	
### 霍夫曼编码

- 等长编码和不等长编码
- 在设计不等长编码时，要考虑解码的唯一性，如果一组编码中任一编码都不是其他任何一个编码的前缀，那么称这组编码为前缀编码（prefix code），这保证了编码在解码时的唯一性。
- 霍夫曼树可用于构造最短的前缀编码，即霍夫曼编码（Huffman Code）：
  1. 设需要编码的字符集为：`$ d_1,d_2, \dots, d_n $`，这些字符在字符串中出现的频率为：`$ w_1,w_2,\dots,w_n $`。
  1. 以 `$ d_1,d_2,\dots,d_n $` 作为叶结点，`$ w_1,w_2,\dots,w_n $` 作为叶结点的权值，构造一棵霍夫曼树。
  1. 规定哈夫曼编码树的左分支代表 `0`，右分支代表 `1`，则从根结点到每个叶结点所经过的路径组成的 `0、1` 序列即为该叶结点对应字符的编码。

	
- 假设有一组字符 `{a, b, c, d, e, f}`，对应的频率分别为 `5%, 9%, 12%, 13%, 16%, 45%`，则字符 `a, b, c, d, e, f` 对应的哈夫曼编码是什么？

		
## 实用技巧

`Utilities`

	
### STL 文件读写流

1) 复习一下基础 STL 文件读写相关类和对象
  - [课件：C++ STL（标准模板库）](https://courses.fmsoft.cn/plzs/cpp-class-template-and-stl.html#/6)

	
2) `open()` 方法和 STL 文件打开模式

```cpp []
void open(const char* filename, ios_base::openmode mode = ios_base::in | ios_base::out);
void open(const string& filename, ios_base::openmode mode = ios_base::in | ios_base::out);
```

| 成员常量 | 含义               | 解释              |
| ---      | ---                | ---               |
| `in`     | 输入（input）      | 打开文件用于读取。|
| `out`    | 输出（output）     | 打开文件用于写入。|
| `binary` | 二进制（binary）   | 文件上的读写操作以二进制数据进行而不是文本。|
| `at`     | 尾部（at end）     | 打开时的读写位置在文件尾部。|
| `app`    | 追加（append）     | 所有的输出操作发生在文件尾部，也就是写入的内容将会被追加到文件尾部。|
| `trunc`  | 截断（truncate）   | 打开时，文件中已有的任何内容将被清除/废弃。 |

	
```cpp []
#include <fstream>      // std::fstream

int main()
{
    std::fstream fs;
    fs.open ("test.txt", std::fstream::in | std::fstream::out | std::fstream::app);
    fs << "This is a line\n";
    fs.close();
    return 0;
}
```

	
3) 输入输出流的缓冲模式

- 缓冲模式
   1. 行缓冲（文本模式）
   1. 块缓冲/完全缓冲（二进制模式）
   1. 无缓冲
- 操作器 `ostream& flush(ostream& os);` 可用于刷新输出缓冲区。
- 操作器 `ostream& endl(ostream& os);` 输出新行符，同时刷新输出缓冲区。
- `ostream& std::fstream::flush();` 方法可用于刷新输出缓冲区。
- `void std::fstream::close();` 方法在关闭流之前，也会刷新输出缓冲区。

	
4) 二进制模式常用读写方法

- `istream& std::istream::read(char* dst, streamsize n);` 方法从流中读取指定长度的字节到目标内存。
- `ostream& std::ostream::write(const char* src, streamsize n);` 方法将目标内存中指定长度的字节写入流。
- [示例程序](https://gitee.com/vincentwei7/PLZS/blob/main/source/noi-csp-j/lesson-4/fstream-binary.cpp)

```cpp
#include <iostream>     // std::cout and std::cerr
#include <fstream>      // std::ofstream and std::ifstream

using namespace std;

int main()
{
    struct student {
        int id;
        int age;
        float height;
        float weight;
        char  name[16];
    } students[] = {
        { 10001, 10, 159.0f, 55.5f, "Tom" },
        { 10002, 11, 160.0f, 58.5f, "Jerry" },
    };

    ofstream ofs;
    ofs.open("students.bin", ofstream::out | ofstream::binary | std::ostream::app);
    for (size_t i = 0; i < sizeof(students)/sizeof(students[0]); i++) {
        ofs.write((const char*)(students + i), sizeof(struct student));
    }
    ofs.close();

    ifstream ifs("students.bin", ofstream::in | ofstream::binary);
    if (ifs) {
        // 调用 seekg() 将读取位置置于文件尾。
        ifs.seekg(0, ifs.end);
        // 然后调用 tellg() 确定文件长度。
        size_t length = ifs.tellg();

        // 确定文件中保存的学生记录数
        size_t nr_students = length/sizeof(struct student);

        // XXX 改变流中的读取位置到文件头
        ifs.seekg(0, ifs.beg);

        // 依次读取学生记录并输出基本信息
        for (size_t i = 0; i < nr_students; i++) {
            struct student student;

            ifs.read((char*)(&student), sizeof(struct student));
            cout << "Got a student: " << student.id << " (" << student.name << ")\n";
        }

        ifs.close();
    }
    else {
        cerr << "Failed to open students.bin file\n";
    }
}
```

	
5) 输入/输出流的重定向

- 重定向（redirect）的概念。
- Shell 中重定向标准输出、标准错误的方法：
  1. `$ PROGRAM [1]>FILE`：将标准输出重定向到文件 `FILE`。
  1. `$ PROGRAM 2>FILE`：将标准错误重定向到文件 `FILE`。
  1. `$ PROGRAM [1]>>FILE`：将标准错误重定向并追加到文件 `FILE`。
- Shell 中重定向标准输入的方法：
  1. `$ PROGRAM <FILE`：将标准输入重定向为文件 `FILE`，程序将从 `FILE` 中读取输入内容。
- C++ STL 输入/输出流的 `std::streambuf` 对象：
  1. 每个文件流（`std::ifstream`、`std::ofstream` 或 `std::ofstream`）关联有一个 `std::filebuf` 对象。
  1. 每个字符串流（`std::stringstream`）关联有一个 `std::stringbuf` 对象。

	
6) 动态改变 C++ 的流对象的流缓冲区对象
  - 使用 STL `std::ios::rdbuf()` 方法，通过设置输入输出流对象的流缓冲区对象，可实现“重定向”。
  - [示例程序](https://gitee.com/vincentwei7/PLZS/blob/main/source/noi-csp-j/lesson-4/iostream-rdbuf.cpp)

```cpp []
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    // 备份 cin 和 cout 的默认 filebuf 对象
    streambuf *cin_backup, *cout_backup;
    cin_backup = cin.rdbuf();
    cout_backup = cout.rdbuf();

    // 打开要参与重定向的文件
    fstream in, out;
    in.open("in.txt", ios::in | ios::out | ios::trunc);
    out.open("out.txt", ios::out | ios::app);
    if (in.fail() || out.fail())
        return -1;

    // 向 `in.txt` 文件写入一个整数
    in << 1000 << endl;

    in.seekg(0, in.beg);

    // 将 `in` 的 filebuf 对象设置给 cin 使用
    cin.rdbuf(in.rdbuf());

    // 将 `out` 的 filebuf 对象设置给 cout 使用
    cout.rdbuf(out.rdbuf());

    // 此后在 cin 和 cout 上的读取和写入，
    // 相当于从 in.txt 中读取，向 out.txt 写入。
    int n;
    cin >> n;
    cout << n << endl;

    // 恢复 cin 和 cout 的 filebuf 对象
    cin.rdbuf(cin_backup);
    cout.rdbuf(cout_backup);

    // 关闭 in 和 out 流
    in.close();
    out.close();

    return 0;
}
```

	
### Linux 上的文件及文件系统操作

- 文件和目录操作
  1. `creat()`：创建文件。
  1. `unlink()`：移除文件。
  1. `mkdir()`：创建目录。
  1. `rmdir()`：移除目录。
  1. `stat()`：获取文件的统计信息，如类型、大小、创建日期、修改日期、所有者、许可模式等。
- 遍历目录项（directory entry）：
  1. `opendir()`：打开一个目录用于读取其目录项。
  1. `readdir()`：读取一条目录项。
  1. `closedir()`：关闭已打开的目录。
- 使用 Linux 手册页获取有关命令、C 标准库接口的文档。如：
  1. `$ man 2 mkdir` 命令。
  1. [在线手册页](https://www.man7.org/linux/man-pages/man2/mkdir.2.html)

	
- [示例程序](https://gitee.com/vincentwei7/PLZS/blob/main/source/noi-csp-j/lesson-4/readdir.cpp)

```cpp []
#include <iostream>
#include <string>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

using namespace std;

struct _Spaces { unsigned n; };

inline _Spaces indent(unsigned level) {
    return { level };
}

inline ostream& operator<<(ostream& os, _Spaces _s) {
    for (unsigned i = 0; i < _s.n; i++) {
        os << ' ';
    }

    return os;
}

void list_dir_entries(unsigned level, const string& path)
{
    DIR*    dir;
    struct  dirent* dir_ent;

    dir = ::opendir(path.c_str());
    if (dir == nullptr) {
        cerr << "Failed to open directory: " << path << endl;
        return;
    }

    cout << indent(level * 2) << path << "/" << endl;

    while ((dir_ent = ::readdir(dir)) != nullptr) {
        // 跳过 . 和 ..
        if (strcmp(dir_ent->d_name, ".") == 0
                || strcmp(dir_ent->d_name, "..") == 0)
            continue;

        // 组装完整文件路径
        string full_path = path + "/" + dir_ent->d_name;

        struct stat my_stat;
        if (::stat(full_path.c_str(), &my_stat) < 0 ){
            cerr << "Failed to stat file: " << full_path << endl;
            continue;
        }

        if (S_ISDIR(my_stat.st_mode)) {
            list_dir_entries(level + 1, full_path);
        }
        else {
            cout << indent(level * 2 + 1) << dir_ent->d_name << endl;
        }

        // XXX struct stat 结构中的 st_size 字段包含有文件的尺寸信息。
    }

    ::closedir(dir);
}

int main(int argc, const char* argv[])
{
    string start;
    if (argc > 1)
        start = argv[1];
    else
        start = ".";

    list_dir_entries(0, start);
    return 0;
}
```

		
## 作业

`Homework`

	
1. 编写程序 `huffman-encode.cpp`，该程序使用霍夫曼编码压缩标准输入中给定的任意文本（仅 ASCII 码），并将压缩后的内容保存为二进制文件 `huffman-code.bin`。运行效果如下：

```console
./huffman-encode
<asdfasdfasdf^D>        # Ctrl+D（^D） 表示输入结束。
Compressed and saved to huffman-code.bin
```

2. 编写程序 `huffman-decode.cpp`，该程序读取 `huffman-code.bin` 中的内容并还原为原始文本。运行效果如下：
```console
./huffman-decode
asdfasdfasdf
```

	
3. 编写程序 `directory-tree.cpp`，该程序递归读取给定目录下的所有子目录及其文件，并构造为一个一般树，之后使用三种方式（深度优先前序、深度优先后序、广度优先）遍历这棵树，分别找出尺寸最大、最小和修改日期最新的文件。运行效果如下：

```console
./directoy-tree .
The largest file: readdir (12,1234 Bytes)
The smallest file: readdir.cpp (1,234 Bytes)
The latest modified file: directory-tree
```

	
### 参考链接

- [本讲示例程序](https://gitee.com/vincentwei7/PLZS/blob/main/source/noi-csp-j/lesson-4/)
- [在线Linux手册页](https://www.man7.org/linux/man-pages)：目前只有英文版。
- [std::fstream 参考](https://cplusplus.com/reference/fstream/)：来自 cplusplus.com，只有英文版，但易懂。
- [std::fstream 参考](https://zh.cppreference.com/w/cpp/io/basic_fstream)：来自 cppreference.com，有中文版，但晦涩。


