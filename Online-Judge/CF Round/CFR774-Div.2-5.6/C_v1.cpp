#include <bits/stdc++.h>

int main() {
  int tt, ans; std::cin >> tt;
  long long n;
  std::set <long long> s;
  std::vector <long long> frac;
  long long sum = 1, tot = 2;
  do {
    s.insert(sum);
    sum *= tot++;
  } while (sum <= 1e12);
  sum = 1;
  do {
    s.insert(sum);
    sum *= 2;
  } while (sum <= 1e12);

  frac.push_back(0);
  for (auto it : s)
    frac.push_back(it);

  // for (int i = 1; i < frac.size(); i++)
  //   std::cout << frac[i] << ' ';

#ifndef debug
  std::vector <long long> count(60, 0);
  for (int i = 1; i < frac.size(); i++)
    count[i] = count[i-1] + frac[i];

  auto dfs = [&](auto self, int now, long long tem, int cnt) -> void {
    if (tem > n) return;
    if (cnt > ans) return;
    if (tem == n) ans = std::min(cnt, ans);
    // if (tem + count[now - 1] < n) return;
    for (int i = now - 1; i >= 1; i--) {
      if (tem + count[i] < n) return;
      self(self, i, tem + frac[i], cnt + 1);
    }
  };
  while (tt--) {
    ans = INT_MAX;
    std::cin >> n;
    dfs(dfs, frac.size(), 0ll, 0);
    if (ans == INT_MAX)
      puts("-1");
    else
      std::cout << ans << std::endl;
  }
#endif
  return 0;
}