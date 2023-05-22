#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, n) for (int i = a; i <= n; i++)
#define per(i, a, n) for (int i = n; i >= a; i--)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pi acos(-1)
#define il inline
#define rg register
#define SZ(x) ((int)(x).size())
#define all(x) x.begin(), x.end()
#define INF 0x7fffffff
#define inf 0x3f3f3f3f
#define MOD 998244353
#define mod 1000000007
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef long long ll;
typedef double db;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;

    VI a(n + 1, 0);
    multiset<int> s0, s1;
    rep(i, 1, n) cin >> a[i];
    
    rep(i, 1, n) {
      int tem;
      cin >> tem;
      if (a[i] == 0)
        s0.insert(tem);
      else
        s1.insert(tem);
    }

    // for (auto it : s1)
    //   cout << it << ' ';
    // cout << '\n';

    if (s1.size() == s0.size()) {
      ll sum = 0;
      for (auto it : s1)
        sum += it * 2;
      for (auto it : s0)
        sum += it * 2;
      cout << sum - min(*s0.begin(), *s1.begin()) << '\n';
    } else if (SZ(s1) > SZ(s0)) {
      ll sum = 0;
      int tem = SZ(s1) - SZ(s0);
      for (int i = 1; i <= tem; ++i) {
        sum += *s1.begin();
        s1.erase(s1.begin());
      }
      for (auto it : s1)
        sum += it * 2;
      for (auto it : s0)
        sum += it * 2;
      cout << sum << '\n';
    } else {
      ll sum = 0;
      int tem = SZ(s0) - SZ(s1);
      for (int i = 1; i <= tem; ++i) {
        sum += *s0.begin();
        s0.erase(s0.begin());
      }
      for (auto it : s1)
        sum += it * 2;
      for (auto it : s0)
        sum += it * 2;
      cout << sum << '\n';
    }
  }
  return 0;
}