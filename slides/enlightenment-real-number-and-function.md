# 信息学启蒙<br/>`第四单元 实数和函数`

1. 从整数到实数
1. 实数范围内的运算
1. 分数的性质及运算
1. 小数的性质及运算
1. 开方运算的性质
1. 对数运算的性质
1. 数学中的函数
1. 程序中的函数
1. 两个数论常用的函数
1. 程序中调用数学函数

		
## 第四单元 实数和函数<br/>`第一讲 从整数到实数`

	
### 提纲

- 标题：从整数到实数
- 旁白：清华大大，数怎么就有理、无理了？您给我讲讲呗。
- 主播：哇，兮兮都知道有理数了！今天一次性讲清楚哈。来看白板。
- 讲解要点：
   - 整数相除产生有理数。
   - 有理数的两种表达：分数和小数。
   - 有理数表达为小数的特点：不循环小数或者循环小数。
   - 无理数的定义：无限不循环小数。
   - 其他常见的无理数：圆周率、黄金分割比。
   - 数学函数

	
<div class="move-top">

### 两个整数相除余数不为零时

- 分数：`$ \frac{1}{2}, \ 3\frac{1}{2} $`
- 小数：`$ 0.5, \ 3.5 $`
- 分数转为小数。

</div>

	
<div class="move-top">

### 有理数的定义

- 整数、有限小数和无限循环小数统称为有理数。

</div>

	
<div class="move-top">

### 无理数和实数的定义

- 有不循环小数或者循环小数，也应该有无限不循环小数。
- 用代数式构造一个无限不循环小数：

`$$
\large{
    \displaystyle{ \sum_{n=0}^{\infty} \frac{1}{10^{n!}} }
}
$$`<!-- .element: class="fragment fade-in" -->

- 无理数：无限不循环小数。
- 实数：有理数和无理数统称为实数。

</div>

	
<div class="move-top">

### 常见无理数

- 根号二：`$ \sqrt{2} \approx 1.414 $`
- 根号三：`$ \sqrt{3} \approx 1.732 $`
- 圆周率：`$ \pi \approx 3.14159 $`
- 黄金分割比：`$ \Phi \approx 1.618 $`
- 自然常数：`$ e \approx 2.71828 $`

</div>

	
### 作业

<div class="no-list-style">

1) 将下面的假分数化为最简分数形式：

`$$
\begin{align}
    \frac{3}{2} &= \qquad\qquad \frac{28}{11} &&= \\
    \frac{77}{33} &= \qquad\qquad \frac{89}{3} &&= \\
\end{align}
$$`

2) 将下面的分数化为小数：

`$$
\begin{align}
    \frac{1}{2} &= \qquad\qquad 10\frac{1}{2} &&= \\
    \frac{11}{28} &= \qquad\qquad 5\frac{17}{89} &&= \\
\end{align}
$$`

3) 编写考鼎码算法，将给定的分数（依次输入分子和分母）化为最简分数形式，输出其整数部分、最简分数的分子及分母。
</div>

		
## 第四单元 实数和函数<br/>`第二讲 实数范围内的运算`

	
### 提纲

- 标题：实数范围内的运算
- 旁白：人类是怎么发现无理数的？您给我讲讲呗。
- 主播：无理数的发现有个悲伤的故事。来看白板。
- 讲解要点：
   - 整数相除产生有理数。
   - 有理数的两种表达：分数和小数。
   - 有理数表达为小数的特点：不循环小数或者循环小数。
   - 无理数的定义：无限不循环小数。
   - 其他常见的无理数：圆周率、黄金分割比。
   - 数学函数

	
### 人类发现的第一个无理数

- 人类发现的第一个无理数：`$ \large{ \sqrt{2} } $`。
- 开方运算是幂的一种逆运算：已知 `$ n $` 和 `$ P $`，求满足等式 `$ x^n = P\ (P \ge 0) $` 的 `$ x $` 的过程叫开方，`$ x $` 叫做 `$ P $` 的 `$ n $` 次方根，记作

`$$
\large{
    x = \sqrt[n]{P}
}
$$`<!-- .element: class="fragment fade-in" -->

- 对数运算是幂的另一种逆运算：如果 `$ a^x = P\ (a \gt 0, 且 a\ne 1) $`，则 `$ x $` 叫做以 `$ a $` 为底 `$ P $` 的对数，记作

