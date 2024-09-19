#include <bits/stdc++.h>

using ll = long long;

int main() {
  int tt;
  std::cin >> tt;
  while (tt--) {
    int a, b, c;
    std::cin >> a >> b >> c;
    if ((a + b + c) % 2) {
      std::cout << "-1\n";
    } else if (a + b >= c) {
      std::cout << (a + b + c) / 2 << '\n';
    } else
      std::cout << a + b << '\n';
  }
  return 0;
}
