#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned int;
using db = double;

#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pi acos(-1)
#define sz(x) ((int)(x).size())
#define all(x) x.begin(),x.end()
#define INF 0x7fffffff
#define inf 0x3f3f3f3f
#define mod 998244353
#define MOD 1000000007
typedef std::vector<int> VI;
typedef std::pair<int,int> PII;

i64 gcd(i64 a,i64 b) { return b?gcd(b,a%b):a; }

void solve() {
  int n;
  std::cin >> n;
  VI a(n + 1);
  std::set<int> odd, even;
  rep (i, 1, n) {
    std::cin >> a[i];
    if (a[i] % 2)
      odd.insert(a[i]);
    else
      even.insert(a[i]);
  }
  bool flag = true;
  for (int i = 1; i <= n; ++i)
    if (a[i] % 2)
      continue;
    else {
      if (odd.lower_bound(a[i]) != odd.begin())
        continue;
      flag = false;
      break;
    }
  if (flag) {puts("YES");return;}
  flag = true;
  for (int i = 1; i <= n; ++i)
    if (a[i] % 2 == 0)
      continue;
    else {
      if (odd.lower_bound(a[i]) != odd.begin())
        continue;
      flag = false;
      break;
    }
  if (flag) puts("YES");
  else puts("NO");
}
int main() {
  int tt;
  std::cin >> tt;
  while(tt--)
    solve();
}
