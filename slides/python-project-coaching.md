# Python 综合练习辅导

1. Python 程序的模块化管理
1. 软件架构设计要点
1. 从排序说起
1. Python 编码风格
1. 可测试性及单元测试
1. Python 程序的调试

		
## Python 程序的模块化管理

1. 将复杂软件划分为不同的模块，有利于项目的管理和维护。
1. 复杂软件（如操作系统）通常是由多个不同层级的软件构成的一个堆叠栈（software stack）。

	
- Android 架构图

<img class="r-frame" style="height:640px;width:auto;" src="assets/android-framework.svg" />

	
### 看 Python 3.10 标准库的目录结构

- 模块（module）和包（package）：模块通常保存为单独的 Python 源文件；而包则通过目录组织。
- Python 库的搜索路径，可通过 `sys.path` 获得；默认搜索当前目录。
- 以标准库中的 `curses` 模块为例：

```console
$ cd /usr/lib/python3.10/
$ tree curses/
curses/
├── ascii.py
├── has_key.py
├── __init__.py
├── panel.py
├── __pycache__
│   ├── ascii.cpython-310.pyc
│   ├── has_key.cpython-310.pyc
│   ├── __init__.cpython-310.pyc
│   ├── panel.cpython-310.pyc
│   └── textpad.cpython-310.pyc
└── textpad.py
```

	
### `import` 语句

- `import x`：装载模块 `x.py`，或包 `x` 中的 `__init__.py` 模块。
- `from x import y`：从包 `x` 装载 `y.py` 模块。
- 模块通常被实现为类；一个模块一个类。
- 包则是多个相关类的合集，被置于同一目录中维护。

	
### `import` 语句的多种用法

- `import io`：装载 `io` 模块（`io.py` 文件）。
- `import curses`：从 `curses` 包中装载默认模块（`__init__.py` 文件）。
- `from curses import textpad`：从 `curses` 包中装载并执行 `textpad.py` 文件。
- `from curses import textpad as textinput, panel`：从 `curses` 包中装载并执行 `textpad.py` 文件，将模块取名为 `textinput`，同时装载 `panel.py` 模块。
- `from curses import *`：从 `curses` 包中装载所有的模块文件（太粗暴，不建议如此使用）。

	
### 使用 `import` 装载项目内部模块

- 复杂软件的源文件也应该按照模块在树状目录中进行组织，如：

```console
$ tree project-bastet/
project-bastet/
├── bastet.py
├── shapes.py
└── utils
    ├── misc.py
    └── timing.py
```

- `import foo.bar`：在 `./foo` 目录中装载 `bar` 模块（或 `./foo/bar` 目录中的 `__init__.py` 模块）。
- `import foo.bar as foobar`：同上，别名为 `foobar`。
- `from foo import bar`：在 `./foo` 目录中装载 `bar` 模块（或 `./foo/bar` 目录中的 `__init__.py` 模块）。
- 注意和系统标准库或第三方库重名的问题。

		
## 软件架构设计要点

- 模块划分原则
   1. 可被重复使用的功能应被实现为独立模块。
   1. 各个模块的功能应保持单一，接口的定义要清晰。
   1. 构成合理的软件堆叠栈，绝对不能依赖上层模块，避免同级模块之间的依赖关系。
- 模块实现原则：
   1. 除必要的常数外，模块的实现不要使用用于提示用户的字符串字面值。
   1. 模块的实现中不要调用依赖标准输入和标准输出的 `print()`、`input()` 等函数（测试代码除外）。
- 软件的根本：如何组织、管理和处理数据
   1. 组织：对需求做适当抽象，使用合理的数据类型和数据结构来表达目标需求对象。
   1. 管理：数据的变化体现程序的运行逻辑。
   1. 处理：使用合适的算法高效处理数据。

	
### 综合练习分析

- 分析综合练习应该使用什么样的数据结构和 Python 数据类型。
- 分析综合练习中哪些功能可以构成模块。
- 分析综合练习中有哪些关键的算法。
- 综合练习：
   1. 贪婪
   1. 2048
   1. 贪吃蛇
   1. 数独
   1. 打字员
   1. 俄罗斯方块

		
## 从排序说起

