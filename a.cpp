#include <bits/stdc++.h>
#define int long long
using namespace std;
void read() {}
template <typename T, typename... Ts> inline void read(T &arg, Ts &...args) {
  T x = 0, f = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-')
      f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 3) + (x << 1) + (c - '0');
    c = getchar();
  }
  arg = x * f;
  read(args...);
}
const int N = 1e3 + 5, mod = 1e9 + 7;
vector<int> a, b;
int n, l, r, z, f[N][N];
int inv[N], fac[N];
int C(int n, int m) { return fac[n] * inv[n - m] % mod * inv[m] % mod; }
int A(int n, int m) { return fac[n] * inv[n - m] % mod; }
void init() {
  inv[0] = fac[0] = inv[1] = 1;
  for (int i = 1; i < N; i++)
    fac[i] = fac[i - 1] * i % mod;
  for (int i = 2; i < N; i++)
    inv[i] = (mod - mod / i) * inv[mod % i] % mod;
  for (int i = 1; i < N; i++)
    inv[i] = inv[i - 1] * inv[i] % mod;
}
int dfs(int i, int j) {
  if (!(~i))
    return 1;
  if (~f[i][j])
    return f[i][j];
  f[i][j] = 0;
  int x = 0;
  if (i > 0)
    x = b[i - 1];
  for (int k = a[i]; k <= j; k += 2)
    (f[i][j] += C(n, k) * dfs(i - 1, min(2 * (j - k) + x, n))) %= mod;
  return f[i][j];
}
int solve(int x) {
  memset(f, -1, sizeof(f));
  a.clear(), b.clear();
  int p = z, q = x;
  while (p)
    a.push_back(p & 1), p >>= 1;
  while (q)
    b.push_back(q & 1), q >>= 1;
  if (b.size() < a.size())
    return 0;
  a.resize(b.size());
  return dfs(a.size() - 1, 1);
}
signed main() {
  init();
  read(n, l, r, z);
  printf("%lld\n", (solve(r) - solve(l - 1) + mod) % mod);
  return 0;
}