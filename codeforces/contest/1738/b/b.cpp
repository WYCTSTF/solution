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


    vector<ll> a(n + 1, 0), s(n + 1, 0);

    s[0] = INT_MAX;

    rep (i, n - k + 1, n)
      cin >> s[i];
    
    if (n == 1 || k == 1) {
      puts("Yes");
      continue;
    }
    
    for (int i = n; i >= n - k + 2; --i)
      a[i] = s[i] - s[i - 1];
    
    if (k == n)
      a[1] = s[1];

    auto check = [&]() {
      if (k == 1)
        return ((s[n] >= 0) ? true : false);
      for (int i = n - k + 2; i < n; ++i)
        if (a[i] > a[i + 1])
          return false;
      if (n - k + 2 <= n && (ll)a[n - k + 2] * (n - k + 1) < s[n - k + 1]) {
        // cout << a[n - k + 2] << ' ' << (n - k + 1) << ' ' << s[n - k + 1] << '\n';
        // cout << "fuck\n";
        return false;
      }
      return true;
    };

    if (check())
      puts("Yes");
    else
      puts("No");
  
  }
  return 0;
}