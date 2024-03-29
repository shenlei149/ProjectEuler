[Problem 549](https://projecteuler.net/problem=549 "Problem 549 - Project Euler")

定义 $s(n) = m$，给定一个整数 $n$，$m$ 是最小的整数，使得 $m!$ 能够整除 $n$。

举两个简单的例子，$s(10)=5,s(25)=10$。

定义 $S(n) = \sum s(i) 2 \leq i \leq n$

题目中给了一个当 $n = 100$ 的值用于测试：$S(100)=2012$

求 $S(10^8)$

首先要意识到，不可能把阶乘本身算出来，比如 1517，由质数 37 和 41 相乘得到，那么对应的 $m$ 应该是 41，但是 41 的阶乘非常之大。

给定一个数 $n$，求满足题意的 $m$，因为这里肯定需要遍历所有的 $n$，$10^8$ 这么大了，所以求 $m$ 的函数的时间复杂度最好是常量时间，$n\lg(n)$ 也很快，$n\sqrt(n)$ 就太慢了，这都到 $10^{12}$ 次了，复杂度已经高的吓人了，计算机无法短时间算出来了。所以我们下面的目标就是在合理的时间复杂搞定 $s(n)$ 这个函数：一定要控制在 $nlg(n)$ 以内。

首先，如果这个数 $n$ 是质数，那么 $m$ 肯定就是 $n$ 本身。

对于一个非质数，一个可行的思路就是把 $n$ 分解质因数，质因数出现的次数也是需要保留的，要不然 25 这个数，是 $5\times 5$，如果不保留质因数的次数，那么计算得到的 $m$ 就成了 5 了，显然是不对的。然后再如何处理呢？

假设分解质因数结果是
$$p_1^{n_1}p_2^{n_2}\cdots p_q^{n_q}$$
想办法凑够 $n_1$ 个 $p_1$，$p_1$ 包含 1 个 $p_1$，$2p_1$ 又包含一个（如果 $p_1$ 等于 2，这里还会多包含一个），$3p_1$ 又包含一个 $p_1$，依次类推。再想办法凑够 $n_2$ 个 $p_2$。依此类推。共计 $q$ 个结果，最大的那个数字就是我们要求的 $m$。

以上想法计算 $S(100)$ 没啥问题。但是：分解质因数的函数离 $\lg(n)$ 还是差很远，所以导致短时间无法运算完毕。

如果我能过滤掉很多值不用去计算了，那么时间就能大大降低了。

首先 $10^8$ 以内的质数占了 5.7% 的样子，所以这 5.7% 是不用计算的。

其次，考虑某个质数 $p$，乘以小于它的某个数 $m$，得到的这个值 $n$，$S(n)$ 也是p。写一个两层 `for` 循环就能得出这些 $n$ 值，这占了大概 66.7%，这一下子就节省了大多数的时间。

再次，在上一条的基础上再进一步，某个质数 $p$，乘以两个小于它的数 $m_1$ 和 $m_2$，得到的 $n$ 值，$S(n)$ 也是 $p$。三层 `for` 循环能搞定，这大概占了 22.3%，又能节约挺多时间的了。这里可以做一个小的优化，$m_2$ 可以从 $m_1+1$ 和 $p/(m_1+1)$ 两者比较大的一方开始，因为如果 $m_2m_1$ 小于 $p$，那么这个数字肯定在上一步的时候就被标记了。

再再次，还能再排除 3.4% 的数据，这里也可以使用上面提到的优化思想。

最后，只剩约 1.9% 的数据需要按照之前说的逻辑进行判定了。

这次代码又丑又长，特别是中间的几个 `for` 循环嵌套。
