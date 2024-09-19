#include <bits/stdc++.h>

using ll = long long;

void solve() {
  int n;
  std::cin >> n;
  std::string s;
  std::cin >> s;

  int ans = INT_MAX;
  for (int len = 1; len * len <= n; ++len) {
    int tot = 0;
    if (n % len)
      continue;
    for (int x = 1; x <= n / len; ++x) {
      for (int pos = 0; pos < len; ++pos)
        if (s[pos + (x - 1) * len] != s[pos])
          tot++;
    }
    if (tot <= 1)
      ans = std::min(ans, tot);
  }
  std::cout << ans << '\n';
}

int main() {
  int tt;
  std::cin >> tt;
  while (tt--) {
    solve();
  }
}
