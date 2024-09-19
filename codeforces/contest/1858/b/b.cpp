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
#define fi first
#define se second
#define pi acos(-1)
#define sz(x) ((int)(x).size())
#define all(x) x.begin(),x.end()

i64 gcd(i64 a,i64 b) { return b?gcd(b,a%b):a; }

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> a(m + 1);
    for (int i = 1; i <= m; ++i)
      cin >> a[i];
    a[0] = 1;
    a.push_back(n + 1);

    auto calc = [&](int x) {
      return max(0, x / d);
    };
    int sum = m + (a[1] != 1);
    for (int i = 1; i <= m + 1; ++i)
      sum += calc(a[i] - a[i - 1] - 1);
    int mn = sum, tot = 0;
    for (int i = 1; i <= m; ++i) {
      int now = sum;
      if (a[i] != 1) {
        now -= calc(a[i] - a[i - 1] - 1) + calc(a[i + 1] - a[i] - 1) + 1;
        now += calc(a[i + 1] - a[i - 1] - 1);
      }
      if (now < mn) {
        mn = now;
        tot = 1;
      } else if (now == mn)
        tot++;
    }
    cout << mn << ' ' << tot << '\n';
  }
}
