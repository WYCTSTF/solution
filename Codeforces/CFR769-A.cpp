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
    if (s.size() > 2)
      puts("NO");
    else {
      if (s == "01" || s == "10" || s.size() == 1)
        puts("YES");
      else
        puts("NO");
    }
  }
  return 0;
}
