## 第三讲：Python 数据类型

1. 第二讲作业点评
1. 数值
1. 字符串
1. 列表及元组
1. 字典
1. 其他数据类型
1. 编程的中层境界：数据和代码分离

		
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
# 在 while 循环的条件为 False 时，或者 for 循环的循环体未被执行时。
else:
    print(f'{n} is a prime!')
```

	
### 参考实现：`check-prime-improved.py`

```python
#!/usr/bin/python3

# 该函数返回两个值；第一个值表示是否为质数，第二个值表示找到的因子。
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
    print(f'{n} has a factor neither itself nor one: {factor}; it is not a prime.')
```

	
### 三人行必有我师

1. 赋值语句一次可以操作多个变量。
1. 函数一次可以返回多个数据。
1. `case _:` 分句可在 `match` 语句中处理默认（default）情形。
1. 循环中可以使用 `else` 分句。
1. 内置函数 `max()` 可用于取最大值；`min()` 可用于取最小值。
1. 内置函数 `assert()` 可在参数的求值（evaluate）结果为非真时终止（abort）程序的运行，方便调试。
1. 使用运算符 `is` 和 `is not` 可判断一个值是否为 `True`、`False` 等特殊值。

		
## 数据类型综述

1) 数据类型（data type）：编程语言用来表达（represent）现实世界中不同种类数据的方法。
2) 我们已经接触过三种 Python 数据类型：
   - 整数（integer）
   - 布尔值（boolean）
   - 字符串（string）
3) Python 中的数据本质上被视作不同类型的一个实例（instance），如：
   - `1` 是 `int` 类型的一个实例。
   - `True` 是 `bool` 类型的一个实例。
   - `1.0` 是 `float` 类型的一个实例。
   - `'Python'` 是 `str` 类型的一个实例。
4) `int()`、`float()`、`bool()` 这几个函数本质上是 `int`、`float` 和 `bool` 类型的构造函数（constructor）。

	
### 数据类型相关函数

4) `type()` 函数可返回一个数据的类型。
5) `isinstance()` 函数可判断一个数据是否属于某个特定的类型。

```python
>>> type(1)
<class 'int'>
>>> type(1.0)
<class 'float'>
>>> type('Python')
<class 'str'>
>>> isinstance(1, int)
True
>>> isinstance(1, float)
False
>>> isinstance(1.0, float)
True
>>> isinstance(True, int)
True
>>> isinstance(True, bool)
True
>>> isinstance('Python', str)
True
```

		
## 数值

- 计算机程序中的数值（number）主要用来表达（represent）数学上的数值。
- Python 的数值有四种子类型（sub classes/sub types）：
   1. 整数（`int`）
   1. 布尔值（`bool`）
   1. 浮点数（`float`）
   1. 复数（`complex`）

	
### 讲解视频[3-1：Python 数据类型：数值](#)

1) 在 Python 中布尔值被视作等同于整数；算术表达式中使用布尔值时，`False` 等同于 0，`True` 等同于 1。
2) 立即数（immediate value）的概念。所有带有小数点的立即数被视作浮点数。
3) Python 的 `print()` 函数显示浮点数时，始终会包含小数点。
4) 可以用类似科学计数法的方式定义一个立即数：`1E10` 或者 `33E2`，此时该立即数始终是浮点数。
5) Python 中的整数可使用二进制（binary，`0b`）、八进制（octonary，`0o`）、十六进制（hexadecimal，`0x`）写法。
6) 大部分算术运算符的结果数据类型取决于操作数（operand）的类型：操作数中有浮点数时，结果一定是浮点数。

	
（续）

7) 针对数值的常用内置函数：
   - `int()`、`float()`、`bool()`：构造对应的数值类型。
   - `abs(x)`：取绝对值；`max(x1, x2, ...)`：取最大值；`min(x1, x2, ...)`：取最小值；`round(x[, n])`：四舍五入；`pow(x, y)`等价于 `x ** y`。
8) 针对浮点数运算，可导入 Python 的内置模块 `math`：`import math`，其中包含有很多常用的数学函数，比如对数函数、三角函数等。
   - `math.sqrt()`：求平方根；`math.isclose(x, y)`：判断两个浮点数是否接近（考虑表达误差）。
9) `math.pi` 是 `math` 模块定义的常量，即圆周率；类似的还有 `math.e`（自然常数）。

	
### 拓展讲解和讨论

1. 进制的概念
1. 科学计数法
1. 为什么叫浮点数
1. 准确判断两个浮点数大小的方法
1. 复数（complex）
   - 复数高等数学引入的一种数值类型，在 Python 中使用 `complex()` 构造复数。
   - 进行复数运算时，可导入内置的 `cmath` 模块。
1. 拓展资料：
   - [Python 3.10 官方文档：数学函数](https://docs.python.org/zh-cn/3.10/library/math.html)
   - [Python 3.10 官方文档：关于复数的数学函数](https://docs.python.org/zh-cn/3.10/library/cmath.html)

		
## 字符串

- 计算机程序中的字符串主要用来表达构成自然语言的文本或者文本片段。
- 字符串字面值（literal）的概念。
- Python 的字符串字面值使用成对出现的单引号（single-quotes，`''`）或者双引号（double-quote，`""`）定义。
- 亦可使用成对出现的三单引号或者三双引号来定义。此时，键入其中的特殊字符（制表符、回车符）等均将原样保留。
- 三单引号或者三双引号定义的文本段落也被当做块注释（block comment）使用。

	
### 讲解视频[3-2：Python 数据类型：字符串](#)

1. 定义字符串字面值时要考虑的两个问题：
   - 如果文本本身包含单引号（`'`）或者双引号（`"`）怎么办？
   - 如果文本中需要包含一些特殊字符，如换行符、回车符怎么办？
