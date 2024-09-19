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
  int tt;
  cin >> tt;

  while (tt--) {
    int n;
    cin >> n;
    VI a(n + 1, 0);
    rep (i, 1, n)
      cin >> a[i];
    int mn = a[1] * 2 - 1;
    int ans = 0;
    rep (i, 2, n)
      ans += (int)ceil((double)(a[i]) / (double)mn) - 1;
    cout << ans << '\n';
  }
  return 0;
}