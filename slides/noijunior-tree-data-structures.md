# 树形数据结构

1. 概览
1. 一般树
1. 二叉树
1. 特殊树
1. 树的操作
1. 实用技巧

		
## 概览

- 定义：树是一种非线性（non-linear）数据结构和由节点集合组成的层次结构（hierarchy），树的每个节点都存储一个值和对其他节点（“子节点”）的引用列表。
- 树形数据结构在计算机中随处可见：
  1. 文件系统被组织称树形管理。
  1. 文档被解释为树形数据结构进行处理。
  1. 

	
### Linux 文件系统

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

	
### HTML 文档

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

<img style="height:300px;width:auto;" src="assets/noijunior-html-dom-tree.svg" />

		
## 一般树

		
## 二叉树

		
## 特殊树

		
## 树的操作

		
## 实用技巧

		
## 作业

	
### 参考链接

