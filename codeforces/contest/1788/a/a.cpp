#include <bits/stdc++.h>

using ll = long long;
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  set<int> s;
  int tot = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    if (a[i] == 2)
      tot++;
    s.insert(tot);
  }
  int tag, now = 0;
  for (int i = 1; i <= n; ++i) {
    if (a[i] == 2)
      ++now;
    if (now * 2 == tot) {
      cout << i << '\n';
      return;
    }
  }
  cout << "-1\n";
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}