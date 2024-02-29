#include <bits/stdc++.h>

void solve() {
  std::set<int> s;
  int a, b, l, L;
  std::cin >> a >> b >> l;
  L = l;
  int x = 0, y = 0;
  while (L % a == 0)
    x++, L /= a;
  L = l;
  while (L % b == 0)
    y++, L /= b;
  for (int i = 1, tx = a; i <= x && l % tx == 0; ++i, tx *= a) 
  {
    for (int j = 1, ty = b; j <= y && (l / tx) % ty == 0; ++j, ty *= b) {
      s.insert(l / tx / ty);
    }
  }
  for (int j = 1, ty = b; j <= y && l % ty == 0; ++j, ty *= b)
    s.insert(l / ty);
  for (int i = 1, tx = a; i <= x && l % tx == 0; ++i, tx *= a)
    s.insert(l / tx);
  std::cout << s.size() + 1 << '\n';
}

int main() {
  int tt;
  std::cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
