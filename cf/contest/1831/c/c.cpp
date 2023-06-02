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
  std::vector<int>f(n+1,0);
  std::vector<std::vector<PII>> e(n+1);
  std::vector<PII> edge;
  for(int u,v,i=1;i<n;++i){
    cin>>u>>v;
    e[u].pb({v,i}),e[v].pb({u,i});
    edge.pb({u,v});
  }
  int ans=0;
  f[1]=1;
  VI id(n+1);
  std::function<void(int,int)>dfs=[&](int u,int fr){
    for(auto&[v,w]:e[u]){
      if(v==fr)continue;
      id[v]=w;
      if(w>id[u])f[v]=f[u];
      else f[v]=f[u]+1;
      dfs(v,u);
    }
  };
  dfs(1,-1);
  rep(i,1,n)ans=std::max(ans,f[i]);
  cout<<ans<<'\n';
}

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;cin>>tt;
  while(tt--){
    solve();
  }
  return 0;
}
