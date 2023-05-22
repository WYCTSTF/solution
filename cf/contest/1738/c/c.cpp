#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, n) for (int i = a; i <= n; i++)
#define per(i, a, n) for (int i = n; i >= a; i--)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pi acos(-1)
#define il inline
#define rg register
#define SZ(x) ((int)(x).size())
#define all(x) x.begin(), x.end()
#define INF 0x7fffffff
#define inf 0x3f3f3f3f
#define MOD 998244353
#define mod 1000000007
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef long long ll;
typedef double db;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;

    int tj = 0, to = 0;
    for (int i = 1; i <= n; ++i) {
      int tem;
      cin >> tem;
      if (tem % 2)
        tj++;
      else
        to++;
    }
    tj %= 4, to %= 4;

#define A puts("Alice");
#define B puts("Bob");

    if (tj == 0) {
      A
    } else if (tj == 1) {
      if (to == 0)
        B
      if (to == 1)
        A
      if (to == 2)
        B
      if (to == 3)
        A
    } else if (tj == 2) {
      B
    } else {
      A
    }
  }

  return 0;
}

/*

alice拿奇数不改变状态 bob拿奇数会改变状态

1. tj % 2 = 1, to % 2 = 0

2. 奇数个奇数 奇数个偶数

第一步 alice拿奇数 bob就拿偶数 反之一样，然后就变成 “偶数个偶数，偶数个奇数”

Alice 赢，除非奇数只有一个，那么bob赢

3. 奇数个奇数，偶数个偶数

alice拿奇数，bob就拿奇数

alice偶数，bob偶数

bob赢

4. 偶数个奇数，奇数个偶数

alice拿偶数，bob先手的情况1，alice赢

*/