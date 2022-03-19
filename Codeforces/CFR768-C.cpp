#include <bits/stdc++.h>
using namespace std;
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n / 2; i++)
      v[i] = i, v[i + n / 2] = n - 1 - i;
    if (k == n - 1) {
      if (n == 4) {
        cout << "-1" << endl;
        continue;
      } else {
        swap(v[0], v[3]);
        swap(v[0], v[n / 2 + 1]);
      }
    } else {
      for (int i = 0; i < n; i++)
        if (v[i] == k) {
          swap(v[i], v[0]);
          break;
        }
    }
    for (int i = 0; i < n / 2; i++)
      cout << v[i] << ' ' << v[i + n / 2] << endl;
  }
  return 0;
}