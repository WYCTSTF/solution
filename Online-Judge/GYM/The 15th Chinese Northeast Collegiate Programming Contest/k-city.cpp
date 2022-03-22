#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,q,fa[N];
long long sz[N], ans[N];
struct Edge{
    int u,v,w;
    bool operator<(const Edge &a)const{
        return w>a.w;
    }
}e[N];
struct Query{
    int val,id;
    bool operator<(const Query &a)const{
        return val>a.val;
    }
}Q[N];
template<typename T>
inline void scan(T &x) {
    x=0; int f=1; char ch=getchar();
    while(ch<'0'||ch>'9')
        f=(ch=='-')?-1:1,ch=getchar();
    while (ch>='0'&&ch<='9')
        x=(x<<3)+(x<<1)+ch-48,ch=getchar();
    x*=f;
}
int find(int o){return (o==fa[o])?o:(fa[o]=find(fa[o]));}
int main() {
    int tt; scan(tt);
    for (;tt;--tt){
        scan(n),scan(m),scan(q);
        for(int i=1;i<=n;++i)
            sz[i]=1,fa[i]=i;
        for(int i=1;i<=m;++i)
            scan(e[i].u),scan(e[i].v),scan(e[i].w);
        for(int i=1;i<=q;++i)
            scan(Q[i].val),Q[i].id=i;
        sort(Q+1,Q+1+q);
        sort(e+1,e+1+m);
        int st=1; long long sum=0;
        for(int i=1;i<=q;++i){
            int val=Q[i].val;
            for(;st<=m&&e[st].w>=val;++st){
                int u=find(e[st].u),v=find(e[st].v);
                if(u!=v){
                    sum+=sz[u]*sz[v];
                    if(sz[u]<sz[v]) swap(u,v);
                    fa[u]=v;
                    sz[v]+=sz[u];
                }
            }
            ans[Q[i].id]=sum;
        }
        for(int i=1;i<=q;++i) cout<<ans[i]<<endl;
    }
    return 0;
}