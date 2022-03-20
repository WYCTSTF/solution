#include <bits/stdc++.h>
using namespace std;
int n;
int a[510];
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    cin >> n;
    int p1 = 0;
    for (int i = 1; i <= n; i++)
      cin >> a[i];
    for (int i = 1; i <= n; i++) {
      if (a[i] != i) {
        p1 = i;
        break;
      }
    }
    int p2 = 0;
    if (p1 != 0)
      for (int i = 1; i <= n; i++) {
        if (a[i] == p1)
          p2 = i;
      }
    if (p1 == 0 && p2 == 0) {
      // cout << "fuck1" << endl;
      for (int i = 1; i <= n; i++)
        cout << a[i] << ' ';
    } else {
      // cout << "fuck2" << endl;
      for (int j = 1; j < p1; j++)
        cout << a[j] << ' ';
      for (int j = p2; j >= p1; j--) {
        cout << a[j] << ' ';
      }
      for (int j = p2 + 1; j <= n; j++)
        cout << a[j] << ' ';
    }
    cout << endl;
  }
  return 0;
}