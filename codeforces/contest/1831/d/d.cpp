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
  int n;
  cin>>n;
  std::vector<PII>_(n);
  for(auto&it:_)cin>>it.fi;
  for(auto&it:_)cin>>it.se;
  sort(all(_));
  i64 ans=0;
  for(int al=1;al*al<=2*n;++al){
    VI cnt(2*n+10,0);
    for (auto&[ar,br]:_){
      int bl=al*ar-br;
      if(bl<=n&&bl>=1)
        ans+=cnt[bl];
      if(ar==al)
        cnt[br]++;
    }
  }
  cout<<ans<<'\n';
}

int main(){
  int tt;cin>>tt;
  while(tt--)solve();
  return 0;
}
