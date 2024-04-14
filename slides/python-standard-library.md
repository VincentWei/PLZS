# Python 标准库

1. 作业回顾
1. Python 标准库概览
1. Python 函数的参数类型
1. Python 类和对象的基本概念
1. 针对常用数据类型的接口
1. 常用模块及其主要接口
1. 深入理解递归调用
1. 要点回顾
1. 作业

		
## 作业回顾

### 递归（recursive）调用生成斐波那契数列

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

	
### 巧妙处理打印多个数值的分隔符和终止符

```python
# 0, 1, 1, 2, 3, 5, 8, 13.
for i in range(a):
    p = fibonacci(i)
    if p > a:
        break

    if p == 0:
        pass
    else:
        print(', ', end='')
    print(p, end='')
print('.')
```

	
### 消除重复代码

- `my_range()` 函数的原始实现

```python
def my_range(start, stop = None, step = None):
    # Statements validating arguments are omitted.
    ...

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
    # Statements validating arguments are omitted.
    ...

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

- 大部分编程语言支持面向对象（object-oriented）的编程。
- 类（class）用来定义一类具有共同属性的事物，由一组数据和方法构成。
- 对象（object）则是某个类的一个实例。
- 在 Python 中，所有内置数据类型对应一个内置的类。
- 在自定义类中，通过实现一些内部预定义的方法，比如 `__abs__()`、`__str__()` 等，可实现针对该类之对象的取绝对值、字符串化等操作。

	
### Python 类的定义

- 使用 `class` 语句定义一个类。
- 一个类由一组属性（attribute）和一组方法（method）构成。
- 属性有类属性和实例属性之分。
- 使用预定义方法 `__init__()` 定义一个类的初始化（initialize）函数。
- 所有类方法的第一个参数用于传递该类的实例对象，故而常用 `self` 作为该参数的名称。

```python
class Circle(object):           # `object` 是 Circle 的基类（base class）；亦称父类（parent class）或超类（super class）
    pi = 3.14159265             # pi 是类属性，对所有类的实例只有一个副本

    def __init__(self, r):
        self.r = r              # 实例属性，每个类的实例均有自己的副本

    def premiter(self):
        return 2. * self.pi * self.r

    def area(self):
        return self.pi * self.r * self.r

    def __str__(self):
        return 'A circle with a radius of ' + str(self.r) + '.'
```

	
### Python 类的使用

1. 使用类名称作为函数名调用类的构造方法以创建一个实例。
1. 通过类的实例可访问（access）类或实例的属性或调用方法。

```python
c = Circle(1.0)     # 解释器会创建一个 Circle 对象并调用 Circle 类的 __init__() 方法。
s = c.area()        # 调用 Circle 类的 area 方法；此时将使用类属性 pi 的默认值进行计算。
                    # 解释器会将 c 作为第一个参数传入 Circle 类的 `area` 方法。

# print() 将调用 Circle 类的 `__str__()` 方法。
print(c, "Its area is", s)

import math
Circle.pi = math.pi # 使用 math 模块中的 pi 常量覆盖类属性 pi 的值。
s = c.area()        # 调用 Circle 对象的 area 方法；此时将使用修改后的类属性 pi 的默认值进行计算。
                    # 解释器会将 c 作为第一个参数传入 Circle 类的 `area` 方法。
c1 = Circle(1.0)
s = c1.area()

