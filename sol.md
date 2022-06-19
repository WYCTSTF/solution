# ICPC校赛题解

## 查漏补缺

令 $A=\sum\limits_{i=1}^n a[i]$， $B=\sum\limits_{i=1}^{n-1}b[i]$， $C=\sum\limits_{i=1}^{n-2}c[i]$

答案即为 $A-B$ 和 $B-C$

```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n - 1), c(n - 2);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n - 1; i++)
    cin >> b[i];
  for (int i = 0; i < n - 2; i++)
    cin >> c[i];
  long long A = accumulate(a.begin(), a.end(), 0LL),
            B = accumulate(b.begin(), b.end(), 0LL),
            C = accumulate(c.begin(), c.end(), 0LL);
  cout << A - B << '\n' << B - C << endl;
  return 0;
}
```

复杂度 $O(N)$

## 英雄交换

如果a[2]=4 那么我们说2和4关联

画图或者分析可以知道，所有关联的点为 $1$ 组，共 $k$ 组的话，那么答案就是 $n-k$

```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

bool vis[N];

int main() {
  int tt; cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n+1);
    memset(vis,false,sizeof vis);
    for (int i = 1; i <= n; i++) cin >> a[i];
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      if (vis[i] == 0) {
        cnt++;
        for (int j = i; vis[j] == false; j = a[j])
          vis[j] = true;
      }
    }
  }
  return 0;
}
```

每个点只会被扫描标记一次，均摊 $O(N)$

## 泰泰的电子厂

令 $a[i]$ 表示能从别的点到 $i$ 的节点个数

显然，对于每个节点，我们都要统计它能到哪些节点$\{j\}$，并且给这些点的 $a[j]+1$

最后统计的时候，如果有一个点$a[i] == n-1$ 那么说明这个点能被别的所有点访问

```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector a(n + 1, 0), to(n + 1, 0);
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      to[u] = v;
    }
    for (int i = 1; i <= n; i++) {
      if (to[i] != 0) {
        int tag = i;
        while (tag != 0) {
          a[to[tag]]++;
          tag = to[tag];
        }
      }
    }
    bool flag = false;
    for (int i = 1; i <= n; i++) {
      if (a[i] == n - 1) {
        flag = true;
        cout << i << endl;
        break;
      }
    }
    if (!flag)
      cout << -1 << endl;
  }
  return 0;
}
```

处理 $a[i]$ 的部分在树是一个链的时候最复杂，最坏 $O(N^2)$

当构成一个菊花图的时候，最好 $O(N)$

## 做题训练

签到题，循环或者列式计算都可

```cpp
#include <bits/stdc++.h>
using namespace std;
long long calc(int k) {
  return 2*k*(k+2)/3;
}
int main() {
  int n;
  cin >> n;
  long long sum = 0, now = 1;
  while (sum + calc(now) <= n) {
    sum += calc(now);
    now++;
  }
  cout << --now << endl;
  return 0;
}
```

## 杰哥的妹子序列

暴力可得60分

```cpp
#include <bits/stdc++.h>
using namespace std;

int a[500010];

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int op;
    cin >> op;
    if (op == 1) {
      int x, y;
      cin >> x >> y;
      for (int i = n; i >= n - x + 1; i--) {
        a[i] = y;
      }
    } else {
      set<int>s{a+1,a+n+1};
      cout << s.size() << endl;
    }
  }
  return 0;
}
```

观察可知正序或者倒序并不影响答案

当区域修改时，我们可以维护一个 $x$ 单调上升的栈

如果后来的 $x'$ 大于栈顶的 $x$ 说明它位于更靠后的一段位置，这时要考虑这个颜色是否已经出现过

如果小于等于当前栈顶 $x$ 说明原来的区域被新的覆盖，一直退栈到栈顶 $x$ < 当前 $x'$，同时更新答案即可

对于每个查询 $O(1)$ 回答，对于每个修改操作，至多 $M$ 次，复杂度 $O(M)$

