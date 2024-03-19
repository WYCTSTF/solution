#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
  int n, c;
  cin >> n >> c;
  i64 total = 1ll * (c + 1) * (c + 2) / 2;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (auto ai : a) total -= 1ll * ai / 2 + 1, total -= c - ai + 1;
  int cnt[2] = {0, 0};
  for (auto ai : a) {
    cnt[ai % 2]++;
    total += cnt[ai % 2];
  }
  cout << total << '\n';
}
int main() {
  int tt;
  cin >> tt;
  while (tt--)
    solve();
  return 0;
}
