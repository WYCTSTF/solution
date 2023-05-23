#include <bits/stdc++.h>
// #ifdef LOCAL
// #include <dbg.h>
// #else
// #define dbg(...) 42
// #endif

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned int;
using db = double;

#define rep(i, a, n) for (int i = a; i <= n; i++)
#define per(i, a, n) for (int i = n; i >= a; i--)
#define pb push_back
#define fi first
#define se second
#define pi acos(-1)
#define sz(x) ((int)(x).size())
#define all(x) x.begin(), x.end()
typedef std::vector<int> VI;
typedef std::pair<int, int> PII;

i64 gcd(i64 a, i64 b) { return b ? gcd(b, a % b) : a; }

const int mod = 1e9 + 7;
int inv[200010];

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::unordered_map<int, int> b;
  for (int i = 0, x; i < n; ++i)
    std::cin >> x, b[x] += 1;
  std::vector<std::pair<int,int>> _;
  for(auto&x:b)
    _.pb(std::move(x));
  sort(all(_));
  int ans=0;
  for (int i=0;i<sz(_.size());++i)
}

int main() {
  int tt;
  std::cin >> tt;
  inv[1] = 1;
  for (int i = 2; i <= 200000; ++i)
    inv[i] = (1ll * (mod - mod / i) * inv[mod % i]) % mod;
  while (tt--) {
    solve();
  }
  return 0;
}
