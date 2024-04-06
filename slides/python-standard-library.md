## Python 标准库和常用模块

1. 三人行必有我师
1. Python 标准库概览
1. Python 函数的参数类型
1. Python 类和对象的基本概念
1. 针对常用数据类型的接口
1. 常用模块及其主要接口
1. 要点回顾
1. 作业

		
## 三人行必有我师

### 递归（recursive）调用生成斐波那契数列

```python
#!/usr/bin/python3

def fibonacci(n):
   if n <= 1:
       return n
   else:
       return fibonacci(n - 1) + fibonacci(n - 2)

mx = 0
while mx <= 0:
    try:
        mx = int(input('Please input a positive integer: '))
    except ValueError:
        mx = 0

print(f"The Fibonacci numbers less than {mx}:")

for i in range(mx):
    a = fibonacci(i)
    b = fibonacci(i + 1)
    if a >= mx or b >= mx:
        print(a, end = '.\n')
        break
    else:
        print(a, end = ', ')
```

	
### 消除重复代码

- `my_range()` 函数的原始实现

```python
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
```

	

- 消除重复代码

```python
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
    sign = 1
    if step > 0:
        sign = -1

    while i * sign < stop * sign:
        yield i
        i += step
```

		
## Python 标准库概览

1) [Python 标准库官方文档](https://docs.python.org/zh-cn/3.10/library/index.html)
2) 常用：
   - 内置函数、常量以及针对针对内置数据类型的接口。
   - 内置异常。
   - 文本及二进制数据处理。
   - 针对日期、时区、日历等数据类型以及容器、数组、堆队列等抽象数据结构的接口。
   - 数值及数学模块，包括 `math`、`cmath` 等模块。
   - 文件和目录访问。
   - 通用操作系统服务。
   - 运行时服务。
   - 数据持久化。
   - 国际化。

	
3) 高阶：
   - 加解密。
   - 文件格式。
   - 并发执行。
   - 数据压缩和归档。
   - 网络和进程间通讯。
   - 互联网数据处理。
   - 结构化标记语言支持。
   - 互联网协议和支持。
   - 多媒体服务。
   - 开发工具。
   - 调试和分析。
   - 软件打包和分发。
   - 导入模块。
   - Python 语言服务。
   - ...

		
## Python 函数参数类型

1) 默认（default）参数。
   - 使用赋值运算符（`=`）定义特定形参的默认值。
   - 调用时，定义有默认值的形参之默认值可被实参覆盖。
   - 不定义默认值的形参位置应该置于默认参数之前。

```python
def my_range(start, stop = None, step = None):
    ...
```

	
2) 关键字参数和位置参数
   - 在调用函数时，使用 `kw=value` 的写法指定传入函数的实参。
   - 不使用关键词参数时，参数的位置决定了实参对应的形参。
   - 关键词参数应在位置参数之后传入。
   - 所有参数只能赋值一次。

```python
print(n, end=', ')
```

	
3) 任意位置参数
   - 适用于参数数量可变的情形。
   - 任意位置参数会被解释器构成一个元组传入函数，对应的形参之前使用单个星号（asterisk，`*`）。

```python
import sys

result = 10
print("The result is: ", result, sep='')

def my_print(*t):
    for x in t:
        s = str(x)
        for c in s:
            sys.stdout.write(c)

    sys.stdout.write('\n')

my_print("The result is: ", result)
```

	
4) 任意关键词参数
   - 适用于参数数量可变的且使用 `kw=value` 形式传递的参数。
   - 任意位置参数会被解释器构成一个字典传入函数，对应的形参之前使用两个星号。

```python
d1 = dict(name='Vincent', weight=68, age=50)

def my_dict(**kws):
    '''return kws'''

    d = {}
    for k in kws:
        d[k] = kws[k]
    return d

d2 = dict(name='Vincent', weight=68, age=50)
assert(d1 == d2)
```

	
5) 特殊形参（`/` 和 `*`）
   - 在定义函数时，位于 `/` 之前的参数只能以位置参数的形式传递。
   - 在定义函数时，位于 `*` 之后的参数只能以关键词参数的形式传递。
   - 不符合以上用法的函数调用产生 `TypeError` 错误。

```python
# a, b：只能以位置参数形式传递。
# c：位置或关键词参数形式传递。
# d：只能以关键词参数形式传递。
def foo(a, b, /, c, *, d):
    ...
```

		
## Python 类和对象的基本概念

- 大部分编程语言支持面向对象的编程。
- 类（class）用来定义一类具有共同属性的事务，由一组数据和方法构成。
- 对象（object）则是某个类的一个实例。
- 在 Python 中，所有内置数据类型对应一个内置类。
- 在自定义类中，通过实现一些内部预定义的方法，比如 `__abs__()`、`__str__()` 等，可实现针对该类之对象的取绝对值、字符串化等操作。

	
### Python 类的定义

