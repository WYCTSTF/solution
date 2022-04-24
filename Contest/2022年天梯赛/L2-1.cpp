#include <bits/stdc++.h>
#define pb push_back
#define debug cerr << "fuck" << endl;
#define las(k) k[now][k[now].size() - 1]
using namespace std;
const int N = 1010;
int main() {
  int n, m, k, now = 0;
  queue<int> q;
  stack<int> s;
  vector<int> ans[N];
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    int tem;
    cin >> tem;
    q.push(tem);
  }
  // debug
  while (!s.empty() || !q.empty()) {
    if ((int)ans[now].size() == k) {
      now++;
      continue;
    }
    if (ans[now].empty()) {
      // debug
      if (s.empty()) {
        if (q.empty()) {
          now--;
          break;
        } else {
          ans[now].pb(q.front()), q.pop();
        }
      } else {
        ans[now].pb(s.top()), s.pop();
      }
    } else {
      if (!s.empty() && s.top() <= las(ans)) {
        ans[now].pb(s.top()), s.pop();
        continue;
      }
      if (q.empty()) {
        now++;
      } else {
        if (q.front() > las(ans)) {
          if ((int)s.size() < m) {
            s.push(q.front()), q.pop();
          } else {
            now++;
          }
        } else {
          ans[now].pb(q.front()), q.pop();
        }
      }
    }
  }
  while ((int)ans[now].size() == 0)
    now--;
  for (int i = 0; i <= now; i++) {
    for (int j = 0; j < ans[i].size(); j++) {
      cout << ans[i][j];
      if (j != ans[i].size() - 1)
        cout << ' ';
    }
    if (i != now)
      cout << endl;
  }
  return 0;
}