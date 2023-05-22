#include <bits/stdc++.h>
using namespace std;
map<int, char> mp;
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    mp.clear();
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    string s;
    cin >> s;

    bool flag = true;

    for (int i = 0; i < n; ++i) {
      if (mp.find(a[i]) != mp.end() && mp[a[i]] != s[i]) {
        flag = false;
        // cout << i << '\n';
        break;
      } else {
        mp[a[i]] = s[i];
      }
    }

    cout << (flag ? "YES" : "NO") << '\n';
  }
  return 0;
}