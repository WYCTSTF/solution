#include <bits/stdc++.h>
using namespace std;
struct Node {
  int x, y;
};
bool cmp1(const Node &a, const Node &b) {
  return a.x < b.x;
}
bool cmp2(const Node &a, const Node &b) {
  return a.y < b.y;
}
int main() {
  int n, m, tem, Max = -1;
  std::cin >> n >> m;
  vector <vector<Node>> e(100010);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      cin >> tem;
      e[tem].push_back({i, j});
      Max = max(Max, tem);
    }
  long long sum = 0, ans = 0, tot;
  for (int i = 1; i <= Max; i++) {
    if (e[i].size() <= 1) continue;
    sort(e[i].begin(), e[i].end(), cmp1);
    sum = e[i][0].x, tot = 1;
    for (int j = 1; j < e[i].size(); j++) {
      ans += (e[i][j].x) * tot - sum;
      sum += e[i][j].x; tot++;
    }
    sort(e[i].begin(), e[i].end(), cmp2);
    sum = e[i][0].y, tot = 1;
    for (int j = 1; j < e[i].size(); j++) {
      ans += (e[i][j].y) * tot - sum;
      sum += e[i][j].y; tot++;
    }
  }
  cout << ans << endl;
  return 0;
}