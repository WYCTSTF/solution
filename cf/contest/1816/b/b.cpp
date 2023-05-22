#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector a(n + 1, vector<int>(2));
  for (int i = 1; i <= n; ++i)
    a[i][i%2] = i;
  for (int i = n * 2; i > n; --i)
    a[n*2-i+1][i%2]=i;
  swap(a[2][1],a[n][1]);
  for (int i = 1; i <= n; ++i)
    cout << a[i][0] << " \n"[i == n];
  for (int i = 1; i <= n; ++i)
    cout << a[i][1] << " \n"[i == n];
  return;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
