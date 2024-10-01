#include <bits/stdc++.h>
using namespace std;
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    map<int, vector<int>> mp;
    for (int i = 1; i <= n; ++i)
      cin >> a[i], mp[a[i]].push_back(0);
    for (int i = 1; i <= m; ++i) {
      int x, y;
      cin >> x >> y;
      mp[a[x]].push_back(i);
      a[x] = y;
      mp[y].push_back(i);
    }
    long long ans = 0;
    for (auto &[x, v] : mp) {
      ans += 1ll * (m + 1) * m / 2;
      if ((int)v.size() % 2)
        v.push_back(m + 1);
      int las = 0, len = 0;
      for (int i = 0; i < v.size(); i += 2) {
        len += v[i] - las;
        las = v[i + 1];
      }
      len += m - las + 1;
      ans -= 1ll * (len - 1) * len / 2;
    }
    cout << ans << '\n';
  }
  return 0;
}