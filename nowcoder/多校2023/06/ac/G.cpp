#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int x, y, z;
    cin >> x >> y >> z;
    int g = gcd(x, y);
    if ((min(x,y) == 0 && z == 0) || (z % g == 0 && z!= 0))
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
