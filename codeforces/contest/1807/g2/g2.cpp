#include <bits/stdc++.h>
#ifdef LOCAL
#include "dbg.h"
#else
#define debug(...) 42
#endif
using ll = long long;
using namespace std;
bool solve() {
  int n;
  cin >> n;
  ll l = 1, r = 1;
  vector<int> a(n, 0);
  for (int &i : a)
    cin >> i;
  sort(a.begin(), a.end());
  if (a[0] != 1)
    return false;
  for (int i = 1; i < n; ++i) {
    if (a[i] > r)
      return false;
    r += a[i];
  }
  return true;
}
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    if (solve())
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}