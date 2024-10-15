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
-  节点级别（level）：从根节点到该节点的路径上的边数。根节点的级别为 `0`。

<img style="height:500px;width:auto;" src="assets/noijunior-tree-data-structure.png" />

	
-  节点的祖先（ancestor）：根到该节点的路径上的任何前任节点都称为该节点的祖先。
-  兄弟（sibling）节点：同一父节点的子节点称为兄弟节点。
-  内部（internal）节点：至少有一个子节点的节点称为内部节点。
-  外部（external）节点：即叶子节点。
-  节点的邻居（neighbour）：一个节点的父节点或子节点称为该节点的邻居。
-  子树（subtree）：树中任意一个节点及其后代（descendant）构成了子树。

<img style="height:500px;width:auto;" src="assets/noijunior-tree-data-structure.png" />

	
- 边（edge）数：边可以定义为两个节点之间的连接。如果一棵树有 `N` 个节点，那么它将有 `N-1` 条边。从每个节点到树的任何其他节点只有一条路径。
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

	
### 树的基本操作

- 创建（create）：在数据结构中创建树。
- 插入（insert）：在树中插入数据。
- 删除（delete）：在树中移除数据。
- 搜索（search）：在树中搜索特定数据，以判断它是否存在。
- 遍历（traverse）：以特定的规则访问树中的每个节点：
  1. 深度优先遍历（depth-first search，DFS）
  1. 广度优先遍历（breadth-first search，BFS）

		
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
#include <vector>

template <typename T>
class tree_node {
public:
    T payload;

    // 使用节点指针构成的 `vector` 表示子节点。
    std::vector<tree_node*> children;

    tree_node(const T& data) {
        this->paylod = data;
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

	
2) 创建

	
3) 遍历

	
4) 示例

	
### 课堂练习

（十分钟内完成）

1. 复制一般树的源文件 `generic-tree.cpp`，修改其中的 `dfs()` 和 `bfs()` 两个遍历方法，将其调整为迭代实现。
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

- 深度优先（DFS）
  1. 前序遍历（preorder traversal，当前、左、右）：首先访问节点，然后访问左子树，然后访问右子树。
  1. 中序遍历（inorder traversal，左、当前、右）：首先访问左子树，然后访问节点，然后访问右子树。
  1. 后序遍历（postorder traversal，左、右、当前）：访问左子树，然后访问右子树，然后是节点。
- 广度优先（BFS）：
  1. 级序遍历（level order traversal）：

	
### 实现

1) 泛型类声明

```cpp
// Class for Binary Tree Node
template <typename T>
class bin_tree_node_node {
    T payload;
    bin_tree_node_node *left;
    bin_tree_node_node *right;

    bin_tree_node_node(const T& data) {
        this->payload = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};
```

	
2) 



		
## 特殊树

`Special Trees`

		
## 树的典型应用

`Typical Applications`

	
### 文件系统

	
### 霍夫曼编码

		
## 实用技巧

		
## 作业

	
### 参考链接

