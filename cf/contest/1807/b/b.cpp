#include <bits/stdc++.h>

using ll = long long;
using namespace std;

bool solve() {
  int n;
  cin >> n;
  int a = 0, b = 0;
  for (int i = 1; i <= n; ++i) {
    int tem;
    cin >> tem;
    if (tem % 2)
      b += tem;
    else
      a += tem;
  }
  if (a <= b)
    return false;
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
