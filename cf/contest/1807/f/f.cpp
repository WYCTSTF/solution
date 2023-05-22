#include <bits/stdc++.h>
#ifdef LOCAL
#include "dbg.h"
#else
#define dbg(...) 42
#endif
using namespace std;
map<int, map<string, int>> vis;
map<string, pair<int, int>> dir;
void solve() {
  int n, m, x1, x2, y1, y2;
  string now;
  cin >> n >> m >> x1 >> y1 >> x2 >> y2 >> now;
  if (x1 == x2 && y1 == y2) {
    cout << "0\n";
    return;
  }
  vis.clear();
  int ans = 0;
  auto check = [&](int &x, int &y, string &to) {
    auto [tx, ty] = pair<int, int>{x - dir[to].first, y - dir[to].second};
    bool flag = false;
    string tem = to;
    if (x < 1 || x > n)
      to[0] = (to[0] == 'U') ? 'D' : 'U', flag = true;
    if (y < 1 || y > m)
      to[1] = (to[1] == 'L') ? 'R' : 'L', flag = true;
    if (!flag)
      return;
    ans++;
    x = tx + dir[to].first, y = ty + dir[to].second;
  };
  while (true) {
    dbg(x1, y1, now);
    if (vis[(x1 - 1) * m + y1][now]) {
      cout << "-1\n";
      return;
    }
    vis[(x1 - 1) * m + y1][now] = 1;
    x1 += dir[now].first, y1 += dir[now].second;
    check(x1, y1, now);
    if (x1 == x2 && y1 == y2) {
      cout << ans << '\n';
      return;
    }
  }
}
int main() {
  dir["UL"] = {-1, -1};
  dir["UR"] = {-1, 1};
  dir["DL"] = {1, -1};
  dir["DR"] = {1, 1};
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}