```cpp
#include <bits/stdc++.h>
using namespace std;
int vis[1000005];
int main() {
  int n, m, res = 1;
  cin >> n >> m;
  vector<pair<int, int>> q;
  q.push_back({n, 0});
  vis[0] = 1;
  while (m--) {
    int op, x, y;
    scanf("%d", &op);
    if (op == 1) {
      scanf("%d%d", &x, &y);
      while (!q.empty() && q.back().first <= x) {
        int u = q.back().second;
        vis[u]--;
        if (vis[u] == 0)
          res--;
        q.pop_back();
      }
      q.push_back({x, y});
      vis[y]++;
      if (vis[y] == 1)
        res++;
    } else
      printf("%d\n", res);
  }
  return 0;
}
```

## ICPC竞赛排行榜

我们使用结构体保存每支队伍的队号 $id$、解题数 $u$、总罚时 $v$ 以及每一题 $i$ 错误的次数 $cnt[i]$。

对于输入的每组 $x,y,s,t$，如果 $s=0$，说明队伍 $x$ 交了一次 $y$ 题的错误代码，那么队伍 $x$ 的 $cnt[i]++$；如果 $s=1$，说明队伍 $x$ 在 $t$ 时刻交了 $y$ 题的正确代码，那么队伍 $x$ 的解题数 $u++$，总罚时 $v+=t+cnt[i]*1200$，即加上当前的时间和之前错误次数所产生的罚时。

处理完所有的日志后按解题数从大到小，相同解题数则总罚时从小到大，相同总罚时则队号从小到大对每只队伍进行排序。然后输出排名前k的队伍信息即可。

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1010;
int n, k;

struct Team
{
  int id, u, v;
  int cnt[15];
  bool operator< (const Team &t) const
  {
    if (u != t.u) return u > t.u;
    else if (v != t.v) return v < t.v;
    else return id < t.id;
  }
}team[N];

