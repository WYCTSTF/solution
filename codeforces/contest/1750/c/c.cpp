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
    string a, b;
    cin >> a >> b;
    bool eq = false, ne = false;
    rep (i, 0, n - 1) {
      if (a[i] == b[i])
        eq = true;
      else
        ne = true;
    }
    if (eq == ne) {
      cout << "NO\n";
      continue;
    } else {
      int tem = b[0] - '0';
      cout << "YES\n";
      vector<PII> ans;
      for (int i = 0; i < n; ++i) {
        if (a[i] == '1') {
          ans.pb({i + 1, i + 1});
          tem = 1 - tem;
        }
      }
      if (a[0] == '1')
        tem = 1 - tem;

      if (tem) {
        ans.pb({1, n});
        ans.pb({1, 1});
        ans.pb({2, n});
      }

      cout << ans.size() << '\n';
      for (auto &[x, y] : ans) {
          cout << x << ' ' << y << '\n';
      }
    }
  }
  return 0;
}