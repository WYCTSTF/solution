#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> s;
  for (int i = 1; i <= n; ++i) {
    int a, b;
    cin >> a >> b;
    while (a >= b) {
      s.push_back(a);
      a -= b;
    }
  }
  sort(s.begin(), s.end(), greater<int>());
  for (int &i:s)
    cout << i << ' ';
  cout << '\n';
  cout << m << ' ' << s.size() << '\n';
  cout << s[m - 1] << '\n';
  return 0;
}
