#include <bits/stdc++.h>

int main() {
  int n;
  std::cin >> n;
  std::vector <int> dp[2];
  std::vector <int> w[2];
  std::vector <int> val(n + 1);
  std::vector <std::vector<int>> e(n + 1);
  dp[0].resize(n + 1, 0), dp[1].resize(n + 1, 0);
  w[1].resize(n + 1, 0), w[0].resize(n + 1, 0);

  auto dfs = [&](auto self, int u, int fa) -> void {
    dp[0][u] = 0, dp[1][u] = 1;
    w[0][u] = 1, w[1][u] = e[u].size();
    for (auto v : e[u]) {
      if (v == fa) continue;
      self(self, v, u);

      dp[1][u] += dp[0][v], w[1][u] += w[0][v];

      if (dp[0][v] > dp[1][v] || (dp[0][v] == dp[1][v] && w[0][v] < w[1][v])) {
        dp[0][u] += dp[0][v];
        w[0][u] += w[0][v];
      } else {
        dp[0][u] += dp[1][v];
        w[0][u] += w[1][v];
      }
    }
  };

  auto tot = [&](auto self, int u, int fa, int op) -> void {
    if (op == 1)
      val[u] = e[u].size();
    else
      val[u] = 1;
    for (auto v : e[u]) {
      if (v == fa) continue;
      if (op == 1) {
        self(self, v, u, 0);
      } else {
        if (dp[0][v] > dp[1][v] || (dp[0][v] == dp[1][v] && w[0][v] < w[1][v]))
          self(self, v, u, 0);
        else
          self(self, v, u, 1);
      }
    }

  };

  for (int i = 1; i < n; i++) {
    int u, v; std::cin >> u >> v;
    e[u].push_back(v), e[v].push_back(u);
  }
  if (n == 2) {
    puts("2 2\n1 1");
    return 0;
  }
  dfs(dfs, 1, 0);
  // 随便定一个根 rt = 1
  if (dp[0][1] > dp[1][1] || (dp[0][1] == dp[1][1] && w[0][1] < w[1][1])) {
    std::cout << dp[0][1] << ' ' << w[0][1] << '\n';
    tot(tot, 1, 0, 0);
  } else {
    std::cout << dp[1][1] << ' ' << w[1][1] << '\n';
    tot(tot, 1, 0, 1);
  }
  for (int i = 1; i <= n; i++)
    std::cout << val[i] << ' ';
  return 0;
}