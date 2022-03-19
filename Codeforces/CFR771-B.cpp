#include <bits/stdc++.h>
using namespace std;
priority_queue<int> odd, even;
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    int tem;
    bool flag = true;
    while (!odd.empty())
      odd.pop();
    while (!even.empty())
      even.pop();
    for (int i = 1; i <= n; i++) {
      cin >> tem;
      if (tem % 2 == 1) {
        if (!odd.empty()) {
          if (odd.top() > tem)
            flag = false;
        }
        odd.push(tem);
      } else {
        if (!even.empty())
          if (even.top() > tem)
            flag = false;
        even.push(tem);
      }
    }
    if (flag)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}