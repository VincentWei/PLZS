## Python 数据类型

1. 三人行必有我师
1. 数值
1. 字符串
1. 列表及元组
1. 字典
1. 其他数据类型
1. 编程的中层境界：解耦数据和代码
1. 要点回顾
1. 作业

		
## 三人行必有我师

### 赋值语句一次可以操作多个变量

- 使用逗号（colon，`,`）可在赋值语句中一次操作多个变量；函数亦可一次返回多个值。

```python
a, b = 0, 1
while a <= n:
    if a == n or b > n:
        print(a, end = '.\n')
    else:
        print(a, end = ', ')
    a, b = b, a + b
```

	
### 处理解释器异常

- 给 `int()`、`float()` 函数不可识别的字符串时，会产生 `ValueError` 错误；此时应使用 `try` 语句处理异常。

```python
d = 0
while d <= 0:
    try:
        d = float(input("Please input the length of one side of a square: "))
    except ValueError:
        d = 0
```

	
### 在 `match` 语句中处理默认情形

- `case _:` 分句可在 `match` 语句中处理默认（default）情形。

```python
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

	
### 内置函数 `max()` 和 `min()`

- 内置函数 `max()` 可用于取最大值；`min()` 可用于取最小值。
- 循环中可以使用 `else` 分句。

```python
# 内置函数 `max()` 可用于取最大值；`min()` 可用于取最小值。
for i in range(2, max(n // 2, 3)):
    if n % i == 0:
        print(f'{n} equals to {i} * { int(n / i)}; it is not a prime.')
        break
# 循环语句中可以使用 `else` 分句；
# 该分句定义的语句体（suite），在 `while` 或者 `for` 循环的条件
# 为 `False` 时执行。
else:
    print(f'{n} is a prime!')
```

	
### 巧用 `assert()` 函数协助调试

- 内置函数 `assert()` 可在参数的求值（evaluate）结果为非真时终止（abort）程序的运行，方便调试。
- 使用运算符 `is` 和 `is not` 可判断一个值是否为 `True`、`False` 等特殊值。

```python
prime, factor = check_prime(2)
# 内置函数 `assert()` 可在参数的求值（evaluate）结果为非真时终止（abort）
# 程序的运行，方便调试。
assert(prime is True)
prime, factor = check_prime(3)
```

		
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

- 计算机程序中的数值（number）用来表达数学上的数值。
- Python 的数值有四种子类型（sub classes/sub types）：
   1. 整数（`int`）
   1. 布尔值（`bool`）
   1. 浮点数（`float`）
   1. 复数（`complex`）

	
### 讲解视频

[3-1：Python 数据类型：数值](https://www.douyin.com/video/7349792693872053523)

1) 在 Python 中布尔值被视作等同于整数；算术表达式中使用布尔值时，`False` 等同于 0，`True` 等同于 1。
2) 我们直接输入到代码中数值称为立即数（immediate value）；所有带有小数点的立即数被视作浮点数。
4) 可以用类似科学计数法的方式书写一个立即数：`1E10` 或者 `33E2`，此时该立即数始终是浮点数。
3) Python 的 `print()` 函数显示浮点数时，始终会包含小数点；整数不会包含小数点。
5) Python 中的整数可使用二进制（binary，`0b` 前缀）、八进制（octonary，`0o` 前缀）、十六进制（hexadecimal，`0x` 前缀）写法。
6) 大部分算术运算符的结果数据类型取决于操作数（operand）的类型：操作数中有浮点数时，结果一定是浮点数；`/` 运算符的结果一定是浮点数。

	
[3-1：Python 数据类型：数值](https://www.douyin.com/video/7349792693872053523)（续）

7) 针对数值的常用内置函数：
   - `int()`、`float()`、`bool()`：构造对应的数值类型；这些函数接受字符串作为参数，但必须可解析（parse）为对应的数值，否则会产生 `ValueError` 错误。
   - `abs(x)`：取绝对值；`max(x1, x2, ...)`：取最大值；`min(x1, x2, ...)`：取最小值；`round(x[, n])`：四舍五入；`pow(x, y)`等价于 `x ** y`。
8) 针对浮点数运算，可导入 Python 的内置模块 math：`import math`；其中包含有很多常用的数学函数，比如对数函数、三角函数等。
   - `math.sqrt()`：求平方根；`math.isclose(x, y)`：判断两个浮点数是否接近。
9) 数学常量：`math.pi` 是 `math` 模块定义的常量，即圆周率；类似的还有 `math.e`（自然常数）。

	
### 拓展信息

1. 进制的概念
1. 科学计数法以及浮点数名称的由来
1. 准确判断两个浮点数大小的方法
1. 模块的概念
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

	
### 讲解视频

[3-2：Python 数据类型：字符串](https://www.douyin.com/video/7349793411769175308)

1. 定义字符串字面值时要考虑的两个问题：
   - 如果文本本身包含单引号（`'`）或者双引号（`"`）怎么办？
   - 如果文本中需要包含一些特殊字符，如换行符、回车符怎么办？
1. 针对字符串的操作符（operator）：拼接（`+`）、重复（`*`）、索引值引用（`[]`）、切片（`[:]`）、成员检测（`in`）、非成员检测（`not in`）。
1. 针对字符串的内置方法（method）：`str.startswith()`、`str.endswith()`、`str.replace()` 等。

	
### 拓展信息

1. 函数原型的描述方法。
1. 字符串的构造函数 `str()` 可以串行化（serialize）任意一个数据。
1. 字符集和编码。
1. 拓展资料：
   - [Python 3.10 官方文档：字符串方法](https://docs.python.org/zh-cn/3.10/library/stdtypes.html#string-methods)

```python
#!/usr/bin/python3
# coding=UTF-8

print("这是 UTF-8 编码的中文简体汉字字符串")
print(str(True))
print(True)
```

		
## 列表和元组

- 计算机程序中的列表（list）用来表达可使用索引（index）值引用的一组有序（ordered）数据。
- 列表中的一个项（item）也会被称为一个单元（unit）或一个成员（member）。
- 在其他编程语言中，可能使用数组（array）这一术语（term）。

	
### 讲解视频

[3-3：Python 数据类型：列表和元组](https://www.douyin.com/video/7349794459124550975)

1) Python 中的列表使用成对出现的中括号（square brackets，`[]`）定义，各个单元之间使用逗号（comma，`,`）分隔。
2) Python 中的元组（`tuple`）本质上是就是不可变的列表，使用成对出现的小括号（parentheses，`()`）定义，各个单元之间使用逗号（comma，`,`）分隔。
3) 使用 `list()` 和 `tuple()` 亦可基于字符串和 `range()` 函数构造（construct）列表和元组。
4) 针对字符串的运算符亦可用于列表和元组：拼接（`+`）、重复（`*`）、索引值引用（`[index]`）、切片（`[i:j:k]`）、成员检测（`in`）、非成员检测（`not in`）。
5) 使用 `l += other` 可将 `other` 列表的内容追加到 `l` 列表之后。

	
[3-3：Python 数据类型：列表和元组](https://www.douyin.com/video/7349794459124550975)（续）

6) 列表中的数据项可以是任意数据类型，也就是列表中可以包含另一个列表；列表中的数据可以改变：`l[index] = value`。
7) 元组中的单元不可改变，但若其中的某成员是一个列表，则这个列表中的数据项可以改变。
8) 在列表或者元组数据 `s` 上使用 `for x in s` 语句可以遍历其中的成员。
9) 可使用 `del l[index]` 语句移除一个列表成员。

	
### 拓展信息

