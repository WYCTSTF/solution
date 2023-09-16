#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
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

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  bitset<100010> vis;
  while (tt--) {
    int n;
    cin >> n;
    vis.reset();
    vector<int> ans;
    for (int i = 1; i <= n; ++i) {
      if (vis[i] == 0) {
        vis[i] = 1;
        int t = i;
        while (t <= n) {
          ans.push_back(t);
          vis[t] = true;
          t <<= 1;
        }
      }
    }
    for (int i = 0; i < n; ++i)
      cout << ans[i] << " \n"[i == n - 1];
  }
  return 0;
}
