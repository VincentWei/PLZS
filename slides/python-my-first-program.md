## 我的第一个 Python 程序

1. 课程内容介绍
1. 走进 Python 的世界
1. Python 表达式和运算符
1. Python 函数
1. 把源代码保存起来以备重复使用
1. 我的第一个程序

		
## 课程内容介绍

欢迎进入编程的世界！

	
1. 课程规划
   - 课程前半阶段围绕一个单机益智游戏进行，后半阶段围绕一个联网的游戏进行，五人一组协作开发。
   - 整个课程会涉及到 Linux、Python、JavaScript、HVML、开源人工智能大模型等开发环境或编程语言。
   - 课程共包含 10 讲课程和 10 场直播。每讲/场两个课时（每课时 40 分钟）；一般每周五 20:30 开讲。
1. 对学生的要求
   - 对编程有强烈的兴趣且学有余力。
   - 做好“听课一小时，实践八小时”的投入准备。
   - 要大胆尝试；计算机不会爆炸，顶多重装系统。
   - 不要依赖家长，要学会利用互联网，多请教老师和同学。

	
1. 中期大作业
   - 每组选择一个简单的益智小游戏，由助教老师指导开发。
   - 游戏有两个版本：在终端中直接运行的版本以及在浏览器中运行的版本。
1. 结业大作业
   - 每组选择一个联网且包含人工智能元素的小型联网游戏。
   - 游戏由服务器端（Python）、网页端（JavaScript）程序组成。
   - 小组成员协作完成。

	
1. 如何听课
   - 手机横屏观看直播或者直播回放；点击可隐藏评论区信息。
   - 观看直播时可放大画面，可参与互动，但不要操作电脑，以免打断思路。
   - 课程中的实操内容，应通过直播回放对照操作自己的电脑；可一边操作电脑一边观看，必要时可暂停播放。

		
## 实操：走进 Python 的世界

1. Ubuntu Linux 简介
1. Python 简介
1. 终端和命令行
1. 把 Python 解释器当计算器用

	
### 总结：实操过程涉及的命令

- `sudo`：以超级（super）用户（user）身份干活（do）。
- `apt`：Ubuntu 使用的软件包管理工具：
   - `apt install` 安装某个软件包。
   - `apt remove`：移除（remove）某个软件包。
   - `apt update`：检查是否有需要更新（update）的软件包。
   - `apt upgrade`：升级（upgrade）软件包到最新版本。
- `python`：Python 解释器（interpreter）；可交互式执行 Python 程序或者执行给定的 Python 程序。
- `man`：显示给定命令的手册页内容（文档）。

	
### 总结：实操过程涉及的术语

- 终端（terminal）：该术语来自早期的计算机操作控制台，操作员通过一个可显示固定大小字符的显示器和一个键盘操控计算机。在图形显示器上的终端程序，是用软件模拟字符显示器运行的，也叫伪（pseudo）终端。
- 外壳（shell）：操作系统为字符终端上的用户提供的最基本程序，用于输入（input）命令（command）并获得命令的执行结果。在这里，由于命令包括外壳程序的内部命令和外部程序（program）两种形式，故而使用命令这一术语。
- 提示字符串（prompt string，PS）：外壳（或类似程序）展示在行首的提示文本，用于向用户表明可以输入一个新的命令了。针对普通用户的命令，提示字符串通常使用 `$` 结尾；针对超级用户的命令，提示字符串通常使用 `#` 结尾。

	
### 总结：实操过程涉及的术语

- 命令行（command line）：输入给计算机外壳程序一串文本，用于描述计算机需要完成的工作。通常由程序的名字和一组选项组成，如 `mkdir -p devel/python`。
- 命令行界面（command line interface，CLI）：通过字符终端提供菜单、输入文本等功能的界面。由于硬件能力所限，无法展示图形、图像、视频等内容。
- 图形用户界面（graphics user interface，GUI）：通过图形显示器提供菜单、窗口、对话框等交互功能的界面。可展示丰富的图形、图像和视频等内容。
- 交互（interacting）：指用户（人）和计算机之间的互动。用户提供的数据叫输入（input），计算机提供的数据叫输出（output）。

	
### 一些有关命令的常识

1. 大部分情况下可用 Ctrl+C 终止一个正在运行的命令。
1. 大部分情况下可用 `--help` 选项来显示一个命令的使用说明。
1. 命令使用说明中的一些习惯用法：
   - Linux 命令是区分大小写的，通常使用小写字母。要注意字符的全角和半角区别。
   - 命令的选项（option）和参数（parameter）通常使用大写单词表示。
   - `[]` 包围起来表示可选的部分，不使用 `[]` 包围的表示一定要出现。
   - `|` 表示二选一或者多选一。
   - `||` 表示同时出现或者只出现其中一个或者不出现任何一个。
   - `...` 表示某个部分可以多次重复出现。
1. 命令行中的选项通常使用 `-` 或者 `--` 打头，前者只用一个字母区别不同的选项；后者用单词或者用 `-` 连接的短语区别不同的选项。

	

```console
$ mkdir --help
Usage: mkdir [OPTION]... DIRECTORY...
Create the DIRECTORY(ies), if they do not already exist.

Mandatory arguments to long options are mandatory for short options too.
  -m, --mode=MODE   set file mode (as in chmod), not a=rwx - umask
  -p, --parents     no error if existing, make parent directories as needed
  -v, --verbose     print a message for each created directory
  -Z                   set SELinux security context of each created directory
                         to the default type
      --context[=CTX]  like -Z, or if CTX is specified then set the SELinux
                         or SMACK security context to CTX
      --help     display this help and exit
      --version  output version information and exit

GNU coreutils online help: <https://www.gnu.org/software/coreutils/>
Full documentation <https://www.gnu.org/software/coreutils/mkdir>
or available locally via: info '(coreutils) mkdir invocation'
```

	
### Python 解释器的常见错误

1. `SyntaxError: invalid syntax`：无效（invalid）语法（语法）。
1. `NameError: name 'XXX' is not defined`：名称 XXX 未定义。

		
## Python 的表达式和运算符

	
### 总结：实操过程涉及的术语

- `mkdir`：创建（make）目录（directory）。
- `cd`：改变（change）目录（directory）。

		
## Python 函数

	
### 总结：实操过程涉及的命令

- `mkdir`：创建（make）目录（directory）。
- `cd`：改变（change）目录（directory）。

		
## 把源代码保存起来以备重复使用

	
### 总结：实操过程涉及的命令

- `mkdir`：创建（make）目录（directory）。
- `cd`：改变（change）目录（directory）。

		
## 我的第一个程序

		
## 作业

1. 搭建好基于 Ubuntu Linux 22.04 的学习环境，将本节所讲内容对照回放实操一遍。
1. 整理自己所学的几何公式，将其写成对应的 Python 函数，程序调用这些函数，求值并打印对应的结果。

```console
$ formulas-with-one-parameter.py 11
area_of_square(11): 121
perimeter_of_square(11): 44

$ formulas-with-two-paramemters.py 10 8
perimeter_of_rectangle(10, 8): 36
area_of_triangle(10, 8): 40
```

