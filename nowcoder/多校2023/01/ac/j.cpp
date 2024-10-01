#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll mod=998244353;
ll pow(ll a,ll b){
  ll ans=1;
  for(;b;b>>=1,a=a*a%mod)if(b&1)ans=ans*a%mod;
  return ans;
}
int main(){
  ll n,m;
  cin>>n>>m,m+=n;
  ll d=1,dx=1,ans=1;
  while(n<m){
    ll r=log2(n+1);
    ll lim=min(m,(1ll<<(r+1))-1);
    ll _dx=1<<r,_d=_dx-1;
    dx=dx*pow(_dx,lim-n)%mod;
    ans=(ans*pow(_d,lim-n)%mod)*pow(pow(_dx,lim-n),mod-2)%mod;
    n=lim;
  }
  cout << ans << '\n';
  // cout<<d<<' '<<dx<<'\n';
  return 0;
}
