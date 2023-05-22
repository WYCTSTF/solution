#include <bits/stdc++.h>
using namespace std;

// 二分图判定
// 染色法 O(N)
const int N = 1000010;
int n, m, v[N];
vector<int> e[N];

bool dfs(int u, int c) {
  v[u] = c;
  for (int y : e[u]) {
    if (v[y] == c)
      return false;
    if (!v[y] && !dfs(y, 3 - c))
      return false;
  }
  return true;
}
int main() {
  for (int i = 1; i <= n; ++i) {
    if (!v[i] && !dfs(i, 1)) {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";
  return 0;
}

// ----------------------------------