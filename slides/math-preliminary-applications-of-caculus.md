# 微积分的初步应用

		
## 中值定理

若函数 `$ f(x) $` 在区间 `$ [a, b] $` 上可微，  
则必存在一个点 `$ \xi \in (a, b) $`，使得下式成立：  
`$ f(b)-f(a)=f^{\prime}(\xi)(b-a), \quad  $`

		
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

