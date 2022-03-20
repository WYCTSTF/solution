#include <bits/stdc++.h>
using namespace std;
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    if (n % 7 == 0)
      cout << n << endl;
    else if (n % 10 >= n % 7)
      cout << n - (n % 7) << endl;
    else
      cout << n + 7 - (n % 7) << endl;
  }
  return 0;
}