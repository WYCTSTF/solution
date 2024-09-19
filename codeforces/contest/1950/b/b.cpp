#include <bits/stdc++.h>

using ll = long long;

int main() {
  int tt;
  std::cin >> tt;
  while (tt--) {
    int n;
    std::cin >> n;
    for (int i = 0; i < n << 1; ++i) {
      for (int j = 0; j < n << 1; ++j) {
        if ((i / 2) % 2 == (j / 2) % 2)
          std::cout << "#";
        else
          std::cout << '.';
      }
      std::cout << '\n';
    }
  }
  return 0;
}