1. 针对字符串的操作符（operator）：串接（`+`）、重复（`*`）、索引值引用（`[]`）、切片（`[:]`）、成员检测（`in`）、非成员检测（`not in`）。
1. 针对字符串的内置方法（method）：`startswith()`、`endswith()` 等。

	
### 拓展讲解和讨论

1. 字符集和编码
1. 拓展资料：
   - [Python 3.10 官方文档：字符串方法](https://docs.python.org/zh-cn/3.10/library/stdtypes.html#string-methods)

		
## 列表和元组

- 计算机程序中的列表（list）用来表达可使用索引（index）值引用的一组有序（ordered）数据。其中的一个数据项（data item）称为一个单元（unit）。
- 在其他编程语言中，可能使用数组（array）这一术语（term）。
- Python 中的列表使用成对出现的中括号（square brackets，`[]`）定义，各个单元之间使用逗号（comma，`,`）分隔。
- Python 中的元组本质上是就是不可变的列表，使用成对出现的小括号（parentheses，`()`）定义，各个单元之间使用逗号（comma，`,`）分隔。
- 列表或元组中的单元可通过 `[]` 引用，或通过 `[:]` 定义一个范围从而构成切片（slice）。

	
### 讲解视频[3-3：Python 数据类型：列表和元组](#)

	
要点总结

1. 列表中的数据项可以是任意数据类型，也就是列表中可以包含另一个列表。
1. 元组中的单元不可改变，但若其中的单元是一个列表，则这个列表中的数据项可以改变。
1. `+` 和 `*` 可以作用于列表和元组，分别用于串接（concatenate）两个列表/元组，或者扩大列表/元组 N 倍；这两种操作均构成一个新的列表/元组。

		
## 字典

	
### 讲解视频[3-4：Python 数据类型：字典](#)

		
## 其他数据类型

### 虚无

1. 虚无（none 或 nothing）类型表示空，就是什么也没有。
1. 在 Python 中用 `None` 表示。
1. 试试下面的代码：

```python
def none():
    pass

pass()
type(pass())
```

	
### 可调用类型

- 可调用（callable）类型指函数或者方法等：
   1. 使用 `def` 语句定义的函数便是一个可调用类型。
   1. 内置的函数或方法。
   1. 用户自定义的类、构造函数及其方法。

	
### 模块

- 用于表达被导入的软件模块的抽象数据类型。
   1. 模块可使用 `import` 语句导入。
   1. 使用 `dir()` 函数可展示模块提供的接口（interface）。

	
### 字节序列

1. 用于表达一般性的数据，比如图片、语音、视频等多媒体数据。
1. 在 Python 中有两种字节序列类型：
   - 字节们（`bytes`）：使用 `bytes()` 构造。
   - 字节组（`bytearray`）：使用 `bytearray()` 构造。
1. 字节们本质上是字节为单位的不可变序列。
1. 字节组本质上是字节为单位的可变序列。
1. 为什么不直接使用 `int` 列表？

	
### 集合

1. 数学上的集合概念：集合中的元素（element）具有唯一性。
1. Python 中的集合提供类似数学上的集合的功能，具有如下特点：
   - 不可通过索引值索引。
   - 可执行数学定义的集合操作，如相交、合并等操作。
1. 在 Python 中有两种集合类型：
   - 集合（`set`）：使用 `set()` 构造，可更改。
   - 冰冻集合（`frozenset`）：使用 `frozeset()` 构造，不可更改。
1. 在程序中，集合可用来维护现实中不可重复的唯一性标识符（如学号、身份证号、手机号码、邮件地址）等信息。

		
## Pythone 数据类型的分类

1) 虚无（`None`）
2) 数值（number）
   - 整型（integral）
      * 整数（`int`）
      * 布尔值（`bool`）
   - 浮点数（`float`）
   - 复数（`complex`）
