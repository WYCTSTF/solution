#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int ask(int l, int r) {
  cout << "? " << r - l + 1 << ' ';
  for (int i = l; i <= r; ++i) {
    cout << i;
    if (i != r)
      cout << ' ';
    else
      cout << endl;
  }
  int ans;
  cin >> ans;
  return ans;
}

void solve() {
  int n;
  cin >> n;
  vector<ll> a(n + 1), sum(n + 1, 0);
  for (int i = 1; i <= n; ++i)
    cin >> a[i], sum[i] = sum[i - 1] + a[i];
  int l = 1, r = n;
  while (l < r) {
    int mid = l + r >> 1;
    if (ask(l, mid) != sum[mid] - sum[l - 1])
      r = mid;
    else
      l = mid + 1;
  }
  cout << "! " << l << '\n';
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
