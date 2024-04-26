# Python 大作业辅导

1. Python 程序的模块化管理
1. 软件架构设计要点
1. Python 编码风格
1. 可测试性及单元测试
1. Python 程序的调试方法

		
## Python 程序的模块化管理

1. 将复杂软件划分为不同的模块，有利于项目的管理和维护。
1. 复杂软件（如操作系统）构成了由多个不同层级的软件构成的一个堆叠结构（software stack）。

	
- Android 架构图

<img class="r-frame" style="height:auto;width:100%;" src="assets/android-framework.svg" />

	
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

- `import x`：装载模块 `x`，或包 `x` 中的 `__init__.py` 模块。
- `from x import y`：从包 `x` 装载指定的模块。
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
   1. 可被重复使用的功能应被独立模块。
   1. 各个模块的功能应保持单一，接口的定义要清晰。
   1. 构成合理的软件堆叠栈，绝对不能依赖上层模块，避免同级模块之间的依赖关系。
- 模块实现原则：
   1. 模块的实现中不要调用依赖标准输入和标准输出的 `print()`、`input()` 等函数（测试代码除外）。
- 软件的根本：如何组织、管理和处理数据
   1. 组织：对需求做适当抽象，使用合理的数据类型和数据结构来表达目标需求对象。
   1. 管理：数据的变化体现程序的运行逻辑。
   1. 处理：使用合适的算法高效处理数据。

	
### 大作业分析

- 分析大作业应该使用什么样的数据结构和 Python 数据类型。
- 分析大作业中哪些功能可以构成模块。
- 分析大作业中有哪些关键的算法。
- 大作业：
   1. 贪婪
   1. 2048
   1. 贪吃蛇
   1. 数独
   1. 打字员
   1. 俄罗斯方块

		
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

		
## Python 程序的调试方法


		
## AI 实战班内容介绍

1. 

