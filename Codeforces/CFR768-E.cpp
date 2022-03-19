#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, l[N], r[N];
struct line {
  int l, r;
  bool operator<(const line &a) const { return l < a.l; }
};
vector<line> p;
int main() {
  // cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    l[i] = 0x3f3f3f3f, r[i] = -1;
  }
  for (int i = 1; i <= n; i++) {
    int tem;
    cin >> tem;
    l[tem] = min(l[tem], i);
    r[tem] = max(r[tem], i);
  }
  for (int i = 1; i <= n; ++i) {
    if (l[i] != r[i] && l[i] != 0x3f3f3f3f) {
      p.push_back((line){l[i], r[i]});
    }
  }
  sort(p.begin(), p.end());
  p.push_back((line){n + 1, n + 2});
  int ans = 0, _R = 0, L = 0, R = -0;
  for (int i = 0; i < (int)(p.size()); ++i) {
    if (p[i].l < R)
      _R = max(_R, p[i].r);
    else {
      if (_R <= R)
        L = p[i].l, R = p[i].r;
      else
        L = R, R = _R, i--;
      ans += R - L - 1;
    }
  }
  cout << ans << endl;
}