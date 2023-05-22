#include <bits/stdc++.h>

using ll = long long;
using namespace std;
void solve(){
  int n,q;
  cin>>n>>q;
  vector<ll> a(n+1),sum(n+1);
  sum[0]=0;
  for(int i=1;i<=n;++i)
    cin>>a[i],sum[i]=sum[i-1]+a[i];
  for(int i=1;i<=q;++i){
    int l,r,k;
    cin>>l>>r>>k;
    if((1ll*sum[n]+sum[l-1]-sum[r]+1ll*k*(r-l+1)) % 2)
      cout<<"YES\n";
    else
      cout<<"NO\n";
  }
}
int main() {

  int tt;
  cin>>tt;
  while(tt--){
    solve();
  }
	return 0;
}
