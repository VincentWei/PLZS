## 第二讲：流程控制

1. 作业回顾
1. 流程控制的来由
1. Python 的逻辑表达式和逻辑运算符
1. Python 的流程控制语句
1. 使用 Git 管理源文件

		
## 第一讲作业回顾

看演示视频[2-1：第一讲作业回顾](#)

1. 使用 VIM 编写作业程序。
1. 展示 VIM 的复制和粘贴功能。
1. 展示在 VIM 中快速移动光标的功能。
1. 展示在 VIM 快速删除代码的功能。
1. 展示保存文件的功能。
1. 在终端程序中启动多个标签页，切换标签页。
1. 通过多个标签页调试程序。

	
### 作业点评

在函数中调用 `input()` 和 `print()` 完成交互好不好？

```python
def Square():
    a = int(input("即将计算正方形周长与面积，请输入正方形边长："));
    print("正方形周长为", a * 4);
    print("正方形面积为", a ** 2);

def Triangle():
    a = int(input("即将计算三角形面积，请输入三角形底的长度:"));
    b = int(input("即将计算三角形面积，请输入对应的高的长度:"));
    print("三角形面积为", float(a * b / 2));

Square();
Triangle();
```

	
三人行必有我师

```python
def area_of_square(r):
    return r*r

def perimeter_of_square(r):
    return 4*r

def perimeter_of_rectangle(l,h):
    return 2*(l+h)

def area_of_triangle(s,h):
    return (s*h)/2

"""
Helper function: Detecting negative value
"""
def detect (a):
    if a <= 0:
        a = float(input("输入数字不合规（小于或等于0），请重新输入："))
        return detect(a)
    else:
        return a

r_1 = float(input("将计算正方形面积，请输入一个边长："))
r_1 = detect(r_1)
print(f'area_of_square({r_1}): {area_of_square(r_1)}')

r_2 = float(input("将计算正方形周长，请输入一个边长："))
r_2 = detect(r_2)
print(f'perimeter_of_square({r_2}): {perimeter_of_square(r_2)}')

l_1 = float(input("将计算矩形周长，请输入一个边长："))
l_1 = detect(l_1)
h = float(input("将计算矩形周长，请输入另一个边长："))
h = detect(h)
print(f'perimeter_of_rectangle({l_1},{h}): {perimeter_of_rectangle(l_1,h)}')


l_2 = float(input("将计算三角形面积，请输入底边长："))
l_2 = detect(l_2)
h_2 = float(input("将计算三角形面积，请输入高："))
h_2 = detect(h_2)
print(f'area_of_triangle({l_2},{h_2}): {area_of_triangle(l_2,h_2)}')
```

		
## 流程控制的来由

1. 现实中存在很多逻辑判断，比如：
   - 判断用户输入的合法性
   - 判断三条线段是否可以构成三角形
1. 计算机最擅长执行重复性工作。
   - 人生就是一天一天重复吃饭、干活、睡觉。
   - 代码若不能最大化重复利用，便是对算力的浪费。
1. 流程控制语句的分类：
   - 分支语句
   - 循环语句

		
## Python 的逻辑表达式和逻辑运算符

看演示视频[2-2：Python 的逻辑表达式和逻辑运算符](#)

1. 现实世界中的命题和数学中的数值比较代数式
1. 真假两个值的世界：逻辑代数/布尔代数

		
## Python 的流程控制语句

看演示视频[2-3：Python 的流程控制语句](#)

1. `pass` 语句的用途。
1. `if` 语句的用途和写法；`else` 分句。
1. 复合语句（compound statement）和分句（clause）。
1. `elif` 分句的来由。
1. `match` 语句的用途和写法；`case` 分句。
1. `while` 语句的用途和写法。
1. `for` 语句的用途和写法。
1. `break` 语句和 `continue` 语句。
1. 在循环中使用 `else` 分句。

	
### 总结：`pass` 语句

	
### 总结：`if` 语句

	
### 总结：`match` 语句

	
### 总结：`while` 语句

	
### 总结：`for` 语句和 `range()` 函数

	
### 总结：`break` 语句和 `continue` 语句

	
### 总结：在循环中使用 `else` 分句

		
## 使用 Git 管理源文件

- Git 和 GitHub 的故事

	
看演示视频[2-4：在 GitHub 上创建代码仓库](#)

1. 访问 GitHub 网站并登录。
1. 生成 SSH 密钥，并将公钥登记到 GitHub。
1. 新建代码仓库；设置公开或者私密。
1. 按照页面执行 git 命令。
1. 复制第一个 Python 程序到仓库中，并将其添加、提交、推送到 GitHub 仓库。
1. 修改文件，提交修改并推送到 GitHub。
1. 刷新 GitHub 页面查看源文件。
1. 分享仓库或者源文件链接给老师或者同学。
1. 提示 Gitee 和 GitHub 的基础功能基本雷同。

	
### Git 的工作原理

	
### 视频中用到的主要命令：

	
### 非对称加密算法

		
## 进一步学习资料

1. [Python 3.10 官方文档](https://docs.python.org/zh-cn/3.10/index.html)
1. [git 常用命令]()

		
## 作业

1) 在 GitHub 或者 Gitee 上创建一个代码仓库（名为 `PLZS`），用以维护自己的程序。今后的作业提交分享仓库或者源文件链接给老师即可。
2) 输出小于用户指定的正整数的 Fibonacci 数列。运行效果如下：
```console
$ ./fibonacci.py
Please input a positive integer:<-5>
Please input a positive integer:<11>
The Fibonacci series less than 11:
0,1,1,2,3,5,8
```

	
3) 增强第一讲作业，循环提示用户选择一个公式，并判断用户输入的合法性。运行效果如下：

```console
$ ./formulas.py
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

	
4) 循环提示用户输入一个正整数，并判断该正整数是否为一个质数。运行效果如下：

```console
$ ./check-prime.py
Please input a positive integer:<11>
11 is a prime.
Please input a positive integer:<12>
12 equls to 2 * 6, so it's not a prime.
```

