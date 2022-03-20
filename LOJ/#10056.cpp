#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,cnt,Xor[N],trie[N*32][3];
int tot,head[N];
int Next[N<<1],to[N<<1],val[N<<1];
bool vis[N];

void add(int u,int v,int w) {
    to[++tot]=v,val[tot]=w,Next[tot]=head[u],head[u]=tot;
}
void dfs(int p,int res){
    Xor[p]=res; vis[p]=true;
    for(int i=head[p];i;i=Next[i]){
        if(vis[to[i]]==false)
            dfs(to[i],res^val[i]);
    }
}
void insert(int x){
    int p=0;
    for(int i=31;i>=0;i--){
        int ch=(x>>i)&1;
        if(!trie[p][ch]) trie[p][ch]=++cnt;
        p=trie[p][ch];
    }
}
int ask(int x){
    int p=0,res=0;
    for(int i=31;i>=0;i--){
        int ch=(x>>i)&1;
        if(trie[p][!ch]) p=trie[p][!ch],res+=(1<<i);
        else p=trie[p][ch];
    }
    return res;
}
int main(){
    cin >> n;
    int x,y,z;
    for(int i=1;i<n;i++){
        cin>>x>>y>>z;
        add(x,y,z),add(y,x,z);
    }
    dfs(1,0);
    // Xor里面任意两个数字异或都是任意路径的异或和
    // 无端联想：到底以什么样的出发点去理解树，会更加灵活，更具有普遍性？
    int ans=-1;
    for(int i=1;i<=n;i++)
        insert(Xor[i]);
    for(int i=1;i<=n;i++)
        ans=max(ans,ask(Xor[i]));
    cout<<ans<<endl;
    return 0;
}