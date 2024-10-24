#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include"algo/debug.h"
#else
#define dbg(...) 114514
#endif
using i64=long long;
const int N=500010;
vector<pair<int,int>>adj[N];
bitset<N>vis;
int dis[N];
int main(){
  cin.tie(nullptr)->sync_with_stdio(false);
  int n,s;cin>>n>>s;
  for(int i=1,u,v,w;i<n;++i)
    cin>>u>>v>>w,adj[u].push_back({v,w}),adj[v].push_back({u,w});
  int st=0,ed=0;
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
  int ans=INT_MAX;
  for(int l=0,r=0;l<dia.size();++l){
    r=max(l,r);
    while(r+1<dia.size()&&dd[r+1]-dd[l]<=s)r++;
    ans=min(ans,max(dd[l],dd[dia.size()-1]-dd[r]));
  }
  vis.reset();
  dd.resize(n+1);
  for(int&x:dia)
    dis[x]=0,vis[x]=1;
  function<void(int)>mark=[&](int u){
    ans=max(ans,dis[u]);
    for(auto&[v,w]:adj[u])
      if(vis[v]==0)
        vis[v]=1,dis[v]=dis[u]+w,mark(v);
  };
  for(int&x:dia)
    mark(x);
  cout<<ans<<'\n';
  return 0;
}
