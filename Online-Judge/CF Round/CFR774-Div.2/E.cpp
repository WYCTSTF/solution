#include <bits/stdc++.h>

signed main() {
  long long n, m;
  std::cin >> n >> m;
  std::vector frac(23, 0ll);
  std::bitset <20*1000000> vis;
  std::bitset <1000000> num;
  
  int cnt = 0;

  for (int i = 1; i <= 20; i++) {
    for (int j = 1; j <= m; j++) {
      if (vis[i * j] == 0) cnt++;
      vis[i * j] = 1;
    }
    frac[i] = cnt;
  }

  long long ans = 1;

  for (int i = 2; i <= n; i++) {
    if (num[i]) continue;
    long long j = 1, now = i;
    while (now <= n) {
      num[now] = 1;
      j++, now *= i;
    }
    j--;
    ans += frac[j];
  }
  std::cout << ans << '\n';
  return 0;
}