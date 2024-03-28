## Python 流程控制

1. 作业回顾
1. 流程控制的来由
1. 布尔运算快速入门
1. Python 的逻辑表达式和逻辑运算符
1. Python 的流程控制语句
1. 使用 Git 管理源文件
1. 要点回顾
1. 作业

		
## 第一讲作业回顾

看演示视频[2-1：第一讲作业回顾](https://www.douyin.com/video/7347519692115823881)

1. 使用 Vim 编写作业程序。
1. 从课件（浏览器）中复制代码到 Vim 编辑器。
1. 在 Vim 中复制相似代码。
1. 在 Vim 中快速移动光标的功能。
1. 在 Vim 快速删除代码的功能。
1. 保存文件、退出Vim、执行程序、报错、修改，如此循环。
1. 在终端程序中启动多个标签页，切换标签页。
1. 通过多个标签页不退出 Vim 调试程序。

	
### 作业点评

标准答案？

```python
#!/usr/bin/python3

def perimeter_of_square(d):
    return d * 4

def area_of_square(d):
    return d ** 2

d = float(input('将计算正方形的周长和面积，请输入正方形的边长：'))
c = perimeter_of_square(d)
print('perimeter_of_square(', d, '): ', c)

a = area_of_square(d)
print('area_of_square(', d, '): ', c)

def area_of_triangle(d, h):
   return d * h /2

d = float(input('将计算三角形的面积，请输入三角形底边的长：'))
h = float(input('再输入这个底边对应的高：'))

a = area_of_triangle(d, h)
print('area_of_triangle(', d, ',', h, '): ', a)
```

	
三人行必有我师

```python
def Square():
    a = int(input("即将计算正方形周长与面积，请输入正方形边长："));
    print("正方形周长为", a * 4, end=';');
    print("正方形面积为", a ** 2);
```

```python
def area_of_square(r):
    return r*r

r_1 = float(input("将计算正方形面积，请输入一个边长："))
print(f'area_of_square({r_1}): {area_of_square(r_1)}')
```

	
学到了新技巧

```python
#!/usr/bin/python3

"""
学到新技能：
1. 块注释。
1. print() 函数中使用格式化字符串。
1. print() 函数中使用 `end = ','` 指定行尾的字符串，可替代默认的新行符。
"""

def perimeter_of_square(d):
    return d * 4

def area_of_square(d):
    return d * d

def prompt_for_square():
    d = float(input("即将计算正方形周长与面积，请输入正方形边长："))
    c = perimeter_of_square(d)
    s = area_of_square(d)
    print(f"正方形周长为 {c}", end = '; ')
    print(f"正方形面积为 {s}", end = '.\n')

prompt_for_square()
prompt_for_square()
```

		
## 流程控制的来由

1. 现实中存在很多逻辑判断：
   - 判断用户输入的合法性。
   - 判断三条线段是否可以构成三角形。
1. 计算机最擅长执行重复性工作。
   - 人生就是一天一天重复吃饭、干活/学习、睡觉。
   - 计算机的重复方法：重复执行一个程序；程序中重复执行某段代码。
   - 优秀的程序员始终追求最大程度重复利用已有的代码；爱炫耀的程序员喜欢写一些软件包给别人使用：开源的原动力。
1. 所有的编程语言都支持流程控制（flow-control）；流程控制建立在逻辑判断的基础之上。

		
## 布尔逻辑运算快速入门

1. 布尔代数是计算机底层技术的数学基石（二进制）。
1. 英国数学家 George Boole 在其著作《逻辑的数学分析》中首次系统阐述了“布尔代数”，揭示了逻辑运算及其规律。
1. 用于表示命题（proposition）真假的值称为布尔值，只有两种取值：真（true）、假（false）。
1. 我们对布尔值可以执行三种基本的运算，称为“逻辑运算”：与（and）、或（or）、非（not）。

	
### 逻辑运算及其定律

1. 计算机科学文献或者文档中，通常用 `|` 表示“或”，`&` 表示“与”，`!` 表示“非”，`0` 表示假，`1` 表示真。
1. 基本运算（真值表）

	
<img class="r-frame" style="height:auto;width:100%;" src="assets/plzs-true-values-table.svg" />

	
1) 互补律
   - `!!A = A`
   - `A & !A = 0`
   - `A | !A = 1`

	
2) 重言律：别说废话
   - `A & A = A`
   - `A | A = A`
   - `A & 1 = A`
   - `A | 1 = 1`
   - `A & 0 = 0`
   - `A | 0 = A`

	
3) 交换律和结合律：很像算术加法和乘法
   - `A & B = B & A`
   - `A | B = B | A`
   - `(A & B) & C = A & (B & C)`
   - `(A | B) | C = A | (B | C)`

	