int main()
{
  cin >> n >> k;
  int x, y, s, t;
  for (int i = 0; i < n; i++) team[i].id = i;
  while (cin >> x >> y >> s >> t)
  {
    if (!s) team[x].cnt[y]++;
    else team[x].u++, team[x].v += t + team[x].cnt[y] * 1200;
  }
  sort(team, team + n);
  for (int i = 0; i < k; i++) cout << team[i].id << ' ' << team[i].u << ' ' << team[i].v << endl;
  return 0;
}
```

## 小龙找DNA

后缀自动机

无需深究...

感兴趣移步 [SA & SAM](https://oi-wiki.org/string/sa/)

## 最大乘积

DFS可得部分分

**动态规划**：维护当前状态下的最大正值和最小负值
设当前数为a[i]

* 若a[i]>0，则

  最大正值[i]=max(最大正值[i-2]*a[i],最大正值[i-1])

  最大负值[i]=max(最大负值[i-2]*a[i],最大负值[i-1])

* 若a[i]<0，则

  最大正值[i]=max(最大负值[i-2]*a[i],最大正值[i-1])

  最大负值[i]=max(最大正值[i-2]*a[i],最大负值[i-1])

```cpp
#include <iomanip>
#include <iostream>
using namespace std;
const int N = 250;
double dpA[N], dpB[N], a[N];
int n;
int main(void) {
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++) {
    if (a[i] > 0) {
      dpA[i + 2] = max((dpA[i] != 0 ? dpA[i] : 1) * a[i], dpA[i + 1]);
      dpB[i + 2] = min(dpB[i] * a[i], dpB[i + 1]);
    } else if (a[i] < 0) {
      dpA[i + 2] = max(dpB[i] * a[i], dpA[i + 1]);
      dpB[i + 2] = min((dpA[i] != 0 ? dpA[i] : 1) * a[i], dpB[i + 1]);
    } else
      dpA[i + 2] = dpA[i + 1], dpB[i + 2] = dpB[i + 1];
  }
  cout << fixed << setprecision(4) << dpA[n + 1];
  return 0;
}
```
----


## 矩形覆盖

找出第一个矩形的左下角坐标$(x1,y1)$ 和 右上角坐标 $(x2,y2)$
以及第二个矩形的左下角坐标$(x3,y3)$ 和 右上角坐标 $(x4,y4)$

答案即为$[min(y2, y4)-max(y1, y3)]\times[min(x2, x4)-max(x1, x3)]$

分类讨论几种情况即可得之

## 杰哥的妹子方阵

令杰哥所在位置为(0,0) 不考虑所在的列和行能看到的两人

剩余人数即斜率不同的个数，进一步得到 $gcd(x,y)=1 | x>0,y>0$ 的数量 $+2$ 就是答案

即 $\sum\limits_{i=1}^{n-1}\sum\limits_{j=1}^{m-1}[gcd(i,j)==1]$ 其中 $[ n ]$ 即单位函数 $\varepsilon(n)=\begin{cases}1 & while\ n=1 \\ 0 & otherwise\end{cases}$

<!-- `gcd(x,y) = if (b==0) then x else gcd(y,x%y)` 仅考虑初始时 $x>y$ -->


至此测试点 $1-10$ 在 $O(nm)$ 复杂度可做，有50的部分分

特判 $n = 1, m = 1$ 的一些情况可得测试点 $1-3$ 的 $15$ 分

下面为了方便讨论，令 $n=n-1$，$m=m-1$

对于测试点 $11 - 13$，$n=m$，我们统计 $\sum\limits_{i=1}^{n}\sum\limits_{j=1}^{n}[gcd(i,j)=1]$

这就是 $2\times\sum\limits_{i=1}^{n}\varphi(i)+1$，$\varphi(n)$ 为欧拉函数，表示 $1\to n$ 中与 $n$ 互质的数

例如 $\varphi(p) = p-1$ ($p$为质数)，$\varphi(1)=1$

首先考虑一个质数$p$,先来证一下结论：
$$\varphi(p^c)=p^c-p^{c-1}$$
对于质数p而言，$[1，p^c]$中与$p^c$不互质的数有$p^{c-1}$个，即$p^k$,$k\in[1,c)$，相当于用总数减去p的倍数

推广而言，我们容易发现$\varphi(p_1^{k_1}* p_2^{k_2})=\varphi(p_1^{k_1})*\varphi(p_2^{k_2})$，容斥一下也就是总数-$p_1$的倍数-$p_2$的倍数，再加上$p_1$、$p_2$的倍数

$$N-\frac{N}{p_1}-\frac{N}{p_2}+\frac{N}{p_1p_2}=N(1-\frac{1}{p_1})(1-\frac{1}{p_2})$$

事实上这就是欧拉函数的积性性质

积性函数：
若n,m互质，有f(mn)=f(m)*f(n)，则称函数为积性函数
若此质因数分解之后，$\forall n=p_1^{k_1}p_2^{k_2}...p_c^{k^c}$，有
$$\varphi(n)=\prod_{i=1}^c{p_i^{k_i-1}(p_i-1)}= n * \prod_{i=1}^c{\frac{p_i-1}{p_i}}= n * \prod_{i=1}^{c}({1-\frac{1}{p_i}})$$

根据计算式，只要分解质因数，即可顺便求出欧拉函数
```cpp
int phi(int n) {
    int ans=0;
    for (int i=2;i*i<=n;i++) {
        if (n%i==0) {
            ans = ans / i * (i-1);
            while (n%i==0) n/=i;
        }
    }
    if (n>1) ans=ans/n*(n-1);
    return ans;
}
```
这个过程可以用Pollar Rho优化

对于 $4*10^4$ 的数据，我们可以用试除法 $O(n\sqrt(n))$ 时间内处理

当然，利用积性函数的性质，线性筛也可以 $O(N)$ 时间内做到

------

对于更加一般的通式，我们需要使用莫比乌斯反演，降低计算的复杂度

前置知识是[狄利克雷卷积](https://zhuanlan.zhihu.com/p/137619492)，卷的是数论函数

## 定义：

常数函数 <b>$1$</b> 的 Dirichlet Inverse，我们将其称为莫比乌斯函数 $\mu$

$\displaystyle\mu(n) = \begin{cases}\frac{1}{1(n)} & while\ n =1 \\ -\frac{1}{1(1)}\sum\limits_{d\mid n,d>1}1(d)\mu(\frac{n}{d}) & otherwise\end{cases}$

$\forall$ 素数 $p$，有 $\mu(p) = -1, \mu(p^k)=0\ (k>1)$

即$\mu(n) = \begin{cases}1 & while\ n=1 \\ (-1) ^ m & while\ n=p_1p_2\dots p_m \\ 0 & otherwise \end{cases}$

其中 $p_1,\dots,p_m$ 都是质数

mobius反演 因数形式： $\displaystyle g(n) = \sum\limits_{d\mid n}f(d) \iff f(n) = \sum\limits_{d\mid n}\mu(d)g(\frac{n}{d})$

## 线性筛 $O(N)$ 求 $\mu(n)$

```cpp
bitset<N> vis;
int mu[N];
vector<int> primes;
void init() {
  mu[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (vis[i] == 0) {
      primes.push_back(i);
      mu[i] = -1;
    }
    for (auto p : primes) {
      if (p * i > n)
        break;
      vis[p * i] = 1;
      if (p % i == 0) {
        mu[i] = 0;
        break;
      } else
        mu[p * i] = mu[p] * mu[i];
    }
  }
}
```

## 性质

$\mu$ 满足

$$\sum\limits_{d\mid n}\mu(d) = \begin{cases} 1 & while\ n = 1 \\ 0 & otherwise \end{cases}$$

即 
$$\varepsilon = \mu * 1,\sum\limits_{d\mid n}\mu(d)=[n==1]=\varepsilon(n)$$

### 证明：

设 $n=\prod\limits_{i=1}^k{p_{i}^{c_i}}$, $n'=\prod\limits_{i=1}^k{p_i}$

有
$$\sum\limits_{d\mid n}{\mu(d)}=\sum\limits_{d\mid n'}\mu(d)=\sum\limits_{i=0}^k{C^i_k (-1)^i}=(1+(-1))^k$$

当 $k = 0$ 时，$n =1$，值为 $1$，其余为 $0$

二项式定理： $(x+y)^n=\sum\limits_{k=0}^n{\mathrm(_k^n)x^{n-k}y^k}$

----------

$$\sum\limits_{i=1}^{n}\sum\limits_{j=1}^{m}[gcd(i,j)==1]$$

$$\Rightarrow \sum\limits_{i=1}^{n}\sum\limits_{j=1}^{m}\sum_{d\mid x,d\mid y}\mu(d)$$

交换求和号，上下界改为 $d$ 的倍数

$$\sum\limits_{d=1}^{min(n,m)}\mu(d)\sum\limits_{x=1}^{\lfloor\frac{n}{d}\rfloor}1\sum\limits_{y=1}^{\lfloor\frac{m}{d}\rfloor}1$$

即

$$\sum\limits_{d=1}^{min(n,m)}\mu(d)\lfloor\frac{n}{d}\rfloor\lfloor\frac{m}{d}\rfloor$$

这样我们就能O(N)解决，如果配合树状数组、线段树维护前缀和，整除分块，复杂度可以达到$O(\sqrt{N})$

```cpp
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int mu[N];
bitset<N> vis;
vector<int> primes;
void init(int n) {
  mu[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (vis[i] == 0) {
      primes.push_back(i);
      mu[i] = -1;
    }
    for (auto p : primes) {
      if (p * i > n) break;
      vis[p * i] = 1;
      if (i % p == 0) {
        mu[i * p] = 0;
        break;
      } else {
        mu[i * p] = mu[i] * mu[p];
      }
    }
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  n--, m--;
  long long ans = 0;
  init(n);
  if (n == 0 && m == 0) {
    puts("0");
    return 0;
  }
  if (n == 0 || m == 0) {
    puts("1");
    return 0;
  }
  for (int d = 1; d <= min(n, m); d++) {
    ans += 1ll * mu[d] * (n / d) * (m / d);
  }
  cout << ans + 2 << endl;
  return 0;
}
```