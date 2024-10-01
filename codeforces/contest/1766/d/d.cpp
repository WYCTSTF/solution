#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int mnp[10000010];
vector<int>pr;
void solve(){
  int x,y;cin>>x>>y;
  if (gcd(x,y)>1){cout<<"0\n";return;}
  if(x+1==y){cout<<"-1\n";return;}
  int d=y-x,k=INT_MAX;
  while (d!=1){
    int g=mnp[d];k=min(k,g-x%g);
    d/=mnp[d];
  }
  cout<<k<<'\n';
}
int main(){
  cin.tie(nullptr)->sync_with_stdio(false);
  for(int i=2;i<=(int)(1e7);++i){
    if(!mnp[i])pr.push_back(i),mnp[i]=i;
    for(auto &p:pr){
      if((ll)p*i>(ll)(1e7)) break;
      mnp[p*i]=p;
      if(i%p==0) break;
    }
  }
  mnp[1]=1;
  int tt;cin>>tt;
  while(tt--){
    solve();
  }
  return 0;
}