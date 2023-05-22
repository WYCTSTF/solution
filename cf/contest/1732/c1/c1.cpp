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

const int N = 100010;
int a[N], pre[N], suf[N], tot[N];
long long add[N], x[N];

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      add[i] = add[i - 1] + a[i];
      x[i] = (x[i - 1] ^ a[i]);
      tot[i] = tot[i - 1] + (a[i] != 0);
    }

    a[0] = pre[0] = 0;
    for (int i = 1; i <= n; ++i)
      pre[i] = ((a[i - 1]) ? i - 1 : pre[i - 1]);

    a[n + 1] = 0;
    suf[n + 1] = n + 1;
    for (int i = n; i >= 1; --i)
      suf[i] = ((a[i + 1]) ? i + 1 : suf[i + 1]);

    auto val = [&](int l, int r) {
      return add[r] - add[l - 1] - (x[r] ^ x[l - 1]);
    };

    for (; q; q--) {
      int l, r;
      cin >> l >> r;

      if (tot[r] - tot[l - 1] > 31) {
        if (a[l] == 0)
          l = suf[l];
        if (a[r] == 0)
          r = pre[r];
        VI lc, rc;
        ll tem = val(l, r);
        int mn = r - l + 1, nl = l, nr = r;

        for (int i = l, j = 1; i <= r && j <= 31; ++j, i = suf[i])
          lc.pb(i);

        for (int i = r, j = 1; i >= l && j <= 60; ++j, i = pre[i])
          rc.pb(i);

        for (int _l : lc) {
          for (int _r : rc) {
            if (_l > _r)
              continue;
            if (val(_l, _r) == tem && _r - _l + 1 < mn)
              mn = _r - _l + 1, nl = _l, nr = _r;
          }
        }

        cout << nl << ' ' << nr << '\n';
      } else if (tot[r] - tot[l - 1] == 0)
        cout << l << ' ' << l << '\n';
      else {
        // cerr << "fuck2" << '\n';
        if (a[l] == 0)
          l = suf[l];
        if (a[r] == 0)
          r = pre[r];
        ll tem = val(l, r);
        int mn = r - l + 1, nl = l, nr = r;
        for (int _l = l; _l <= r; _l = suf[_l])
          for (int _r = _l; _r <= r; _r = suf[_r])
            if (val(_l, _r) == tem && _r - _l + 1 < mn)
              mn = _r - _l + 1, nl = _l, nr = _r;
        cout << nl << ' ' << nr << '\n';
      }
    }
  }
  return 0;
}