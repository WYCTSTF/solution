#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 31640;
inline char gc() {
  static const int N = 1 << 20;
  static char buf[N | 1], *S = buf, *T = buf;
  return S == T && (T = (S = buf) + fread(buf, 1, N, stdin), S == T) ? EOF : *S++;
}
template<typename T>
inline void read(T &x) {
  x = 0;
  char ch = gc();
  for (; ch < '0' || ch > '9';) ch = gc();
  for (; ch <= '9' && ch >= '0';)
    x = x * 10 + (ch ^ 48), ch = gc();
}
bitset<N> vis;
vector<int> primes;
void solve() {
  int n;
  read(n);

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    read(a[i]);
  }

  set<int> s;
  for (int i = 0; i < n; ++i) {
    int x = a[i];
    for (auto p : primes) {
      if (p * p > x)
        break;
      if (x % p == 0) {
        if (s.count(p)) {
          cout << "YES\n";
          return;
        }
        s.insert(p);
        while (x % p == 0)
          x /= p;
      }
    }
    if (x > 1) {
      if (s.count(x)) {
        cout << "YES\n";
        return;
      }
      s.insert(x);
    }
  }
  cout << "NO\n";
}
int main() {
  for (int i = 2; i <= (int)sqrt(1e9); ++i) {
    if (!vis[i])
      primes.push_back(i);
    for (auto j : primes) {
      if ((ll)j * i > (ll)(sqrt(1e9)))
        break;
      vis[i * j] = 1;
      if (i % j == 0)
        break;
    }
  }
  int tt;
  read(tt);
  while (tt--) {
    solve();
  }
  return 0;
}