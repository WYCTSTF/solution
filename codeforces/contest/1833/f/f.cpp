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

const int mod=1e9+7;
int inv[200010];

void solve(){
  int n,m;cin>>n>>m;
  std::unordered_map<int,int> b;
  rep(i,1,n){
    int tem;cin>>tem;
    b[tem]=b[tem]+1;
  }
  std::vector<PII>_;
  for(auto &i:b)_.pb(std::move(i));
  //dbg(_);
  sort(all(_));
  int ans=0;
  for(int i=0;i<sz(_);++i){
    int j=i;
    while(j+1<sz(_)&&_[j+1].fi==_[j].fi+1)
      ++j;
    int len=j-i+1;
    VI pre(len+1,1),suf(len+1,1);
    rep(k,1,len)
      pre[k]=(1ll*pre[k-1]*_[i+k-1].se)%mod,suf[k]=(1ll*suf[k-1]*inv[_[i+k-1].se])%mod;
    rep(k,m,len)
      ans=(1ll*pre[k]*suf[k-m]%mod+1ll*ans)%mod;
    i=j;
  }
  cout<<ans<<'\n';
}

int main(){
  inv[1]=1;
  rep(i,2,200000)inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
  int tt;cin>>tt;
  while(tt--)solve();
  return 0;
}
