## 我的第一个 Python 程序

1. 走进 Python 的世界
1. Python 表达式和运算符
1. Python 函数
1. 把源代码保存起来以备重复使用
1. 我的第一个程序

		
## 走进改变世界的大门

1. 为什么选择 Linux，为什么用 Ubuntu？
1. 为什么选择 Python 作为入门编程语言？
1. 千万记住：我们用的是 Python 3！

		
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

		
## 运行 Python 解释器

Python 解释器（interpreter）的两种运行模式：
1. 交互模式（interactive mode）：学习、探索、调试
1. 解释器模式执行指定的 Python 程序。

	
看演示视频[1-2：初次运行 Python 解释器](https://www.douyin.com/video/7347338851989474610)

1. `python3` 命令在交互模式下的提示信息以及输入提示字符串。
1. 尝试加减法算式。
1. 尝试使用包含 `×`、`÷` 的四则混合运算算式；了解书本表达方式和程序表达方式的差异。
1. 尝试在算式中使用小括号、中括号和大括号。
1. 尝试输入一个代数式。
1. 通过设定一个名称的值重复调用包含这个名称的代数式。
1. 算术表达式和变量的概念。

	
### Python 解释器报告的常见错误

1. `SyntaxError: SyntaxError: invalid character '÷' (U+00F7)`：语法（Syntax）错误：无效（invalid）字符。
1. `TypeError: unsupported operand type(s) for /: 'list' and 'int'`：类型错误：`/` 不支持的操作数（operand）：`list` 和 `int`。
1. `NameError: name 'XXX' is not defined`：名称错误：名称 XXX 未定义。

	
### 探索过程中的思考

1. 编程语言是一种比自然语言更加精确的语言，有严格的语法要求。
1. 我们要用普通键盘上可用的按键字符来书写代码，书本上常见的数学符号，如 `÷` 等通常不可被编程语言的解释器或编译器（compiler）识别。
1. 键盘上字符的分类（ASCII 字符集）：
   - 字母（letter）：小写字母（`a-z`），大写字母（`A-Z`）
   - 数字（digit）：`0-9`
   - 符号（symbol）：`!$()[];` 等

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

- 一个算术表达式（expression）由数值（number）、变量（variable）和算术运算符构成。
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

1. 变量名必须以字母或者下划线（underline，`_`）打头，然后后接字母、数字或下划线，但不能包含除下划线之外的其他符号。
1. Python 的变量名是区别字母的大小写的，所以 `A` 和 `a` 是两个不同的变量。
1. 使用等于号（equal sign，`=`）给变量赋值；等于号的右侧是一个表达式。

```python
a = 5
h = 3
s = a * h /2
```

	
### 语句

1. 不同的编程语言通常会使用不同的语法来表示一个完整的可执行逻辑功能，这样一个完整的逻辑功能构成了一条语句（statement）。
1. `a = 5` 或者 `s = a * h /2` 这样的语句叫赋值（assignment）语句：表示将一个表达式的值赋值给一个变量。
1. 在 Python 中，语句按行分隔；文本文件中分隔两个文本行的符号被称为新行符（new line，`\n`）。
1. 在 Python 中，一行代码可包含多条简单的语句，使用分号（semicolon，`;`）来分隔，但不推荐使用。
1. 在 Python 以交互模式运行时，一个表达式构成一条语句，且会始终将最后一条表达式的值赋值给一个特殊的变量 `_`。

```python
>>> a = 5; h = 3; a * h /2
7.5
>>> print(_)
7.5
```

		
## Python 函数

- 把 Python 当做计算器（calculator）使用实在是大材小用了！
- 能否支持公式？比如计算正方向的周长公式以及计算三角形的面积公式，数学书本上如此表达：

```
定义函数 C(d) = d × 4
函数 S(d, h) = (d × h) ÷ 2

则 C(4) 的结果是 16
则 S(4, 2) 的结果是 4
```

	
看讲解视频[1-6：函数的由来](#)

	
看演示视频[1-3：最简单的 Python 函数](https://www.douyin.com/video/7347343772990147890)

1. 使用 `def` 语句定义一个函数。
1. 语句的嵌套和缩进规则。
1. 使用 `return` 定义函数的返回值。
1. 使用函数：传入不同的参数来调用函数。
1. 解释形参和实参的概念；解释变量作用域的概念。

	
### 知识点：有关函数的概念或术语

- 函数（function）是重复利用一段代码的最基本方法，几乎所有的编程语言都支持函数；有一类编程语言就叫函数式编程语言。
- Python 使用 `def` 语句定义一个函数，一个函数包括函数名（其命名规则和变量名类似）及其形参（parameter），形参可以没有，也可以有多个，用逗号（comma，`,`）分隔，用小括号包围，然后紧接着是一个冒号（colon，`:`），之后另起一行用其他语句定义函数的功能，也称作函数体（body）。
- 语句中可以嵌套其他语句；在 Python 中，嵌套的语句必须使用相同数量的空格（space）或者制表符（tab）来缩进。
- Python 使用 `return` 语句定义函数的返回值。
- 使用函数的方法称作调用（call）这个函数，要传递函数要求的所有参数的实际值（表达式），称为实参（argument）。
- 表达式定义的更新： 一个表达式（expression）由数值（number）、变量（variable）、算术运算符和函数调用构成。
- 试试写一个求正方向面积的函数和一个求三角形面积的函数。

	

```python
def area_of_square(a):
    return a ** 2

def area_of_triangle(a, h):
    return a * h / 2

area_of_triangle(5, 10) + area_of_square(10)
```

	
### 知识点：关键词

- `def`、`return` 等用于定义语句类型的单词或者缩写称为关键词（keyword）。
- 有一些编程语言不区分关键词的大小写（比如 BASIC），但 Python 区分大小写，且一定要用小写字母。
- 不同的编程语言定义有自己的关键词，但大部分相似。
- 关键词是保留字（reserved word），不能使用关键词定义变量或函数名。

	
### 常用的 Python 内置函数

- `print()`：输出一行文本。
- `input()`：提示用户并返回用户输入的文本。
- `quit()`：退出解释器。
- `int()`：将文本转换为整数。
- `float()`：将文本转换为浮点数。
- `type()`：返回数据的类型名称。

```python
>>> def area_of_square(a):
...     return a ** 2
...
>>> a = int(input("请输入一个整数："))
请输入一个整数：100
>>> s = area_of_square(a)
>>> print('The area is:', s)
The area is: 10000
```

	
### 思考

`int` 和 `float` 两种数值类型是怎么来的？非要区分吗？

		
## 把源代码保存起来以备重复使用

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

		
## 我的第一个程序

- 使用 VIM 编写一个简单的 Python 程序并保存成文件。
- 使用解释器执行程序，或者直接执行该程序。

	
看演示视频[1-5：用 VIM 编写程序并执行程序](https://www.douyin.com/video/7347347606030290185)

	
### 总结：演示视频涉及的概念

- 可执行（executable）程序、（编译后的）二进制（binary）程序以及程序的搜索路径。
- 脚本（script）程序、源代码（source code）和源文件（source file）。
- Python 程序通常使用 `.py` 作为后缀名。
- 文件的访问模式：可读（readable）、可写（writable）、可执行。
- 代码编辑器会根据源文件的后缀名识别源文件使用的编程语言，并根据该编程语言的语法高亮显示关键词、语句、注释等。

	
### 总结：演示视频中用到的命令

- `chmod`：改变（change）文件的许可模式（permission mode）。
- `mkdir`：创建（make）目录（directory）。
- `which`：可显示给定命令对应的程序路径。
- `file`：可分析并显示给定文件的类型。

	
### 总结：编程中常用的技巧或习惯

- Linux 的外壳程序在命令行提供命令补全功能（按 TAB 键）。
- 给目录和文件取名时，遵循类似变量名的习惯，不要使用中文或者特殊字符。
- 将不同的程序分门别类保存到不同的目录中，有助于锻炼归纳和总结思维。

	
### 总结：空白字符和注释

空白字符（whitespace）
   - 空白字符，空格（space）或者制表符（tab），用于分隔语句中的关键词和变量名、函数名，是必须的。
   - 空白字符还可以用来分隔一个表达式中的不同组成部分。在不引起歧义的情况下可不使用空白字符，空白字符的多少也无关紧要。
   - 灵活使用空白字符格式化程序代码，可有效提升代码的阅读体验。

注释
   - 绝大多数的脚本语言都支持使用 `#` 做注释（comment）；注释是程序中用自然语言解释程序功能用的，不是程序的一部分，解释器会忽略注释的内容。
   - 在脚本第一行使用 `#!/usr/bin/python3` 这样的方式，可指定脚本程序的解释器。这样操作系统的外壳程序就知道用哪个解释器来执行脚本程序了。

	
### 第一个 Python 程序

```python
#!/usr/bin/python3

# 计算正方形面积的函数
def area_of_square(a):
    return a ** 2

# 计算三角形面积的函数
def area_of_triangle(a, h):
    return a * h / 2

# 默认变量（_）在解释器模式中不可用
# area_of_triangle(5, 10) + area_of_square(10)
# print(_)

s = area_of_triangle(5, 10) + area_of_square(10)
print(s)
```

		
## 要点回顾

1. 以交互模式运行 Python 解释器。
1. Python 算术表达式和算术运算符。
1. Python 变量及函数。
1. 常用 Python 内置函数。
1. VIM 的基本使用。
1. 使用 Python 解释器执行 Python 程序。
1. 常用 Linux 命令。

		
## 进一步学习资料

1. [知乎文章：115个最常用的Linux命令行大全](https://zhuanlan.zhihu.com/p/420247468)
1. [Python 3.10 官方文档](https://docs.python.org/zh-cn/3.10/index.html)
1. [VIM 官方文档中文版](https://yianwillis.github.io/vimcdoc/doc/help.html)
1. [VIM 实操教程](https://dofy.gitbook.io/learn-vim/zh-CN)

		
## 作业

1. 搭建好基于 Ubuntu Linux 22.04 的学习环境，将本节所讲内容对照演示视频实操一遍。
1. 整理自己所学的几何公式（至少三个），将其写成对应的 Python 函数，程序调用这些函数，提示用户输入（使用 `input()` 内置函数）需要的参数值，求值并打印对应的结果。要求使用 VIM 编辑源文件。

运行效果：

```console
$ ./formulas.py
将计算正方向的面积，请输入一个边长：<11>
area_of_square(11): 121
将计算正方向的周长，请输入一个边长：<11>
perimeter_of_square(11): 44
将计算矩形的周长，请输入一个边长：<10>
将计算矩形的周长，请输入另一个边长：<8>
perimeter_of_rectangle(10, 8): 36
将计算三角形的面积，请输入底边的长：<10>
将计算三角形的面积，请输入底边对应的高：<8>
area_of_triangle(10, 8): 40
```

