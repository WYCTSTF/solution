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

void solve() {
  int n,m,d;cin>>n>>m>>d;
  vector<int>p;int las=1,pos;bool flag=false;
  int ans=1;
  map<int,int>mp;
  rep(i,1,m){
    int tem;cin>>tem;
    mp[tem]=i;
    if(tem-las<d && tem - las >= 1&&!flag){
      flag=true;
      pos=tem;
    }else{
      p.pb(tem);
    }
  }
  if(!flag){
    pos = p[m];
    p.pop_back();
  }
  debug(p);
  for(int now:p){
    ans++;
    ans+=(now-las-1)/d;
    las=now;
  }
  ans+=(n-las)/d;
  cout<<ans<<' '<<mp[pos]<<'\n';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;

  while (tt--) {
    solve();
  }
  return 0;
}
