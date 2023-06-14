#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, s;
  cin >> n >> m >> s;
  vector<vector<int>> adj(n + 1);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> dep(n + 1);
  vector<vector<int>> f(n + 1, vector<int>(26, 0));
  dep[0] = 0;
  function<void(int, int)> dfs = [&](int u, int fr) {
    dep[u] = dep[fr] + 1;
    f[u][0] = fr;
    for (int i = 1; dep[u] >= (1 << i); ++i)
      f[u][i] = f[f[u][i - 1]][i - 1];
    for (auto &v : adj[u]) {
      if (v ^ fr) {
        dfs(v, u);
      }
    }
  };
  dfs(s,0);
  auto qry=[&](int u,int v){
    if(u==v)return u;
    if(dep[u]<dep[v])swap(u,v);
    for(int i=20;i>=0;--i)
      if(dep[f[u][i]]>=dep[v])
        u=f[u][i];
    if(u==v)return u;
    for(int i=20;i>=0;--i)
      if(f[u][i]!=f[v][i])
        u=f[u][i],v=f[v][i];
    return f[u][0];
  };
  for(int i=1;i<=m;++i){
    int u,v;cin>>u>>v;
    cout<<qry(u,v)<<'\n';
  }
  return 0;
}
