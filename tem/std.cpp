#include <bits/stdc++.h>
using namespace std;
void read() {}
template <typename T, typename... Ts> inline void read(T &arg, Ts &...args) {
  T x = 0, f = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-')
      f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 3) + (x << 1) + (c - '0');
    c = getchar();
  }
  arg = x * f;
  read(args...);
}
const int N = 1e5 + 5, inf = 0x3f3f3f3f;
int main() {
#ifdef ONLINE_JUDGE
  freopen("graph.in", "r", stdin);
  freopen("graph.out", "w", stdout);
#endif
  int n, m, k;
  read(n, m, k);
  array<int, N> in;
  array<vector<int>, N> e;
  vector<pair<int, int>> edge;
  for (int i = 1; i <= m; i++) {
    int u, v;
    read(u, v);
    edge.emplace_back(u, v);
  }
  sort(edge.begin(), edge.end());
  edge.resize(unique(edge.begin(), edge.end()) - edge.begin());
  for (auto [u, v] : edge)
    e[u].push_back(v), in[v]++;
  set<int> se[2];
  for (int i = 1; i <= n; i++)
    if (!in[i])
      se[0].insert(i);
  vector<int> ans;

  vector<pair<int, int>> res;
  while (!se[0].empty() || !se[1].empty()) {
    if (k && !se[0].empty()) {
      if (se[1].empty()) {
        se[1].insert(*se[0].rbegin());
        se[0].erase(*se[0].rbegin());
      }
      while (!se[0].empty() && k) {
        se[1].insert(*se[0].begin());
        se[0].erase(*se[0].begin());
        k--;
      }
    }
    int u = inf;
    if (!se[0].empty())
      u = *se[0].begin();
    if (!se[1].empty())
      u = min(u, *se[1].rbegin());
    if (se[1].find(u) != se[1].end()) {
      se[1].erase(u);
      if (!se[1].empty())
        res.emplace_back(u, *se[1].rbegin()); // loop？
    } else
      se[0].erase(u);
    ans.push_back(u);
    for (auto v : e[u])
      if (--in[v] == 0)
        se[0].insert(v);
  }
  for (auto it : ans)
    printf("%d ", it);
  printf("\n%lu\n", res.size());
  for (auto [u, v] : res)
    printf("%d %d\n", u, v);
  return 0;
}