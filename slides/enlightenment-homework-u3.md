# 信息学启蒙作业讲解<br/>`第三单元 数论基础`

		
## 第一讲 从自然数到整数

	
1) 完成如下计算，如遇代数式，则 `$ a $` 取 `$ 11 $`，`$ b $` 取 `$ -33 $`：

`$$
\begin{align}
    0 - 88 &= -88               \\
    0 + -88 &= -88              \\
    -88 \times b &= 2904        \\
    88 \times -3 &=  -264       \\
    0 - a \times 3 &= -33       \\
    123 - 256 &= -133           \\
    \mid -256 \mid &=  256      \\
    \mid 256 \mid &=   256      \\
    100 + 120 \div (12 - \mid 17 - 26 \mid) \times 6 &= 340 \\
    (a - b) \div 11 &= 4        \\
\end{align}
$$`

	
2) 展开并计算如下代数和式，体验代数的简洁之美：`$ \displaystyle{ \sum_{n=0}^{5}(-1)^n n } $`。

`$$
\large{
\begin{align}
    &\displaystyle{ \sum_{n=0}^{5}(-1)^n n } \\
    &= (-1)^0 \times 0 + (-1)^1 \times 1 + (-1)^2 \times 2 + (-1)^3 \times 3 + (-1)^4 \times 4 + (-1)^5 \times 5 \\
    &= 0 - 1 + 2 - 3 + 4 - 5 \\
    &= -3
\end{align}
}
$$`

	
3) 增强加法实现的乘法考鼎码算法，使之支持负数作为被乘数或乘数。

```mathematica
算始 乘法 (n, m)
    若始 (m < 0)
        m := -m
        n := -n
    若终

    r := 0
    当始 (m != 0)
        r := r + n
        m := m - 1
    当终

    输出 r
算终
```

		
## 第二讲 整数的性质

	
1) 当 `$ n $` 分别取 `$ -4 $`、`$ -3 $`、`$ -2 $`、`$ -1 $`、`$ 0 $`、`$ 5 $` 时，计算对应代数式的值：

`$$
\begin{align}
    &n      &=  &-4 \quad   &-3 \quad   &-2 \quad   &-1 \quad   &0 \quad &5 \\
    &2n     &=  &-8 \quad   &-6 \quad   &-4 \quad   &-2 \quad   &0 \quad &10 \\
    &2n + 1 &=  &-7 \quad   &-5 \quad   &-3 \quad   &-1 \quad   &1 \quad &11 \\
    &n^2    &=  &16 \quad   &9 \quad    &4 \quad    &1 \quad    &0 \quad &25 \\
    &n^3    &=  &-64 \quad  &-27 \quad  &-8 \quad   &-1 \quad   &0 \quad &125 \\
\end{align}
$$`

	
2) 写出 `$ 30 $` 以内的所有质数。

`$$
\large{
    2,\ 3,\ 5,\ 7,\ 11,\ 13,\ 17,\ 19,\ 23,\ 29
}
$$`

	
3) 编写考鼎码算法，计算从 `$ 1 $` 开始的 `$ n $` 个奇数之和。

```mathematica
算始 奇数之和 (n)

    r := 0
    i := 0
    当始 (i < n)
        r := r + (i * 2 + 1)
        i := i + 1
    当终

    输出 r
算终
```

	
4) 编写考鼎码算法，判定一个给定的整数是否为一个完全立方数。

```mathematica
算始 是否为完全立方数 (n)

    i := 1
    当始 (i < n)
        若始 (i * i * i == n)
            输出 真
            终止    # 此时算法必须提前终止
        若终

        i := i + 1  # 别忘了递增，否则会死循环
    当终

    输出 假
算终
```

	
优化版：

