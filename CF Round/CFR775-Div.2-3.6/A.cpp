#include <bits/stdc++.h>
using namespace std;
int main() {
  int tt; cin >> tt;
  while (tt--) {
    int n; cin >> n;
    vector a(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    int st = 1, ed = n;
    while (a[st] == 1) st++;
    while (a[ed] == 1) ed--;
    st--;
    ed++;
    cout << max(ed - st, 0) << endl;
  }
  return 0;
}