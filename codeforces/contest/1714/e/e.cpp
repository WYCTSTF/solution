#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int A[15] = {0, 1, 0, 9, 18, 5, 6, 25, 14, 23};

signed main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n, tem;
    cin >> n;
    // cout << n << '\n';
    int s = -1;
    vector<int> a(n);
    bool ok = true;
    for (int i = 0; i < n; ++i)
      cin >> a[i];
    for (int i = 0; i < n; ++i) {
      tem = a[i];
      int now = tem % 10;
      tem += A[now];
      // deb(s), deb(tem);

      if (s == -1)
        s = tem;
      else if (tem == s)
        continue;

      else if (abs(tem - s) % 20 == 0 && tem % 10 != 0)
        s = max(s, tem);
      else {
        // cout << "No" << '\n';
        ok = false; break;
      }
    }
    puts(ok ? "Yes" : "No");
    // solve();
  }
  return 0;
}