```mathematica
算始 是否为完全立方数 (n)

    i := 1
    当始 (i < n)
        i3 := i * i * i
        若始 (i3 > n)
            跳出
        又若 (i3 == n)
            输出 真
            终止    # 此时算法必须提前终止
        若终

        i := i + 1  # 别忘了递增，否则会死循环
    当终

    输出 假
算终
```

		
## 第三讲 完美数

	
1) 列出下列各数的真因子（第一行为示例解答）：

`$$
\begin{align}
    4  &:  1, 2                     \\
    2  &:  1                        \\
    12 &:  1, 2, 3, 4, 6            \\
    25 &:  1, 5                     \\
    77 &:  1, 7, 11                 \\
\end{align}
$$`

	
2) 编写考鼎码算法，判定给定的正整数是不是完美数。

<div class="long-code">

```mathematica
# n 必须为正整数
算始 是否为完美数 (n)
    # 获取 n 的真因子序列
    s := []
    i := 1
    当始 (i < n)
        若始 (n % i == 0)
            s := s + [i]
        若终
        i := i + 1
    当终

    # 计算真因子之和
    sum := 0
    i := 0
    当始 (s[i] != 未定义)
        sum := sum + s[i]
        i := i + 1
    当终

    # 判断是否为完美数
    若始 (sum == n)
        输出 真
    若否
        输出 假
    若终
算终
```

</div>

	
3) 如果某个正整数 `$ a $` 的真因子之和为 `$ b $`，而 `$ b $` 的真因子之和为 `$ a $`，则称 `$ a, b $` 为一对亲和数。古希腊的毕达哥拉斯于两千年前发现了第一对亲和数：`$ 220, 284 $`。请编写考鼎码算法，判定给定的两个正整数是不是亲和数。

```mathematica
# n 必须为正整数
算始 是否为亲和数 (a, b)
    # 获取 a 的真因子序列
    s := []
    i := 1
    当始 (i < a)
        若始 (a % i == 0)
            s := s + [i]
        若终
        i := i + 1
    当终

    # 计算 a 的真因子之和
    sum := 0
    i := 0
    当始 (s[i] != 未定义)
        sum := sum + s[i]
        i := i + 1
    当终

    # 判断 a 的真因子之和是否等于 b
    若始 (sum != b)
        输出 假
        终止        # 算法这时可直接终止
    若终

    # 获取 b 的真因子序列
    s := []
    i := 1
    当始 (i < b)
        若始 (b % i == 0)
            s := s + [i]
        若终
        i := i + 1
    当终

    # 计算 b 的真因子之和
    sum := 0
    i := 0
    当始 (s[i] != 未定义)
        sum := sum + s[i]
        i := i + 1
    当终

    # 判断 b 的真因子之和是否等于 a
    若始 (sum == a)
        输出 真
    若否
        输出 假
    若终
算终
```

		
## 第四讲 自恋数

	
1) 求出下列十进制三位数各位的立方和（第一行为示例解答）：

`$$
\begin{align}
    123  &:  1^3 + 2^3 + 3^3 = 36 \\
    234  &:  2^3 + 3^3 + 4^3  = 99 \\
    205  &:  2^3 + 0^3 + 5^3  = 133 \\
\end{align}
$$`

	
2) 写出满足自恋数条件的十进制数对应的代数等式。

`$$
\large{
    (d_{n-1} \cdots d_1d_0)_{10} = d_{n-1}^n + \cdots + d_1^n + d_0^n
}
$$`

或，

`$$
\large{
    (d_n \cdots d_2d_1)_{10} = d_n^n + \cdots + d_2^n + d_1^n
}
$$`

	
3) 小明希望从 `$ 1 $` 开始的 `$ n $` 个奇数的连乘积式之结果随奇数的数量而发生正负号的变化：偶数个奇数的积式其结果为正值，奇数个奇数的积式其结果为负值。请写出对应的代数式。

`$$
\large{
    \prod_{k=1}^n -(2k-1)
}
$$`

或，

`$$
\large{
    (-1)^n \prod_{k=1}^n (2k-1)
}
$$`

	
4) 编写考鼎码算法，找出小于等于给定正整数 `$ n $` 的所有自恋数。

