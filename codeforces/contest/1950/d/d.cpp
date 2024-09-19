#include <bits/stdc++.h>
constexpr int N = 1e5 + 10;
std::set<int> v;
std::bitset<N> vis;
bool check(int n) {
  while (n) {
    if (n % 10 > 1) return false;
    n /= 10;
  }
  return true;
}
int main() {
  int tt;
  std::cin >> tt;
  vis.reset();
  for (int i = 10; i <= 100000; ++i) {
    if (check(i)||vis[i]) v.insert(i), vis[i] = 1;
    if (!vis[i]) continue;
    for (auto &_ : v) {
      if (_ > i) break;
      if (i * _ > N) break;
      vis[i * _] = 1;
    }
  }
  vis[1] = 1;
  while (tt--) {
    int n;
    std::cin >> n;
    if (vis[n])
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
