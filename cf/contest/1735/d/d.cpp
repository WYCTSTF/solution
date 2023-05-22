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

ll encode(VI &x, int k) {
  ll c = 0, t = 1;
  for (int j = 0; j < k; ++j) {
    c += t * x[j];
    t *= 3;
  }
  return c;
}

int main() {
  int n, k;
  cin >> n >> k;

  vector a(n, VI(k));
  set<ll> s;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < k; ++j)
      cin >> a[i][j];
  
  for (int i = 0; i < n; ++i)
    s.insert(encode(a[i], k));
  
  ll ans = 0;
  VI c(k);
  for (int i = 0; i < n; ++i) {
    int cnt = 0;
    for (int j = 0; j < n; ++j) {
      if (i == j)
        continue;
      for (int t = 0; t < k; ++t) {
        if (a[i][t] == a[j][t])
          c[t] = a[i][t];
        else
          c[t] = 3 - a[i][t] - a[j][t];
      }
      if (s.count(encode(c, k)))
        ++cnt;
    }
    cnt /= 2;
    ans += cnt * (cnt - 1) / 2;
  }
  cout << ans << '\n';
  return 0;
}