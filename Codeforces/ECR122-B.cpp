#include <bits/stdc++.h>
using namespace std;
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int tg = 0;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '0')
        tg++;
    }
    if (s.size() > 2)
      if (tg * 2 != (int)(s.size()))
        cout << min(tg, (int)(s.size()) - tg) << endl;
      else
        cout << tg - 1 << endl;
    else
      puts("0");
  }
  return 0;
}