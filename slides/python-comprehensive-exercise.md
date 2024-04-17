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
- `calendar` 模块

	
### 有关时间的术语和问题

1. `epoch`：Unix 类系统的计时起点，即 1970 年 1 月 1 日 00:00:00（UTC）。
1. UTC（协调世界时，Coordinated Universal Time）：早先的 GMT（格林威治时间）。
1. DTS（夏时制，Daylight Saving Time）：某些时区（timezone）为在夏季最大化利用日光而进行的时间调整，通常比冬季时间快一个小时。
1. 操作系统使用多个时钟（clock）来满足程序的不同计时需求：
   - 墙钟（wall clock）指和人类墙上挂的时钟一致的时间；操作系统通过记录和更新 epoch 以来的秒数（跳秒，leap seconds）作为墙钟时间。
   - 单调（monotonic clock）指始终单调增加的时钟，不会因为调整系统时间而变化。该时钟适合用于衡量程序的执行时间。
1. 本地时间（local time）指对应当前地区（时区）的墙钟时间。
1. 四种常见的时区表示方法：
   - 保留名称，如 `UTC`、`GMT`
   - 国家，如 `PRC`、`GB`
   - 城市，如 `Asia/Shanghai`、`Pacific/Auckland`、`US/Michigan`
   - UTC 偏移量，如 `+0800`
1. Linux 系统中设置时区：`tzselect` 命令。

	
### 有关时间的术语和问题（续）

1. 千年虫和跳秒溢出问题。
1. 操作系统时间的初始化过程。

	
### `time` 模块

- [官方文档](https://docs.python.org/zh-cn/3.10/library/time.html)

	
### `datetime` 模块

- [官方文档](https://docs.python.org/zh-cn/3.10/library/datetime.html)

	
### `calendar` 模块

- [官方文档](https://docs.python.org/zh-cn/3.10/library/calendar.html)

		
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

