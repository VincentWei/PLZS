# 圆周率、自然常数及其计算

- 圆和圆周率
- 阿基米德估测圆周率的方法
- 计算圆周率的现代方法
- 自然常数为何『自然』？
- 自然常数的有趣性质
- 计算自然常数
- 圆周率和自然常数是超越无理数

		
## 圆和圆周率

- 圆的几何定义：在一个平面内，围绕一个点并以一定长度为距离旋转一周所形成的封闭曲线叫作圆。
- 其他定义：
  1. 在平面内，和给定点的距离等于定长的点构成的集合叫作圆。
  1. 在平面内，给定一条封闭曲线 C 和一个定点 O，若曲线 C 上的任意一点到 O 点的距离都相等，则曲线 C 就是圆。

<img style="height:500px;width:auto;" src="assets/math-circle.svg" />

	
### 圆周率

- 古希腊人发现圆是相似图形；圆的直径扩大两倍，周长也会扩大两倍。
- 阿基米德（Archimedes）证明了圆的周长和直径的比例是定值，后人将其记为 `$ \pi $`（圆周率）。
- 试试证明圆的周长和直径的比例是定值？

<img style="height:500px;width:auto;" src="assets/math-circle-and-pi.svg" />

	
### 圆的周长和面积的关系

<img style="height:700px;width:auto;" src="assets/math-circle-area-and-circumference.svg" />

	
### 巴塞尔问题

1) 欧拉给出的答案（1735 年）：

`$$
\large{
    \frac{\pi^2}{6} = \frac{1}{1^2} + \frac{1}{2^2} + \frac{1}{3^2} + \frac{1}{4^2} + \frac{1}{5^2} + \cdots
}
$$`

	
2) 欧拉推导过程

	
3) 试试求下面的级数？

`$$
\begin{array}{c}
    \frac{1}{1^4} + \frac{1}{2^4} + \frac{1}{3^4} + \frac{1}{4^4} + \frac{1}{5^4} + \cdots  \\
    \frac{1}{1^6} + \frac{1}{2^6} + \frac{1}{3^6} + \frac{1}{4^6} + \frac{1}{5^6} + \cdots  \\
    \frac{1}{1^2} + \frac{1}{3^2} + \frac{1}{5^2} + \frac{1}{7^2} + \frac{1}{9^2} + \cdots  \\
    \frac{1}{2^2} + \frac{1}{4^2} + \frac{1}{6^2} + \frac{1}{8^2} + \frac{1}{10^2} + \cdots
\end{array}
$$`

		
## 阿基米德估测圆周率的方法

原理：用内接正多边形逼近圆  

<img style="height:700px;width:auto;" src="assets/math-circle-and-squares.svg" />

	
### 用两倍边数的正多边形继续逼近

<img style="height:700px;width:auto;" src="assets/math-archimedes-and-pi.svg" />

	
### 阿基米德的结论

- 阿基米德从正六边形开始，然后将边数依次倍增为 12、24、48、96，最终确定了：

`$$
\large{
    3\frac{10}{71} < \pi < 3\frac{1}{7}
}
$$`

	
### 阿基米德方法的后世结论

- 用正 4096 边形估测圆周率：

`$$
\begin{align}
\pi & \approx 2048 \sqrt {2 - \sqrt {2 + \sqrt {2 + \sqrt {2 + \sqrt {2 + \sqrt {2 + \sqrt {2 + \sqrt {2 + \sqrt {2 + \sqrt {2 + \sqrt{2} } }}}}}}}}} \\
    & = 3.141\ 594 \ 618\cdots
\end{align}
$$`

- 弗朗索瓦・爱维特（1593 年）

`$$
  \frac{2}{\pi} = \frac{\sqrt{2}}{2} \times \frac{\sqrt{2 + \sqrt{2}}}{2} \times \frac{\sqrt{2 + \sqrt{2 + \sqrt {2}}}}{2} \times \cdots
$$`

		
## 计算圆周率的现代方法

### 约翰・沃利斯（1655 年）