3) 序列（sequence）
   - 字符串（`str`）；不可变（immutable）
   - 元组（`tuple`）；不可变（immutable）
   - 列表（`list`）；可变（mutable）
   - 字节们（`bytes`）；不可变（immutable）
   - 字节组（`bytearray`）；可变（mutable）

	
（续）

4) 集合类型
   - 集合（`set`）
   - 冰冻集合（`frozenset`）
5) 映射（mapping）
   - 字典（`dict`）
6) 可调用（callable）类型
   - 用户自定义（user-defined）函数（`function`）
   - 内置（built-in）函数或方法（`builtin_function_or_method'）
8) 模块（module）
   - 模块（`module`）

		
## 针对容器的运算符或函数

1. 容器（container）：序列、集合及映射统称为容器。
1. `in`：测试成员包含在容器中。
1. `not in`：测试成员不包含在容器中。
1. `for x in`：遍历（travel）容器中的成员。
1. `len()`：获取容器的长度（length），亦即容器成员（或元素）的个数。

		
## 针对序列的运算符

1. `+`：串接
1. `\*`：重复
1. `[]`：用索引值引用
1. `[:]`：切片
1. `del` 语句：移除特定元素（仅针对可变序列）

		
## 编程的中层境界：数据和代码分离

	
### 使用列表定义单元测试用例

原始代码：

```python
prime, factor = check_prime(2)
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
```

	
将数据和代码分离：

```python
cases = [
    [2, True],
    [3, True],
    [4, False],
    [5, True],
    [9, False],
    [1973, True],
    [2024, False],
]

for i in range(len(cases)):
    prime, factor = check_prime(cases[i][0])
    assert(prime is cases[i][1])
```

	
### 使用字典列表定义公式

原始代码：

```python
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
        case _:
            quit()
```

	
将数据和代码分离：

```python
formulas = [
    { 'name': 'Triangle',   'func': prompt_for_triangle },
    { 'name': 'Square',     'func': prompt_for_square },
    { 'name': 'Circle',     'func': prompt_for_circle },
]

def prompt_for_formula():
    formula = len(formulas) + 1
    while formula < 0 or formula > len(formulas):
        print('To calculate the area, please choose a geometrical shape:')
        i = 1
        for f in formulas:
            print(f'{i}. {f["name"]}')
            i = i + 1
        print('0. Exit')
        formula = int(input('Your choice:'))

    return formula

while True:
    f = prompt_for_formula()
    if f > 0 and f <= len(formulas):
        formulas[f - 1]['func']()
    else:
        quit()
```

		
## 本节必须掌握的知识点和技能

		
## 本节涉及的 Linux 系统命令

		
## 进一步学习资料

1. [Python 3.10 官方文档](https://docs.python.org/zh-cn/3.10/index.html)

		
## 作业