4) 吸收律：B 没啥存在感
   - `A & (A | B) = A`
   - `A | (A & B) = A`

	
5) 程序中使用较多的
   - `!(A & B) = !A | !B`
   - `!(A | B) = !A & !B`

		
## Python 的逻辑表达式和逻辑运算符

看演示视频[2-2：Python 的逻辑表达式和逻辑运算符](https://www.douyin.com/video/7347520313871191346)

1. 计算机程序中的命题来自哪里？算术表达式的值、数值比较的结果、逻辑表达式、函数的返回值等等。
1. Python 中用于比较数值的运算符（等于、不等于、大于、小于、大于等于、小于等于）。
1. Python 中的逻辑运算符。
1. 写一个函数判断三个线段长度能否构成一个三角形。
1. 写一个函数判断一个整数是否为偶数。
1. 写一个函数判断一个正整数是否为质数？

		
## Python 的流程控制语句

1. 流程控制语句的分类：
   - 条件（condition）语句或分支（branch）
   - 循环（loop）语句

	
看演示视频[2-3：Python 的流程控制语句](https://www.douyin.com/video/7347520627844091174)

1. `if` 语句的用途和写法；`else` 分句。
1. 复合语句（compound statement）和分句（clause）。
1. `elif` 分句的来由。
1. `match` 语句的用途和写法；`case` 分句。
1. `while` 语句的用途和写法。
1. `for` 语句和 `range()` 函数。
1. `break` 语句和 `continue` 语句。
1. `pass` 语句的用途。

	
### 实例：`if` 语句

```python
def is_even_or_odd_0(n):
    if n % 2 == 0:
        return True
    else:
        if n % 2 == 1:
            return False

def is_even_or_odd_1(n):
    if n % 2 == 0:
        return True
    elif n % 2 == 1:
        return False

def is_even_or_odd_2(n):
    if n % 2 == 0:
        return True
    else:
        return False

def is_even_or_odd_3(n):
    if n % 2 == 0:
        return True

    return False

def is_even_or_odd_4(n):
    if n % 2:
        return False

    return True

def is_even_or_odd_best(n):
    n = int(n)
    return n % 2 == 0

def can_make_a_triangle(d1, d2, d3):
    if (d1 <= 0 or d2 <= 0 or d3 <= 0):
        return False
    elif ((d1 + d2) > d3) and ((d1 + d3) > d2) and ((d2 + d3) > d1):
        return True
    else:
        return False
```

	
### 实例：`match` 语句

```python
def day_of_week(weekday):
    match weekday:
        case 0:
            return "Sunday"
        case 1:
            return "Monday"
        case 2:
            return "Tuesday"
        case 3:
            return "Wednesday"
        case 4:
            return "Thursday"
        case 5:
            return "Friday"
        case 6:
            return "Saturday"
        case _:
            return "<Wrong Weekday Value>"

    return "<NeverGetHere>"

def is_prime(n):
    n = int(n)

    if n < 2:
        return "<BadValue>"
    elif n > 10:
        return "<DontKnow>"

    match n:
        case 3 | 5 | 7:
            return True

    return False
```

	
### 实例：`while` 或 `for` 循环

```python
def list_even_numbers_less_than_0(n):
    n = int(n)
    a = 0
    while a < n:
        if a % 2 == 0:
            print(a)
        a = a + 1

def list_even_numbers_less_than_1(n):
    n = int(n)
    a = 0
    flag = True
    while True:
        if a >= n:
            break

        if flag:
            print(a)

        a = a + 1
        flag = not flag

def list_even_numbers_less_than_2(n):
    for a in range(0, n, 2):
        print(a)

def list_even_numbers_less_than_3(n):
    n = int(n // 2)
    for a in range(n):
        print(a * 2)
```

	
### 浮点数比较陷阱！

- 在交互模式下试试逻辑表达式：`0.1 + 0.2 == 0.3`

```python
# 直接对比浮点数会得到不正确的结果
def can_make_a_triangle_bad(d1, d2, d3):
    if (d1 <= 0 or d2 <= 0 or d3 <= 0):
        return False
    elif ((d1 + d2) > d3) and ((d1 + d3) > d2) and ((d2 + d3) > d1):
        return True
    else:
        return False

# 折中方案
def can_make_a_triangle_workaround(d1, d2, d3):
    if (d1 > 10000 or d2 > 10000 or d3 > 10000):
        return "<BadValue>"

    if (d1 <= 0 or d2 <= 0 or d3 <= 0):
        return False

    d1 = int(d1 * 10000)
    d2 = int(d2 * 10000)
    d2 = int(d3 * 10000)

    if ((d1 + d2) > d3) and ((d1 + d3) > d2) and ((d2 + d3) > d1):
        return True
    else:
        return False
```

		
## 使用 Git 管理源文件

- Git 和 GitHub 的故事

	
看演示视频[2-4：在 Gitee 上创建代码仓库](https://www.douyin.com/video/7347520971370237235)

1. 访问 GitHub 网站并登录。
1. 生成 SSH 密钥対，并将公钥登记到 GitHub。
1. 新建公开代码仓库。
1. 运行 `man git` 查看 Git 的手册页。
1. 按照页面提示复制相关命令并在本地执行。
1. 复制第一个 Python 程序到仓库中，并将其添加、提交、推送到 GitHub 仓库。
1. 修改文件，提交修改并推送到 GitHub。
1. 刷新 GitHub 页面查看源文件。
1. 分享仓库或者源文件链接给老师或者同学。
1. 看看 Gitee 页面：基本功能和 GitHub 雷同。

	
### 视频中用到的主要命令

```console
# 生成 SSH 密钥对
$ ssh-keygen

# 设置 git 用户信息
$ git config --global user.name "your-username"
$ git config --global user.email "your-email-address"

# 复制文件
cp ~/my-first-python-program.py .

# 复制文件
mv ~/my-first-python-program.py .
```

	
克隆 Github 上的代码仓库到本地

```console
$ git clone git@github.com:<YourAccountName>/plzs-homework.git
$ cd plzs-homework
$ vim README.md
$ git add README.md
$ git commit -m "first commit"
$ git branch -M main
$ git push -u origin main
```

或者，在本地创建 Git 仓库并推送到 GitHub：

```console
$ mkdir plzs-homework
$ cd plzs-homework
$ vim README.md
$ git init
$ git add README.md
$ git commit -m "first commit"
$ git branch -M main
$ git remote add origin git@github.com:VincentWei/plzs-homework.git
$ git push -u origin main
```

		
## 要点回顾

1. 在 Linux 桌面不同应用之间复制、粘贴文本。
1. Python 中的块注释方法。
1. 在 `print()` 函数中使用格式化字符串。
1. 布尔运算的基本概念。
1. Python 的逻辑表达式和逻辑运算符。
1. Python 的流程控制语句。
1. 浮点数对比陷阱。
1. 在 GitHub 或者 Gitee 上创建公开仓库并提交代码。

		
## 本节涉及的 Linux 系统命令

1. `ls` 或 `ll`：列出（list）当前目录中的文件和子目录；`ll` 会输出更多信息并带颜色。
1. `mkdir`：创建（`m`a`k`e）目录（`dir`ectory）。
1. `cd`：改变（`c`hange）目录（`d`irectory）。
1. `man`：显示指定命令的手册页（`man`ual page）内容，也就是随机文档（document）。
1. `cp`：复制（`c`o`p`y）文件。
1. `mv`：移动（`m`o`v`e）文件；亦可用于重命名文件。

		
## 进一步学习资料

1. [Python 3.10 官方文档](https://docs.python.org/zh-cn/3.10/index.html)
1. [知乎文章：最常用的19个Git命令](https://zhuanlan.zhihu.com/p/40461007])

		
## 作业

1) 在 GitHub 或者 Gitee 上创建一个自己的代码仓库（名为 `plzs-homework`），用以维护自己的程序。今后的作业提交分享仓库或者源文件的链接给老师即可。
2) 输出小于用户指定的正整数的斐波那契（Fibonacci）数列。运行效果如下：

```console
$ ./fibonacci.py
Please input a positive integer:<-5>
Please input a positive integer:<11>
The Fibonacci numbers less than 11:
0, 1, 1, 2, 3, 5, 8.
```

	
3) 增强第一讲作业，循环提示用户选择一个公式，并判断用户输入的合法性。运行效果如下：

```console
$ ./formulas-improved.py
To calculate the area/volume, please choose a geometrical shape:
1. Triange
2. Square
3. Cone
4. Circle
0. Exit
Your choice:<1>
Please input the base of your triangle: <4>
Please input the height of your triangle: <2>
The area of your triangle is: 4.0
To calculate the area/volume, please choose a geometrical shape:
1. Triange
2. Square
3. Cone
4. Circle
0. Exit
Your choice:<2>
Please input the side of your square: <4>
The area of your square is: 16.0
```

	
4) （初中及以上）循环提示用户输入一个正整数，并判断该正整数是否为一个质数。运行效果如下：

```console
$ ./check-prime.py
Please input a positive integer:<11>
11 is a prime.
Please input a positive integer:<12>
12 equls to 2 * 6, so it's not a prime.
```

