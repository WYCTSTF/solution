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

  int n;cin>>n;
  VI a(n+1),b(n+1),ta(n+1,1),tb(n+1,1);
  std::map<int,int>ma,mb;
  rep(i,1,n){
    cin>>a[i];
    if(a[i]==a[i-1])ta[i]+=ta[i-1];
    ma[a[i]]=std::max(ma[a[i]],ta[i]);
  }
  rep(i,1,n){
    cin>>b[i];
    if(b[i]==b[i-1])tb[i]+=tb[i-1];
    mb[b[i]]=std::max(mb[b[i]],tb[i]);
  }
  int ans=0;
  for(int i=1;i<=n*2;++i)
    ans=std::max(ans,ma[i]+mb[i]);
  cout<<ans<<'\n';
}


int main(){
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;cin>>tt;
  while(tt--)solve();
  return 0;
}
