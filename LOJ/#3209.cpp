#include<bits/stdc++.h>
#define int long long
using namespace std;
// #define rg register
// #define int long long

const int N=5e5+10;

char op[N];
stack<int> fh;
int ans,f[N],s[N];
int n,x,tot,head[N],fa[N];

struct FuckCCF{
    int to,nxt;
} a[N];

inline void add(int u,int v){
    a[++tot].nxt=head[u],a[tot].to=v;
    head[u]=tot;
}

void dfs(int x) {
    int top=0;
    if(op[x]==')'){
        if(!fh.empty()){
            top=fh.top();
            fh.pop();
            f[x]=f[fa[top]]+1;
        }
    }
    else if(op[x]=='(') fh.push(x);
    s[x]=s[fa[x]]+f[x];
    for(int i=head[x];i;i=a[i].nxt){
        int v=a[i].to;
        dfs(v);
    }
    if(top!=0) fh.push(top);
    else if(op[x]=='(') fh.pop();
}

signed main() {
    #ifndef debug
    freopen("brackets.in","r",stdin);
    freopen("brackets.out","w",stdout);
    #endif
    
    scanf("%lld",&n);
    scanf("%s",op+1);
    for(int i=2;i<=n;i++){
        scanf("%lld",&fa[i]);
        add(fa[i],i);
    }
    dfs(1);
    for (int i=1;i<=n;i++) ans=ans^(s[i]*i);
    printf("%lld",ans);
    return 0;
}