```mathematica
算始 列出自恋数 (n)
    k = 1
    当始 (k < n)

        # k 的十进制各位序列
        s := []
        e := 0      # 序列的长度也就是一共有多少十进制位数
        x := k      # 使用 x 计算十进制各位；k 要保持不变，
                    # 因为下面还要用
        当始 (x != 0)
            r := x % 10
            s := [r] + s
            x := x // b
            e := e + 1
        当终

        # 计算十进制各位的 e 次方之和
        sum := 0
        i := 0
        当始 (i < e)
            # 计算当前位的 e 次方
            power := 1
            j := 0
            当始 (j < e)
                power := power * s[i]
                j := j + 1
            当终

            # 将 power 加到 sum 中
            sum := sum + power
            i := i + 1
        当终

        # 判断是否为自恋数
        若始 (sum == k)
            输出 k
        若终

        k := k + 1
    当终
算终
```

		
## 第五讲 质数的判定

	
1) 挑选出 `$ 1,\ 2,\ 7,\ 8,\ 31,\ 87,\ 91,\ 100,\ 201,\ 992 $` 当中的质数。

`$$
\large{
    2,\ 7,\ 31
}
$$`

	
2) 从 `$ 500! + 2 $` 开始一路取到 `$ 500! + 500 $`，则将得到 `$ 499 $` 个连续的整数，且这些整数均有大于 `$ 2 $` 的因子。请据此证明：两个相邻质数之间的缺口可以任意长。

- 证明：
   1. 给定任意大于 `$ 2 $` 的正整数 `$ n $`。
   1. 从 `$ (n-1)! + 2 $` 开始一路取到 `$ (n-1)! + (n-1) $`，则将得到 `$ n-2 $` 个连续的整数，且这些整数均有大于 `$ 2 $` 的因子，所以全部为合数。
   1. 设小于 `$ (n-1)! + 2 $` 的最大的质数是 `$ p_1 $`，大于 `$ (n-1)! + (n-1) $` 的最小的质数是 `$ p_2 $`，则一定有 `$ p_2 - p_1 > n - 2 $`。
   1. 又因为 `$ p_1,\ p_2 $` 之间全是合数，所以这两个质数为相邻质数。
   1. 因为这里的 `$ n $` 可以取任意大的值，故而得出结论：两个相邻质数之间的缺口可以任意长。
   1. 证毕！

	
3) 优化本节给出的质数判定算法。

```mathematica
# 这个算法假设传入的参数 n 是正整数
算始 是否为质数 (n)
    若始 (n < 2)
        返回 假
    若终

    若始 (n == 2)
        返回 真
    若终

    i := 2
    # 只要 i 的平方大于 n 就没必要继续判断了
    当始 (i * i <= n)
        若始 (n % i == 0)
            返回 假
        若终
        i := i + 1
    当终

    返回 真
算终
```

		
## 第六讲 算术基本定理

	
1) 分解如下整数，将其写成质因子的幂相乘的形式（第一行为示例解答）：

`$$
\begin{align}
    100 &= 2^2 \times 5^2       \\
    88  &= 2^3 \times 11        \\
    127 &= 127                  \\
    256 &= 2^8                  \\
    565 &= 5 \times 113         \\
    999 &= 3^3 \times 37        \\
\end{align}
$$`

	
2) 设定一个已知质数构成的序列，初始时，该序列中只有 `2` 一个元素。然后从 `3` 开始依次检测每个整数，用已知质数序列中的每个质数去除这个整数。如果某个已知质数是这个整数的因子，则该整数为一个合数，否则该整数为下一个新发现的质数，并将其加入到已知质数的序列当中。如此，我们可以生成一个包含从小到大排列的所有质数的序列。请按此方法编写考鼎码算法，生成小于等于给定正整数 `n` 的所有质数序列。请思考上述算法的至少一个优化点。

	
- 朴素版本

<div class="long-code">

