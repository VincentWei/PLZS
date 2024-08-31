# 函数逼近法

- 从求解根号二的近似值说起
- 利用泰勒公式
- 线性插值法
- 牛顿逼近法
- 插值多项式

		
## 从求解平方根的近似值说起

- 朴素方法：二分逼近法

	
### 实际运行效果

- 求根号二，精确到小数点后十位

```
Iteration #0:  x = 1.5000000000; errors: 0.2500000000
Iteration #1:  x = 1.2500000000; errors: -0.4375000000
Iteration #2:  x = 1.3750000000; errors: -0.1093750000
Iteration #3:  x = 1.4375000000; errors: 0.0664062500
Iteration #4:  x = 1.4062500000; errors: -0.0224609375
Iteration #5:  x = 1.4218750000; errors: 0.0217285156
Iteration #6:  x = 1.4140625000; errors: -0.0004272461
Iteration #7:  x = 1.4179687500; errors: 0.0106353760
Iteration #8:  x = 1.4160156250; errors: 0.0051002502
Iteration #9:  x = 1.4150390625; errors: 0.0023355484
Iteration #10: x = 1.4145507812; errors: 0.0009539127
Iteration #11: x = 1.4143066406; errors: 0.0002632737
Iteration #12: x = 1.4141845703; errors: -0.0000820011
Iteration #13: x = 1.4142456055; errors: 0.0000906326
Iteration #14: x = 1.4142150879; errors: 0.0000043148
Iteration #15: x = 1.4141998291; errors: -0.0000388434
Iteration #16: x = 1.4142074585; errors: -0.0000172643
Iteration #17: x = 1.4142112732; errors: -0.0000064748
Iteration #18: x = 1.4142131805; errors: -0.0000010800
Iteration #19: x = 1.4142141342; errors: 0.0000016174
Iteration #20: x = 1.4142136574; errors: 0.0000002687
Iteration #21: x = 1.4142134190; errors: -0.0000004056
Iteration #22: x = 1.4142135382; errors: -0.0000000685
Iteration #23: x = 1.4142135978; errors: 0.0000001001
Iteration #24: x = 1.4142135680; errors: 0.0000000158
Iteration #25: x = 1.4142135531; errors: -0.0000000263
Iteration #26: x = 1.4142135605; errors: -0.0000000052
Iteration #27: x = 1.4142135642; errors: 0.0000000053
Iteration #28: x = 1.4142135624; errors: 0.0000000000
```

		
## 利用泰勒公式

`$$
\begin{align}
    f(x)   & =\sum^{n}_{k=0}\frac{f^{(k)}(a)}{k!}(x-a)^{k}+R_{n}\\
    R_{n}  & =\frac{f^{(n+1)}(\xi)}{(n+1)!}(x-a)^{n+1} & (a < \xi < x)
\end{align}
$$`

	
### 泰勒公式的证明

	
### 平方根的泰勒公式展开

`$$
\begin{align}
  f(x) & = \sqrt{x} = x^{\frac{1}{2}} \\
  f'(x) & = \frac{1}{2} \times \frac{x^{\frac{1}{2}}}{x^1} \\
  f''(x) & = \frac{1}{2} \times \frac{1-2}{2} \times \frac{x^{\frac{1}{2}}}{x^2} \\
  \cdots \\
  f^{(n)}(x) & = \frac{1}{2} \times \frac{1-2}{2} \times \cdots \times \frac{1-2(n-1)}{2} \times \frac{x^{\frac{1}{2}}}{x^n} \\
\end{align}
$$`

若 `$ a = 1 $` 则有：

`$$
\begin{align}
  f(1) & = 1 \\
  f^{(n)}(1) & = \frac{1}{2} \times \frac{1-2}{2} \times \cdots \times \frac{1-2(n-1)}{2} \qquad (n \gt 0)
\end{align}
$$`


	
于是，

`$$
\begin{align}
    \sqrt{x}  = 1 & + f'(1) (x - 1) + \frac{1}{2}f''(1)(x - 1)^2 \\
                  & + \frac{1}{3!}f^{(3)}(1)(x - 1)^3 + \frac{1}{4!}f^{(4)}(1)(x - 1)^4 \\
                  & ... \\
                  & + \frac{1}{n!}f^{(n)}(1)(x - 1)^n +  R_{n}
\end{align}
$$`

其中，

`$$
    R_{n} = \frac{1}{(n+1)!} \times \frac{1}{2} \times \frac{1-2}{2} \times \cdots \times \frac{1-2n}{2} \times \xi^{\frac{1 - 2(n + 1)}{2}} \times (x - 1) \quad (1 < \xi < x)
$$`

	
于是，

`$$
\begin{align}
   & \because \xi^{\frac{1 - 2(n + 1)}{2}} \lt 1 ; \quad \xi \in (1, x) \quad or \quad (x, 1) \quad 且 \quad x \ge 0 \\
   & \therefore \left| R_{n} \right| \lt \frac{1}{(n+1)!} \times \frac{1}{2} \times \frac{2-1}{2} \times \cdots \times \frac{2n-1}{2} \times \left| x - 1 \right|
\end{align}
$$`

- 挑战来了
   1. `$ \left| R_{n} \right| $` 并不能随着 `$ n $` 的变大迅速降低，甚至越来越大，这意味着对应的泰勒级数是发散的。
   1. 在 `$ \sqrt{x} $` 的导函数中，包含有 `$ \sqrt{x} $` 本身。
