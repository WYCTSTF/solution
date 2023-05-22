#include <bits/stdc++.h>
using ll = long long;

int main() {
  int tt;
  std::cin >> tt;
  while (tt--) {
    int n;
    std::cin >> n;
    int mx = -1, mn = INT_MAX;
    int x = 1, y = 1;
    for (int i = 0; i < n; ++i) {
      int tem;
      std::cin >> tem;
      if (tem == mx)
        x++;
      if (tem > mx)
        x = 1, mx = tem;
      if (tem == mn)
        y++;
      if (tem < mn)
        y = 1, mn = tem;
    }
    if (mx == mn)
      std::cout << (ll)x * (x - 1) << '\n';
    else
      std::cout << (ll)2 * x * y << '\n';
  }
  return 0;
}