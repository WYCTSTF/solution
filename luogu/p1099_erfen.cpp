#include<bits/stdc++.h>
#ifdef LOCAL
#include"algo/debug.h" #else
#define dbg(...) 114514
#endif
using namespace std;
using i64=long long;
int main(){
  cin.tie(nullptr)->sync_with_stdio(false);
  int n,s;cin>>n>>s;
  vector<vector<pair<int,int>>>adj(n+1);
  for(int i=1,u,v,w;i<n;++i)
    cin>>u>>v>>w,adj[u].push_back({v,w}),adj[v].push_back({u,w});
  int st=0,ed=0;
  vector<int>dis(n+1,0);
  function<void(int,int,int&)>dfs=[&](int u,int fr,int &ep){
    if(dis[u]>dis[ep])ep=u;
    for(auto &[v,w]:adj[u])
      if(v^fr)
        dis[v]=dis[u]+w,dfs(v,u,ep);
  };
  dfs(1,0,st);
  dis[st]=0;
  dfs(st,0,ed);
  vector<int>dia;
  function<void(int,int,vector<int>)>get=[&](int u,int fr,vector<int>path){
    if(u==ed){dia=path;return;}
    for(auto&[v,w]:adj[u])
      if(v^fr)
        path.push_back(v),get(v,u,path),path.pop_back();
  };
  get(st,0,{st});
  //debug(dia);
  vector<int>dd(dia.size(),0);
  function<void(int)>calc=[&](int p){
    int u=dia[p];
    if(u==ed)return;
    for(auto&[v,w]:adj[u])
      if(v==dia[p+1])
        dd[p+1]=dd[p]+w,calc(p+1);
  };
  calc(0);
  //debug(dd);
  i64 low=0,high=dd.back();
  high/=2;
  //debug(dia);
  //debug(dd);
  //debug(low,high);
  int maxx=-1;
  bitset<500010>vis;
  vector<int>ddis(n+1);
  function<void(int)> mark=[&](int u){
    maxx=max(maxx,ddis[u]);
    for(auto&[v,w]:adj[u])
      if(vis[v]==0)
        vis[v]=1,ddis[v]=ddis[u]+w,mark(v);
  };
  auto check=[&](int k){
    maxx=-1;
    vis.reset();
    fill(ddis.begin(),ddis.end(),0);
    int l=0,r=dia.size()-1;
    while(l+1<dia.size()&&dd[l+1]<=k)
      ++l;
    while(r>=1&&dd[dia.size()-1]-dd[r-1]<=k)
      --r;
    for(int i=l;i<=r;++i) vis[dia[i]]=1;
    for(int i=l;i<=r;++i) mark(dia[i]);
    return (dd[r]-dd[l]<=s&&maxx<=k);
  };
  while(low+1<high){
    i64 mid=(low+high)/2;
    if(check(mid))
      high=mid;
    else
      low=mid;
  }
  cout<<low+1<<'\n';
  return 0;
}
