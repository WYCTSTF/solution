#include <bits/stdc++.h>
using namespace std;
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 1; i <= n; ++i) {
      int a;
      cin >> a;
      mp[a]++;
    }
    int tot = 0;
    for (auto it : mp)
      tot += it.second - 1;
    if (tot % 2)
      ++tot;
    cout << n - tot << '\n';
  }
  return 0;
}