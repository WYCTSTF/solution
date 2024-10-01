#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  vector<vector<int>> ans(46);
  vector<int> a;
  while (a.size() < 9) {
    int lim = 9 - a.size(), tem;
    if (a.empty())
      tem = 0;
    else
      tem = accumulate(a.begin(), a.end(), 0);
    for (int i = 1; i <= lim; ++i) {
      a.push_back(i);
      ans[tem+i] = a;
      a.pop_back();
    }
    a.push_back(lim);
  }
  while (tt--) {
    int n;
    cin >> n;
    auto _ans = ans[n];
    reverse(_ans.begin(), _ans.end());
    for(int i:_ans)
      cout<<i;
    cout<<'\n';
  }
  return 0;
}