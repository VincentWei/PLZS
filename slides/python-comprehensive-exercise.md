# Python 综合练习

1. 作业回顾
1. 综合练习可选项目
1. 时间的获取和转换
1. 终端编程
1. 伪随机数
1. 要点回顾
1. 综合作业注意事项

		
## 作业回顾

### 将元组成员作为函数的位置参数传入

```python
#!/usr/bin/python3

test_cases = (
    {
        'args': 5,
        'expected_result': [0, 1, 2, 3, 4]
    },
    {
        'args': (5,),
        'expected_result': [0, 1, 2, 3, 4]
    },
)

for test_case in test_cases:
    input_params = test_case['args']
    if isinstance(test_case['args'], tuple):
        result = list(my_range(*test_case['args']))
    else:
        result = list(my_range(test_case['args']))
```

- 类似地，能否将字典作为关键词参数传入函数？

	
### `map()` 函数和可迭代对象

- `map(function, iterable, ...)`：该函数返回一个迭代器；在该迭代器上迭代时，会将 `function` 作用于 `iterable` 中的每一项并返回结果。
- 迭代器（iterator）：一个可以记住遍历位置的对象，对应的类要实现 `__next__()` 方法。
- 可迭代（iterable）对象：实现了 `__iter__()` 方法的类的对象。
- Python 序列、映射以及实现了 `__iter__()` 方法的类都是可迭代的。

```ptyon
def my_print(*args, sep=' ', end='\n', file=None, flush=False):
    contents = sep.join(map(str, args)) + end
```

	
### 使用迭代器实现斐波那契数列

- 在可迭代对象上使用 `iter()` 函数可以构造迭代器；迭代器由类的 `__iter__()` 方法创建。
- 在迭代器上调用 `next()` 函数，将调用迭代器对象的 `__next__()` 方法获取下个数据。
- 可迭代对象可用于 `for` 循环以及支持可迭代对象的函数或方法。

```ptyon
#!/usr/bin/python3

class FibIterator(object):
    def __init__(self):
        self.a = 0
        self.b = 1

    def __next__(self):
        r = self.a
        self.a, self.b = self.b, self.a + self.b
        return r

class Fibonacci(object):
    def __init__(self):
        pass

    def make_list(self, maxn):
        l = []
        a, b = 0, 1
        while a <= maxn:
            l += (a, )
            if a == maxn or b > maxn:
                break
            a, b = b, a + b
        return l

    def __iter__(self):
        return FibIterator()

fib = Fibonacci()

print("Use make_list() to generate Fibonacci numbers less than 50:")
fibs = fib.make_list(50)
for x in fibs:
    print(x)

print("Use iter() and next() to generate Fibonacci numbers less than 50:")
it = iter(fib)
while True:
    x = next(it)
    if x > 50:
        break
    print(x)

print("Use `for x in iterable` statment to generate Fibonacci numbers less than 50:")
for x in fib:
    if x > 50:
        break
    print(x)

```

	
### 处理构建对象时的传入非法值

```ptyon
class Square:
    def __init__(self, side):
        if not isinstance(side, float) or side < 0:
            raise(ValueError)
        self.side = side
```

或者，

```ptyon
class Square:
    def __init__(self, side):
        self.side = float(side)
        if self.side < 0:
            raise(ValueError)
```

	
### 恰当命名，保持简洁

```ptyon
class Square:
    def __init__(self, side):
        self.side = float(side)
        if self.side < 0:
            raise(ValueError)

    # Don't name like calculate_perimeter();
    # calc_perimeter() may be better.
    def perimeter(self):
        return 4 * self.side

    # Don't name as calculate_area();
    # calc_area() may be better.
    def area(self):
        return self.side ** 2
```

	
### Vim 默认设置

编辑 `~/.vimrc` 文件，添加如下设置：

```vim
set expandtab
set tabstop=4
set shiftwidth=4
set cindent
set list
set listchars=tab:▷⋯,trail:◇
set cc=80
set ruler
syntax on
```

		
## 综合练习可选项目

- 参考如下游戏中的一款，用 Python 实现（难度逐步提高）：
   1. 2048（`$ sudo apt install 2048 && 2048`）
   1. 贪婪（`$ sudo apt install greed && greed`）
   1. 数独（`$ sudo apt nudoku && nudoku`）
   1. 打字员（`$ sudo apt install gtypist && gtypist`）
   1. 俄罗斯方块（`$ sudo apt install bastet && bastet`）

		
