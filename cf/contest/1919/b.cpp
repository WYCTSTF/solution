#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> a(n+1);
  for(int i=1;i<=n;++i)
    a[i]=(s[i-1]=='+'?1:-1);
  vector<int> pre(n+1,0);
  for(int i=1;i<=n;++i)
    pre[i]=pre[i-1]+a[i];
  cout<<abs(pre[n])<<'\n';
}
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
