#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  string rs = s;
  reverse(rs.begin(), rs.end());
  cout << min({rs + s, s + rs , s}) << '\n';
}
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
