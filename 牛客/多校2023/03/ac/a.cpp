#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  reverse(s.begin(), s.end());
  int a = 0;
  for (char c : s) {
    if (c == '1')
      a++;
    a *= 2;
  }
  a /= 2;
  int b = 0;
  cin >> s;
  reverse(s.begin(), s.end());
  for (char c : s) {
    if (c == '1')
      b++;
    b *= 2;
  }
  b /= 2;
  cout << max(b - a, a - b) << '\n';
  return 0;
}
