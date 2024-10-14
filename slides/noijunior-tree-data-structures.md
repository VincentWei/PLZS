# 树形数据结构

1. 概览
1. 一般树
1. 二叉树
1. 特殊树
1. 树的应用
1. 实用技巧

		
## 概览

- 树是一种非线性（non-linear）数据结构，常用于表达具有从属关系的层次结构（hierarchy）：
  1. 某个国家的各级行政区划可以构成一颗树。
  1. 一个公司的组织结构可以构成一棵树。
  1. 一个家族人员可以构成一棵树。
- 树形数据结构在计算机中随处可见：
  1. 文件系统被组织称树形管理。
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

一个简单的 HTML 文档内容

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

<img style="height:1000px;width:auto;" src="assets/noijunior-html-dom-tree.svg" />

	
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
- 遍历（traverse）：以特定的规则遍历树中的每个节点。

		
## 一般树

		
## 二叉树

		
## 特殊树

		
## 树的典型应用

		
## 实用技巧

		
## 作业

	
### 参考链接

