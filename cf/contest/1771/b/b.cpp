#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1, n);
    for (int i = 1; i <= m; ++i) {
      int l, r; cin >> l >> r;
      if (l > r) swap(l, r);
      a[l] = min(a[l], r - 1);
    }
    for (int i = n - 1; i >= 1; --i)
      a[i] = min(a[i + 1], a[i]);
    // for (int i = 1; i <= n; ++i)
    //   cout << a[i] << " \n"[i == n];
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
      int tem = a[i] - i + 1;
      ans += tem;
    }
    cout << ans << '\n';
  }
  return 0;
}