#include <bits/stdc++.h>
void solve(){
  int n;
  std::cin >> n;
  std::vector<int> l(n + 1, INT_MAX), r(n + 1, -1);
  for (int i = 1; i <= n; ++i) {
    int tem;
    std::cin >> tem;
    l[tem] = std::min(l[tem], i), r[tem] = std::max(r[tem], i);
  }
  int L = 1, R = n - 1;
  for (int i = 0; i <= n; ++i) {
    if (l[i] != INT_MAX) {
      L = std::max(L, l[i]), R = std::min(R, r[i] - 1);
    }
    else break;
  }
  if (L <= R) {
    std::cout << 2 << '\n' << '1' << ' ' << L << '\n' << L + 1 << ' ' << n << '\n';
  }
  else
    std::cout << "-1\n";
}
int main() {
  int tt;
  std::cin>>tt;
  while(tt--){
    solve();
  }
  return 0;
}
