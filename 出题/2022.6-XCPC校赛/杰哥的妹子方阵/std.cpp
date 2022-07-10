#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int mu[N];
bitset<N> vis;
vector<int> primes;
void init(int n) {
  mu[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (vis[i] == 0) {
      primes.push_back(i);
      mu[i] = -1;
    }
    for (auto p : primes) {
      if (p * i > n) break;
      vis[p * i] = 1;
      if (i % p == 0) {
        mu[i * p] = 0;
        break;
      } else {
        mu[i * p] = mu[i] * mu[p];
      }
    }
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  n--, m--;
  long long ans = 0;
  init(n);
  if (n == 0 && m == 0) {
    puts("0");
    return 0;
  }
  if (n == 0 || m == 0) {
    puts("1");
    return 0;
  }
  for (int d = 1; d <= min(n, m); d++) {
    ans += 1ll * mu[d] * (n / d) * (m / d);
  }
  cout << ans + 2 << endl;
  return 0;
}