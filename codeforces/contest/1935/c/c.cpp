#include <bits/stdc++.h>
void solve(){
  int n, l;
  std::cin >> n >> l;
  std::vector<int> a(n), b(n), p(n);
  for (int i = 0; i < n; ++i)
    std::cin >> a[i] >> b[i];
  std::iota(p.begin(), p.end(), 0);
  std::sort(p.begin(), p.end(), [&](int i, int j) { return b[i] < b[j]; });
  std::vector<long long> dp(n + 1, 1e18);
  int ans = 0;
  for (auto i : p) {
    for (int j = n - 1; j >= 1; --j) {
      dp[j + 1] = std::min(dp[j + 1], dp[j] + a[i]);
      if (dp[j] + a[i] + b[i] <= l)
        ans = std::max(ans, j + 1);
    }
    dp[1] = std::min(dp[1], 1ll * a[i] - b[i]);
    if (a[i] <= l)
      ans = std::max(ans, 1);
  }
  std::cout << ans << '\n';
}
int main() {
  int tt;
  std::cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
