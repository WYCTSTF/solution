#include <bits/stdc++.h>
using namespace std;
// head
const int N=1e5+10;
int a[N],trie[33*N][3],tot;
void insert(int x){
    int p=0;
    for(int i=31;i>=0;i--){
        int ch=(x>>i)&1;
        if(!trie[p][ch]) trie[p][ch]=++tot;
        p=trie[p][ch];
    }
}
int ask(int x){
    int p=0,ans=0;
    for(int i=31;i>=0;i--){
        int ch=(x>>i)&1;
        if(trie[p][!ch]) p=trie[p][!ch],ans+=(1<<i);
        else p=trie[p][ch];
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];insert(a[i]);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,ask(a[i]));
    }
    cout<<ans<<endl;
    return 0;
}