- 使用 `class` 语句定义一个类；`object` 是 Python 基类（base class）或父类（parent class）。
- 一个类由一组属性（attribute）和一组方法（method）构成。
- 属性有类属性和实例属性之分。
- 使用预定义方法 `__init__()` 定义一个类的初始化（initialize）函数。
- 所有类方法的第一个参数用于传递该类的实例对象，故而常用 `self` 作为该参数的名称。

```python
class Circle(object):
    pi = 3.14159265             # 类属性

    def __init__(self, r):
        self.r = r              # 实例属性

    def premiter(self):
        return 2. * self.pi * self.r

    def area(self):
        return self.pi * self.r * self.r
```

	
### Python 类的使用

1. 使用类名称作为函数名调用类的构造方法以创建一个实例。
1. 通过类的实例可访问（access）对应的属性或调用对应的方法。

```python
c1 = Circle(1.0)    # 解释器会创建一个 Circle 对象并调用 Circle 类的 __init__() 方法。
s = c1.area()       # 调用 Circle 对象的 area 方法；此时将使用类属性 pi 的默认值进行计算。
                    # 解释器会将 c1 作为第一个参数传入 Circle 类的 `area` 函数。

import math
Circle.pi = math.pi # 使用 math 模块中的 pi 常量覆盖类属性 pi 的值。
s = c1.area()       # 调用 Circle 对象的 area 方法；此时将使用修改后的类属性 pi 的默认值进行计算。
                    # 解释器会将 c1 作为第一个参数传入 Circle 类的 `area` 函数。
```

		
## 针对常用数据类型的接口

	
### 针对数值的接口

- `abs(x)`：返回一个数的绝对值。参数 `x` 可以是整数、浮点数或任何实现了 `__abs__()` 方法的对象。
- `divmod(a, b)`：以两个（非复数）数字为参数，在作整数除法时，返回商和余数。
   1. 对于整数而言，结果与 `(a // b, a % b)` 相同。
   1. 对于浮点数则结果为 `(q, a % b)`，其中 `q` 通常为 `math.floor(a / b)`，但也可能比它小 `1`。
- `class int([x])` 和 `class int(x, base=10)`： 返回一个基于数字或字符串 `x` 构造的整数对象，或者在未给出参数时返回 `0`。
   1. 对一般性的对象 `x`，如果 `x` 定义了 `__int__()`，`int(x)` 将返回 `x.__int__()`；如果 `x` 定义了 `__index__()`，它将返回 `x.__index__()`；如果 `x` 定义了 `__trunc__()`，它将返回 `x.__trunc__()`。
   1. 对于浮点数，它将向零舍入。
- `class float([x])`：返回从数值或字符串 `x` 生成的浮点数。
   1. 对于一般性的对象 `x`；如果 `x` 定义了 `__float__(x)`，则会返回 `x.__float__()`；如果未定义 `__float__()`，则将回退（fallback）至 `__index__()`。
- `round(number[, ndigits])`：返回 `number` 舍入到小数点后 `ndigits` 位精度的值。
   1. 如果 `ndigits` 被省略或为 `None`，则返回最接近输入值的整数。
   1. 对于支持 `round()` 方法的内置类型，结果值会舍入至最接近的 10 的负 `ndigits` 次幂的倍数；如果与两个倍数同样接近，则选用偶数。因此，`round(0.5)` 和 `round(-0.5)` 均得出 0 而 `round(1.5)` 则为 2。
   1. `ndigits` 可为任意整数值（正数、零或负数）。如果省略了 `ndigits` 或为 `None`，则返回值将为整数。否则返回值与 `number` 的类型相同。
   1. 对于一般的 Python 对象 `x`, `round` 将委托（delegate）给 `x.__round__()`。
- `pow(base, exp[, mod])`：返回 `base` 的 `exp` 次幂。
   1. 如果 `mod` 存在，则返回 `base` 的 `exp` 次幂对 `mod` 取余（比 `pow(base, exp) % mod` 更高效）。
   1. 两参数形式 `pow(base, exp)` 等价于乘方运算符: `base ** exp`。

	
### 学会看语法描述文档

1) 以 Python 的浮点数描述语法

```
sign        ::=  "+" | "-"
infinity    ::=  "Infinity" | "inf"
nan         ::=  "nan"
digitpart   ::=  digit (["_"] digit)*
number      ::=  [digitpart] "." digitpart | digitpart ["."]
exponent    ::=  ("e" | "E") ["+" | "-"] digitpart
floatnumber ::=  number [exponent]
floatvalue  ::=  [sign] (floatnumber | infinity | nan)
```

	
### 针对字符串的接口

