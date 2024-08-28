# 什么是信息学

		
## 信息学的内容

`$$
信息学
\begin{cases}
  数学
  \begin{cases}
   初等数论 \\
   微积分 \\
   离散数学 \\
   编解码  \\
   \cdots
  \end{cases} \\
  算法和数据结构
  \begin{cases}
   二分、倍增、排序、搜索\cdots
   线性数据结构、树型数据结构、哈希表\cdots
  \end{cases}  \\
  编程语言
  \begin{cases}
   Python \\
   C/C++
  \end{cases} \\
  平台
  \begin{cases}
   操作系统 \\
   数据库 \\
   Web \\
   AI \\
   \cdots
  \end{cases}
\end{cases}
$$`

		
## 我的课程体系

`$$
清华老魏信息学
\begin{cases}
  信息学的数学基础
  \begin{cases}
   数系及其运算 \\
   离散数学结构 \\
   编解码  \\
   \cdots
  \end{cases} \\
  算法和数据结构入门 \\
  算法和数据结构提高 \\
  编程语言
  \begin{cases}
   Python 实战 \\
   C++ 基础 \\
   C 语言最佳实践
  \end{cases} \\
  平台
  \begin{cases}
   Linux 环境高级编程 \\
   零基础普及
  \end{cases}
\end{cases}
$$`

	
### 

若函数 `$ \phi(x) $` 和 `$ \psi(x) $` 在区间 `$ \left[ a, b \right] $` 上可微，  
且 `$ \forall x \in (a, b) $` 有 `$ \psi'(x) \neq 0 $`，则必存在一个点  
`$ \xi \in (a, b) $`，使得下式成立：  
`$ \frac{\phi(b)-\phi(a)}{\psi(b) - \psi(a)} = \frac{\phi'(\xi)}{\psi'(\xi)} $`

		
## 函数的微分

- 函数的增量：`$ \Delta y \approx f'(x) \Delta x $`
- 函数的微分：`$ dy = f'(x)dx $`

		
## 逼近函数

1. 从函数的增量想到：`$ f(x) \approx f(a) + f'(a)(x -a ) $`。
1. 能否构造一个更逼近 `$ f(x) $` 的函数？

	
### 泰勒公式

`$$
\begin{align}
    f(x)  \approx f(a) & + f'(a)(x -a ) + \frac{f''(a)}{2}(x - a)^2 \\
                       & + \frac{f^{(3)}(a)}{3!}(x-a)^3 \\
                       & + \frac{f^{(4)}(a)}{4!}(x-a)^4
\end{align}
$$`

且有，

`$$
\begin{align}
    f(x)   & =\sum^{n}_{k=0}\frac{f^{(k)}(a)}{k!}(x-a)^{k}+R_{n}\\
    R_{n}  & =\frac{f^{(n+1)}(\xi)}{(n+1)!}(x-a)^{n+1} & (a < \xi < x)
\end{align}
$$`

		
## 泰勒级数

某些函数满足：

`$$
f(x) =\sum^{\infty}_{k=0}\frac{f^{(k)}(a)}{k!}(x-a)^{k}
$$`

		
## 无穷级数

莱布尼兹解决的第一个数学问题，求下面无穷级数的值：

`$$
1 + \frac{1}{3} + \frac{1}{6} + \frac{1}{10} + \frac{1}{15} + \cdots
$$`

	
### 调和级数

`$$
1 + \frac{1}{2} + \frac{1}{3} + \frac{1}{4} + \frac{1}{5} + \cdots
$$`

	
### 达朗贝尔准则

