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
  int n, k;
  std::cin >> n >> k;
  std::vector<PII> a(n), b(n);
  rep(i,0,n-1)
    std::cin>>a[i].fi,a[i].se=i;
  rep(i,0,n-1)
    std::cin>>b[i].fi;
  std::sort(all(a));
  std::sort(all(b));
  rep(i,0,n-1)
    b[i].se=a[i].se;
  sort(all(b),[&](const PII &x,const PII &y){return x.se<y.se;});
  rep(i,0,n-1)
    std::cout<<b[i].fi<<" \n"[i==n-1];
}

int main() {
  int tt;
  std::cin >> tt;
  while(tt--)
    solve();
  return 0;
}
