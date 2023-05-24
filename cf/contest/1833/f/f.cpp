#include <bits/stdc++.h>

#ifdef LOCAL
#include <dbg.h>
#else
#define dbg(...) 42
#endif

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned int;
using db = double;

using std::cin, std::cout;

#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define fi first
#define se second
#define pi acos(-1)
#define sz(x) ((int)(x).size())
#define all(x) x.begin(),x.end()
typedef std::vector<int> VI;
typedef std::pair<int,int> PII;

i64 gcd(i64 a,i64 b) { return b?gcd(b,a%b):a; }

void solve(){
  int n,m;cin>>n>>m;
  std::unordered_map<int,int> b;
  rep(i,1,n){
    int tem;cin>>tem;
    b[tem]=b[tem]+1;
  }
  std::vector<PII>_;
  for(auto &i:b)_.pb(std::move(i));
  dbg(_);
}

int main(){
  int tt;cin>>tt;
  while(tt--)solve();
  return 0;
}
