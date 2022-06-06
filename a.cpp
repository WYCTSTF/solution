#include <bits/stdc++.h>
using namespace std;

const int N = 501000;
const int M = 1010000;
stack<pair<int, int>> sta;
set<int> vis;
int n, m;
int pos[M];

int main() {
  vis.insert(0);
  sta.push(make_pair(1, 0));
  pos[0] = 1;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int op, x, y;
    cin >> op;
    if (op == 1) {
      cin >> x >> y;
      x = n - x + 1;
      while (!sta.empty() && sta.top().first >= x) {
        if (sta.top().first == pos[sta.top().second]) {
          pos[sta.top().second] = -1;
          vis.erase(sta.top().second);
        }
        sta.pop();
      }
      sta.push(make_pair(x, y));
      vis.insert(y);
      if (pos[y] == 0)
        pos[y] = x;
      else
        pos[y] = min(pos[y], x);
    } else
      cout << vis.size() << endl;
  }
  return 0;
}