# print() 将调用 Circle 类的 `__str__()` 方法。
print(c, "Its area is", s)
```

		
## 针对常用数据类型的接口

	
### 重新理解 `int()` 和 `float()` 内置函数

- `class int([x])` 和 `class int(x, base=10)`： 返回一个基于数字或字符串 `x` 构造的整数对象，或者在未给出参数时返回 `0`。
   1. 对一般性的对象 `x`，如果 `x` 定义了 `__int__()`，`int(x)` 将返回 `x.__int__()`；如果 `x` 定义了 `__index__()`，它将返回 `x.__index__()`；如果 `x` 定义了 `__trunc__()`，它将返回 `x.__trunc__()`。
   1. 对于浮点数，它将向零舍入。
- `class float([x])`：返回从数值或字符串 `x` 生成的浮点数。
   1. 对于一般性的对象 `x`；如果 `x` 定义了 `__float__(x)`，则会返回 `x.__float__()`；如果未定义 `__float__()`，则将回退（fallback）至 `__index__()`。

	
### 学会看语法描述文档

- Python 的浮点数描述语法

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

	
### 针对数值的内置函数

- `abs(x)`：返回一个数的绝对值。参数 `x` 可以是整数、浮点数或任何实现了 `__abs__()` 方法的对象。
- `pow(base, exp[, mod])`：返回 `base` 的 `exp` 次幂。
   1. 如果 `mod` 存在，则返回 `base` 的 `exp` 次幂对 `mod` 取余（比 `pow(base, exp) % mod` 更高效）。
   1. 两参数形式 `pow(base, exp)` 等价于乘方运算符: `base ** exp`。
- `divmod(a, b)`：以两个（非复数）数字为参数，在作整数除法时，返回商和余数。
   1. 对于整数而言，结果与 `(a // b, a % b)` 相同。
   1. 对于浮点数则结果为 `(q, a % b)`，其中 `q` 通常为 `math.floor(a / b)`，但也可能比它小 `1`。

	
### 针对数值的内置函数（续）

- `round(number[, ndigits])`：返回 `number` 舍入到小数点后 `ndigits` 位精度的值。
   1. 如果 `ndigits` 被省略或为 `None`，则返回最接近输入值的整数。
   1. 对于支持 `round()` 方法的内置类型，结果值会舍入至最接近的 10 的负 `ndigits` 次幂的倍数；如果与两个倍数同样接近，则选用偶数。因此，`round(0.5)` 和 `round(-0.5)` 均得出 0 而 `round(1.5)` 则为 2。
   1. `ndigits` 可为任意整数值（正数、零或负数）。如果省略了 `ndigits` 或为 `None`，则返回值将为整数。否则返回值与 `number` 的类型相同。
   1. 对于一般的 Python 对象 `x`, `round` 将委托（delegate）给 `x.__round__()`。

	
### 针对字符串的接口

1. `str.find(sub[, start[, end]])`：返回子字符串 `sub` 在 `s[start:end]` 切片内被找到的最小索引。如果 `sub` 未被找到则返回 -1。
1. `str.index(sub[, start[, end]])`：类似于 `find()`，但在找不到子字符串时会引发 `ValueError`。
1. `str.endswith(suffix[, start[, end]])`：如果字符串以指定的 `suffix` 结束返回 `True`，否则返回 `False`。如果有可选参数 `start`，将从所指定位置开始检查。如果有可选项 `end`，将在所指定位置停止比较。
1. `str.startswith(prefix[, start[, end]])`：如果字符串以指定的 `prefix` 开始则返回 `True`，否则返回 `False`。如果有可选参数 `start`，将从所指定位置开始检查。如果有可选参数 `end`，将在所指定位置停止比较。

	
### 针对字符串的接口（续）

1. `str.capitalize()`：返回原字符串的一个副本（copy），其首个字符大写，其余为小写。
1. `str.casefold()`：返回原字符串消除大小写的副本。 消除大小写的字符串可用于忽略大小写的匹配。
1. `str.replace(old, new[, count])`：返回字符串的副本，其中出现的所有子字符串 `old` 都将被替换为 `new`。如果给出了可选参数 `count`，则只替换前 `count` 次出现。
1. `str.format(*args, **kwargs)`：执行字符串格式化操作。调用此方法的字符串可以包含字符串字面值或者以花括号 `{}` 括起来的替换域。每个替换域可以包含一个位置参数的数字索引，或者一个关键字参数的名称。返回的字符串副本中每个替换域都会被替换为对应参数的字符串值。
1. [更多字符串方法](https://docs.python.org/zh-cn/3.10/library/stdtypes.html#string-methods)。

	
#### 示例

```python
# str.format()
"The sum of 1 + 2 is {0}".format(1+2)                   # 'The sum of 1 + 2 is 3'
"The sum of 1 + 2 is {sum}".format(sum=1+2)             # the same as above

'The quick brown fox jumps over the lazy dog'.endswith('dog')     # True
'The quick brown fox jumps over the lazy dog'.index('foobar')     # ValueError
```

	
### 针对容器的内置全局函数

1. 容器（container）：序列、集合及映射统称为容器。
1. `len()`：获取容器的长度（length），亦即容器成员（或键值对）的个数。
1. `max()`：获取容器中各单元之最大值。
1. `min()`：获取容器中各单元之最小值。

		
### 针对可变序列的内置方法

1. `s.append(x)`：在 `s` 的尾部追加新单元 `x`。
1. `s.clear()`：清除所有成员，变成空序列。
1. `s.copy()`：复制序列；返回一个浅（shallow）拷贝。
1. `s.count(x)`：返回 `x` 在序列中出现的次数。
1. `s.extend(t)`：用 `t` 的内容扩展 `s`。
1. `s.index(x)`：搜索并返回和指定数据 `x` 匹配的（matched）第一个成员之索引值。
1. `s.insert(i, x)`：插入数据 `x` 到指定的位置 `i`。
1. `s.pop()`：提取最后一项，并将其从 `s` 中移除。
1. `s.pop(i)`：提取在 `i` 位置上的项，并将其从 `s` 中移除。
1. `s.remove(x)`：移除和指定数据 `x` 匹配的第一个项。
1. `s.reverse()`：就地（in-place）将序列成员逆序。
1. `s.sort()`：对序列中的成员排序。

	
### 针对序列的内置方法

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
   - `d.copy()`：返回原字典的一个浅拷贝。
   - `d.fromkeys()`：使用指定的键元组以及可选的值构建一个字典。
   - `d.setdefault(key[, default])`：如果字典存在键 `key`，则返回其值。如果不存在，插入值为 `default` 的键 `key`，并返回 `default`。`default` 默认为 `None`。
   - `d.update([other])`：使用来自 `other` 的键值对更新字典，覆盖原有的键。返回 `None`。

		
## 常用模块及其主要接口

1. `io` 模块
1. `sys` 模块

	
### `io` 模块及其主要接口

1) 文件 I/O 和流（stream）的基本概念
2) 文件 I/O 中缓冲区（buffer）的概念。
3) 文件 I/O 的基本操作
   - 打开（open）：以指定的读/写或文本/二进制模式打开指定的文件。
   - 读取（read）：从当前读写位置读取数据并修改当前的读写位置。
   - 写入（write）：在当前读写位置写入指定的数据并修改当前读写位置。
   - 定位（seek）：修改当前的读写位置。
   - 刷新（flush）：将缓冲区中的内容刷新到操作系统（可理解为将缓冲区的内容写入到文件）。
   - 关闭（close）：刷新缓冲区中的内容并关闭文件。

	
