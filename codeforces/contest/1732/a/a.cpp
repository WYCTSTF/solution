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
    VI a(n + 1);
    rep (i, 1, n)
      cin >> a[i];
    int g = a[1];
    rep (i, 2, n)
      g = gcd(g, a[i]);
    if (g == 1)
      cout << "0\n";
    else if (gcd(g, n) == 1)
      cout << "1\n";
    else if (gcd(g, n - 1) == 1)
      cout << "2\n";
    else
      cout << "3\n";
  }
  return 0;
}