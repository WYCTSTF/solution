#include <bits/stdc++.h>

int main() {
  int tt; std::cin >> tt;
  long long fac[15], t = 1;
  for (int i = 1; i <= 15; i++) t *= i, fac[i-1] = t;
  while (tt--) {
    long long n; std::cin >> n;
    
    int ans = 100;

    for (int i = 0; i < pow(2, 15); ++i) {
      std::bitset<15>b(i);
      long long t = n;
      for (int j = 0; j < 15; j++) t -= b[j] * fac[j];
      if (t >= 0) {
        std::bitset <64> b1(t);
        ans = std::min(ans, (int)(b.count() + b1.count()));
      }
    }
    std::cout << ans << '\n';
  }
  return 0;
}