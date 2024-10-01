#include <bits/stdc++.h>
#define int long long
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else #define debug(...) 42
#endif

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned int;
using db = double;
using VI = std::vector<int>;
using PII = std::pair<int, int>;

#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define fi first
#define se second
#define pi acos(-1)
#define sz(x) ((int)(x).size())
#define all(x) x.begin(),x.end()

i64 gcd(i64 a,i64 b) { return b?gcd(b,a%b):a; }

signed main() {
  int tt;
  cin >> tt;
  bitset<1000010> vis;
  for (int i = 2; i <= 1e6 - 1; ++i) {
    int now = i + 1, base = i;
    while (now <= 1e6) {
      base *= i;
      if (now + base <= 1e6) now += base;
      else break;
      vis[now] = 1;
    }
  }
  while (tt--) {
    int n;
    cin>>n;
    if(vis[n])cout<<"YES\n";
    else cout<<"NO\n";
  }
  return 0;
}
