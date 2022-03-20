// 赛道修建
#include<set>
#include<cstdio>
#include<iostream>
const int N=5e4+10;
int h[N],tot,n,m,f[N],g[N],len,ver[N<<1],val[N<<1],nxt[N<<1];
inline void add(int u,int v,int w){
    ver[++tot]=v,val[tot]=w,nxt[tot]=h[u],h[u]=tot;
    ver[++tot]=u,val[tot]=w,nxt[tot]=h[v],h[v]=tot;
}
void dfs(int u,int fa){
    f[u]=0;
    std::multiset<int>s;
    for(int i=h[u];i;i=nxt[i]){
        int v=ver[i],w=val[i];
        if(v==fa) continue;
        dfs(v,u);
        f[u]+=f[v];
        if(g[v]+w>=len)f[u]++;
        else s.insert(g[v]+w);
    }
    g[u]=0;
    while(s.size()){
        const int x=*s.begin();
        s.erase(s.begin());
        std::multiset<int>::iterator it=s.lower_bound(len-x);
        if (it==s.end()) g[u]=x;
        else s.erase(it),f[u]++;
    }
}
bool check(int k){
    len=k;
    dfs(1,0);
    return f[1]>=m;
}
signed main(){
    freopen("track.in","r",stdin);
    freopen("track.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
    }
    int l=1,r=5e7,res=-1;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid)) res=mid,l=mid+1;
        else r=mid-1;
    }
    std::cout<<res;
    return 0;
}