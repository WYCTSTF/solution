#include <bits/stdc++.h>
using namespace std;
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    if ((n + m) % 2)
      cout << "Alice\n";
    else
      cout << "Bob\n";
  }
  return 0;
}
