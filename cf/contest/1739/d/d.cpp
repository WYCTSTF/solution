#include <bits/stdc++.h>

using namespace std;

#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pi acos(-1)
#define il inline
#define rg register
#define SZ(x) ((int)(x).size())
#define all(x) x.begin(),x.end()
#define INF 0x7fffffff
#define inf 0x3f3f3f3f
#define MOD 998244353
#define mod 1000000007
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef long long ll;
typedef double db;
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a; }


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tt;
  cin >> tt;
  
  while (tt--) {
    int n, k;
    cin >> n >> k;
    
    vector<int> fa(n + 1);
    vector<vector<int>> g(n + 1);

    for (int i = 2; i <= n; ++i) {
      int x;
      cin >> x;
      fa[i] = x;
      g[x].push_back(i);
    }

    int ans = 0;

    function<int(int, int)> dfs = [&](int u, int mid) {
      int mx = 0;
      for (int v : g[u])
        mx = max(mx, dfs(v, mid));
      if (u == 1 || fa[u] == 1) return 0;
      if (mx + 1 < mid) return mx + 1;
      ans++;
      return 0;
    };

    auto check = [&](int mid) -> bool {
      ans = 0;
      dfs(1, mid);
      return (ans <= k);
    };

    int l = 1, r = n;
    while (l < r) {
      int mid = (l + r) / 2;
      if (check(mid)) r = mid;
      else l = mid + 1;
    }

    cout << r << '\n';
  }
  return 0;
}