1. 列表和元组的不同
1. `range()` 到底是啥？有何优势？
1. 拓展资料：
   - [Python 3.10 官方文档：序列类型](https://docs.python.org/zh-cn/3.10/library/stdtypes.html#sequence-types-list-tuple-range)

		
## 字典

1. 计算机程序中的字典（dictionary）通常用来表达具有多重属性的复杂对象，比如一名学生的学号、姓名、性别、生日、身高、体重等。
1. 一个字典由一组键值对（key-value pair）构成，每个键值对由一个键（通常为字符串）和对应的值构成。
1. 一个字典中的键不可重复，我们可通过键来引用对应的值。
1. 在其他编程语言中，可能使用对象（object）这一术语或者关联数组（associated array）这一术语；键值对会被称为“属性（property）”。

	
### 讲解视频

[3-4：Python 数据类型：字典](#https://www.douyin.com/video/7349773341986802979)

1) Python 中的字典使用成对出现的大括号（braces，`{}`）定义，各个键值对之间使用逗号（comma，`,`）分隔，键和值之间使用冒号（colon，`:`）分隔。
2) 使用 `dict()` 可基于键值对参数构造一个字典：`dict(one=1, two=2, three=3)`。
3) 使用 `d[key]` 这样的语法引用字典 `d` 中一个键值对的值；字典中的键值对是无序的，无法使用索引值引用。
4) 使用 `d[key] = value` 改变 `key` 对应的值为 `value`。
5) 字典中的键可以是除字符串之外的其他数据类型，如整数、浮点数；字典中的值可以是任意数据类型。
6) 在字典数据 `d` 上使用 `for x in d` 语句遍历键；在字典数据 `d` 上使用 `for x in d.values()` 语句遍历值。
7) `del d[key]` 语句移除一个键值对。

	
### 拓展信息

