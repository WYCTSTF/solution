#include <bits/stdc++.h>
#define rep(i,a,n,k) for(int i=a;i<=n;i+=k)
#define per(i,a,n,k) for(int i=n;i>=a;i-=k)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define il inline
#define rg register
#define SZ(x) ((int)(x).size())
#define all(x) x.begin(),x.end()
using namespace std;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef long long ll;
typedef double db;
const int INF=0x7fffffff;
const int inf=0x3f3f3f3f;
const int MOD=998244353;
const int mod=1e9+7;
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a; }
// head

int main() {
  int tt; cin >> tt;
  while (tt--) {
    int n; cin >> n;
    vector<int>a(n + 1);
    ll sum = 0, Max = -1;
    for (int i = 1; i <= n; i++) {
      cin >> a[i]; sum += a[i]; Max = max(Max, a[i]);
    }

    if (Max - 1 > sum - Max) {
      cout << Max - (sum - Max) << endl;
    } else {
      if (sum == 0) puts("0");
      else cout << 1 << endl;
    }
  }
  return 0;
}