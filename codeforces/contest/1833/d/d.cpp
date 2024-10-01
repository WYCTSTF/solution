#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned int;
using db = double;

#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pi acos(-1)
#define sz(x) ((int)(x).size())
#define all(x) x.begin(),x.end()
#define INF 0x7fffffff
#define inf 0x3f3f3f3f
#define mod 998244353
#define MOD 1000000007
typedef std::vector<int> VI;
typedef std::pair<int,int> PII;

i64 gcd(i64 a,i64 b) { return b?gcd(b,a%b):a; }

void solve() {
  int n;
  std::cin >> n;
  VI a(n + 1);
  rep (i, 1, n)
    std::cin >> a[i];
  if (a[1] != n) {
    int pm = 1;
    while (a[pm] != n && pm < n)
      pm++;
    if (pm == n && a[pm - 1] < a[1]) {
      std::cout << a[n] << ' ';
      for (int i = 1; i < n; ++i)
        std::cout << a[i] << ' ';
      std::cout << '\n';
      return;
    }
    int pcm = pm - 1;
    while (pcm > 2 && a[pcm - 1] > a[1])
      pcm--;
    for (int i = pm; i <= n; ++i)
      std::cout << a[i] << ' ';
    for (int i = pm - 1; i >= pcm; --i)
      std::cout << a[i] << ' ';
    for (int i = 1; i < pcm; ++i)
      std::cout << a[i] << ' ';
    std::cout << '\n';
  } else {
    int pm = 1;
    while (a[pm] != n - 1 && pm < n)
      ++pm;
    if (pm == n) {
      std::cout << a[n] << ' ';
      for (int i = 1; i < n; ++i)
        std::cout << a[i] << ' ';
      std::cout << '\n';
      return;
    }
    for (int i = pm; i <= n; ++i)
      std::cout << a[i] << ' ';
    std::cout << a[pm - 1] << ' ';
    for (int i = 1; i < pm - 1; ++i)
      std::cout << a[i] << ' ';
    std::cout << '\n';
  }
}

int main() {
  int tt;
  std::cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
