#include <bits/stdc++.h>
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
  int n;
  i64 ans = -1;
  cin >> n;
  vector<int> v(n + 1);
  for (int k = 2; k <= n; ++k) {
    
    i64 tem = 0, mx = -1;
    for (int i = 1; i <= k; ++i)
      v[n - i + 1] = n - k + i;
    for (int i = 1; i <= n - k; ++i)
      v[i] = i;
    for (int i = 1; i <= n; ++i)
      tem += 1ll * i * v[i], mx = max(mx, 1ll * i * v[i]);
    // debug(v);
    tem -= mx;
    ans = max(ans, tem);
  }
  cout << ans << '\n';
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
