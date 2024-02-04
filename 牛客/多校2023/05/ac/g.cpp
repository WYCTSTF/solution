#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> t(5, 0);
  int ans = INT_MAX;
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  int l = 0, r = 0;
  t[a[0]]++;
  auto check = [&]() -> bool {
    if (t[1] == 0 || t[2] == 0 || t[3] == 0 || t[4] < k)
      return false;
    return true;
  };
  while (l <= r && r < n) {
    bool flag = false;
    while (check()&&l<r)
      t[a[l]]--,l++,flag=true;
    if(flag)
      --l,t[a[l]]++;
    if(check())
      ans = min(ans, r-l+1);
    r++;
    if(r<n)
      t[a[r]]++;
  }
  cout<<ans<<'\n';
  return 0;
}
