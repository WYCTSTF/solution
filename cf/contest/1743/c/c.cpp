#include <bits/stdc++.h>

using namespace std;

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
      cin >> a[i];
    vector<vector<int>> f(n + 1, vector<int>(2, 0));
    s = '$' + s;
    if (s[1] == '1')
      f[1][0] = a[1];
    for (int i = 2; i <= n; ++i) {
      f[i][0] = max(f[i - 1][0], f[i - 1][1]);
      if (s[i] == '1') {
        f[i][0] += a[i];
        if (s[i - 1] == '1')
          f[i][1] = f[i - 1][1] + a[i - 1];
        else
          f[i][1] = max(f[i - 1][0], f[i - 1][1]) + a[i - 1];
      }
    }
    cout << max(f[n][0], f[n][1]) << '\n';
  }
  return 0;
}