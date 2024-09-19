#include <bits/stdc++.h>

using ll = long long;

int main() {
  int tt;
  std::cin >> tt;
  while (tt--) {
    int a, b;
    // std::cerr << "fuck you  ----------- " << a << '\n';
    scanf("%d:%d", &a, &b);
    if (a < 12) {
      if (a == 0) a += 12;
      if (a < 10) std::cout << '0';
      std::cout << a << ':';
      if (b < 10) std::cout << '0';
      std::cout << b << " AM\n";
    } else {
      if (a > 12) a -= 12;
      if (a < 10) std::cout << '0';
      std::cout << a << ':';
      if (b < 10) std::cout << '0';
      std::cout << b << " PM\n";
    }
  }
  return 0;
}
