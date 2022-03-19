#include<bits/stdc++.h>
using namespace std;
const int N=6e5+10;
int n,m,a[N],b[N],bin[30],Root[N];
struct Trie{
    int tot;
    int ch[N*24][2],sum[N*24];
    int insert(int x,int val){
        int tmp,y;tmp=y=++tot;
        for(int i=23;i>=0;i--)
        {
            ch[y][0]=ch[x][0]; ch[y][1]=ch[x][1];
            sum[y]=sum[x]+1;
            int t=val&bin[i];t>>=i;
            ch[y][t]=++tot;
            y=ch[y][t], x=ch[x][t];
        }
        sum[y]=sum[x]+1;
        return tmp;
    }
    int query(int l,int r,int val){
        int tmp=0;
        for(int i=23;i>=0;i--)
        {
            int t=val&bin[i];t>>=i;
            if(sum[ch[r][t^1]]-sum[ch[l][t^1]])
                tmp+=bin[i],r=ch[r][t^1],l=ch[l][t^1];
            else r=ch[r][t],l=ch[l][t];
        }
        return tmp;
    }
}trie;
int main()
{
    // cin.tie(nullptr)->sync_with_stdio(false);
    bin[0]=1;for(int i=1;i<30;i++) bin[i]=bin[i-1]<<1;
    cin>>n>>m;
    n++;
    for(int i=2;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) b[i]=b[i-1]^a[i];
    for(int i=1;i<=n;i++)
        Root[i]=trie.insert(Root[i-1],b[i]);
    char ch[5];
    int l,r,x;
    while(m--)
    {
        scanf("%s", ch);
        if(ch[0]=='A'){
            n++;
            cin>>a[n];b[n]=b[n-1]^a[n];
            Root[n]=trie.insert(Root[n-1],b[n]);
        }else{
            cin>>l>>r>>x;
            cout<<trie.query(Root[l-1],Root[r],b[n]^x)<<endl;
        }
    }
    return 0;
}