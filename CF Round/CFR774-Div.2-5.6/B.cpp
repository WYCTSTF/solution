#include <bits/stdc++.h>

int main() {
  int tt; std::cin >> tt;
  while (tt--) {
    int n;
    std::cin >> n;
    std::vector<int>a(n, 0);
    for (int i = 0; i < n; i++)
      std::cin >> a[i];
    long long s1 = 0, s2 = 0;
    sort(a.begin(), a.end());
    s1 += a[0], s1 += a[1];
    s2 += a[n-1];
    int t1 = 2, t2 = n-2;

    while (s2 <= s1 && t1 < t2) {
      if (s2 > s1) break;
      s1 += a[t1], s2 += a[t2];
      // std::cout << s1 << " " << s2 << std::endl;
      t1++, t2--;
    }
    if (s2 <= s1) puts("NO");
    else puts("YES");
  }
  return 0;
}