4) 文本 I/O（由 `TextIOBase` 类实现）
   - 读取将产生字符串（`str`）对象；写入要求传入 `str` 对象。
   - 会执行新行符（`\n`）的平台相关的转换（在 Windows 上，写入的 `\n` 将被存储为 `\r\n` 两个字符；读取的 `\r\n` 会转换为 `\n` 单个字符）。
   - 采取行缓冲（line-buffering）策略：写入时，遇到 `\n` 才会将缓冲区中的内容刷新到操作系统；否则只会保存到缓冲区——提高读写性能。
   - 可执行文本的编码转换，默认和当前的区域（locale）设置有关；建议使用 UTF-8 编码。
   - `f = open("myfile.txt", "r")`

	
5) 二进制 I/O（由 `BufferedIOBase` 类实现）
   - 读取将产生字节串（`bytes`）对象；写入要求传入类似字节串的对象。
   - 采取块缓冲（block-buffering）策略：写入时，只有缓冲区中的内容达到事先创建的缓冲区大小（通常为 8192 字节）才会将数据刷新到操作系统；否则会保存到缓冲区——提高读写性能。
   - `f = open("myfile.jpg", "rb")`
6) 裸（raw）I/O（由 `RawIOBase` 类实现）
   - 本质上就是无缓冲（unbuffered）的二进制 I/O。
   - `f = open("myfile.jpg", "rb", buffering = 0)`

	
7) 主要接口：
   - `closed`：如果流已关闭，则为 `True`。
   - `close()`：刷新并关闭此流。如果文件已经关闭，则此方法无效。文件关闭后，对文件的任何操作（例如读取或写入）都会引发 `ValueError`。
   - `flush()`：刷新流的写入缓冲区（如果适用）。这对只读和无缓冲流不起作用。
   - `readable()`：如果可以读取流则返回 `True`，否则为 `False`；不可读时，在流上调用 `read()` 方法将引发 `OSError` 错误。
   - `readline(size=-1, /)`：从流中读取并返回一行。如果指定了 `size`，将至多读取 `size` 个字节。
   - `readlines(hint=-1, /)`：从流中读取并返回包含多行的列表。可以指定 `hint` 来控制要读取的行数。

	
8) 主要接口（续）：
   - `seek(offset, whence=SEEK_SET, /)`：将流位置修改到给定的字节 `offset`。`offset` 将相对于由 `whence` 指定的位置进行解析。`whence` 的默认值为 `SEEK_SET`。`whence` 的可用值有：
      * `SEEK_SET` 或 0 -- 流的开头（默认值）；`offset` 应为零或正值。
      * `SEEK_CUR` or 1 -- 当前流位置；`offset` 可以为负值。
      * `SEEK_END` or 2 -- 流的末尾；`offset` 通常为负值。
   - `seekable()`：如果流支持随机访问则返回 `True`。如返回 `False`，则 `seek()`, `tell()` 和 `truncate()` 将引发 `OSError`。
   - `tell()`：返回当前流的位置。

	
