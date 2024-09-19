#include <bits/stdc++.h>

using ll = long long;

using namespace std;

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int x, y;
    cin >> x >> y;
    int num = y / 2 + y % 2;
    int res = x - num * 15 + y * 4;
    if (res > 0)
      num += res / 15 + (res % 15 != 0);
    cout << num << '\n';
  }
  return 0;
}