- 解决方案：选择一个最接近的起始值（比如一个完全平方数），然后执行多次迭代。

	
### 实际运行效果

1000 的平方根，精确到小数点 10 位

```
Iteration #0:  a =  25.0000000000; x =  6.9565013885; errors: 951.6070884311
Iteration #1:  a =  48.3929115689; x =  9.6308232660; errors: 907.2472432188
Iteration #2:  a =  92.7527567812; x = 13.2033198661; errors: 825.6723445144
Iteration #3:  a = 174.3276554856; x = 17.7537798768; errors: 684.8033000864
Iteration #4:  a = 315.1966999136; x = 22.9958142099; errors: 471.1925288234
Iteration #5:  a = 528.8074711766; x = 27.8814215541; errors: 222.6263321241
Iteration #6:  a = 777.3736678759; x = 30.8288090213; errors: 49.5845343304
Iteration #7:  a = 950.4154656696; x = 31.5838781432; errors: 2.4586414338
Iteration #8:  a = 997.5413585662; x = 31.6226810230; errors: 0.0060449177
Iteration #9:  a = 999.9939550823; x = 31.6227766011; errors: 0.0000000365
Iteration #10: a = 999.9999999635; x = 31.6227766017; errors: 0.0000000000
31.6227766017 while sqrt() gives: 31.6227766017
```

		
## 线性插值法

- 将函数 `$ f(x) $` 在给定区间内用连续的折线段逼近。
- 找到 `$ x $` 所在区间，如 `$ \left[a_{i}, a_{i+1} \right] $`，则

`$$
   f(x) \approx f(a_{i}) + \frac{x - a_{i}}{a_{i+1} - a_{i}} \times \left[ f(a_{i+1}) - f(a_{i}) \right]
$$`

		
## 牛顿逼近法

- 求一个规范化多项式方程的根，相当于求对应函数在 `$ f(x) = 0 $` 时的取值。

	
### 递推公式

`$$
   x_n = x_{n - 1} - \frac{f(x_{n-1})}{f'(x_{n-1})}
$$`

	
### 牛顿逼近法求平方根

`$$
\begin{align}
   x^2 - a & = 0 \\
   f(x) & = x^2 - a \\
   f'(x) & = 2x
\end{align}
$$`

	
### 实际运行效果

- 1000 的平方根，精确到小数点 20 位。
- 取第一个估测值为 500。

```
Iteration #0:  x1  = 251.24900099900099803563; errors: 249.25099900099900196437
Iteration #1:  x2  = 127.61455816345907976483; errors: 123.63444283554191827079
Iteration #2:  x3  = 67.72532736082604287731; errors: 59.88923080263303688753
Iteration #3:  x4  = 41.24542607499115121072; errors: 26.47990128583489166658
Iteration #4:  x5  = 32.74526934448863357829; errors: 8.50015673050251763243
Iteration #5:  x6  = 31.64201586865078752453; errors: 1.10325347583784605376
Iteration #6:  x7  = 31.62278245070104532033; errors: 0.01923341794974220420
Iteration #7:  x8  = 31.62277660168433257581; errors: 0.00000584901671274451
Iteration #8:  x9  = 31.62277660168379256334; errors: 0.00000000000054001248
Iteration #9:  x10 = 31.62277660168379256334; errors: 0.00000000000000000000
31.62277660168379256334 while sqrt() gives: 31.62277660168379256334
```

	
### 牛顿逼近法起始估测值的确定

1. 考查方程 `$ x^3 - 2x - 5 = 0 $`，设 `$ f(x) = x^3 - 2x - 5 $`。
1. 考查方程 `$ x^3 - x^2 - x - 1 = 0 $`，设 `$ f(x) = x^3 - x^2 - x - 1 $`。

		
## 插值多项式

- 线性插值能否推广为多项式插值？
- 在很多情况下，泰勒公式无法给出收敛情形，而且多项式的次数并不是越高越好。

对 `$ \left[ x_0, x_2 \right] $` 区间中的函数 `$ y = f(x) $`，可考虑  
使用二次多项式 `$ P(x) = a_0 + a_1x + a_2x^2 $` 逼近，只要满足：

`$$
\begin{align}
   y_0 & = a_0 + a_1x_0 + a_2x^2_0 \\
   y_1 & = a_0 + a_1x_1 + a_2x^2_1 \\
   y_2 & = a_0 + a_1x_2 + a_2x^2_2
\end{align}
$$`

其中，

`$$
\begin{align}
   y_0 & = f(x_0) = P(x_0) \\
   y_1 & = f(x_1) = P(x_1) \\
   y_2 & = f(x_2) = P(x_2)
\end{align}
$$`


	
### 三点确定插值二次多项式


	
### 插值二次多项式公式

`$$
\begin{align}
   P(x) = & y_0 \frac{(x - x_1)(x - x_2)}{(x_0 - x_1)(x_0 - x_2)} + y_1 \frac{(x - x_0)(x - x_2)}{(x_1 - x_0)(x_1 - x_2)} \\
          & + y_2 \frac{(x - x_0)(x - x_1)}{(x_2 - x_0)(x_2 - x_1)}
\end{align}
$$`

