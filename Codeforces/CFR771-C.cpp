#include <bits/stdc++.h>
using namespace std;
int ans = 0;
int a[100010];
set<int> s;
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    s.clear();
    int n;
    cin >> n;
    int Max = -1, ans = 0;
    // for (int i = 1; i <= n; i++)
    //   s.insert(i);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if (Max > a[i])
        continue;
      else {
        if (Max < i)
          ans++;
        Max = max(Max, a[i]);
        // 如果a[i] < Max但是还是不用加 意味着后面还有更小的
        // cout << *s.begin() << ' ';
        // if (*s.begin()<a[i] && Max > *s.begin()) continue;
      }
      s.erase(a[i]);
    }
    cout << ans << endl;
  }
  return 0;
}