## 时间的获取和转换

- 有关时间的知识点
- `time` 模块
- `datetime` 模块

	
### 有关时间的知识点

1. `epoch`：Unix 类系统的计时起点，即 1970 年 1 月 1 日 00:00:00（UTC）；也称作“Unix 纪元”起点。
1. `纪元时间（seconds since the epoch）`，也称为 `Unix 时间`：自 epoch 以来的秒数，通常不包括润秒（leap seconds）。
1. UTC（协调世界时，Coordinated Universal Time）：早先的 GMT（格林威治时间）。
1. DTS（夏时制，Daylight Saving Time）：某些时区（timezone）为在夏季最大化利用日光而进行的时间调整，通常比冬季时间快一个小时。
1. 本地时间（local time）指对应当前地区（时区）的时间。
1. 四种常见的时区表示方法：
   - 保留名称，如 `UTC`、`GMT`
   - 国家，如 `PRC`、`GB`
   - 城市，如 `Asia/Shanghai`、`Pacific/Auckland`、`US/Michigan`
   - UTC 偏移量，如 `+0800`

	
### 有关时间的知识点（续）

1. 操作系统使用多个时钟（clock）来满足程序的不同计时需求：
   - 墙钟（wall clock）指和人类墙上挂的钟表所指时间一致的时钟，也就是 Unix 时间；墙钟也称为实时（real time）时钟。
   - 单调时钟（monotonic clock）指一个始终单调增加的时钟，不会记录系统暂停的时间，也不会因为调整系统时间而变化。
   - 引导时间时钟（boot time clock）等同于单调时钟，但同时记录了系统暂停的时间。
   - 国际原子时间（International Atomic Time，TAI）时钟，基于墙钟并插入润秒。
   - 性能时钟，用于记录当前进程或线程消耗的 CPU 时间。
1. Linux 系统中设置时区：`tzselect` 命令。
1. 千年虫和 Unix 时间溢出问题。
1. 操作系统时间的初始化过程。

	
### `time` 模块