1. `str.endswith()`：如果字符串以指定的 `suffix` 结束返回 `True`，否则返回 `False`。如果有可选参数 `start`，将从所指定位置开始检查。如果有可选项 `end`，将在所指定位置停止比较。
1. `str.startswith(prefix[, start[, end]])`：如果字符串以指定的 `prefix` 开始则返回 `True`，否则返回 `False`。如果有可选参数 `start`，将从所指定位置开始检查。如果有可选参数 `end`，将在所指定位置停止比较。
1. `str.replace(old, new[, count])`：返回字符串的副本（copy），其中出现的所有子字符串 `old` 都将被替换为 `new`。如果给出了可选参数 `count`，则只替换前 `count` 次出现。

	
### 针对容器的内置全局函数

1. 容器（container）：序列、集合及映射统称为容器。
1. `len()`：获取容器的长度（length），亦即容器成员（或键值对）的个数。
1. `max()`：获取容器中各单元之最大值。
1. `min()`：获取容器中各单元之最小值。

		
### 针对可变序列的内置方法

1. `s.append(x)`：在 `s` 的尾部追加新单元 `x`。
1. `s.clear()`：清除所有成员，变成空序列。
1. `s.copy()`：复制序列。
1. `s.count(x)`：返回 `x` 在序列中出现的次数。
1. `s.extend(t)`：用 `t` 的内容扩展 `s`。
1. `s.index(x)`：搜索并返回和指定数据 `x` 匹配的（matched）第一个成员之索引值。
1. `s.insert(i, x)`：插入数据 `x` 到指定的位置 `i`。
1. `s.pop()`：提取最后一项，并将其从 `s` 中移除。
1. `s.pop(i)`：提取在 `i` 位置上的项，并将其从 `s` 中移除。
1. `s.remove(x)`：移除和指定数据 `x` 匹配的第一个项。
1. `s.reverse()`：就地（in-place）将序列成员逆序。
1. `s.sort()`：对序列中的成员排序。

	
### 针对不可变序列的内置方法

1. `s.count(x)`：返回 `x` 在序列中出现的次数。
1. `s.index(x[, i[, j])`：`x` 在 `s` 中首次出现项的索引号（索引号在 `i` 或其后且在 `j` 之前）。

	
### 针对字典的内置方法

1) 针对字典的常用内置方法：
   - `d.clear()`：清除字典中的所有键值对。
   - `d.get()`：获取指定键的值；若不存在返回 `None`（不产生异常）。
   - `d.items()`：返回构成的键值对列表，其中的每个单元是一个对应键、值构成的元组。
   - `d.keys()`：返回字典的键列表。
   - `d.pop(key[, default])`：弹出指定键对应的键值对，返回其值；若不存在则返回 `default`。
   - `d.popitem()`：删除最后插入字典的键值对，返回对应的值。
   - `d.values()`：返回字典的值列表。

	
2) 针对字典的其他内置方法：
   - `d.copy()`：浅复制字典。
   - `d.fromkeys()`：使用指定的键元组以及可选的值构建一个字典。
   - `d.setdefault(key[, default])`：如果字典存在键 `key`，则返回其值。如果不存在，插入值为 `default` 的键 `key`，并返回 `default`。`default` 默认为 `None`。
   - `d.update([other])`：使用来自 `other` 的键值对更新字典，覆盖原有的键。返回 `None`。

		
## 要点回顾

		
## 作业

1) 优化使用递归函数生成斐波那契数列的程序（命名为 `fibonacci-recursion-optimized.py`），运行效果同前。
2) 使用递归函数计算阶乘，运行效果如下：

```console
$ ./factorial.py
Please input a positive integer: <-5>
Please input a positive integer: <20>
The factorial of 20 is: 2432902008176640000
```

	
3) 按照内置函数 `print()` 的接口定义，实现 `my_print()` 函数，添加测试代码并和 `print()` 的结果做对比。

> `print(*objects, sep=' ', end='\n', file=None, flush=False)`
>
> 将 `objects` 打印输出至 `file` 指定的文本流，以 `sep` 分隔并在末尾加上 `end`。`sep`、 `end`、 `file` 和 `flush` 必须以关键字参数的形式给出。
>
> 所有非关键字参数都会被转换为字符串，就像是执行了 `str()` 一样，并会被写入到流，以 `sep` 分隔并在末尾加上 `end`。`sep` 和 `end` 都必须为字符串；它们也可以为 `None`，这意味着使用默认值。如果没有给出 `objects`，则 `print()` 将只写入 `end`。
>
> `file` 参数必须是一个具有 `write(string)` 方法的对象；如果参数不存在或为 `None`，则将使用 `sys.stdout`。 由于要打印的参数会被转换为文本字符串，因此 `print()` 不能用于二进制模式的文件对象。 对于这些对象，应改用 `file.write(...)`。
>
> 输出缓冲通常由 `file` 确定。 但是，如果 `flush` 为真值，流将被强制刷新。