1. 字典的键
1. 拓展资料：
   - [Python 3.10 官方文档：字典方法](https://docs.python.org/zh-cn/3.10/library/stdtypes.html#mapping-types-dict)

		
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
- 特殊函数：生成器（generator）；使用 `yield` 语句；内置函数 `range()` 本质上就是一个生成器。

	
`my-range-generator.py`：

```python
#!/usr/bin/python3

def my_range(start, stop = None, step = None):
    if not isinstance(start, int):
        raise(ValueError)

    if stop is None:
        stop = start
        start = 0
    elif not isinstance(stop, int):
        raise(ValueError)

    if step is None:
        if stop > start:
            step = 1
        else:
            step = -1
    elif not isinstance(step, int) or step == 0:
        raise(ValueError)

    if stop > start and step < 0:
        raise(ValueError)
    elif stop < start and step > 0:
        raise(ValueError)

    i = start
    if step > 0:
        while i < stop:
            yield i
            i += step
        else:
            pass
    else:
        while i > stop:
            yield i
            i += step
        else:
            pass

l = list(my_range(5))
print(l)

l = list(my_range(-5))
print(l)

l = list(my_range(2, 10))
print(l)

l = list(my_range(2, 2))
print(l)

l = list(my_range(2, 10, 2))
print(l)

for x in my_range(7):
    print(x)

f = my_range(0, 10, 2)
print(f)
for x in f:
    print(x)
```

	
### 模块

- 用于表达被导入的软件模块的抽象数据类型。
   1. 模块可使用 `import` 语句导入。
   1. 使用 `dir()` 函数可展示模块提供的接口（interface）。

	
### 字节序列

1. 用于表达一般性的二进制数据，比如图片、语音、视频等多媒体数据。
1. 在 Python 中有两种字节序列类型：
   - 字节串（`bytes`）：使用 `bytes()` 构造。
   - 字节组（`bytearray`）：使用 `bytearray()` 构造。
1. 字节串本质上是字节为单位的不可变序列。
1. 字节组本质上是字节为单位的可变序列。
1. 为什么不直接使用 `int` 列表？

	
### 集合

1. 数学上的集合概念：集合中的元素（element）具有唯一性；两个集合可以执行并、交、减等操作。
1. Python 中的集合提供类似数学上的集合的功能，具有如下特点：
   - 不可通过索引值索引。
   - 可执行数学定义的集合操作，如并、交、减等操作。
1. 在 Python 中有两种集合类型：
   - 集合（`set`）：使用 `set()` 构造，可更改。
   - 冰冻集合（`frozenset`）：使用 `frozeset()` 构造，不可更改。
1. 在程序中，集合可用来维护现实中不可重复的唯一性标识符（如学号、身份证号、手机号码、电子邮件地址）等信息。

		
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
   - 字节串（`bytes`）；不可变（immutable）
   - 字节组（`bytearray`）；可变（mutable）

	
（续）

4) 集合类型
   - 集合（`set`）
   - 冰冻集合（`frozenset`）
5) 映射（mapping）
   - 字典（`dict`）
6) 可调用（callable）类型
   - 用户自定义（user-defined）函数（`function`）
   - 内置（built-in）函数或方法（`builtin_function_or_method`）
8) 模块（module）
   - 模块（`module`）
9) 其他抽象类型
   - 类（`class`），比如生成器

	
### 针对序列的运算符

1. `s + t`：`s` 和 `t` 拼接；返回一个新的序列。
1. `n * s` 或 `s * n`：相当于将 `s` 重复 `n` 次返回一个新的序列。
1. `s[i]`：`s` 的第 `i` 项，起始为 0。
1. `s[i:j]`：`s` 从 `i` 到 `j` 的切片（slice）。
1. `s[i:j:k]`：`s` 从 `i` 到 `j` 步长为 `k` 的切片。
1. `x in s`：成员检测；如果 `s` 中的某项等于 `x` 则结果为 `True`，否则为 `False`。
1. `x not in s`：非成员检测；如果 `s` 中的某项等于 `x` 则结果为 `False`，否则为 `True`。

	
### 针对可变序列的运算符

1. `s += t`：将 `t` 追加到 `s`。
1. `s *= n`：将 `s` 的内容拼接给自己 `n - 1` 次；n <= 0 时，`s` 变空。

	
### 针对映射的运算符

