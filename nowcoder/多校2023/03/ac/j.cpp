#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n + 1);
  vector<int> in(n + 1, 0);
  for (int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    in[v]++;
    adj[u].push_back(v);
  }
  set<int> q;
  for (int i = 1; i <= n; ++i) {
    if (in[i] == 0)
      q.insert(i);
  }
  vector<int> ans{};
  while (!q.empty()) {
    int u = *q.begin();
    for (int v : adj[u]) {
      if (--in[v] == 0)
        q.insert(v);
    }
    ans.push_back(u);
    q.erase(u);
  }
  if (ans.size() == n) {
    cout << "1\n";
    for (int i : ans)
      cout << i << ' ';
  } else {
    cout << "2\n";
    for (int i = 1; i <= n; ++i)
      cout << i << " \n"[i == n];
    for (int i = n; i >= 1; --i)
      cout << i << " \n"[i == 1];
  }
  return 0;
}
