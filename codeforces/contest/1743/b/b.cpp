#include <bits/stdc++.h>
using namespace std;
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    cout << "1 ";
    for (int i = n; i >= 2; --i) {
      cout << i << ' ';
    }
    cout << '\n';
  }
  return 0;
}