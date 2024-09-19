#include <bits/stdc++.h>
using namespace std;
void solve() {
  int a[8][8];
    memset(a, 0, sizeof a);
    for (int i = 0; i < 8; ++i) {
      string s;
      cin >> s;
      for (int j = 0; j < 8; ++j)
        a[i][j] = ((s[j] == '.') ? 0 : 1);
    }
    for (int i = 1; i < 7; ++i)
      for (int j = 1; j < 7; ++j)
        if (a[i][j] && a[i + 1][j + 1] && a[i + 1][j - 1] && a[i - 1][j + 1] && a[i - 1][j - 1])
          {cout << i + 1 << ' ' << j + 1 << '\n';return;}
}
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}