# Python 综合练习

1. 作业回顾
1. 综合练习可选项目
1. 时间的获取和转换
1. 终端编程
1. 数据持久化
1. 其他知识点
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
   1. 贪婪（`$ sudo apt install greed && greed`）
   1. 数独（`$ sudo apt nudoku && nudoku`）
   1. 打字员（`$ sudo apt install gtypist && gtypist`）
   1. 俄罗斯方块（`$ sudo apt install bastet && bastet`）

		
## 时间的获取和转换

- 有关时间的术语和问题
- `time` 模块
- `datetime` 模块

	
### 有关时间的知识点

1. `epoch`：Unix 类系统的计时起点，即 1970 年 1 月 1 日 00:00:00（UTC）。
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
>>> from datetime import timedelta
>>> year = timedelta(days=365)
>>> ten_years = 10 * year
>>> ten_years
datetime.timedelta(days=3650)
>>> ten_years.days // 365
10
>>> nine_years = ten_years - year
>>> nine_years
datetime.timedelta(days=3285)
>>> three_years = nine_years // 3
>>> three_years, three_years.days // 365
(datetime.timedelta(days=1095), 3)
```

	
`date` 类

```python
>>> from datetime import date
>>> d = date.fromordinal(730920) # 730920th day after 1. 1. 0001
>>> d
datetime.date(2002, 3, 11)

>>> # Methods related to formatting string output
>>> d.isoformat()
'2002-03-11'
>>> d.strftime("%d/%m/%y")
'11/03/02'
>>> d.strftime("%A %d. %B %Y")
'Monday 11. March 2002'
>>> d.ctime()
'Mon Mar 11 00:00:00 2002'
>>> 'The {1} is {0:%d}, the {2} is {0:%B}.'.format(d, "day", "month")
'The day is 11, the month is March.'
```

	
`datetime` 类

```python
>>> from datetime import datetime, date, time, timezone

>>> # Using datetime.combine()
>>> d = date(2005, 7, 14)
>>> t = time(12, 30)
>>> datetime.combine(d, t)
datetime.datetime(2005, 7, 14, 12, 30)

>>> # Using datetime.now()
>>> datetime.now()
datetime.datetime(2007, 12, 6, 16, 29, 43, 79043)   # GMT +1
>>> datetime.now(timezone.utc)
datetime.datetime(2007, 12, 6, 15, 29, 43, 79060, tzinfo=datetime.timezone.utc)

>>> # Using datetime.strptime()
>>> dt = datetime.strptime("21/11/06 16:30", "%d/%m/%y %H:%M")
>>> dt
datetime.datetime(2006, 11, 21, 16, 30)
```

		
## 终端编程

1. ANSI 转义序列
1. `colorist` 模块
1. `curses` 模块

	
### ANSI 转义序列

	
### `colorist` 模块

	
### `curses` 模块

		
## 数据持久化

	
### 二进制数据读写

	
### `pickle` 模块

	
### `sqlite3` 模块

		
## 其他知识点

		
## 要点回顾

1. 掌握 `time` 和 `datetime` 模块的基本用法。
1. 掌握 ANSI 转义序列的基本概念。
1. 掌握使用 `pip` 命令安装第三方 Python 模块的方法。
1. 掌握 `colorist` 和 `curses` 模块的基本用法。
1. 掌握二进制文件读写的基本方法。
1. 掌握 `pickle` 模块的基本用法。
1. 掌握 `sqlite3` 模块的基本用法。
1. 掌握随机数的生成方法。

