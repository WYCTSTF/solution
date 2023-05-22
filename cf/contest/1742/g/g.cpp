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
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  multiset<int> s;
  while (tt--) {
    int n;
    cin >> n;

    rep(i, 1, n) {
      int tem;
      cin >> tem;
      s.insert(tem);
    }

    VI ans;

    int now = 0, mx = 0, pos = 0;

    for (int i = 31; i >= 0 && !s.empty(); --i) {
      pos = -1;
      for (auto it : s) {
        if ((now | it) > mx)
          mx = now | it, pos = it;
      }
      if (pos == -1)
        break;
      now = mx;
      s.erase(s.find(pos));
      ans.pb(pos);
    }

    while (!s.empty())
      ans.pb(*s.begin()), s.erase(s.begin());

    for (auto it : ans)
      cout << it << ' ';
    cout << '\n';
  }
  return 0;
}