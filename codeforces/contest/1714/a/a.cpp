#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

#define rep(i, a, n) for (int i = a; i <= n; i++)
#define per(i, a, n) for (int i = n; i >= a; i--)
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
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
  int tt;
  cin >> tt;
  while (tt--) {
    int n, H, M;
    cin >> n >> H >> M;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i)
      cin >> v[i].first >> v[i].second;
    sort(all(v));
    auto it = lower_bound(all(v), PII{H, M});
    // cerr << it->first << ' ' << it->second << ' ' << it - v.begin() << ' ' <<
    // v.end() - v.begin() << '\n';
    int ans = 0;
    if (it == v.end() || it->first < H || (it->first == H && it->second < M)) {
      ans += (24 - H - 1) * 60 + 60 - M;
      ans += (v[0].first) * 60 + v[0].second;
    } else {
      if (it->second < M)
        it->first--, it->second += 60;
      ans += (it->first - H) * 60 + it->second - M;
    }
    cout << ans / 60 << ' ' << ans % 60 << endl;
  }
  return 0;
}