`$$
  \frac{\pi}{2} = \frac{2}{1} \times \frac{2}{3} \times \frac{4}{3} \times \frac{4}{5} \times \frac{6}{5} \times \frac{6}{7} \times \frac{8}{7} \times \frac{8}{9} \times \cdots
$$`

	
### 泰勒级数

- 反正切函数的泰勒级数展开：

`$$
    \arctan {x} = x - \frac{x^3}{3} + \frac{x^5}{5} - \frac{x^7}{7} + \frac{x^9}{9} - \cdots
$$`

- `$ x = 1 $` 时，有：

`$$
    \frac{\pi}{4} = 1 - \frac{1}{3} + \frac{1}{5} - \frac{1}{7} + \frac{1}{9} - \cdots
$$`

	
### 让泰勒级数收敛得更快

`$$
    \frac{\pi}{4} = \arctan {\frac{1}{2}} + \arctan {\frac{1}{5}} + \arctan {\frac{1}{8}}
$$`

- 约翰・马钦（1706 年）

`$$
    \frac{\pi}{4} = 4 \arctan {\frac{1}{5}} - \arctan {\frac{1}{239}}
$$`

- F. 施特默（1896 年）

`$$
    \frac{\pi}{4} = 44 \arctan {\frac{1}{57}} + 7 \arctan {\frac{1}{239}} - 12 \arctan {\frac{1}{682}} + 24 \arctan {\frac{1}{12943}}
$$`

	
### 邱德诺夫斯基级数

`$$
    \frac{1}{\pi} = 12\sum_{k=0}^{\infty } \frac{(-1)^k(6k)!(545\ 140\ 134k + 13\ 591 \ 409)}{(3k)!(k!)^3(3\ 640 \ 320)^{3k+\frac{3}{2}} }
$$`

	
### 使用计算机计算圆周率更有效的方法

- 贝利-博温-普劳夫公式（1996 年）

`$$
   \pi = \sum_{n=0}^{\infty}\frac{1}{2^{4n}} \left( \frac{4}{8n+1} - \frac{2}{8n+4} - \frac{1}{8n+5} - \frac{1}{8n+6} \right)
$$`

- 贝拉尔（1997 年）：可用于计算 `$ \pi $` 在 2、4、8、16 进制下单个位数上的数值

`$$
   \pi = \frac{1}{64}\sum_{n=0}^{\infty}\frac{(-1)^n}{2^{10n}} \left( -\frac{32}{4n+1} - \frac{1}{4n+3} + \frac{256}{10n+1} - \frac{64}{10n+3} - \frac{4}{10n+5} - \frac{4}{10n+7} + \frac{1}{10n+9}\right)
$$`


		
## 自然常数的有趣性质

1) 自然常数来源之极限

`$$
e = \lim_{k \to \infty} \left( 1 + \frac{1}{k}\right)^k = 2.718281828459045\cdots
$$`

2) 自然常数来源之无穷级数

`$$
e = 1 + \frac{1}{1!} + \frac{1}{2!} + \frac{1}{3!} + \frac{1}{4!} + \frac{1}{5!} + \frac{1}{6!} + \cdots
$$`

	
### 推导

1) 极限。考虑 `$ u_n = \left( 1 + \frac{1}{n}\right)^n $` 的牛顿二项式展开。

	
2) 两个有关自然常数的函数的导函数

`$$
\begin{align}
    (\ln x)' & = \frac{1}{x} \\
    (e^x)' & = e^x
\end{align}
$$`

	
3) 泰勒级数

`$$
   e^x = \frac{x^0}{0!} + \frac{x^1}{1!} + \frac{x^2}{2!} + \frac{x^3}{3!} + \frac{x^4}{4!} + \frac{x^5}{5!} + \frac{x^6}{6!} + \cdots
$$`

	
### 扩展：推导 `$ x^x $` 的导数


		
## 自然常数为何『自然』？

		
## 计算自然常数

		
## 圆周率和自然常数是超越无理数
