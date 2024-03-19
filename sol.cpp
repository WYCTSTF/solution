#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
typedef long long ll;
typedef pair<int, int> pll;
#define f first
#define s second

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int n, m;
int r, c;

int g[N][N];
int vis[N][N];

int ans = 0;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

void bfs(int x, int y) {
  queue<pll> q;
  q.push({x, y});
  while (!q.empty()) {
    auto it = q.front();
    cout << it.f << ' ' << it.s << endl;
    vis[it.f][it.s] = 1;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int ix = dx[i] + it.f;
      int iy = dy[i] + it.s;
      if (vis[ix][iy]) continue;
      if (ix >= 1 and ix <= n and iy >= 1 and iy <= m) {
        if (gcd(g[ix][iy], g[x][y]) > 1) {
          q.push({ix, iy});
          vis[ix][iy] = 1;
          ans++;
        }
      }
    }
  }
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> g[i][j];
    }
  }
  cin >> r >> c;
  bfs(r, c);
  cout << ans << endl;
  return 0;
}
