# Python 综合练习

1. 作业回顾
1. 综合练习可选项目
1. 日期和时间的获取和转换
   - `time` 模块
   - `datetime` 模块
1. 终端编程
   - Escape 序列
   - `curses` 模块
1. 数据持久化
   - 二进制数据读写
   - `pickle` 模块
   - `sqlite3` 模块
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
   1. 贪婪（`$ sudo apt install gread && gread`）
   1. 数独（`$ sudo apt nudoku && nudoku`）
   1. 打字员（`$ sudo apt install gtypist && gtypist`）
   1. 俄罗斯方块（`$ sudo apt install bastet && bastet`）

		
## 时间访问和转换

	
### `datetime` 模块

	
### `time` 模块

		
## 终端编程

	
### Escape 序列

	
### `curses` 模块

		
## 数据持久化

	
### 二进制数据读写

	
### `pickle` 模块

	
### `sqlite3` 模块

		
## 要点回顾

1. 掌握 `datetime` 和 `time` 模块的基本用法。
1. 掌握终端输出中 Escape 序列的基本用法。
1. 掌握 `curses` 模块的基本用法。
1. 掌握二进制数据读写的基本方法。
1. 掌握 `pickle` 模块的基本用法。
1. 掌握 `sqlite3` 模块的基本用法。

