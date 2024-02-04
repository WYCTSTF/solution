#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "algo/debug.h"
#else
#define dbg(...) 42
#endif
using ll = long long;
bool check(ll k) {
  if (k == 1)
    return false;
  for (int i = 2; i * i <= k; ++i)
    if (k % i == 0)
      return false;
  return true;
}
int main() {
  int n;
  ll m = 0;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int tem;
    cin >> tem;
    m += tem;
  }
  if (n == 1) {
    if (check(m))
      cout << "Yes";
    else
      cout << "No";
  } else if (n == 2) {
    if (m < n * 2)
      cout << "No";
    else {
      if (m % 2 == 0 || check(m - 2))
        cout << "Yes";
      else
        cout << "No";
    }
  } else {
    if (m < n * 2)
      cout << "No";
    else
      cout << "Yes";
  }
  return 0;
}
