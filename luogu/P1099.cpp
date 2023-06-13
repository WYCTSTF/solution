#include <bits/stdc++.h>
#ifdef LOCAL
#include <dbg.h>
#else
#define dbg(...) 42
#endif
using namespace std;
int main() {
  int n, s;
  cin >> n >> s;
  vector<vector<pair<int, int>>> adj(n + 1);
  for (int i = 1; i < n; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
  vector<int> dis(n + 1, 0);
  int st = 1;
  function<void(int, int, int &)> dfs = [&](int u, int fr, int &ep) {
    if (dis[u] > dis[ep])
      ep = u;
    for (auto &[v, w] : adj[u])
      if (v ^ fr)
        dis[v] = dis[u] + w, dfs(v, u, ep);
  };
  dis[1] = 0;
  dfs(1, 1, st);
  dis[st] = 0;
  int ed = 0;
  dfs(st, st, ed);
  dbg(st, ed);
  vector<int> dia;
  function<void(int, int, vector<int>)> get = [&](int u, int fr,
                                                  vector<int> path) {
    if (u == ed) {
      dia = path;
    }
    for (auto &[v, w] : adj[u]) {
      if (v ^ fr) {
        path.push_back(v);
        get(v, u, path);
        path.pop_back();
      }
    }
  };
  get(st, st, {st});
  // dbg(dia);
  vector<int> dep(n + 1, 0);
  vector<vector<int>> f(n + 1, vector<int>(26, 0));
  function<void(int, int)> pre = [&](int u, int fr) {
    dep[u] = dep[fr] + 1;
    f[u][0] = fr;
    for (int i = 1; dep[u] >= (1 << i); ++i)
      f[u][i] = f[f[u][i - 1]][i - 1];
    for (auto &[v, w] : adj[u]) {
      if (v ^ fr)
        pre(v, u);
    }
  };
  dep[st] = 1;
  pre(st, 0);
  function<int(int, int)> qry = [&](int u, int v) {
    if (u == v)
      return u;
    if (dep[u] < dep[v])
      swap(u, v);
    for (int i = 20; i >= 0; --i) {
      if (dep[f[u][i]] >= dep[v])
        u = f[u][i];
    }
    if (u == v)
      return u;
    for (int i = 20; i >= 0; --i) {
      if (f[u][i] != f[v][i])
        u = f[u][i], v = f[v][i];
    }
    return f[u][0];
  };
  function<int(int, int)> getd = [&](int u, int v) {
    return dis[u] + dis[v] - 2 * dis[qry(u, v)];
  };
  bitset<310> vis;
  int maxx, ans = INT_MAX;
  vector<int> dd(n + 1, 0);
  function<void(int)> mark = [&](int u) {
    maxx = max(maxx, dd[u]);
    for (auto &[v, w] : adj[u]) {
      if (vis[v] == 0) {
        vis[v] = 1;
        dd[v] = dd[u] + w;
        mark(v);
      }
    }
  };
  // cout << "fuck\n";
  for (int i = 0, j = 0; i < dia.size(); ++i) {
    while (j + 1 < dia.size() && getd(dia[i], dia[j + 1]) <= s)
      ++j;
    vis.reset();
    fill(dd.begin(), dd.end(), 0);
    maxx = -1;
    for (int k = i; k <= j; ++k)
      vis[dia[k]] = 1;
    for (int k = i; k <= j; ++k)
      mark(dia[k]);
    ans = min(ans, maxx);
  }
  cout << ans << '\n';
  return 0;
}