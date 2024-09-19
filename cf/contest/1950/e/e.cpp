#include <bits/stdc++.h>

using ll = long long;

void solve() {
  int n;
  std::cin >> n;
  std::string s;
  std::cin >> s;

  int ans = n;
  for (int len = 1; len * len <= n; ++len) {
    std::set<char> v1{};
    std::set<int> v2{};
    int tot = 0;
    if (n % len)
      continue;
    for (int x = 1; x < n / len; ++x) {
      for (int pos = 0; pos < len; ++pos)
        if (s[pos + x * len] != s[pos])
          v2.insert(pos), v1.insert(s[pos]);
    }
    if (v2.size() <= 1 && v1.size() <= 2)
      ans = std::min(ans, len);
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

