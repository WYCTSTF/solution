#include<bits/stdc++.h>
using std::cin;
using std::vector;
struct DSU {
  std::vector<int> f,siz;
  DSU() {}
  DSU(int n){
    init(n);
  }
  void init(int n){
    f.resize(n);
    std::iota(f.begin(),f.end(),0);
    siz.assign(n,1);
  }
  int find(int x){
    while(x!=f[x])
      x=f[x]=f[f[x]];
    return x;
  }
  bool same(int x,int y){
    return find(x)==find(y);
  }
  bool merge(int x,int y){
    x=find(x),y=find(y);
    if(x==y)return false;
    siz[x]+=siz[y];
    f[y]=x;
    return true;
  }
  int size(int x){
    return siz[find(x)];
  }
};
void solve(){
  int n;
  cin>>n;
  vector<int>a(n);
  for(int i=0;i<n;++i)
    cin>>a[i],a[i]--;
  DSU dsu(n);
  for(int i=0;i<n;++i)
    dsu.merge(i,a[i]);
  vector<int>e(n);
  bool chain=false;
  for(int i=0;i<n;++i)
    if(a[a[i]]==i){
      e[dsu.find(i)]=i;
      chain=true;
    }
  int min=0,max=0;
  for(int i=0;i<n;++i)
    if(dsu.find(i)==i){
      if(!e[i])
        min++;
      max++;
    }
  min+=chain;
  std::cout<<min<<' '<<max<<'\n';
}
int main(){
  int tt;cin>>tt;
  while(tt--){
    solve();
  }
  return 0;
}
