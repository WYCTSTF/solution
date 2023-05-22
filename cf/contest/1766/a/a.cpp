#include <bits/stdc++.h>

using ll = long long;
using namespace std;
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    int ans = 0, tot = 0;
    while (n >= 10)
      n /= 10, tot++;
    cout << tot * 9 + n % 10 << '\n';;
  }
  return 0;
}