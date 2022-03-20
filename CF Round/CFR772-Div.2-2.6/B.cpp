#include <bits/stdc++.h>
#define max(a, b) (a > b ? a : b)

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int tt, ans = 0;
  std::cin >> tt;
  std::vector<int> a;
  
  for (; tt; tt--) {
    int n;
    std::cin >> n;
    a.resize(n, 0);
    for (int i = 0; i < n; i++)
      std::cin >> a[i];

    auto fix = [&](int pos) -> void {
      a[pos] = max(a[pos - 1], a[pos + 1]);
    };

    auto check = [&](int pos) -> bool {
      if (a[pos] > a[pos-1] && a[pos] > a[pos + 1]) return true;
      else return false;
    };
    
    ans = 0;
    for (int i = 1; i < n - 1; i++) {
      if (check(i)) {
        ans++;
        if (i + 2 < n && check(i+2)) fix(i+1);
        else fix(i);
      }
    }
    std::cout << ans << std::endl;
    for (auto it : a) {
      std::cout << it << ' ';
    }
    std::cout << std::endl;
  }
  return 0;
}