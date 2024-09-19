#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
  i64 ans = 0, tot = 1, high = 9, low = 1, n;
  cin >> n;
  while (low <= n) {
    ans += max(0ll, tot * (min(high, n) - low + 1));
    high = high * 10 + 9, low *= 10, tot++;
  }
  cout << ans << '\n';
}
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
