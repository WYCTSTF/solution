#include<bits/stdc++.h>
using namespace std;
const int N=150010;
int l,r,trie[N*32][2],a[N],tot;
void add(int x){
	int p=0;
	for(int i=16;i>=0;i--){
		int ch=(x>>i)&1;
		if(!trie[p][ch]){
			trie[tot+1][0]=trie[tot+1][1]=0;
			trie[p][ch]=++tot;
		}
		p=trie[p][ch];
	}
}
int qryMx(int x) {
	int ans=0,p=0;
	for(int i=16;i>=0;i--){
		int ch=(x>>i)&1;
		if(trie[p][ch^1]) p=trie[p][ch^1],ans+=(1<<i);
		else p=trie[p][ch];
	}
	return ans;
}
int qryMn(int x){
	int ans=0,p=0;
	for(int i=16;i>=0;i--){
		int ch=(x>>i)&1;
		if(trie[p][ch]) p=trie[p][ch];
		else p=trie[p][ch^1],ans+=(1<<i);
	}
	return ans;
}
void solve(){
	cin>>l>>r;
	tot=0; trie[0][0]=trie[0][1]=0;
	for(int i=1;i<=r-l+1;i++){cin>>a[i],add(a[i]);}
	for(int i=1;i<=r-l+1;i++){
		int x=a[i]^l;
		if(qryMn(x)==l&&qryMx(x)==r){
			cout<<x<<endl;
			return ;
		}
	}
}
int main() {
	int tt;cin>>tt;
	while(tt--){
		solve();
	}
	return 0;
}