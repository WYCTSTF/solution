#include <bits/stdc++.h>
using namespace std;
void solve() {
  long double m, x, a, b;
  cin >> m >> x >> a >> b;
  while (m >= x) {
    if ((b - 1.0l) * x >= a || b == 0)
      a += x;
    else
      b--;
    m -= x;
  }
  a += m;
  printf("%.7Lf\n", a / (a + b));
}
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
