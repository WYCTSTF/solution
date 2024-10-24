#include <iostream>
int main() {
  int n;
  std::cin >> n;
  int now = 1;
  for (int len = n; len >= 1; --len) {
    for (int i = 1; i <= len; ++i) {
      if (now < 10) std::cout<<'0';
      std::cout<<(now++);
    }
    std::cout<<'\n';
  }
  return 0;
}
