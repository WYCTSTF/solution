#include <iostream>
#include <utility>
int main() {
  int tt;
  std::cin >> tt;
  while (tt--) {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    if (a > b) std::swap(a, b);
    if (c > d) std::swap(c, d);
    if (a > c) std::swap(a, c), std::swap(b, d);
    if (d > b && c < b)
      std::cout << "YES\n";
    else
      std::cout << "NO\n";
  }
  return 0;
}