`$$
\large{
    x = \log_a{P}
}
$$`<!-- .element: class="fragment fade-in" -->

	
<div class="move-top">

### 运算的封闭性

- 自然数范围内的封闭运算：加法、乘法、带余除法
- 整数范围内的封闭运算：加法、乘法、减法、带余除法
- 有理数范围内的封闭运算：加法、乘法、减法、除法
- 实数范围内的封闭运算：加法、乘法、减法、除法、开方、对数

</div>

	
<div class="move-top">

### 四则运算的等价性

- 减法本质上等价于加法：`$ a - b = a + (-b) $`。
- 除法本质上等价于乘法：`$ a \div b = a \times \frac{1}{b} $`。
- 倒数：对任意实数 `$ a \ne 0 $`，一定有实数 `$ b $` 使得 `$ ab = 1 $`；这时，称 `$ b $` 为 `$ a $` 的倒数。实际上有 `$ b = 1 \div a = \frac{1}{a} $`，而 `$ a $` 是 `$ b $` 的倒数。

</div>

	
### 乘法分配律的推广


	
### 作业

		
## 第四单元 实数和函数<br/>`第三讲 分数的性质及基本运算`

	
### 提纲

- 标题：从整数到实数
- 旁白：清华大大，两个分数相加、相乘有啥技巧吗？您给我讲讲呗。
- 主播：有技巧，不过技巧可是建立在规律之上的。来看白板。
- 讲解要点：

	
### 作业

<div class="no-list-style">

1) 完成如下分数相关的计算：

`$$
\begin{align}
    \frac{1}{2} + 4\frac{3}{5} &= \\
    10\frac{1}{2} - \frac{1}{3} &= \\
    \frac{1}{2} \times 3\frac{1}{3} &= \\
    \frac{1}{2} \div \frac{1}{3} &= \\
\end{align}
$$`

</div>

		
## 第四单元 实数和函数<br/>`第四讲 小数的性质及运算`

	
### 提纲

- 标题：小数的性质及运算
- 旁白：清华大大，十进制整数可以转换为二进制，十进制小数怎么转换为二进制呢？
- 主播：哇，这问题都想到了，太棒了！咱看白板哈。
- 讲解要点：

	
### 作业

<div class="no-list-style">

1) 完成如下小数相关的计算：

`$$
\begin{align}
    0.12345 + 10.56789 & = \\
    0.12345 - 10.56789 & = \\
    10.56789 \times 0.56 & = \\
    10.56789 \div 0.56 & = \\
\end{align}
$$`

</div>

		
## 第四单元 实数和函数<br/>`第五讲 开方运算的性质`

	
### 提纲

- 标题：开方运算的性质
- 旁白：
- 主播：
- 讲解要点：

	
<div class="move-top">

### 开方和幂的等价关系

</div>

	
### 作业

		
## 第四单元 实数和函数<br/>`第六讲 对数运算的性质`

	
### 提纲

- 标题：对数运算的性质
- 旁白：
- 主播：
- 讲解要点：

	
### 作业

		
## 第四单元 实数和函数<br/>`第七讲 数学中的函数`

	
### 提纲

- 标题：数学中的函数
- 旁白：
- 主播：
- 讲解要点：

	
### 作业

		
## 第四单元 实数和函数<br/>`第八讲 程序中的函数`

	
### 提纲

- 标题：程序中的函数
- 旁白：清华大大，我做作业时发现，经常要写一些以前写过的相似代码，好烦呀。
- 主播：哈哈，是时候学函数了。咱看白板哈。
- 讲解要点：
   1. 从数学公式到函数
   1. 代码中的函数
   1. 考鼎伪代码定义函数的方法

	
### 考鼎码定义函数

- 考鼎码使用 `函始/函终` 两个关键词定义一个函数。
- 每个函数应该具有唯一的名称。
- 函数名称之后用括号指定一个或多个参数名（`形参`），多个参数名用逗号隔开。
- 这些参数名用于指代`调用`函数时传入的实际参数（`实参`）。
- 函数通常要`返回`一个值。

```mathematica
# 该函数计算并返回两个数的绝对值之和
函始 绝对值之和 (a, b)
    若始 (a < 0)
        a := -a
    若终

    若始 (b < 0)
        b := -b
    若终

    返回 a + b
函终
```

	
### 考鼎码中调用函数