1. 用于获取操作系统维护的各类时钟对应的时间，并执行时区相关的转换
1. [官方文档](https://docs.python.org/zh-cn/3.10/library/time.html)

	
#### `time` 模块主要接口

- `time.time()`：返回以秒为单位的纪元时间；浮点数。
- `time.time_ns()`：返回以纳秒为单位的纪元时间；整数。
- `time.monotonic()`：返回以秒为单位的单调时钟时间；浮点数。
- `time.monotonic_ns()`：返回以纳秒为单位的单调时钟时间；整数。
- `time.thread_time()`：返回以秒为单位的当前线程使用的 CPU 时间；浮点数。
- `time.thread_time_ns()`：返回以纳秒为单位的当前线程使用的 CPU 时间；整数。
- `time.process_time()`：返回以秒为单位的当前进程使用的 CPU 时间；浮点数。
- `time.process_time_ns()`：返回以纳秒为单位的当前进程使用的 CPU 时间；整数。
- `time.sleep(secs)`：休眠当前线程 `secs` 秒（浮点数）。

	
#### `time` 模块主要接口

- `time.gmtime([secs])`：将以秒为单位的纪元时间转换为 UTC `struct_time`。
- `time.localtime([secs])`：将以秒为单位的纪元时间转换为本地时区的 `struct_time`。
- `class time.struct_time`：`gmtime()`、`localtime()` 返回的命名元组对象（named tuple：继承自元组的类，同时增加了通过名称访问元组中各个成员的能力）。
- `time.strftime(format[, t])`：将 `struct_time` 表示的时间转换为字符串，如 `2024年 04月 18日 星期四 10:21:59 CST`。
- `time.strptime(string[, format])`：根据格式解析表示时间的字符串，返回一个 `struct_time` 对象。

	
#### `class time.struct_time`

| 索引 | 属性 | 值 |
| - | - | - |
| 0 | `tm_year` | 如 1993 |
| 1 | `tm_mon` | 范围 [1, 12] |
| 2 | `tm_mday` | 范围 [1, 31] |
| 3 | `tm_hour` | 范围 [0, 23] |
| 4 | `tm_min` | 范围 [0, 59] |
| 5 | `tm_sec` | 范围 [0, 61]；取值 60 用于表示润秒 |
| 6 | `tm_wday` | 范围 [0, 6]；周一为 0 |
| 7 | `tm_yday` | 范围 [1, 366] |
| 8 | `tm_isdst` | 0，1 或 -1；-1 表示夏令时未知 |
| N/A | `tm_zone` | 时区名称的缩写 |
| N/A | `tm_gmtoff` | UTC 以东偏移量的秒数 |

	
### `datetime` 模块

- Gregorian calendar：格里高利历法，也就是公元纪年法；每个日期有一个格里高利历的序号（oridinal），其中公元 1 年 1 月 1 日的序号为 1。
- ISO 6801：日期及时间格式的国际标准，通常具有类似 `2024-04-18 10:58:23.283+08:00` 的形式。
- [`datetime` 模块](https://docs.python.org/zh-cn/3.10/library/datetime.html)：支持日期和时间的数学运算、格式化输出和数据的操作。
- `datetime` 模块提供的类继承关系：
   - `object`
      - `timedelta`
      - `tzinfo`
         - `timezone`
      - `time`
      - `date`
         - `datetime`

	
`timedelta` 类

```python
from datetime import timedelta

year = timedelta(days=365)
ten_years = 10 * year
# datetime.timedelta(days=3650)

ten_years.days // 365
# 10

nine_years = ten_years - year
nine_years
# datetime.timedelta(days=3285)

three_years = nine_years // 3
three_years, three_years.days // 365
# (datetime.timedelta(days=1095), 3)
```

	
`date` 类

```python
from datetime import date
d = date.fromordinal(730920) # 730920th day after 1. 1. 0001
d
# datetime.date(2002, 3, 11)

d.isoformat()
# '2002-03-11'

d.strftime("%d/%m/%y")
# '11/03/02'

d.strftime("%A %d. %B %Y")
# 'Monday 11. March 2002'

d.ctime()
# 'Mon Mar 11 00:00:00 2002'

'The {1} is {0:%d}, the {2} is {0:%B}.'.format(d, "day", "month")
# 'The day is 11, the month is March.'
```

	
`datetime` 类

```python
from datetime import datetime, date, time, timezone

# 使用 datetime.combine()
d = date(2005, 7, 14)
t = time(12, 30)
datetime.combine(d, t)
# datetime.datetime(2005, 7, 14, 12, 30)

# 使用 datetime.now()
datetime.now()
# datetime.datetime(2007, 12, 6, 16, 29, 43, 79043)   # GMT +1

datetime.now(timezone.utc)
# datetime.datetime(2007, 12, 6, 15, 29, 43, 79060, tzinfo=datetime.timezone.utc)

# 使用 datetime.strptime()
dt = datetime.strptime("21/11/06 16:30", "%d/%m/%y %H:%M")
dt
# datetime.datetime(2006, 11, 21, 16, 30)
```

		
## 终端编程

1. ANSI 转义序列
1. `colorist` 模块
1. `curses` 模块

	
### ANSI 转义序列

- ANSI 转义序列（escape sequence）可在向终端输出的字符中插入 `\x1B` 打头的转义代码，从而改变其后字符的颜色、粗斜体、下划线、闪烁等属性。
- 亦可使用 ANSI 转义序列控制光标的位置、滚屏、清屏等功能。

```python
print("这段文字中的颜色名称将以对应的颜色显示："
        "\x1b[31m红色\x1b[0m、\x1b[32m绿色\x1b[0m、\x1b[34m蓝色\x1b[0m。")
```

	
### ANSI 转义序列（续）

- 下面的示例程序显示当前时间并不停更新。
- 其中使用了 `sys`、`time` 和 `datetime` 模块。

```python
#!/usr/bin/python3

from datetime import datetime
import time
import sys

timestr = ''
def show_time():
    global timestr
    new_timestr = datetime.now().isoformat(timespec='seconds')

    if timestr != new_timestr:
        print('\033[1G\x1b[31m', new_timestr, '\x1b[0m', sep='', end='')
        sys.stdout.flush()
        timestr = new_timestr

while True:
    try:
        time.sleep(0.5)
        show_time()
    except KeyboardInterrupt:
        print()
        sys.exit(0)
```

	
### `colorist` 模块

- `colorist` 是一个简单的第三方 Python 模块，一定程度上简化了控制终端字符属性的操控。
- 官方文档[链接](https://jakob-bagterp.github.io/colorist-for-python/)。
- 安装：`$ pip install colorist`。
- 用法：

```python
import colorist
from colorist import Color

print(f"{Color.RED}This text is in RED{Color.OFF}!")

colorist.effect_blink("CYAN and BLINKING!", Color.CYAN)
```

	
### `curses` 模块

- `curses` 模块是 Unix 系统上一个广泛应用的字符终端操作函数库 `ncurses` 的 Python 封装，主要用来简化终端编程，比如移动光标、滚动屏幕、擦除区域、直接获取键盘输入等。
- 在类 Unix 系统中，在全屏字符终端应用的开发中，`ncurses` 的使用较为广泛，比如 Linux 上的文件管理器 `mc`。
- `curses` 隐藏了底层终端类型的差异，提供了一个简单的窗口和面板抽象机制（非重叠），但未提供更加抽象的用户界面（user interface）元素类型，比如按钮、复选框、对话框、菜单等。
- [用 Python 进行 Curses 编程](https://docs.python.org/zh-cn/3.10/howto/curses.html)。

	
#### `curses` 的初始化和终止

- 初始化

```python
import curses

stdscr = curses.initscr()       # 返回一个代表整个屏幕的窗口对象。

curses.noecho()                 # 关闭输入回显。
curses.cbreak()                 # 关闭标准输入的缓冲模式并进入 `cbreak` 模式。
                                # 之后，用户的按键将立即被上报给应用程序。

stdscr.keypad(True)             # 开启小键盘的翻译功能，上下左右等特殊按键将
                                # 被翻译为 curses 定义的常量，如 curses.KEY_UP。
```

- 终止

```python
stdscr.keypad(False)            # 关闭小键盘的翻译功能。
curses.nocbreak()               # 关闭 `cbreak` 模式。
curses.echo()                   # 开启回显模式。
curses.endwin()                 # 还原终端到原始模式。
```

	
#### 使用包装器简化

- 由于终端模式的改变，若在初始化 `curses` 后程序出现异常而没有执行终止操作，会严重影响后续的命令行操作。
- 通常应使用包装器（wrapper）完成终端的初始化和终止操作，并优雅地（gracefully）处理未被捕获的异常。
- 思考：初始化 `curses` 模块之后，`print()` 和 `input()` 函数的行为会发生变化吗？

```python
import curses

def main(stdscr):
    try:
        # event loop here

    except KeyboardInterrupt:
        return

curses.wrapper(main)
```

	
#### 常用接口

- `curses.newwin(nlines, ncols)` 或者 `curses.newwin(nlines, ncols, begin_y, begin_x)`：创建一个实际的窗口（Window）。
- `curses.newpad(nlines, ncols)`：创建一个虚拟的窗口（亦称为面板，pad）。
- `window.clear()`：清空窗口内容。
- `window.addch(ch[, attr])` 或者 `window.addch(y, x, ch[, attr])`：向窗口（的指定位置）添加字符。
- `window.addstr(str[, attr])` 或者 `window.addstr(y, x, str[, attr])`：向窗口（的指定位置）添加字符串；`attr` 是可选的颜色、加粗、闪烁等样式（style）信息。
- `window.refresh([pminrow, pmincol, sminrow, smincol, smaxrow, smaxcol])`：刷新窗口或面板。刷新面板时，需要指定源（面板）左上角坐标以及目标位置的左上角坐标及左下角坐标。

	
#### 注意事项

- 屏幕左上角为坐标原点，x 轴水平向右，y 轴竖直向下。
- 在 `curses` 中指定坐标时，先是行（y）后是列（x）。
- 在窗口、子窗口或面板之外写入字符会引发 `curses.error` 异常。

	
#### 字符的颜色和属性

- 颜色对（color pair）：用于定义字符前景色和背景色的一对颜色。在终端编程中，需要指定颜色对的编号，且 0 号颜色对始终为黑底白字。
- 在调用 `window.addch()` 和 `window.addstr()` 函数时，可通过最后一个 `attr` 参数指定字符或者字符串的颜色对，并和其他属性一并使用。
- 在 `window.addstr()` 函数中，字符串中使用 ANSI 转义序列不会生效。
- 常用字符属性：
   1. `curses.A_BLINK`：闪烁文本。
   1. `curses.A_BOLD`：超亮或粗体文本。
   1. `curses.A_DIM`：半明亮文本。
   1. `curses.A_REVERSE`：反相显示文本。
   1. `curses.A_STANDOUT`：可用的最佳突出显示模式。
   1. `curses.A_UNDERLINE`：带下划线的文本。

	
#### 自定义颜色对

- 由于不同终端类型对颜色的支持能力不同，故而我们通常仅使用八种标准颜色定义颜色对，或者在支持丰富颜色的情形下在程序中做特殊处理。

```python
curses.use_default_colors()     # 调用该函数后，可使用 -1 指定透明背景色

# 使用标准颜色和透明色自定义颜色对；注意 0 号颜色对不可更改，始终为白色（前景色）
color_pairs = 1
for c in (curses.COLOR_BLUE, curses.COLOR_CYAN, curses.COLOR_GREEN,
        curses.COLOR_MAGENTA, curses.COLOR_RED, curses.COLOR_YELLOW,
        curses.COLOR_BLACK):
    curses.init_pair(color_pairs, c, -1)
    color_pairs += 1

# 使用时，调用 curses.color_pair() 函数
stdscr.addstr(new_timestr, curses.color_pair(1) | curses.A_BLINK)
```

	
#### 用户输入

- `window.timeout(delay)`：设置阻塞或非阻塞读取行为：
   - 如果 `delay` 为负值，则会使用阻塞读取（这将一直等待用户输入）。
   - 如果 `delay` 为零，则会使用非阻塞读取，没有输入时 `getch()` 将返回 -1。
   - 如果 `delay` 为正值，则 `getch()` 将阻塞 `delay` 毫秒，若此期间仍无输入将返回 `-1`。
- `window.getch([y, x])`：获取一个按键对应的字符；键盘上的功能键、小键盘键等按键是由大于 255 的数值表示的。在非阻塞模式下，如果没有输入则返回 -1，阻塞模式下会等待直至有键被按下。
- `window.getkey([y, x])`：获取一个按键对应的字符但返回一个字符串而不是一个整数。功能键、小键盘键和其他特殊键则是返回一个包含键名的字符串，如 `KEY_UP`。在非阻塞模式下，如果没有输入则引发一个异常。

	
#### 其他接口

- `window.move(new_y, new_x)`：移动光标至 `(new_y, new_x)`。
- `window.border([ls[, rs[, ts[, bs[, tl[, tr[, bl[, br]]]]]]]])`：绘制窗口边框，可指定左、右、顶、底边线以及左上角、右上角、左下角、右下角的字符。
- `window.clrtoeol()`：从光标位置开始擦除直至行尾。
- `window.clrtobot()`：从光标位置开始擦除直至窗口末端：光标以下的所有行都会被删除，然后会执行 `clrtoeol()` 的等效操作。
- `window.scroll([lines=1])`：将屏幕或滚动区域向上滚动 `lines` 行。
- `window.keypad(flag)`：如果 `flag` 为 `True`，则某些键（小键盘键、功能键等）生成的转义序列将由 curses 解析为整数。如果 `flag` 为 `False`，转义序列将保持原样。

	
#### 示例程序

- 使用不同的颜色显示当前时间：

```python
#!/usr/bin/python3

import curses
from datetime import datetime
import time
import sys

chattrs = (curses.A_BLINK, curses.A_BOLD, curses.A_DIM, curses.A_REVERSE, curses.A_STANDOUT, curses.A_UNDERLINE)

timestr = ''
def show_time(stdscr, row):
    global timestr
    new_timestr = datetime.now().isoformat(timespec='seconds')

    if timestr != new_timestr:
        global color_pairs
        if row >= 0:
            stdscr.addstr(row, 0, new_timestr,
                    curses.color_pair(row % color_pairs) | chattrs[row % len(chattrs)])
        else:
            stdscr.addstr(new_timestr,
                    curses.color_pair(row % color_pairs) | chattrs[row % len(chattrs)])
        stdscr.refresh()
        timestr = new_timestr
        return True

    return False

def event_loop(stdscr):
    max_row, max_col = stdscr.getmaxyx()
    row = 0
    while True:
        ch = stdscr.getch()
        if ch == ord('q'):      # the user press `q`
            return
        elif ch != -1:          # any other key pressed
            row = 0
            if show_time(stdscr, row):
                row = 1
        else:                   # no input
            if show_time(stdscr, row):
                row += 1
                if row >= max_row:
                    row = 0

def main(stdscr):
    try:
        global color_pairs
        # Initialize the color pairs by using standard colors as
        # foreground and the transparent color (-1) as background.
        color_pairs = 1
        curses.use_default_colors()
        for c in (curses.COLOR_BLUE, curses.COLOR_CYAN, curses.COLOR_GREEN,
                curses.COLOR_MAGENTA, curses.COLOR_RED, curses.COLOR_YELLOW,
                curses.COLOR_BLACK):
            curses.init_pair(color_pairs, c, -1)
            color_pairs += 1

        stdscr.clear()
        stdscr.timeout(100)     # 100ms
        event_loop(stdscr)
    except KeyboardInterrupt:       # If the user pressed ^C
        return

curses.wrapper(main)
```

		
## 伪随机数

- 随机数的意义
- 计算机有两种随机数产生方法，一种是伪随机数，一种由内核收集各种随机事件（如按键速度、鼠标位置等）产生。前者常用于非关键领域，而后者更接近于真随机数。
- 伪随机数（pseudo random number）的产生基于一个种子（seed），然后使用固定的算法生成一串看似随机的数值：
   - 种子值通常取系统的纪元时间。
   - 种子值和算法确定时，生成的随机数序列是固定的。
   - 知道随机数序列中的两个随机值之后，其后的随机数序列是可以预测的。

	
### 最基本的伪随机数算法

```python
#!/usr/bin/python3

import time

def my_seed(seed):
    global holdrand
    holdrand = seed

def my_rand():
    global holdrand
    holdrand = (holdrand * 214013 + 2531011) >> 16 & 0x7fff
    return holdrand

my_seed(time.time_ns())

n = 0
while n < 100:
    print(my_rand(), end = ', ')
    n += 1
print()
```

	
### `random` 模块

- `random.seed(a=None, version=2)`：初始化随机数生成器。
- `random.random()`： 返回 `[0.0, 1.0)` 范围内的下一个随机浮点数。
- `random.uniform(a, b)`：返回一个随机浮点数 N ，当 `a <= b` 时 `a <= N <= b`，当 `b < a` 时 `b <= N <= a`。
- `random.randrange(stop)` 或者 `random.randrange(start, stop[, step])`：相当于从 `range(start, stop, step)` 中返回一个随机值。
- `random.randint(a, b)`：返回随机整数 N 满足 `a <= N <= b`；相当于 `randrange(a, b+1)`。
- `random.randint(a, b)`：返回随机整数 N 满足 `a <= N <= b`；相当于 `randrange(a, b+1)`。
- `random.choice(seq)`：从非空序列 `seq` 返回一个随机元素。如果 `seq` 为空，则引发 `IndexError`。
- `random.shuffle(x[, random])`：就地打乱可变序列 `x`（洗牌）。

	
### 使用系统随机数生成器

- `class random.SystemRandom([seed])`：使用 `os.urandom()` 函数的类，从操作系统提供的源生成随机数。
- 可在该类的对象上调用上述 `random` 模块提供的方法，但无需调用 `seed()`。

```python
#!/usr/bin/python3

import random

sysrand = random.SystemRandom()
n = 0
while n < 100:
    print(sysrand.random(), end = ', ')
    n += 1
print()
```

		
## 要点回顾

1. 掌握可迭代对象和迭代器的概念，并积极实践。
1. 掌握 `time` 和 `datetime` 模块的基本用法。
1. 掌握 ANSI 转义序列的基本概念。
1. 掌握使用 `pip` 命令安装第三方 Python 模块的方法。
1. 掌握 `colorist` 和 `curses` 模块的基本用法。
1. 掌握伪随机数的生成方法。

		
## 综合练习注意事项

1. 适当简化功能，两周内开发完成。
1. 先做基础功能，将基础功能实现为类或者函数。
1. 积极实践测试驱动开发（test-driven development），确保基础功能的正确性。
1. 积极尝试解耦代码和数据，提高代码的可维护性。

