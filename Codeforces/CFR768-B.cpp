#include <bits/stdc++.h>
using namespace std;
// head
const int N = 2e5 + 10;
int n, a[N], t[N];
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    cin >> n;
    // cout<<"fuck"<<endl;
    for (int i = 1; i <= n; i++)
      t[i] = a[i] = 0;
    for (int i = 1; i <= n; i++)
      cin >> a[i], t[a[i]]++;
    int ans = 0, End = n, Start, tar = a[n];
    while (t[tar] != n) {
      while (End > 1 && a[End - 1] == a[End])
        End--;
      Start = max(End - (n - End + 1), 1);
      for (int i = Start; i < End; i++)
        if (a[i] != tar)
          t[a[i]]--, t[tar]++, a[i] = tar;
      End = Start;
      ans++;
    }
    cout << ans << endl;
  }
  return 0;
}