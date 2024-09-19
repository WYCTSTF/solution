#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  ll ans = 0;
  for (int x = 0; x < 3; ++x) {
    for (int y = x + 1; y < 3; ++y) {
      map<pair<int, int>, int> cnt;
      for (int i = 0; i + 2 < n; ++i) ans += cnt[{a[i + x], a[i + y]}]++;
    }
  }
  map<tuple<int, int, int>, int> cnt;
  for (int i = 0; i + 2 < n; ++i) ans -= 3 * cnt[{a[i], a[i + 1], a[i + 2]}]++;
  cout << ans << '\n';
}
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
