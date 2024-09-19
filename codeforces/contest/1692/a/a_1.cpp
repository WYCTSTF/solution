#include <bits/stdc++.h>
using namespace std;
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int a, b;
    cin >> a;
    int ans = 0;
    for (int i = 1; i <= 3; ++i)
      cin >> b, ans += b > a;
    cout << ans << '\n';
  }
  return 0;
}