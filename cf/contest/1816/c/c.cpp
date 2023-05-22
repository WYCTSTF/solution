#include <bits/stdc++.h>
#define int long long
using namespace std;
// #ifdef LOCAL
// #include "dbg.h"
// #else
// #define dbg(...) 42
// #endif
void solve() {
  int n;cin >> n;
  vector<int>a(n+1),c(n+1);
  for(int i=1;i<=n;++i)cin>>a[i],c[i]=a[i]-a[i-1];
  // dbg(c);
  int d1 = 0, d2 = 0;
  for (int i = 1; i <= n; i += 2) // odd
    d1 += c[i];
  for (int i = 2; i <= n; i += 2) // even
    d2 += c[i];
  if (n == 2) {puts((a[1] <= a[2]) ? "YES" : "NO");}
  else if (n % 2) {puts("YES");}
  else {
    if (d2 >= 0)
      puts("YES");
    else
      puts("NO");
  }
}
signed main() {
  int tt;cin>>tt;
  while(tt--){
    solve();
  }
  return 0;
}