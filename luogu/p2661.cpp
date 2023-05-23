#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> f(n);
  iota(f.begin(), f.end(), 0);
  function<int(int, int &)> find = [&](int o, int &cnt) {
    cnt++;
    return o == f[o] ? o : find(f[o], cnt);
  };
  int ans = INT_MAX;
  for (int i = 0; i < n; ++i) {
    int to;
    cin >> to;
    --to;
    int cnt = 0;
    if (find(to, cnt) == i)
      ans = min(ans, cnt);
    else
      f[i] = to;
  }
  cout << ans << '\n';
  return 0;
}
