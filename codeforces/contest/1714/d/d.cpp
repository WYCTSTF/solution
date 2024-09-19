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

vector<vector<PII>> ans(110);

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    string t;
    cin >> t;
    t = "$" + t;
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; ++i)
      cin >> v[i];
    int lt = t.size() - 1;

    // deb(v);
    // deb(t);
    vector<int> dp(lt + 1, INT_MAX);

    // cerr << "fuck" << '\n';

    function<bool(int, int)> check = [&](int x, int y) -> bool {
      if (v[y].size() + x > t.size())
        return false;
      for (int i = 0; i < (int)v[y].size(); ++i)
        if (t[i + x] != v[y][i])
          return false;
      return true;
    };

    ans.clear();
    // cout << lt << ' ' << '\n';
    dp[0] = 0;

    for (int i = 1; i <= lt; ++i) {
      if (dp[i - 1] == INT_MAX)
        break;
      for (int j = 0; j < n; ++j) {
        if (check(i, j) == false)
          continue;
        // deb(make_pair(i, j));
        for (int k = i; k < (int)(i + v[j].size()); ++k) {
          if (dp[k] >= dp[i - 1] + 1) {
            dp[k] = dp[i - 1] + 1, ans[k].clear();
            if (ans[i - 1].size())
              ans[k] = ans[i - 1];
            ans[k].pb({j + 1, i});
          }
        }
      }
    }

    // deb(dp);
    if (dp[lt] == INT_MAX)
      cout << -1 << '\n';
    else {
      cout << dp[lt] << '\n';
      for (auto [x, y] : ans[lt])
        cout << x << ' ' << y << '\n';
    }
  }
  return 0;
}