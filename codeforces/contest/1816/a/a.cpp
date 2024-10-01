#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;}
void solve() {
  int n, m;
  cin >> n >> m;
  if (gcd(n, m) == 1)
    cout << "1 \n" << n << ' ' << m << '\n';
  else
    cout << "2\n" << n - 1 << ' ' << "1 \n" << n << ' ' << m << '\n';
}
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
