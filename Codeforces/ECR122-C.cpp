// Find that k<=2e5
#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
  int tt;
  cin >> tt;
  int Hc, Dc, Hm, Dm, k, a, w;
  while (tt--) {
    bool flag = false;
    cin >> Hc >> Dc >> Hm >> Dm;
    cin >> k >> w >> a;
    for (int i = 0; i <= k; ++i) {
      double dc = Dc + i * w;
      double hc = Hc + (k - i) * a;
      if ((int)(hc) % Dm == 0) {
        if (Hm % (int)(dc) == 0) {
          if ((int)(hc) / Dm >= Hm / (int)(dc))
            flag = true;
        } else {
          if ((int)(hc) / Dm > Hm / (int)(dc))
            flag = true;
        }
      } else {
        if (Hm % (int)(dc) == 0) {
          if ((int)(hc) / Dm + 1 >= Hm / (int)(dc))
            flag = true;
        } else {
          if ((int)(hc) / Dm >= Hm / (int)(dc))
            flag = true;
        }
      }
    }
    if (flag == true)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}