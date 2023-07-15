#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned int;
using db = double;
using VI = std::vector<int>;
using PII = std::pair<int, int>;

#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define fi first
#define se second
#define pi acos(-1)
#define sz(x) ((int)(x).size())
#define all(x) x.begin(),x.end()

i64 gcd(i64 a,i64 b) { return b?gcd(b,a%b):a; }

void solve() {
  double n, d, h;
  cin >> n >> d >> h;
  vector<double> y{0.0};
  rep (i, 1, n) {
    double t;
    cin >> t;
    y.pb(t);
  }
  double sum = d * h / 2.0;
  debug(y);
  rep (i, 2, n) {
    double delta = max(0.0, y[i - 1] + h - y[i]);
    double _d = delta / h * d;
    sum += d * h / 2.0;
    sum -= _d * delta / 2.0;
  }
  printf("%.6lf\n", sum);
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
