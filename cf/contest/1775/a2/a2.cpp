#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    int n = s.size();
    s = '$' + s;
    int br = -1;
    if (s[1] == 'a') {
      for (int i = 2; i < n; ++i) {
        if (s[i] == 'b') {
          br = i;
          break;
        }
      }
      if (br == -1) {
        cout << s[1] << ' ' << s[2] << ' ';
        for (int i = 3; i <= n; ++i)
          cout << s[i];
        cout << '\n';
      } else {
        for (int i = 1; i < br; ++i)
          cout << s[i];
        cout << ' ';
        for (int i = br; i < n; ++i)
          cout << s[i];
        cout << ' ' << s[n] << '\n';
      }
    }
    if (s[1] == 'b') {
      for (int i = 2; i < n; ++i) {
        if (s[i] == 'a') {
          br = i;
          break;
        }
      }
      if (br == -1) {
        cout << s[1] << ' ' << s[2] << ' ';
        for (int i = 3; i <= n; ++i)
          cout << s[i];
        cout << '\n';
      } else {
        for (int i = 1; i < br; ++i)
          cout << s[i];
        cout << ' ' << s[br] << ' ';
        for (int i = br + 1; i <= n; ++i)
          cout << s[i];
        cout << '\n';
      }
    }
  }
  return 0;
}

/*

a ... b -> if b in ... then ok else ok
a ... a -> if b in ... then ok else ok
b ... a -> if a in ... then ok else ok
b ... b -> if a in ... then ok else ok

*/