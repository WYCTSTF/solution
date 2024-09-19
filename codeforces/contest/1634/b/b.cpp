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
    int n;
    ll x, y;
    cin >> n >> x >> y;
    int ans = 0;
    rep (i, 1, n) {
      ll tem;
      cin >> tem;
      if (tem % 2)
        ans++;
    }
    if ((x % 2) != (y % 2)) {
      if (ans % 2)
        puts("Alice");
      else
        puts("Bob");
    } else {
      if (ans % 2 == 1)
        puts("Bob");
      else
        puts("Alice");
    }
  }
  return 0;
}