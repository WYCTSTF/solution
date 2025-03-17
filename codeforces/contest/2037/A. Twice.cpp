#include <bits/stdc++.h>
#include <iostream>
int main() {
  int tt;
  std::cin >> tt;
  while (tt--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
      int tem;
      std::cin >> tem;
      a[tem]++;
    }
    int score = 0;
    for (int i = 0; i <= n; ++i)
      score += a[i] / 2;
    std::cout << score << '\n';
  }
  return 0;
}
