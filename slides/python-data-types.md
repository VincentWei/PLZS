## 第三讲：Python 数据类型

1. 第二讲作业点评
1. 数值
1. 字符串
1. 列表及元组
1. 字典
1. 其他数据类型
1. 恰到好处地选择数据类型

		
## 第二讲作业回顾

1. 输出小于用户指定的正整数的斐波那契（Fibonacci）数列。
1. 增强第一讲作业，循环提示用户选择一个公式，并判断用户输入的合法性。
1. 循环提示用户输入一个正整数，并判断该正整数是否为一个质数。

	
### 参考实现：`fibonacci.py`

```python
#!/usr/bin/python3

n = 0
while n <= 0:
    n = int(input('Please input a positive integer: '))

# 赋值语句一次可以操作多个变量。
a, b = 0, 1
while a <= n:
    if a == n or b > n:
        print(a, end = '.\n')
    else:
        print(a, end = ', ')
    a, b = b, a + b
```

	
### 参考实现：`formulas-improved.py`

```python
#!/usr/bin/python3

def area_of_square(d):
    return d * d

def prompt_for_square():
    d = 0
    while d <= 0:
        d = float(input("Please input the length of one side of a square: "))

    s = area_of_square(d)
    print(f"The area of the square is {s}")

def area_of_triangle(d, h):
    return d * h / 2

def prompt_for_triangle():
    d = h = 0
    while d <= 0 or h <= 0:
        d = float(input("Please input the length of one side of a triangle: "))
        h = float(input("Please input the length of the height on the side: "))

    s = area_of_triangle(d, h)
    print(f"The area of the triangle is {s}")

def area_of_circle(r):
    return 3.14159265 * r * r

def prompt_for_circle():
    r = 0
    while r <= 0:
        r = float(input("Please input the length of one side of a circle: "))

    s = area_of_circle(r)
    print(f"The area of the circle is {s}")

def prompt_for_formula():
    formula = 4
    while formula < 0 or formula > 3:
        print('To calculate the area, please choose a geometrical shape:')
        print('1. Triange')
        print('2. Square')
        print('3. Circle')
        print('0. Exit')
        formula = int(input('Your choice:'))

    return formula

while True:
    match prompt_for_formula():
        case 1:
            prompt_for_triangle()
        case 2:
            prompt_for_square()
        case 3:
            prompt_for_circle()
        case _: # _ 指不是 1，不是 2，也不是 3 的情况，相当于默认（default）
            quit()
```

	
### 参考实现：`check-prime.py`

```python
n = 2
while n <= 2:
    n = int(input('Please input an integer larger than 2: '))

# 内置函数 `max()` 可用于取最大值；`min()` 可用于取最小值。
for i in range(2, max(n // 2, 3)):
    if n % i == 0:
        print(f'{n} equals to {i} * { int(n / i)}; it is not a prime.')
        break
# 循环中可以使用 `else` 分句；该分句定义的语句体（suite），
# 在循环条件为 False 时执行。
else:
    print(f'{n} is a prime!')
```

	
### 参考实现：`check-prime-improved.py`

```python
#!/usr/bin/python3

def check_prime(n):
    if n == 2:
        return True, 1

    factor = 1
    for i in range(2, max(n // 2, 3)):
        if n % i == 0:
            factor = i
            break

    if factor > 1:
        return False, factor

    return True, 1

# 单元测试
prime, factor = check_prime(2)
# 内置函数 `assert()` 可在参数的求值（evaluate）结果为非真时终止（abort）
# 程序的运行，方便调试。
assert(prime is True)

prime, factor = check_prime(3)
assert(prime is True)
prime, factor = check_prime(4)
assert(prime is False)
prime, factor = check_prime(5)
assert(prime is True)
prime, factor = check_prime(9)
assert(prime is False)
prime, factor = check_prime(1973)
assert(prime is True)
prime, factor = check_prime(2024)
assert(prime is False)

n = 1
while n <= 1:
    n = int(input('Please input an integer larger than 1: '))

prime, factor = check_prime(n)
if prime:
    print(f'{n} is a prime!')
else:
    print(f'{n} has a factor not itself or one: {factor}; it is not a prime.')
```

	
### 三人行必有我师

