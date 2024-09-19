#include <bits/stdc++.h>
using namespace std;
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
      cin >> a[i];
    set<int> s;
    int tot = 0;
    for (int i = n - 1; i >= 0; --i) {
      if (s.count(a[i])) {
        tot = i + 1;
        break;
      }
      s.insert(a[i]);
    }
    cout << tot << '\n';
  }
  return 0;
}