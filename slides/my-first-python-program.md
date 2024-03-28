## 我的第一个 Python 程序

1. 运行 Python 解释器
1. Python 算术表达式和运算符
1. Python 变量和语句
1. Python 函数
1. 把源代码保存起来以备重复使用
1. 我的第一个程序
1. 作业

		
## 运行 Python 解释器

- 为什么选择 Python 作为入门编程语言？
- 千万记住：我们用的是 Python 3！
- Python 解释器（interpreter）的两种运行模式：
   1. 交互模式（interactive mode）：学习、探索、调试
   1. 文件模式：解释器模式执行指定的 Python 程序。

	
### 演示视频

[0-3-1：初次运行 Python 解释器](https://www.douyin.com/video/7347338851989474610)

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

		
## Python 的算术运算符和表达式

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

		
## Python 变量和语句

	
### 变量

1. Python 变量名必须以字母或者下划线（underline，`_`）打头，然后后接字母、数字或下划线，但不能包含除下划线之外的其他符号。
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

### 讲解视频

[0-3-2：函数的由来](#)

- 把 Python 当做计算器（calculator）使用实在是大材小用了！
- 能否支持函数？比如计算正方向的周长公式以及计算三角形的面积公式，数学书本上如此表达：

```
定义函数 C(d) = d × 4
函数 S(d, h) = (d × h) ÷ 2

则 C(4) 的结果是 16
则 S(4, 2) 的结果是 4
```

	
### 演示视频

[0-3-3：最简单的 Python 函数](https://www.douyin.com/video/7347343772990147890)

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
- 有一些编程语言不区分关键词的大小写（比如 BASIC），但 Python 区分大小写。
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
>>> a = int(input("Please input an integer: "))
Please input an integer: 100
>>> s = area_of_square(a)
>>> print('The area is:', s)
The area is: 10000
```

	
### 思考

`int` 和 `float` 两种数值类型是怎么来的？非要区分吗？

		
## 我的第一个 Python 程序

### 演示视频

[0-3-4：用 Vim 编写程序并执行程序](https://www.douyin.com/video/7347347606030290185)

1. 使用 Vim 编写一个简单的 Python 程序并保存成文件。
1. 使用解释器执行程序，或者直接执行该程序。

	
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

1. 空白字符（whitespace）
   - 空白字符，空格（space）或者制表符（tab），用于分隔语句中的关键词和变量名、函数名，是必须的。
   - 空白字符还可以用来分隔一个表达式中的不同组成部分。在不引起歧义的情况下可不使用空白字符，空白字符的多少也无关紧要。
   - 灵活使用空白字符格式化程序代码，可有效提升代码的阅读体验。
1. 注释
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
1. Python 变量和语句
1. Python 函数。
1. 常用 Python 内置函数。
1. 使用 Python 解释器执行 Python 程序（文件模式）。
1. 直接运行 Python 程序。

		
## 进一步学习资料

1. [Python 3.10 官方文档](https://docs.python.org/zh-cn/3.10/index.html)

		
## 作业

1) 整理自己所学的几何公式（至少三个），将其写成对应的 Python 函数，程序调用这些函数，提示用户输入（使用 `input()` 内置函数）需要的参数值，求值并打印对应的结果。要求使用 Vim 编辑源文件。运行效果如下所示：

```console
$ ./formulas.py
To calculate the area of a square, please input the length of one side: <11>
area_of_square(11): 121
To calculate the primeter of a square, please input the length of one side: <11>
perimeter_of_square(11): 44
To calculate the primeter of a rectangle, please input the length of a side: <10>
Please input the length of another side: <8>
perimeter_of_rectangle(10, 8): 36
To calculate the area of a triangle, please input the length of a side: <10>
Please input the length of the height on the side: <8>
area_of_triangle(10, 8): 40
```

