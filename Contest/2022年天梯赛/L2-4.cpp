#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;
int mp[510][510];
signed main() {
  char op;
  int n,v,w,tot; cin>>n;
  int t1=INT_MAX,t2=INT_MAX;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
      mp[i][j]=INT_MAX;
  for(int i=1;i<=n;i++)
    mp[i][i]=0;
  vector<int>m,f,am,af;
  for(int i=1;i<=n;i++){
    cin>>op;
    if(op=='F') f.pb(i);
    else m.pb(i);
    cin>>tot;
    for(int j=1;j<=tot;j++){
      scanf("%lld:%lld",&v,&w);
      mp[i][v]=w;
    }
  }

  for(int k=1;k<=n;k++)
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
        mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);

  for(auto u:f){
    int Max=-1;
    for(auto v:m)
      Max=max(Max,mp[v][u]);
    if(t1>Max){
      t1=Max; af.clear(); af.pb(u);
    } else if(t1==Max) af.pb(u);
  }
  for(auto u:m){
    int Max=-1;
    for(auto v:f)
      Max=max(Max,mp[v][u]);
    if(t2>Max){
      t2=Max; am.clear(); am.pb(u);
    } else if(t2==Max) am.pb(u);
  }
  sort(am.begin(),am.end());
  sort(af.begin(),af.end());
  for(int i=0;i<(int)af.size();i++){ cout<<af[i];
    if(i!=(int)af.size()-1) cout<<' ';
  }
  cout<<endl;
  for(int i=0;i<(int)am.size();i++){ cout<<am[i];
    if(i!=(int)am.size()-1) cout<<' ';
  }
  return 0;
}