```mathematica
算始 生成质数序列 (n)
    若始 (n < 2)
        返回 []
    又若 (n == 2)
        返回 [2]
    若终

    primes := [2]
    k := 3
    当始 (k <= n)

        i := 0
        flag := 真      # 这个标志先假定 k 为质数
        当始 (primes[i] != 未定义)
            若始 (k % primes[i] == 0)
                flag := 假  # k 是个合数，设置 flag 为假
                跳出        # 不用继续判断，跳出循环

                i := i + 1
            若终
        当终

        # 若 flag 未被修改为 假，
        # 则表明没有已知质数可以整除 k，
        # 也就是说 k 是质数
        若始 (flag == 真)
            primes := primes + [k]
        若终

        k := k + 1
    当终

    返回 primes
算终
```

</div>

	
- 优化版本

<div class="long-code">

```mathematica
算始 生成质数序列 (n)
    若始 (n < 2)
        返回 []
    又若 (n == 2)
        返回 [2]
    若终

    primes := [2]
    k := 3
    当始 (k <= n)

        i := 0
        flag := 真      # 这个标志先假定 k 为质数
        当始 (primes[i] != 未定义)
            若始 (k % primes[i] == 0)
                flag := 假  # k 是个合数，设置 flag 为假
                跳出        # 不用继续判断，跳出循环

                i := i + 1
            若终
        当终

        # 若 flag 未被修改为 假，
        # 则表明没有已知质数可以整除 k，
        # 也就是说 k 是质数
        若始 (flag == 真)
            primes := primes + [k]
        若终

        # k 从 3 开始，只需要检测奇数
        k := k + 2
    当终

    返回 primes
算终
```

</div>

	
3) 尝试证明：任意合数至少有一个质因数。

- 证明：
   1) 根据合数的定义，给定的任意合数 `$ n $` 可以分解为两个整数之乘积，且这两个整数均不为 `$ 1 $` 和 `$ n $`。也就是说有：`$ n = a \times b,\ (1 < a < n,\ 1 < b < n) $`。
   2) `$ a $` 和 `$ b $` 有两种情况：第一，全是质数；第二，有一个是质数另一个是合数；第三，全是合数。若是前两种情况，则得证。
   3) 对第三种情况，取其中一个合数，设其为 `$ n_1 $`，然后继续分解 `$ n_1 $` 并判断其两个因子。
   4) 重复以上过程 `$ m $` 次，并假设每次得到的两个因子均为合数（步骤 2 中的第三种情况），则必然有 `$ 1 < n_{m + 1} < n_m < \cdots < n_1 < n $`。
   5) 当 `$ m $` 足够大时，`$ n_{m + 1} $` 只能取 `$ 2 $`；而 `$ 2 $` 是质数，所以得证。

		
## 第七讲 整数的质因子分解

	
1) 写出质因子分解算法朴素版的考鼎码；该考鼎码分解一个大于 `$ 1 $` 的正整数 `$ n $`，返回一个序列，其中包含该正整数的所有的质因子。注意：如果是该正整数是一个质数，则结果序列中应仅包含自己。

<div class="long-code">

```mathematica
算始 质因子分解 (n)
    若始 (n < 2)
        返回 []
    又若 (n < 4)
        返回 [n]
    若终

    # factors 用来保存找到的质因子，初始化为空序列
    factors := []

    k := 2
    当始 (k <= n)

        若始 (n % k == 0)
            # 以下代码段判断 k 是否为质数

            # 这个标志先假定 k 为质数
            flag := 真
            i := 2
            当始 (i * i < k)
                若始 (k % i == 0)
                    # k 是个合数，设置 flag 为假
                    flag := 假
                    跳出
                若终
                i := i + 1
            当终

            # 若 flag 未被修改为 假，说明 k 是质数
            # 加入到 factors 序列
            若始 (flag == 真)
                factors := factors + [k]
            若终
        若终

        k := k + 1
    当终

    返回 factors
算终
```

