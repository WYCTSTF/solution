#include <bits/stdc++.h>
#define int long long
#define rep(i, a, n, k) for (int i = a; i <= n; i += k)
#define per(i, a, n, k) for (int i = n; i >= a; i -= k)
using namespace std;
int pre[1010];
int b[1010], c[1010];
int dp[1000010];
signed main() {
  int tt, n, k;
  cin >> tt;
  for (int i = 0; i < 1010; i++)
    pre[i] = 0x3f3f3f3f;
  pre[1] = 0;
  for (int i = 1; i <= 1010; i++)
    for (int j = i; j >= 1; j--) {
      if (i + i / j > 1000)
        break;
      pre[i + i / j] = min(pre[i + i / j], pre[i] + 1);
    }
  while (tt--) {
    for (int i = 0; i < 1e6; i++)
      dp[i] = 0;
    cin >> n >> k;
    rep(i, 1, n, 1) cin >> b[i], b[i] = pre[b[i]];
    rep(i, 1, n, 1) cin >> c[i];
    rep(i, 1, n, 1) per(j, 0, min(k, 12000ll), 1) if (j >= b[i]) dp[j] =
        max(dp[j - b[i]] + c[i], dp[j]);
    cout << dp[min(k, 12000ll)] << endl;
  }
  return 0;
}