// 倍增 LCA
#include<cstdio>
const int N=5e5+10;
int n,m,s,tot,f[N][25],ver[N<<1],nxt[N<<1],h[N],dep[N];
inline void add(int u,int v){
    ver[++tot]=v,nxt[tot]=h[u],h[u]=tot;
}
void dfs(int u,int fa){
    dep[u]=dep[fa]+1,f[u][0]=fa;
    for(int i=1;(1<<i)<=dep[u];i++) f[u][i]=f[f[u][i-1]][i-1];
    for(int i=h[u];i;i=nxt[i]){
        if(ver[i]^fa)
            dfs(ver[i],u);
    }
}
inline int lca(int x,int y){
    if(dep[x]<dep[y]) x^=y^=x^=y;
    for(int i=20;i>=0;i--) if(dep[f[x][i]]>=dep[y]) x=f[x][i];
    if(x==y)return x;
    for(int i=20;i>=0;i--) if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
    return f[x][0];
}
signed main(){
    // freopen("a.in","r",stdin);
    scanf("%d%d%d",&n,&m,&s);
    for(int i=1,u,v;i<n;i++)
        scanf("%d%d",&u,&v),add(u,v),add(v,u);
    dfs(s,0);
    for(int i=1,u,v;i<=m;i++)
        scanf("%d%d",&u,&v),printf("%d\n",lca(u,v));
    return 0;
}