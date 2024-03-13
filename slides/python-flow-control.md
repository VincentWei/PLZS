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

在函数中调用 `input()` 和 `print()` 完成交互：

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

		
## 流程控制的来由

1. 现实中存在很多逻辑判断，比如：
   - 判断用户输入的合法性
   - 判断三条线段是否可以构成三角形
1. 计算机最擅长执行重复性工作。
1. 流程控制语句的分类：
   - 分支语句
   - 循环语句

		
## Python 的逻辑表达式和逻辑运算符

看演示视频[2-2：Python 的逻辑表达式和逻辑运算符](#)

1. 现实世界中的命题和数学中的逻辑表达式
1. 真假两个值的世界：逻辑代数/布尔代数

		
## Python 的流程控制语句

看演示视频[2-3：Python 的流程控制语句](#)

	
### `pass` 语句

	
### `if` 语句

	
### `match` 语句

	
### `while` 语句

	
### `for` 语句和 `range()` 函数

	
### `break` 语句和 `continue` 语句

	
### 在循环中使用 `else` 分句

		
## 使用 Git 管理源文件

- Git 和 GitHub 的故事

看演示视频[2-4：在 GitHub 上创建代码仓库](#)

		
## 进一步学习资料

1. [Python 3.10 官方文档](https://docs.python.org/zh-cn/3.10/index.html)

		
## 作业

1) 在 GitHub 或者 Gitee 上创建一个代码仓库（名为 `PLZS`），用以维护自己的程序。
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

