#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::pair;
using std::cin, std::cout, std::string;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int main() {
  string s;
  getline(cin, s);
  vector<int> p;
  int i = 0;
  int m = 0;
  bool fl = false;
  for (char i : s) {
    if (i == ']')
      fl = true;
    if (isdigit(i)) {
      p.push_back(i - '0');
      if (!fl)
        m++;
    }
  }
  int n = (int)(p.size()) / m;
  // cout << n << ' ' << m << '\n';
  vector<vector<int>> adj(n, vector<int>(m));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      adj[i][j] = p[i * m + j];
  vector<vector<int>> be(n, vector<int>(m, 0));
  vector<int> T(n * m, 0);
  int tot = 0;
  auto dfs = [&](auto self, int x, int y, int _be) -> void {
    be[x][y] = _be;
    T[_be]++;
    for (int i = 0; i < 4; ++i) {
      int _x = x + dx[i], _y = y + dy[i];
      if (_x < 0 || _x >= n || _y < 0 || _y >= m)
        continue;
      if (adj[_x][_y] == 1 && be[_x][_y] == 0)
        self(self, _x, _y, _be);
    }
  };
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (adj[i][j] == 1 && be[i][j] == 0) {
        be[i][j] = 1, dfs(dfs, i, j, ++tot);
      }
    }
  }
  int mx = -1;
  for (int i = 1; i <= tot; ++i)
    mx = std::max(mx, T[i]);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      if (adj[i][j] == 0) {
        vector<pair<int,int>> v;
        for (int k = 0; k < 4; ++k) {
          int x = i + dx[k], y = j + dy[k];
          if (x < 0 || x >= n || y < 0 || y >= m)
            continue;
          v.push_back({T[be[x][y]], be[x][y]});
        }
        for (auto g : v)
          for (auto h : v)
            if (g.second != h.second)
              mx = std::max(mx, g.first + h.first + 1);
            else mx = std::max(mx, g.first + 1);
      }
    }
  cout << mx << '\n';
  return 0;
}