- 调用函数：函数名然后是小括号包围的实参列表。
- 函数的返回值可作为表达式的一部分。

```mathematica
算始 调用函数的示例
    a := 输入
    b := 输入

    输出 绝对值之和 (a, b)
算终
```

	
<div class="move-top">

### 函数和算法的区别

- 为避免和已有的算法定义方法相混淆，我们规定 `算始/算终` 定义的算法为单个考鼎码程序的唯一入口。
- 也就是说，一个考鼎码程序可以定义多个 `函数`，但只能包含一个 `算法`。
- 本质上，`算始/算终` 定义的代码属于特殊的函数。

</div>

		
### 作业

1) 将第二单元中所学求幂和阶乘的算法改造成函数，并编写算法调用相应的函数。

		
## 第四单元 实数和函数<br/>`第九讲 两个数论常用的函数`

	
### 提纲

- 标题：两个数论常用的函数
- 旁白：
- 主播：
- 讲解要点：

	
### 求给定正整数的真因子序列

```mathematica
# 该函数求给定正整数的真因子，返回真因子构成的序列
函始 真因子序列 (n)
    s := []
    i := 1
    当始 (i < n)
        若始 (n % i == 0)
            s := s + [i]
        若终
        i := i + 1
    当终

    返回 s
函终
```

	
### 计算序列元素之和


```mathematica
# 该函数计算序列各元素之和并返回求和结果
函始 序列元素之和 (seq)
    sum := 0

    # 若第 i 个元素为 `未定义`，表明序列结束
    i := 0
    当始 (seq[i] != 未定义)
        sum  = sum + seq[i]
        i := i + 1
    当终

    返回 sum
函终
```

	
### 调用函数判定完美数

- 调用函数时，写上函数名并在其后用括号包围需要传入函数的参数（`实参`）。
- 若函数返回一个值，可以将其使用赋值运算符（`:=`）赋给一个变量以备后续使用。

```mathematica
算始 判定完美数
    n := 输入

    # n 作为参数传入函数 `真因子序列`
    # 该函数返回的序列赋值给了 `seq` 变量
    seq := 真因子序列 (n)

    # seq 作为参数传入函数 `序列元素之和`
    # 该函数返回的值赋值给了 `sum` 变量
    sum := 序列元素之和 (seq)

    # 判断 n 和 sum 是否相等，相等则为完美数
    若始 (n == sum)
        输出 真
    若否
        输出 假
    若终
算终
```

	
### 调用函数判定亲和数

- 一个函数的返回值可以作为调用另一个函数的实参而无需使用中间变量。

```mathematica
算始 判定亲和数
    a := 输入
    b := 输入

    sum_a := 序列元素之和 (真因子序列 (a))
    sum_b := 序列元素之和 (真因子序列 (b))

    若始 (a == sum_b)
        若始 (b == sum_a)
            输出 真
        若终
    若终

    输出 假
算终
```

	
### 作业

1) 将正整数分解为指定进制下数码序列的功能写成一个函数，并编写算法调用相应的函数。

		
## 第四单元 实数和函数<br/>`第十讲 程序中调用数学函数`

	
### 提纲

- 标题：程序中调用数学函数
- 旁白：
- 主播：
- 讲解要点：

	
### 考鼎码提供的常见数学函数

- 使用关键词 `声明` 可声明一个函数的名称以及形参个数等。
- 声明的函数表示由系统或第三方提供，可以直接使用；要置于使用之前。
- 函数的声明只需要书写一行，所以不需要标识结束的关键词。
- 所有的编程语言都提供一样的数学函数。

```console
# pow() 用来求给定实数 x 的 y 次幂
声明 pow (x, y)

# sqrt() 用来求给定实数 x 的平方根，x 必须大于等于 0。
声明 sqrt (x)

# log10() 用来求给定实数以 10 为底的对数。
声明 log10 (x)

# log2() 用来求给定实数以 2 为底的对数。
声明 log2 (x)
```

	
### 作业

1) 编写考鼎码算法调用数学函数计算代数和式的值，其中 `$ n $` 为输入的整数：`$ \displaystyle{ \sum_{i=1}^{n}\sqrt{i} } $`。