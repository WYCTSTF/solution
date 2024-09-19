#include <bits/stdc++.h>
#ifdef LOCAL
#include "dbg.h"
#else
#define debug(...) 42
#endif

#define int long long

using ll = long long;

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1, 0), b(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    b[i] = max(a[i], a[i - 1]) - a[i];
    a[i] = max(a[i], a[i - 1]);
  }
  // 5 3 4 2
  // 5 4 3 2
  vector<int> v;
  for (int i = 2; i <= n; ++i) {
    if (b[i] != 0) v.push_back(b[i]);
  }
  sort(v.begin(), v.end(), greater<ll>());
  int cnt = 0ll;
  ll ans = 0ll;
  for (signed i = v.size() - 1; i >= 0; --i) {
    ans += 1ll * (i + 2) * (v[i] - cnt);
    cnt = v[i];
  }
  cout << ans << '\n';
}

signed main() {
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
