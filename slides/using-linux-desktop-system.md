## 使用 Linux 桌面系统

1. 初识开发环境：终端和命令行
1. 用 VIM 编辑文本文件

		
## 初识开发环境：终端和命令行

看演示视频[1-1：初识 Ubuntu Linux 桌面环境](https://www.douyin.com/video/7347522409789967653)

1. 通过程序坞（Dock）启动应用。
1. 启动浏览器（FireFox）；访问 PLZS 仓库以及在线课件；设置书签。
1. 使用启动台（luncher），查找设置程序（settings）；启动设置程序，展示各系统设置选项。
1. 使用启动台（luncher），查找终端程序（terminal）；启动终端程序；了解外壳程序（shell）及命令提示字符串。
1. 在终端中使用 `pwd` 打印当前目录并使用 `ls` 展示当前目录中的文件。
1. 将终端、设置程序添加到程序坞中。
1. 启动文件管理器，对比终端中的目录项；了解 Linux 文件系统和 Windows 文件系统的区别。
1. 运行 `sudo apt` 命令更新或升级系统。
1. 运行 `man apt` 查看 `apt` 命令的用法。
1. 在命令行按上下键翻看命令行历史。

	
### 知识点：演示视频涉及的术语

- 终端（terminal）：该术语来自早期的计算机操作控制台，操作员通过一个可显示固定大小字符的显示器和一个键盘操控计算机。在图形显示器上的终端程序，是用软件模拟字符显示器运行的，也叫伪（pseudo）终端。
- 外壳（shell）：操作系统为字符终端上的用户提供的最基本程序，用于输入（input）命令（command）并获得命令的执行结果。在这里，由于命令包括外壳程序的内部命令和外部程序（program）两种形式，故而使用命令这一术语。
- 提示字符串（prompt string，PS）：外壳（或类似程序）展示在行首的提示文本，用于向用户表明可以输入一个新的命令了。在文档或者书籍当中，针对普通用户的命令，提示字符串通常使用 `$` 结尾；针对超级用户的命令，提示字符串通常使用 `#` 结尾。

	
### 知识点：演示视频涉及的术语

- 命令行（command line）：输入给计算机外壳程序一串文本，用于描述计算机需要完成的工作。通常由程序的名字和一组选项组成，如 `python3 -i devel/python/my-first-program.py`。
- 命令行界面（command line interface，CLI）：通过字符终端提供菜单、输入文本等功能的界面。由于硬件能力所限，无法展示图形、图像、视频等内容。
- 图形用户界面（graphics user interface，GUI）：通过图形显示器提供菜单、窗口、对话框等交互功能的界面。可展示丰富的图形、图像和视频等内容。
- 交互（interaction）：指用户（人）和计算机之间的互动。用户提供的数据叫输入（input），计算机提供的数据叫输出（output）。

	
### 知识点：演示视频涉及的命令

- `sudo`：以超级（super）用户（user）身份干活（do）。
- `apt`：Ubuntu 使用的软件包管理工具：
   - `apt install`：安装（install）某个软件包。
   - `apt remove`：移除（remove）某个软件包。
   - `apt update`：检查是否有需要更新（update）的软件包。
   - `apt upgrade`：升级（upgrade）软件包到最新版本。
- `man`：显示指定命令的手册页（manual page）内容，也就是随机文档（document）。
- `pwd`：打印（print）当前（current）目录（directory）。
- `cd`：改变（change）目录（directory）。
- `ls` 或 `ll`：列出（list）当前目录中的文件和子目录。

	
### 知识点：一些常识

1) Linux 或类 UNIX 系统中的文件系统没有盘符的概念。
2) Linux 或类 UNIX 系统中文件的路径（path）使用斜杆（`/`）符号分隔目录，而 Windows 使用盘符和反斜杠（`\`）。
3) 大部分情况下可用 `Ctrl+C`（`^C`） 终止一个正在运行的命令；如果是全屏运行的程序，大部分情况下可以按 `q` 键退出。
4) Linux 命令是区分大小写的，通常使用小写字母。键入时要注意字符的全角（fullwidth）和半角（halfwidth）的区别。
5) 命令行中的参数（parameter）通常用来表示命令要操作的目标对象，比如文件，主机名称等；选项（option）用来表示执行该命令时的动作开关或标志。

	
### 知识点：一些常识（续）

6) 大部分情况下可用 `--help` 选项来显示一个命令的简易使用说明。
7) 命令使用说明文档中的一些约定或习惯写法：
   - 命令的选项和参数通常使用大写单词表示。
   - `[]` 包围起来表示可选的部分，不使用 `[]` 包围的表示一定要出现。
   - `...` 表示某个部分可以多次重复出现。
8) 命令行中的选项通常使用 `-` 或者 `--` 打头，前者只用一个字母区别不同的选项；后者用单词或者用 `-` 连接的短语区别不同的选项。

	

举个例子

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

		
## 用 VIM 编辑文本文件

常用代码编辑器：

- 集成开发环境（IDE）自带的编辑器
- Visual Studio Code
- VIM（Vi IMproved）：程序员专用文本编辑器

**Linux 桌面环境就是最好的 IDE！**

	
看演示视频[1-4：用 VIM 编辑文本文件](https://www.douyin.com/video/7347347606030290185)

1. `vi` 和 `vim` 的区别。
1. 安装 `vim`。
1. 常规模式进入插入模式。
1. 退出插入模式。
1. 保存文件。
1. 再次查看问题，插入新行，保存并退出。

	
### 知识点：VIM 快速入门

- 常规（normal）模式：移动光标/插入符（caret）的位置、删除文本、复制和粘贴文本等。启动时为常规模式；按 `i` 等字符可进入插入模式。
- 插入（insert）模式：用于键入文本，按 `ESC` 键退出插入模式返回常规模式。
- 命令（command）模式：在常规模式下按冒号（colon：`:`）进入命令模式，可用于保存文件、搜索文本、替换文本等操作。
- 可视（visual）模式：在常规模式下按 `v/V/^V` 进入选择字符、行、列的模式，移动光标按字符、行或者列选择字符，然后可针对选定的字符或行执行相应的编辑操作或者命令。

温馨提示：在初学阶段，学会进入插入模式输入自己的程序，然后退出插入模式，再使用命令模式保存文件并退出 VIM 就可以了！

	
### 速查：VIM 常规模式下移动光标的快捷键

- `h`　光标向左移动一个字符
- `j`　光标向下移动一行
- `k`　光标向上移动一行
- `l`　光标向右移动一个字符
- `H`　光标移动到当前屏幕的最上方那一行的第一个字符位置
- `M`　光标移动到当前屏幕的中央那一行的第一个字符位置
- `L`　光标移动到当前屏幕的最下方那一行的第一个字符位置
- `0`　光标移动到当前行的第一个字符位置
- `$`　光标移动到当前行的最后一个字符位置
- `^f`　向下翻页
- `^b`　向上翻页
- `gg` 或 `1G`　光标移动到文件头
- `<n>G`　光标移动到第 n 行
- `G`　光标移动到文件尾

**探索：试试上下左右键以及 `HOME`、`END`、`PgUp`、`PgDn` 键**

	
### 速查：VIM 常规模式下的常用命令

- `i`　切换到插入模式，在光标当前位置开始输入文本。
- `x`　删除当前光标所在位置的字符。
- `a`　进入插入模式，在光标下一个位置开始输入文本。
- `o`　在当前行的下方插入一个新行，并进入插入模式。
- `O`　在当前行的上方插入一个新行，并进入插入模式。
- `dd`　剪切当前行。
- `yy`　复制当前行。
- `p`　粘贴剪贴板内容到光标下方。
- `P`　粘贴剪贴板内容到光标上方。
- `u`　撤销上一次操作。
- `^r`　重做上一次撤销的操作。
- `.`　重复上个命令。
- `:`　切换到命令模式，可在屏幕底部的提示行输入命令。

**探索：试试在命令前加个数字**

	
### 速查：VIM 命令模式下的常用命令

- `:w [FILE]`　`FILE` 将缓冲区中的内容保存到可选的 `FILE` 文件中。
- `:q`　退出 VIM 编辑器。
- `:q!`　强制退出 VIM 编辑器，不保存修改。

	
### 速查：VIM 搜索和替换

- `/WORD`　向下搜索指定的 WORD；在常规模式或者命令模式下输入。
- `?WORD`　向上搜索指定的 WORD；在常规模式或者命令模式下输入。
- `n`　向下重复上个搜索；在常规模式下输入。
- `N`　向上重复上个搜索；在常规模式下输入。
- `:%s/WORD1/WORD2/gc`　命令模式下，全局搜索 WORD1 并使用 WORD2 替换。`gc` 是可选后缀：`g` 表示替换行内所有搜索到的 WORD1，`c` 表示需要用户确认是否替换。

		
## 进一步学习资料

1. [知乎文章：115个最常用的Linux命令行大全](https://zhuanlan.zhihu.com/p/420247468)
1. [VIM 官方文档中文版](https://yianwillis.github.io/vimcdoc/doc/help.html)
1. [VIM 实操教程](https://dofy.gitbook.io/learn-vim/zh-CN)

		
## 作业

1. 搭建好基于 Ubuntu Linux 22.04 的学习环境，将本节所讲内容对照演示视频实操一遍。
