# 信息学启蒙（算法及其描述）

1. 什么是算法
1. 描述算法的方法：流程图
1. 描述算法的方法：伪代码
1. 进制转换算法

		
## 什么是算法

1. 旁白：清华大大，您老说算法、算法，算法到底是个啥？
1. 作业：用文字描述猜拳游戏的算法。

	
### 从猜拳游戏说起     <!-- .element: class="fragment highlight-current-red" data-fragment-index="1" -->
### 什么是机械计算     <!-- .element: class="fragment highlight-current-red" data-fragment-index="2" -->
### 自然语言描述算法   <!-- .element: class="fragment highlight-current-red" data-fragment-index="3" -->

		
## 抽象和代数

1. 旁白：清华大大，您老说算法、算法，算法到底是个啥？
1. 作业：用文字描述猜拳游戏的算法。

	
### 脱离具体物体的数    <!-- .element: class="fragment highlight-current-red" data-fragment-index="1" -->
### 用字母代表数  <!-- .element: class="fragment highlight-current-red" data-fragment-index="2" -->

	
### 常见代数符号及习惯

- 表示整数：`n`
- 表示一般的数（小数）：`a, b, c`
- 下标表示法：`$ a_0, a_1, ... a_n $`
- 表示未知数或者变的数：`x, y, z`
- 幂： `$ x^n $`
- 和：`$ \sum $`
- 积：`$ \prod $`

		
## 描述算法的方法：流程图

		
## 描述算法的方法：伪代码

		
## 进制转换算法

- 初始算法描述：

```mathematica []
算法开始 转换进制 (x, b)
    循环开始 (当 x ≠ 0 时)
        令 r = x % b
        令 x = x // b
        输出 r
    循环结束
算法结束
```

	
- 分析这个算法的问题

```mathematica []
算法开始 转换进制 (x, b)
    令 s 为一个空的序列
    如果 (x = 0)
        将 0 放入 s
        返回 s
    如果结束

    循环开始 (当 x ≠ 0 时)
        r = x % b
        将 r 插到 s 的最前面
        令 x = x // b
    循环结束

    返回 s
算法结束
```

