#include <cstdio>
#define low(x) (x&-x)
int n,m,tem;
long long c[1000010];
inline long long ask(int p) {
    long long ans=0;
    for (; p; p-=low(p)) ans+=c[p];
    return ans;
}
int main() {
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) {
        scanf("%d",&tem);
        for (int j=i;j<=n;j+=low(j)) c[j]+=tem*1ll;
    }
    for (int i=1,op,x,y; i<=m;i++) {
        scanf("%d%d%d",&op,&x,&y);
        if (op==1) for (int j=x;j<=n;j+=low(j)) c[j]+=y*1ll;
        else printf("%lld\n",ask(y)-ask(x-1));
    }
    return 0;
}