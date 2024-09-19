#include <bits/stdc++.h>

using ll = long long;

using namespace std;

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int ans = 0;
    for (int i = n; i >= 1; --i)
      if (a[i] > ans)
        ans = a[i];
      else
        ans++;
    cout << ans << '\n';
  }
  return 0;
}
