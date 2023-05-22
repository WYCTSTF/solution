#include <bits/stdc++.h>

using namespace std;

int main() {

  vector<int> s;

  int n, m;
  cin >> n >> m;

  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i)
    cin >> a[i];

  vector<vector<int>> adj(n + 1), inv(n + 1);
  for (int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    inv[v].push_back(u);
  }

  bitset<10000> vis;
  vis.reset();
  function<void(int)> dfs1 = [&](int u) {
    vis[u] = 1;
    for (int &v : adj[u])
      if (!vis[v])
        dfs1(v);
    s.push_back(u);
  };
  for (int i = 1; i <= n; ++i)
    if (vis[i] == 0)
      dfs1(i);

  int sc = 0;
  vector<int> scc(n + 1, 0);

  vector<int> val;
  function<void(int)> dfs2 = [&](int u) {
    scc[u] = sc;
    val[sc] += a[u];
    for (int &v : inv[u])
      if (!scc[v])
        dfs2(v);
  };
  val.push_back(0);
  for (int i = n - 1; i >= 0; --i) {
    if (!scc[s[i]]) {
      ++sc;
      val.push_back(0);
      dfs2(s[i]);
    }
  }

  vector<int> dp(sc + 1, 0), in(sc + 1, 0);
  vector<vector<int>> to(sc + 1);
  for (int i = 1; i <= n; ++i)
    for (int &v : adj[i])
      if (scc[i] != scc[v])
        in[scc[v]]++, to[scc[i]].push_back(scc[v]);
  set<int> S;
  for (int i = 1; i <= sc; ++i)
    if (!in[i])
      S.insert(i);
  while (!S.empty()) {
    int u = *S.begin();
    for (int &v : to[u]) {
      if (--in[v] == 0)
        S.insert(v);
      dp[v] = max(dp[v], dp[u] + val[u]);
    }
    S.erase(u);
  }
  int ans = 0;
  for (int i = 1; i <= sc; ++i)
    ans = max(ans, dp[i] + val[i]);
  cout << ans;
  return 0;
}
