#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tt;
  cin >> tt;
  while (tt--) {
    auto get = [&](ll x) {
      ll tem = sqrt(x);
      if (tem * tem > x)
        --tem;
      ll ret = (tem - 1) * 3;
      if (x >= tem * tem)
        ret++;
      if (x >= tem * tem + tem)
        ret++;
      if (x >= tem * (tem + 2))
        ret++;
      return ret;
    };
    ll l, r;
    cin >> l >> r;
    cout << get(r) - get(l - 1) << '\n';
  }
  return 0;
}