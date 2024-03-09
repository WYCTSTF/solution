#include <bits/stdc++.h>
void solve() {
  int n;
  std::cin >> n;
  std::string s;
  std::cin >> s;
  int l = 0, r = s.size() - 1;
  while (l < r && s[l] == s[r]) l++, r--;
  int tag = 1;
  if (l < r && s[l] > s[r]) tag = 0;
  if (tag) {
    std::cout << s;
    if (n % 2) {
      std::reverse(s.begin(), s.end());
      std::cout << s;
    }
    std::cout << '\n';
  } else {
    std::reverse(s.begin(), s.end());
    std::cout << s;
    if (n % 2 == 0) {
      std::reverse(s.begin(), s.end());
      std::cout << s;
    }
    std::cout << '\n';
  }
}
int main() {
  int tt;
  std::cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
