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