1. `key in d`：键检测；如果 `d` 中存在键 `key` 则结果为 `True`，否则为 `False`。
1. `key not in d`：非键检测；如果 `d` 中存在键 `key` 则结果为 `False`，否则为 `True`。
1. `d | other`：合并 `d` 和 `other` 中的键和值来创建一个新的字典，两者必须都是字典。当 `d` 和 `other` 有相同键时，`other` 的值优先。
1. `d |= other`：用 `other` 的键和值更新字典 `d`。`other` 可以是字典或可迭代的键值对。当 `d` 和 `other` 有相同键时，`other` 的值优先。

		
## 编程的中层境界：解耦数据和代码

- 使用恰当的数据结构来表达现实中的事物和对象，可以让程序的逻辑结构更加清晰，也能获得更好的运行性能。
- 在编程中，将立即数、字符串字面值等数据混合在代码中，不利于代码的维护，也容易引入缺陷（bug）。
- 将数据和代码解耦将获得意想不到的好处。

	
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

	
### 使用字典列表定义几何公式信息

原始代码：

```python
def prompt_for_formula():
    formula = -1
    while formula < 0 or formula > 3:
        print('To calculate the area, please choose a geometrical shape:')
        print('1. Triange')
        print('2. Square')
        print('3. Circle')
        print('0. Exit')

        try:
            formula = int(input('Your choice:'))
        except ValueError:
            formula = -1

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
    formula = -1
    while formula < 0 or formula > len(formulas):
        print('To calculate the area, please choose a geometrical shape:')
        i = 1
        for f in formulas:
            print(f'{i}. {f["name"]}')
            i = i + 1
        print('0. Exit')
        try:
            formula = int(input('Your choice:'))
        except ValueError:
            formula = -1

    return formula

while True:
    f = prompt_for_formula()
    if f > 0 and f <= len(formulas):
        formulas[f - 1]['func']()
    else:
        quit()
```

		
## 要点回顾

1. 使用 `try` 语句处理可能得异常。
1. 数值表达中的进制。
1. 定义或者构造字符串的方法以及相关运算符，以及遍历字符串中字符的方法。
1. 定义或者构造列表、元组的方法以及相关运算符，以及遍历列表及元组中成员的方法。
1. 定义或者构造字典数据的方法以及相关运算符，以及遍历字典中值的方法。
1. 了解解耦数据和代码的概念并积极实践。

		
## 作业

1) 生成小于用户指定的正整数的斐波那契（Fibonacci）数列（使用列表），然后计算相邻两个数的比值。运行效果如下：

```console
$ ./fibonacci-improved.py
Please input a positive integer:<-5>
Please input a positive integer:<11>
The Fibonacci numbers less than 11:
0 / 1: 0
1 / 1: 1.0
1 / 2: 0.5
2 / 3: 0.6666666666666666
3 / 5: 0.6
5 / 8: 0.625
```

	
2) 编写一个程序，该程序可以将用户输入的一个自然数转换为 2 到 36 进制展示出来。运行效果如下：

```console
$ ./show-number-in-different-bases.py
Please input a natrual number:<15>
In base  2: 15 in decimal is expressed as `1111`.
In base  3: 15 in decimal is expressed as `120`.
In base  4: 15 in decimal is expressed as `33`.
In base  5: 15 in decimal is expressed as `30`.
In base  6: 15 in decimal is expressed as `23`.
In base  7: 15 in decimal is expressed as `21`.
In base  8: 15 in decimal is expressed as `17`.
In base  9: 15 in decimal is expressed as `16`.
In base 10: 15 in decimal is expressed as `15`.
In base 11: 15 in decimal is expressed as `14`.
In base 12: 15 in decimal is expressed as `13`.
In base 13: 15 in decimal is expressed as `12`.
In base 15: 15 in decimal is expressed as `10`.
In base 16: 15 in decimal is expressed as `F`.
In base 17: 15 in decimal is expressed as `F`.
In base 18: 15 in decimal is expressed as `F`.
...
```

	
3) 编写 `fibonacci-generator.py` 程序，使用生成器实现 Fibonacci 数列的生成功能。运行效果如下：

```console
$ ./fibonacci-generator.py
Please input a positive integer:<-5>
Please input a positive integer:<100>
The Fibonacci numbers less than 100:
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89.
```

	
4) 重构本讲 `my-range-generator.py` 程序为 `my-range-generator-improved.py`，将测试用例组织为适当的数据结构，并解耦代码和数据。运行效果如下：

```console
% ./my-range-generator-improved.py
case 0: passed.
case 1: passed.
case 2: passed.
case 3: passed.
case 4: passed.
case 5: passed.
case 6: passed.
case 7: passed.
```

	
5) 重构 `formulas-improved.py` 为 `formulas-refactored.py` 程序，将公式对应的函数、公式对应的几何形状名称、参数数量和提示字符串构造为一个合理的数据结构，并解耦代码和数据。运行效果不变。