- 生活中的排序无处不在。
- 推荐阅读：[十种排序算法](https://www.runoob.com/w3cnote/ten-sorting-algorithm.html)

	
### Python 的排序接口

1. `sorted(iterable, /, *, key=None, reverse=False)`：内置函数，可针对任意可迭代对象进行排序，返回一个排序后的列表。
   - `key` 参数用于指定一个函数，该函数可从待排序的对象中返回一个用于排序的键。
   - `reverse` 参数用于指定是否执行反序操作；默认从小到大排序。
1. `list.sort(*, key=None, reverse=False)`：列表的方法，对列表执行就地排序；返回 `None`。
   - 只能用于列表，但比 `sorted()` 效率更高。

```python
sorted("This is a test string".split(), key=str.lower)
['a', 'is', 'string', 'test', 'This']
```

	
### 回调函数

- 回调函数（callback function）被其他模块调用的函数。

```python
student_tuples = [
    ('李华', 'A', 15),
    ('张丽', 'B', 12),
    ('王红', 'B', 10),
]

def age_from_student_tuple(st):
    return st[2]
sorted_students = sorted(student_tuples, key=age_from_student_tuple)
```

	
### 匿名函数

- 匿名函数（lambda）：解决为简单工作定义完整函数带来的麻烦。
- lambda 函数是匿名的（不需要指定函数名称），只能赋值给变量或作为参数传递给其他函数来使用。

```python
student_tuples = [
    ('李华', 'A', 15),
    ('张丽', 'B', 12),
    ('王红', 'B', 10),
]

def age_from_student_tuple(st):
    return st[2]
sorted_students = sorted(student_tuples, key=lambda st: st[2])
```

	
### `operator` 模块

- `operator` 模块提供了一套与Python的内置运算符对应的高效率函数。例如 `operator.add(x, y)` 与表达式 `x+y` 相同。
- `operator` 模块的方法返回一个可调用对象，可当做函数传递给 `sorted()` 等函数或方法使用。
- [官方文档](https://docs.python.org/zh-cn/3.10/library/operator.html)

```python
student_tuples = [
    ('李华', 'A', 15),
    ('张丽', 'B', 12),
    ('王红', 'B', 10),
]

from operator import itemgetter, attrgetter
sorted_students = sorted(student_tuples, key=itemgetter(2))
```

	
### `repr()` 和 `eval()` 函数

- `repr(x)` 函数返回一个字符串，该字符串是 `x` 的可打印表述（representation）形式；该字符串可传递给 `eval()` 将其转换为一项 Python 数据。
- 用户自定义类可通过定义 `__repr__` 这一特殊方法为 `repr()` 函数提供自定义的表述形式。

	
- `__repr__` 和 `__str__` 的区别。

```python
class Student:
    def __init__(self, name, grade, age):
        self.name = name
        self.grade = grade
        self.age = age
    def __repr__(self):
        return repr((self.name, self.grade, self.age))
        # return repr({'name': self.name, 'grade': self.grade, 'age': self.age})

student_objects = [
    Student('李华', 'A', 15),
    Student('张丽', 'B', 12),
    Student('王红', 'B', 10),
]

sorted_students = sorted(student_objects, key=attrgetter('age'))
# without __repr__ method:
# [<__main__.Student object at 0x10290ee80>, <__main__.Student object at 0x10290ef10>, <__main__.Student object at 0x10290efd0>]

# use tuple in __repr__ method:
# [('王红', 'B', 10), ('张丽', 'B', 12), ('李华', 'A', 15)]

# use dict in __repr__ method:
# [{'name': '王红', 'grade': 'B', 'age': 10}, {'name': '张丽', 'grade': 'B', 'age': 12}, {'name': '李华', 'grade': 'A', 'age': 15}]
```

	
### `repr()` 和 `eval()` 函数（续）

- `eval(expression[, globals[, locals]])` 函数对一个符合 Python 语法的字符串表达式 `expression` 进行求值；`globals` 和 `locals` 用于指定对表达式求值时的全局或局部变量，通常为字典，包含了变量名和对应数据构成的键值对。
- 使用 `repr()` 可在调试和日志中输出对象的字符串表述，便于理解和排查问题：人机共读。
- 使用 `repr()` 函数可将复杂数据转换为字符串保存到文件中，方便读取和查看：一种简单的数据持久化方法。
- 将 `repr()` 返回的字符串再使用 `eval()` 函数即可将对应的内容转换为 Python 对象：一种对象的序列化和反序列化方法。

		
## Python 编码风格

- 为何编码风格如此重要？
- 编码风格涉及哪些方面？
   - 代码的排版，包括缩进、行的最大长度、在哪里绕行等
   - 空格的使用
   - 注释
   - 命名习惯或规范
   - 其他事项，如全局变量的使用等
- [PEP 8 – Style Guide for Python Code](https://peps.python.org/pep-0008/)

		
## 可测试性及单元测试

- 一定要对独立的模块进行单元测试。
- 将单元测试用例组织成适当的数据结构，解耦测试用例和测试代码，以方便添加新的测试用例。
- 使用下面的代码，在模块被解释器直接调用时执行单元测试：

```python
if __name__ == '__main__':
    print('Hello from main method of foo.py')
    # call test functions here
```

		
## 使用 `pdb` 模块调试 Python 程序

1. 调试器（debugger）有用，但不要过度依赖。
1. `$ python3 -m pdb foo.py`

	
### `pdb` 常用命令

- `l`：查看源代码。
- `ll`：查看当前函数或模块的所有源代码。
- `b [lineno | filename:lineno | functionname]`：设置断点（break point）。
- `tbreak [lineno | filename:lineno | functionname]`：设置临时（temporary）断点，也就是一次性断点。
- `cl [filename:lineno | bpnumber [bpnumber ...]]`：清除断点。
- `p expression`：打印表达式的值。

	
### `pdb` 常用命令（续）

- `s`：单步（step）执行下一行，会进入函数体内。
- `n`：单步执行下一行，但不进入函数体。
- `r`：若当前在函数中，则执行直到函数返回前，否则执行下一行。
- `c`：继续执行直到终止或者下个断点。
- `unt lineno`：执行到指定的行号处。
- `j lineno`：从当前位置跳过代码直接到指定行号处。
- `a`：在函数中时，打印传递给函数的参数及参数值。
- `w`：打印函数的调用栈帧信息。
- `whatis expression`：打印表达式类型。
- `interact`：启动解释器的交互模式。
- `q`：退出调试器。

		
## 后面学什么？

1. 《信奥筑基班》：C++ 编程语言，掌握高精度自然数算术的 C++ 实现。
1. 《信奥初级班》：信息学奥林匹克（入门级）竞赛大纲规定的算法及数据结构。
1. 《信奥提高班》：信息学奥林匹克（提高级）竞赛大纲规定的算法及数据结构。
1. 《数学素养课》：初等数论、离散数学结构等信息学奥林匹克竞赛大纲规定的数学知识。

