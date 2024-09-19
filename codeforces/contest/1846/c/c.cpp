#include <bits/stdc++.h>
#define int long long
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned int;
using db = double;
using VI = std::vector<int>;
using PII = std::pair<int, int>;

#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define fi first
#define se second
#define pi acos(-1)
#define sz(x) ((int)(x).size())
#define all(x) x.begin(),x.end()

i64 gcd(i64 a,i64 b) { return b?gcd(b,a%b):a; }

void solve() {
  int n, m, h;
  cin >> n >> m >> h;
  vector<vector<int>> a(n + 1, vector<int>(m + 1, 0));
  rep(i, 1, n) rep(j, 1, m) cin >> a[i][j];
  vector<pair<int, int>>v;
  for (int i = 1; i <= n; ++i) {
    sort(a[i].begin() + 1, a[i].end());
    int now = 0, pass = 0, tot = 0;
    for (int j = 1; j <= m && now <= h; ++j) {
      if (now + a[i][j] <= h)
        now += a[i][j], tot += now, pass++;
      else
        break;
    }
    v.pb({pass, tot});
  }
  int t1 = v[0].fi, t2 = v[0].se;
  sort(v.begin(), v.end(), [&](const pair<int, int>&x, const pair<int,int>&y){return x.fi == y.fi ? x.se < y.se : x.fi > y.fi;});
  int now = 0;
  while (t1 < v[now].fi) now++;
  while (t2 > v[now].se) now++;
  cout << now + 1 << '\n';
}

signed main() {
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
