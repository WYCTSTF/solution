#include <bits/stdc++.h>

using namespace std;

#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
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
  VI f(61);
  f[2] = 1;
  f[4] = 3;

  VI inv(61, 1);
  rep (i, 2, 60)
    inv[i] = (ll)(MOD - MOD / i) * inv[MOD % i] % MOD;
  
  for (int i = 6; i <= 60; i += 2) {
    f[i] = f[i - 4];

    ll tem = 1ll;
    for (int j = i - 1, k = i / 2 - 1; k > 0; --j, --k)
      tem = ((ll)((ll)tem * j % MOD) * inv[k]) % MOD;
    f[i] = ((ll)f[i] + tem) % MOD;

    tem = 1ll;
    for (int j = i - 4, k = i / 2 - 1; k > 0; --j, --k)
      tem = (((ll)((ll)tem * j) % MOD) * inv[k]) % MOD;
    f[i] = ((ll)f[i] + tem) % MOD;
  }

  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;

    int tem = 1;

    for (int i = n, j = n / 2; j > 0; --j, --i)
      tem = ((ll)(((ll)tem * i) % MOD) * inv[j]) % MOD;

    cout << f[n] << ' ' << ((ll)tem - f[n] - 1 + MOD) % MOD << " 1" << '\n';
  }
  return 0;
}