9) 主要接口（再续）：
   - `truncate(size=None, /)`：将流的大小调整为给定的 `size` 个字节（如果未指定 `size` 则调整至当前位置）。当前的流读写位置不变。
   - `writable()`：如果流支持写入则返回 `True`。若返回 `False`，则 `write()` 和 `truncate()` 将引发 `OSError`。
   - `writelines(lines, /)`：将行列表写入到流。注意该函数不会为每行新行符，需要自行添加。

	
10) 用法示例；注意在其中使用了 `with` 语句以简化异常处理，且不需要显式（explicitly）调用 `f.close()` 方法。

```python
#!/usr/bin/python3

lines = [
    'line 1\n',
    'line 2\n',
    'line 3\n',
]

with open('sample.txt', 'w') as f:
    f.writelines(lines)

with open('sample.txt', 'r') as f:
    for line in f:
        print(line, end='')

    f.seek(0)
    lines = f.readlines()

    for line in lines:
        print(line, end='')

assert(f.closed)
```

	
### `sys` 模块及其主要接口

1) `sys` 模块中主要包含了系统相关的一些信息，被解释器初始化为指定的可直接使用的对象。
2) `sys.exit([arg])`：退出程序并指定程序的退出值。注：在 Linux Shell 中，一个程序的退出值为 `0` 表示成功。
3) `sys.stdin`、`sys.stdout`、`sys.stderr`：标准输入、标准输出和标准错误对应的文件对象。
4) `sys.argv`：传递给 Python 脚本的命令行参数（列表）；其中 `argv[0]` 为脚本的名称
5) `sys.path`：一个字符串列表，包含了模块的搜索路径。

	
### `sys` 模块及其主要接口（续）

6) `sys.copyright`：一个字符串，包含了 Python 解释器有关的版权信息。
7) `sys.platform`：一个字符串，包含平台标识符，可用于判断底层平台（操作系统）是 Windows、Linux 还是 macOS 等。
8) `sys.version`：一个包含 Python 解释器版本号加编译版本号以及所用编译器等额外信息的字符串。 此字符串会在交互式解释器启动时显示。
9) `sys.version_info`：一个包含版本号五部分的元组: `major`, `minor`, `micro`, `releaselevel` 和 `serial`。对应于 Python 版本 3.10.0 的 `version_info` 值为 `(3, 10, 0, 'final', 0)`。可用来判断 Python 解释器的版本，用于向后兼容性处理。

		
## 深入理解递归调用

- 递归实现 `pow()` 函数
   1. 指数幂的求解满足递推（recurrence）公式：P(n) = n * P(n - 1)；
   1. 当 n 为 0 时递推终止：P(0) = 1。

```python
#!/usr/bin/python3

def make_indent(n):
    s = ''
    for x in range(n):
        s += ' '
    return s

def my_pow(f, n, i = 0):
    indent = make_indent(i)
    print('{3}Call #{0}: my_power({1}, {2})'.format(i, f, n, indent))
    if n == 0:
        r = 1
    else:
        r = f * my_pow(f, n - 1, i + 1)

    print('{2}Return {1} for Call #{0}'.format(i, r, indent))
    return r

print('The value of 2 raised to the power of 8 is', my_pow(2, 8))
```

	
### 运行效果

```console
$ ./pow-recursion.py
Call #0: my_power(2, 8)
 Call #1: my_power(2, 7)
  Call #2: my_power(2, 6)
   Call #3: my_power(2, 5)
    Call #4: my_power(2, 4)
     Call #5: my_power(2, 3)
      Call #6: my_power(2, 2)
       Call #7: my_power(2, 1)
        Call #8: my_power(2, 0)
        Return 1 for Call #8
       Return 2 for Call #7
      Return 4 for Call #6
     Return 8 for Call #5
    Return 16 for Call #4
   Return 32 for Call #3
  Return 64 for Call #2
 Return 128 for Call #1
Return 256 for Call #0
The value of 2 raised to the power of 8 is 256
```

	
### 递推的陷进

1. 过深的递归调用可能耗尽系统内存（栈溢出）； 在 Python 中有两个 `sys` 接口可获取或设置解释器内部的递归调用深度（depth）极值（limit）：
   - `sys.getrecursionlimit()`：获取当前的递归调用极值。
   - `sys.setrecursionlimit(limit)`：设置新的递归调用极值。
1. 不恰当的递归调用会极大降低性能。

		
## 要点回顾

1. 掌握递归的概念并积极实践。
1. 掌握类的基本定义和使用方法。
1. 掌握针对不同数据类型的常用内置方法或函数。
1. 掌握 `io` 及 `sys` 模块的常用接口及其用法。

		
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

