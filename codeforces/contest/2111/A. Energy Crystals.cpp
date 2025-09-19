#include <iostream>
int main() {
  int tt;
  std::cin >> tt;
  while (tt--) {
    int x;
    long long sum = 1;
    std::cin >> x;
    while (x > 0) {
      sum += 2, x /= 2;
    }
    std::cout << sum << '\n';
  }
  return 0;
}
/*
 * 14 14 14
 * 14 14 7
 * 14 7 7
 * 3 7 7
 * 7 3 3
 * 1 3 3
 * 1 1 3
 * 1 1 1
 * 1 0 1
 * 1 0 0
 * x x x
 * x/2 x x
 * x/2 x/2 x
 * x/2/2 x/2 x/2
 * x/2/2 x/2/2 x/2
*/