</div>

	
2) 写出质因子分解算法优化版的考鼎码；要求同上。

<div class="long-code">

```mathematica
算始 质因子分解 (n)
    若始 (n < 2)
        返回 []
    又若 (n < 4)
        返回 [n]
    若终

    # factors 用来保存找到的质因子，初始化为空序列
    factors := []

    k := 2
    当始 (k <= n)

        若始 (n % k == 0)

            # 将 n 中所有的 k 除尽
            # 比如 n 为 100 时，以下循环会让 n 变成 25
            当始 (n % k == 0)
                n := n // k
            当终

            factors := factors + [k]
        若终

        k := k + 1
    当终

    返回 factors
算终
```

</div>

	
3) 试着证明：若一个正整数 `$ a $` 的平方为偶数，则 `$ a $` 一定是偶数。

- 证明：
   1) 一个数要么是奇数要么是偶数，而一个奇数的平方始终为奇数，一个偶数的平方始终为偶数。
   2) 故，若一个正整数 `$ a $` 的平方为偶数，则 `$ a $` 一定是偶数。

		
## 第八讲 欧几里得算法

	
1) 利用短除法手工求 `30` 和 `22` 的最大公因子。

	
2) 利用欧几里得算法手工求 `337` 和 `21` 的最大公因子。

	
3) 若两个数的最大公因子为 `$ 1 $`，则称这两个数为互质。请从 `$ 1,\ 2,\ 3,\ 9,\ 25,\ 31,\ 91 $` 中挑选出所有互质的数对（如 `$ 2,\ 3 $`）。

	
4) 使用本讲给出的欧几里得算法，当给定的初始值 `a, b` 取下列各值时，写出算法结束时各变量的值以及执行结果（注：使用表格）。  
      a) `a=22, b=11`<br/>
      b) `a=125, b=20`

	
5) 为防止在取模过程中出现除数为零的情形，需要调整本讲给出的欧几里得算法，请尝试添加代码使之可以避免出现除数为零的情况。

	
6) 写出求最小公倍数的考鼎码。

		
## 第九讲 中国剩余定理

	
1) 我们可以用考鼎码关键词 `且` 将多个逻辑判断表达式连接在一起，表示多个判断同时为 `真` 时整个结果才能为 `真`。比如 `(x >= 3 且 x < 6)` 表示 `x` 取值范围为大于等于 `3` 且小于 `6`；比如 `x` 取值为 `9` 时，对应表达式的值为 `假`。类似地，我们可以关键词 `或` 连接多个逻辑判断表达式，用来表示这些表达式只要有一个为 `真` 则整个结果为 `真`。请使用考鼎码关键词 `且` 调整本节给出的孙子定理朴素解法之考鼎码。

	
2) 本讲给出的孙子定理朴素解法有点低效，请尝试优化。

	
3) 满足中国剩余定理所述问题的整数是唯一的吗？如果不唯一且得到一个解，那么满足该定理的其他整数如何求得？请给出其考鼎码。

	
4) 思考如果模数不是固定的 `$ 3,\ 5,\ 7 $`，对应的余数也不是固定的 `$ 2,\ 3,\ 3 $`，甚至可能给出更多的模数和对应的余数，我们需要如何改造考鼎码算法以适应这种情况？

	
5) 孙子定理提到的 `$ 3,\ 5,\ 7 $` 这样的模数是互质的。请思考如果这些模数不满足互质的条件，会导致什么样的结果？

		
## 第十讲 幻方

	
1) 已知填充幻方的连续整数的起始值 `$ n $`，写出计算 `$ 3 \times 3 $` 幻方各行、列或对角线之和的考鼎码算法。

	
2) 在以上条件下，写出确定对应幻方中心位置数值的考鼎码算法。

	
3) 在以上条件下，画出当选择两个中心位置之外的数值分别填充左上角和右上角，然后确定其他格子的数值并得出是否可以成功解出幻方的算法流程图。

