[Problem 601](https://projecteuler.net/problem=601 "Problem 601 - Project Euler")

对于每个整数 $n$ 我们可以定义一个函数 $streak(n)=k$，其中$k$ 是最小的 $n+k$ 不能被 $k+1$ 整除的数。比如
```
13 可以被 1 整除
14 可以被 2 整除
15 可以被 3 整除
16 可以被 4 整除
17 不可以被 5 整除
```
所以 $streak(13)=4$。类似的
```
120 可以被 1 整除
121 不可以被 2 整除
```
所以 $streak(120)=1$。

$P(s,N)$ 是满足下面两个条件的 $n$ 的和
1. $1 < n < N$
2. $streak(n)=s$

题目给了两个值 $P(3,14)=1$ 和 $P(6,106)=14286$ 帮助验证自想法和实现。

求 $\sum_{i=1}^{31} P(i, 4^i)$

首先看下 $N$ 的数量级，$4^{31}=2^{62}$，都接近 `long` 的数量级了，遍历小于 $N$ 的每个数显然是不合适的。

整除 $k+1$，其实就是被 2，3，4 等整除。手算了 $i=1，2，3，4$ 的情况，发现有规律的：

比如 $i=4$，那么到了 2 3 4 5 的最小公倍数往后的情况和之前的情况是一样的，循环起来了。

那么如果能计算最小公倍数以内的情况，那么就能很容易得到全部的情况。

不过事与愿违，从 2 到 32 这 31 个数的最小公倍数是一个长达 15 的数字，虽然比 $2^{62}$ 小好几个数量级，但是还是不能遍历。

这条路走不通。

下面是一种直接计算的方式。

什么样的 $n$ 满足 $streak(n)=s$ 呢？$(n+1)\% 2 == 0$，否则 $streak(n)=1$。同理，$(n+2)\% 3 == 0$ 等等。

类推到 $(n+s-1) \% s == 0$，最后 $(n+s) \% (s+1) != 0$。

对于前面 $s-1$ 个等式被整除的数都减去 $k$，$k=2,3\cdots s$，得到一个统一的式子
$$(n-1) \% k == 0$$
也就是说，$n-1$ 是 $2,3\cdots s$ 最小公倍数的若干倍。利用这一点，可以容易的找到可能的候选 $n$，$n$ 的数量不会很多，对于 $i$ 等于 31 的情况，粗略估计也只有四位数个吧。

最后利用 $(n+s) \% (s+1) !=0$ 得到 $n$，然后求和。

下面是 $P$ 函数的代码
``` csharp
static long P(int s, long N)
{
    long lcm = Enumerable.Range(1, s)
        .Select(Convert.ToInt64)
        .Aggregate((cur, next) => Utils.GetLcm(cur, next));

    return Enumerable.Range(1, (int)((N - 2) / lcm))
        .Select(i => i * lcm + 1)
        .Count(c => (c + s) % (s + 1) != 0);
}
```
`Enumerable.Range(1, s)`，多了个 1，对于最小公倍数没有影响。`N-2` 的原因是
> 1. $1 < n < N$

调用 $P$ 函数得到和
``` csharp
Enumerable.Range(1, 31).Select(i => P(i, 1L << 2 * i)).Sum();
```
