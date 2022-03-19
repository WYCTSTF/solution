#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, k, a[N], t[N];
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
      t[i] = 0;
    for (int i = 1; i <= n; i++)
      cin >> a[i], t[a[i]]++;
    for (int i = 1; i <= n; i++)
      t[i] += t[i - 1];
    int X = 1, Y = n;
    for (int x = 1; x <= n; x++) {
      int l = x, r = n, y;
      while (l <= r) {
        int mid = l + r >> 1;
        if ((t[mid] - t[x - 1] << 1) >= n + k)
          r = mid - 1, y = mid;
        else
          l = mid + 1;
      }
      if ((t[y] - t[x - 1] << 1) >= n + k && y - x < Y - X)
        X = x, Y = y;
    }
    cout << X << ' ' << Y << endl;
    int now = 0, l = 1;
    for (int i = 1; i <= n && k > 1; i++) {
      now += ((X <= a[i] && a[i] <= Y) ? 1 : -1);
      if (now > 0) {
        cout << l << ' ' << i << endl;
        k--, l = i + 1, now = 0;
      }
    }
    cout << l << ' ' << n << endl;
  }
  return 0;
}