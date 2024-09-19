#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
    }

    if (n % 2) {
      cout << "-1\n";
    } else {
      int num = 0;
      vector<pair<int, int>> ans;
      for (int i = 1; i <= n; i += 2) {
        if (a[i] == a[i + 1]) {
          num++;
          ans.push_back({i, i + 1});
        } else {
          num += 2;
          ans.push_back({i, i});
          ans.push_back({i + 1, i + 1});
        }
      }
      cout << num << '\n';
      for (auto it : ans) {
        cout << it.first << ' ' << it.second << '\n';
      }
    }
  }
  return 0;
}