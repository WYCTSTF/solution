#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin>>tt;
  while(tt--){
    int n,q;
    cin>>n>>q;
    vector<long long>a(n+1,0LL);
    int o=0,e=0;
    for(int i=1;i<=n;++i){
      cin>>a[i];
      if(a[i]%2) o++;
      else e++;
    }
    auto sum=accumulate(a.begin(),a.end(),0LL);
    for (int i = 1; i <= q; ++i) {
      int op, x;
      cin >> op >> x;
      if (x % 2) {
        if (op == 0)
          sum += e * x, o += e, e = 0;
        else
          sum += o * x, e += o, o = 0;
      } else {
        if (op == 0)
          sum += e * x;
        else
          sum += o * x;
      }
      cout << sum << '\n';
    }
  }
  return 0;
}