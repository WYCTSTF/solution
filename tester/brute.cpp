#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int main() {
  int n, m;
  cin >> n >> m;
  if (n == 1 && m == 1) {
    puts("0");
    return 0;
  }
  if (n == 1 || m == 1) {
    puts("1");
    return 0;
  }
  long long ans = 0;
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      if (gcd(i, j) == 1) {
        ans++;
      }
    }
  }
  cout << ans + 2 << endl;
  return 0;
}