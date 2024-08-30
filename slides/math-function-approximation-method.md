# 函数逼近法

- 从求解根号二的近似值说起
- 泰勒公式
- 线性插值法
- 牛顿逼近法
- 三点逼近法

		
## 从求解根号二的近似值说起

- 朴素方法：二分逼近法

	
### 实际运行效果

- 精确到小数点后十位

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

		
## 泰勒公式

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
  f(x) & = x^{\frac{1}{2}} \\
  f'(x) & = -\frac{1}{2} x^{-\frac{1}{2}} \\
  f''(x) & = \frac{1}{2^2} x^{-\frac{1 + 2}{2}} \\
  \cdots \\
  f^{n}(x) & = \frac{1}{2^n} x^{-\frac{1 + 2n}{2}} \\
\end{align}
$$`

	
取 `$ a = 1 $` 逼近，则有：

`$$
\begin{align}
    \sqrt{x}  = 1 & + (x - 1) + \frac{1}{2}(x - 1)^2 \\
                  & + \frac{1}{3!}(x - 1)^3 + \frac{1}{4!}(x - 1)^4 \\
                  & ... \\
                  & + \frac{1}{n!}(x - 1)^n +  R_{n}
\end{align}
$$`

其中，

`$$
    R_{n} = \frac{1}{(n+1)!} \times \frac{1}{2^{n + 1}} \xi^{-\frac{1 + 2(n + 1)}{2}} (x - 1) \quad (1 < \xi < x)
$$`

	
于是，

`$$
\begin{align}
   & \because \xi^{-\frac{1 + 2(n + 1)}{2}} (x - 1) \lt 1 \quad (1 < \xi < x) \\
   & \therefore R_{n} \lt  \frac{1}{2^{n + 1}(n+1)!} (x - 1)
\end{align}
$$`

		
## 线性插值法

中值定理  
`$ f(b)-f(a)=f^{\prime}(\xi)(b-a), \quad (a < \xi < b) $`

		
## 牛顿逼近法

中值定理  
`$ f(b)-f(a)=f^{\prime}(\xi)(b-a), \quad (a < \xi < b) $`

		
## 三点逼近法

