#include <bits/stdc++.h>

int main() {
  int tt;
  std::cin >> tt;
  while (tt--) {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
      std::cin >> a[i];
    
    if (a[0] == 1)
      puts("Yes");
    else
      puts("No");
  }
  return 0;
}