1. 赋值语句一次可以操作多个变量。
1. 函数一次可以返回多个数据。
1. `case _:` 分句可在 `match` 语句中处理默认（default）情形。
1. 循环中可以使用 `else` 分句。
1. 内置函数 `max()` 可用于取最大值；`min()` 可用于取最小值。
1. 内置函数 `assert()` 可在参数的求值（evaluate）结果为非真时终止（abort）程序的运行，方便调试。

		
## 数据类型综述

- 数据类型（data type）

		
## 数值

- 计算机程序中的数值（number）主要用来表达（represent）数学上的数值。
- Python 的数值有四种子类型（sub classes/sub types）：
  1. 整数（integer）
  1. 浮点数（float）
  1. 布尔值（boolean）
  1. 复数（complex）

	
讲解视频[3-1：Python 数据类型：数值](#)


		
## 字符串

- 计算机程序中的字符串主要用来表达构成自然语言的文本或者文本片段。
- Python 的字符串使用成对出现的单引号（single-quotes，`''`）或者双引号（double-quote，`""`）定义。此时，若其中包含特殊字符或者可能引起混淆的单引号、双引号，需要使用转义（escape）字符。
- 亦可使用成对出现的三个单引号或者三个双引号来定义。此时，键入其中的特殊字符（制表符、回车符）等均将原样保留。

	
讲解视频[3-2：Python 数据类型：字符串](#)

		
## 可调用类型

	
讲解视频[3-3：Python 数据类型：可调用类型](#)

		
## 虚无

	
讲解视频[3-4：Python 数据类型：虚无和其他类似类型](#)

		
## 列表和元组

- 计算机程序中的列表（list）用来表达可使用索引（index）值引用的一组数据。其中的一个数据项（data item）称为一个单元（unit）。
- 在其他编程语言中，可能使用数组（array）这一术语（term）。
- Python 中的列表使用成对出现的中括号（square brackets，`[]`）定义，各个单元之间使用逗号（comma，`,`）分隔。
- Python 中的元组本质上是就是不可变的列表，使用成对出现的小括号（parentheses，`()`）定义，各个单元之间使用逗号（comma，`,`）分隔。
- 列表或元组中的单元可通过 `[]` 引用，或通过 `[:]` 定义一个范围从而构成切片（slice）。

```python
```

	
讲解视频[3-5：Python 数据类型：列表和元组](#)

	
要点总结

1. 列表中的数据项可以是任意数据类型，也就是列表中可以包含另一个列表。
1. 元组中的单元不可改变，但若其中的单元是一个列表，则这个列表中的数据项可以改变。
1. `+` 和 `*` 可以作用于列表和元组，分别用于串接（concatenate）两个列表/元组，或者扩大列表/元组 N 倍；这两种操作均构成一个新的列表/元组。

		
## 字典

讲解视频[3-6：Python 数据类型：字典](#)

		
## 其他数据类型

	
### 字节序列

讲解视频[3-7：Python 数据类型：字节们和字节组](#)

	
### 集合

	
讲解视频[3-8：Python 数据类型：集合和冰封集合](#)

		
## Pythone 数据类型的确切分类

1) 虚无（`none`）
2) 数值（`number`）
   - 整型（integral）
      * 整数（`int`）
      * 布尔值（`bool`）
   - 浮点数（`float`）
   - 复数（`complex`）
3) 序列（sequence）
   - 字符串（`string`）；不可变（immutable）
   - 字节序（`bytes`）；不可变（immutable）
   - 元组（`tuple`）；不可变（immutable）
   - 列表（`list`）；可变（mutable）
   - 字节数组（`bytearray`）；可变（mutable）

		
（续）

4) 集合类型
   - 集合（`set`）
   - 冰封集合（`frozenset`）
5) 映射（mapping）
   - 字典（`dict`）
6) 可调用（callable）类型
   - 用户自定义（user-defined）函数（`function`）
   - 内置（built-in）函数或方法（`builtin_function_or_method'）

		
## 恰到好处地选择数据类型

		
## 本节必须掌握的知识点和技能

		
## 本节涉及的 Linux 系统命令

		
## 进一步学习资料

1. [Python 3.10 官方文档](https://docs.python.org/zh-cn/3.10/index.html)

		
## 作业

