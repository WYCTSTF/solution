#include<bits/stdc++.h>
using namespace std;
#define N 3000010
int n,m,ans;
int trie[210][30],tot;
bitset<N>f;
char ch[N];
bool End[N];
void insert(char *ch){
    int p=0; int len=strlen(ch+1);
    for(int i=1;i<=len;i++){
        int x=ch[i]-'a';
        if(!trie[p][x]) trie[p][x]=++tot;
        p=trie[p][x];
    }
    End[p]=true;
}
void dfs(char *ch,int st,int ed){
    int p=0;
    for(int i=st;i<=ed;i++){
        int x=ch[i]-'a';
        if(!trie[p][x]) return;
        p=trie[p][x];
        if(End[p]) f[i]=1;
    }
    // return;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%s",ch+1);
        insert(ch);
    }
    for(int i=1;i<=m;i++){
        scanf("%s",ch+1);
        int len=strlen(ch+1);
        f.reset();
        f[0]=1;
        for(int j=0;j<=len;j++)
            if(f[j])
                dfs(ch,j+1,len);
        for(int j=len;j>=0;j--)
            if(f[j]) {cout<<j<<endl; break;}
    }
}