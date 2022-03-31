#include <bits/stdc++.h>
using namespace std;
int solve() {
  int l, r;
  cin >> l >> r;
  vector a(r - l + 1, 0);
  set<int> s;
  for (int i = 0; i < r - l + 1; i++) {
    int tem;
    cin >> tem;
    s.insert(tem);
  }
  int f = 1;
  auto check = [&](int x) {
    for (auto it : s)
      if ((it ^ x) < l || (it ^ x) > r)
        return false;
    return true;
  };
  while (1) {
    set<int> t = s;
    for (auto it : s)
      if (t.find(it ^ 1) != t.end())
        t.erase(it ^ 1);
    if (l % 2 == 1 && r % 2 == 1)
      return f * (*t.begin() ^ l);
    if (l % 2 == 0 && r % 2 == 0)
      return f * (*t.begin() ^ r);
    if (l % 2 == 1 && r % 2 == 0) {
      if (check(*t.begin() ^ l))
        return f * (*t.begin() ^ l);
      else
        return f * (*t.begin() ^ r);
    }
    t.clear();
    for (auto it : s)
      t.insert(it / 2);
    s = t;
    l /= 2;
    r /= 2;
    f *= 2;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
		cout<< solve()<<endl;
  }
  return 0;
}