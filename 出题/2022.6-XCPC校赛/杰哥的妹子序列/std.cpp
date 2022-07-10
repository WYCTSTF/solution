#include <bits/stdc++.h>
using namespace std;
int vis[1000005];
int main() {
  int n, m, res = 1;
  cin >> n >> m;
  vector<pair<int, int>> q;
  q.push_back({n, 0});
  vis[0] = 1;
  while (m--) {
    int op, x, y;
    scanf("%d", &op);
    if (op == 1) {
      scanf("%d%d", &x, &y);
      while (!q.empty() && q.back().first <= x) {
        int u = q.back().second;
        vis[u]--;
        if (vis[u] == 0)
          res--;
        q.pop_back();
      }
      q.push_back({x, y});
      vis[y]++;
      if (vis[y] == 1)
        res++;
    } else
      printf("%d\n", res);
  }
  return 0;
}