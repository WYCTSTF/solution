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

void solve() {
  VI ans;
  int n;cin>>n;
  std::vector<std::vector<PII>>e(n+1);
  for(int i=1,u,v;i<n;++i){
    cin>>u>>v;
    e[u].pb({v,i});
    e[v].pb({u,i});
  }
  VI siz(n+1);
  std::function<bool(int,int)> dfs=[&](int u,int fa){
    siz[u]=1;
    for(auto &[v,pid]:e[u]){
      if(v==fa)
        continue;
      if(!dfs(v,u))return false;
      if(siz[v]==3)ans.pb(pid);
    }
    return siz[u]<=3;
  };
}

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		solve();
	}
  return 0;
}
