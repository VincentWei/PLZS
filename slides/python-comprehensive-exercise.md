# Python 综合练习

1. 作业回顾
1. 综合练习可选项目
1. 终端编程
   - Escape 序列
   - `curses` 模块
1. 数据持久化
   - 二进制数据读写
   - `pickle` 模块
   - `sqlite3` 模块
1. 要点回顾

		
## 作业回顾

### 在递归调用中缓存结果

```python
#!/usr/bin/python3

def nth_fibonacci(n):
   if n <= 1:
       return n
   else:
       return nth_fibonacci(n - 1) + nth_fibonacci(n - 2)

mx = 0
while mx <= 0:
    try:
        mx = int(input('Please input a positive integer: '))
    except ValueError:
        mx = 0

print(f"The Fibonacci numbers less than {mx}:")

for i in range(mx):
    a = nth_fibonacci(i)
    b = nth_fibonacci(i + 1)
    if a >= mx or b >= mx:
        print(a, end = '.\n')
        break
    else:
        print(a, end = ', ')
```

		
## 综合练习可选项目

- 参考如下游戏中的一款，用 Python 实现（难度逐步提高）：
   1. 2048（`$ sudo apt install 2048 && 2048`）
   1. 贪婪（`$ sudo apt install gread && gread`）
   1. 数独（`$ sudo apt nudoku && nudoku`）
   1. 打字员（`$ sudo apt install gtypist && gtypist`）
   1. 俄罗斯方块（`$ sudo apt install bastet && bastet`）

		
## 终端编程

	
### Escape 序列

	
### `curses` 模块

		
## 数据持久化

	
### 二进制数据读写

	
### `pickle` 模块

	
### `sqlite3` 模块

		
## 要点回顾

1. 掌握终端输出中 Escape 序列的基本概念和用法。
1. 掌握 `curses` 模块的基本用法。
1. 掌握二进制数据读写的基本方法。
1. 掌握 `pickle` 模块的基本用法。
1. 掌握 `sqlite3` 模块的基本用法。

		
## 作业

1) 使用递归函数计算三个递推代数式的值（如阶乘：n!），运行效果如下：

```console
$ ./factorial.py
Please input a positive integer: <-5>
Please input a positive integer: <20>
The factorial of 20 is: 2432902008176640000
```

2) 使用缓存结果的方法（使用列表）优化递归生成斐波那契数列的程序（命名为 `fibonacci-recursion-optimized.py`），运行效果同前。

	
3) 使用类重构 `formulas.py` 程序（命名为 `formulas-in-classes.py`），实现正方形、矩形、圆、三角形（高中及以上）、椭圆（高中及以上）四种几何图形对应的类，并实现用于计算周长和面积的方法。注意构造三角形应给定三个边长，并根据三个边长计算三角形的面积（需要用到 `math` 模块中的三角函数）。运行效果同前。

	
4) 严格按照内置函数 `print()` 的[接口描述](https://docs.python.org/zh-cn/3.10/library/functions.html#print)实现 `my_print()` 函数，添加测试代码并和 `print()` 的执行结果做对比。测试方法：创建两个文件并将 `my_print()` 和 `print()` 的结果分别输出到不同文件，最后对比这两个文件的内容是否一致。要求使用 `sys` 和 `io` 模块。运行效果如下：

```console
$ ./my_print.py my_print.txt print.txt
Printing test case 0 to my_print.txt...done.
Printing test case 0 to print.txt...done.
Printing test case 1 to my_print.txt...done.
Printing test case 1 to print.txt...done.
...
Comparing contents of my_print.txt and print.txt...
All test cases passed.
```

