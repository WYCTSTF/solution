#include <bits/stdc++.h>
using namespace std;

int fac[5] = {600, 60, 0, 10, 1};
set<int> st;

void solve() {
  set<int> tem;
  string s;
  cin >> s;
  int x;
  cin >> x;
  int tot = 0;
  for (int i = 0; i < 5; ++i)
    tot += (int)(s[i] - '0') * fac[i];
  for (int i = 0; i < 1440; ++i) {
    tem.insert(tot);
    tot += x;
    tot %= 1440;
  }
  int res = 0;
  for (int i : tem)
    for (int j : st)
      if (i == j)
        res++;
  cout << res << '\n';
}

int main() {
  int tt;
  cin >> tt;

  auto work = [&](int a, int b) {
    st.insert(a * 60 + b);
    return;
  };

  work(0, 0), work(1, 10), work(2, 20), work(3, 30), work(4, 40), work(5, 50);
  work(10, 1), work(11, 11), work(12, 21), work(13, 31), work(14, 41), work(15, 51);
  work(20, 2), work(21, 12), work(22, 22), work(23, 32);

  while (tt--) {
    solve();
  }
  return 0;
}