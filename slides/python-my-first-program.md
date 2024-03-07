## 我的第一个 Python 程序

1. 课程内容介绍
1. 走进 Python 的世界
1. Python 表达式和运算符
1. Python 函数
1. 把源代码保存起来以备重复使用
1. 我的第一个程序

		
## 课程内容介绍

欢迎进入编程的世界！

	
课程规划

- 课程前半阶段围绕一个单机益智游戏进行，后半阶段围绕一个联网的游戏进行，五人一组协作开发。
- 整个课程会涉及到 Linux、Python、JavaScript、HVML、开源人工智能大模型等开发环境或编程语言。
- 课程共包含 10 讲课程和 10 场直播。每讲/场两个课时（每课时 40 分钟）；一般每周五 20:30 开讲。

对学生的要求
- 对编程有强烈的兴趣且学有余力。
- 做好“听课一小时，实践八小时”的投入准备。
- 要大胆探索尝试；计算机不会爆炸，顶多重装系统。
- 不要依赖家长，要学会利用互联网，多请教老师和同学。

	
中期大作业
- 每组选择一个简单的益智小游戏，由助教老师指导开发。
- 游戏有两个版本：在终端中直接运行的版本以及在浏览器中运行的版本。

结业大作业
- 每组选择一个联网且包含人工智能元素的小型联网游戏。
- 游戏由服务器端（Python）、网页端（JavaScript）程序组成。
- 小组成员协作完成。

	
如何听课
- 手机横屏观看直播或者直播回放；点击可隐藏评论区信息。
- 观看直播时可放大画面，可参与互动，但不要操作电脑，以免打断思路。
- 课程中的实操内容，应通过直播回放对照操作自己的电脑；可一边操作电脑一边观看，必要时可暂停播放。

		
## 走进 Python 的世界

1. 为什么选择 Linux，为什么用 Ubuntu？
1. 为什么选择 Python 作为入门编程语言？
1. 初识开发环境：终端和命令行
1. 把 Python 解释器当计算器用

（实操）

	
### 总结：实操过程涉及的命令

- `sudo`：以超级（super）用户（user）身份干活（do）。
- `apt`：Ubuntu 使用的软件包管理工具：
   - `apt install`：安装（install）某个软件包。
   - `apt remove`：移除（remove）某个软件包。
   - `apt update`：检查是否有需要更新（update）的软件包。
   - `apt upgrade`：升级（upgrade）软件包到最新版本。
- `python`：Python 解释器（interpreter）；可交互式执行 Python 程序或者执行给定的 Python 程序。
- `man`：显示指定命令的手册页（manual page）内容（文档）。

	
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

	
### Python 解释器报告的常见错误

1. `SyntaxError: SyntaxError: invalid character '÷' (U+00F7)`：语法（Syntax）错误：无效（invalid）字符。
1. `NameError: name 'XXX' is not defined`：名称错误：名称 XXX 未定义。

	
### 探索过程中的思考

1. 编程语言是一种比自然语言更加精确的语言，有严格的语法要求。
1. 我们要用普通键盘上可用的按键字符来表示代码，书本上常见的数学符号，如 `÷` 等通常不可被编程语言的解释器或编译器（compiler）识别。
1. 键盘上字符的分类（ASCII 字符集）：
   - 字母（letter）：小写字母（a-z），大写字母（A-Z）
   - 数字（digit）：0-9
   - 符号（symbol）：!、$、()、[]、; 等。

__一定注意区分字符的半角和全角__

		
## Python 的算术运算符、表达式、变量和语句

### 算术运算符

1. 几乎所有编程语言都会支持的算术（arithmetic）运算符（operator）：
  - `+`：加
  - `-`：减
  - `*`：乘
  - `/`：除
  - `%`：取模（余数）
1. Python 支持的算术运算符：
  - `//`：整除，舍去小数部分。
  - `**`：幂乘。

	
### 算术表达式

- 一个表达式（expression）由数值（number）、变量（variable）和算术运算符构成。
- 单个数值也是一个有效的（valid）表达式。
- 要注意表达式中运算符的优先级；大部分规则和数学书本上的定义相同。
- 使用小括号（parentheses，`()` ）可定义运算的分组及优先级，注意左右括号要成对匹配；小括号可嵌套，但嵌套时不使用 `[]`、`{}` 等数学书本上的写法。

```python
5

((50 - 5*6) / 4 + 8) ** 2

a = 5
h = 3
a * h / 2
```

	
### 变量

1. 变量名必须以字母或者下划线（`_`）打头，然后可使用字母或数字，但不能包含符号。
1. Python 的变量名是区别大小写的。
1. 使用等于号（equal sign，`=`）给变量赋值；等于号的右侧是一个表达式。

```python
a = 5
h = 3
s = a * h /2
```

	
### 语句

1. 不同的编程语言通常会使用不同的语法来表示一个完整的可执行逻辑功能，这样一个完整的逻辑功能构成了一条语句（statement）。
1. 在 Python 中，语句按行分隔；文本文件中分隔两个文本行的符号被称为新行符（new line，`\n`）。
1. 在 Python 中，一行代码可包含多条简单的语句，使用分号（semicolon，`;`）来分隔；但不推荐使用。

```python
a = 5; h = 3; s = a * h /2
```

		
## Python 函数

- 把 Python 当做计算器实在是大材小用
- 能否支持公式？比如计算正方向的周长公式，数学书本上如此表达：

```
f(x) = x * 4
```

（当然可以，实操）

	
### 总结：有关函数的概念或术语

- 函数（function）是重复利用一段代码的最基本方法，几乎所有的编程语言都支持。
- Python 使用 `def` 语句定义一个函数，一个函数包括函数名（其命名规则和变量名类似）及其形参（parameter），形参可以有多个。
- 语句中可以嵌套其他语句；在 Python 中，嵌套的语句必须使用相同数量的空格（space）或者制表符（tab）来缩进。
- Python 使用 `return` 语句定义函数的返回值。
- 使用函数的方法称作调用（call）这个函数，要传递函数要求的所有参数的实际值（表达式），称为实参（argument）。
- 表达式定义的更新： 一个表达式（expression）由数值（number）、变量（variable）、算术运算符和函数调用构成。
- 试试写一个求三角形面积的函数。

	

```python
def area_of_square(a):
    return a ** 2

def area_of_triangle(a, h):
    return a * h / 2

area_of_triangle(5, 10) + area_of_square(10)
```

	
### 常用的 Python 内置函数

- `print()`：输出一行文本。
- `input()`：提示用户并返回用户输入的文本。
- `quit()`：退出解释器。
- `int()`：将文本转换为整数。

```
>>> def area_of_square(a):
...     return a ** 2
...
>>> a = int(input("请输入一个整数："))
请输入一个整数：100
>>> s = area_of_square(a)
>>> print('The area is:', s)
The area is: 10000
```

		
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

