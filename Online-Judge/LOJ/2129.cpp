#include<bits/stdc++.h>
using namespace std;
struct Node{ int u,v,w; };
int main(){
	int tt;cin>>tt;
	while(tt--){
		int n;cin>>n; int tot=0;
		map<int,int>mp;
		vector<Node>con(n);
		for(int i=0;i<n;i++) {cin>>con[i].u>>con[i].v>>con[i].w;
			if(mp.find(con[i].u)==mp.end()) mp[con[i].u]=++tot;
			if(mp.find(con[i].v)==mp.end()) mp[con[i].v]=++tot;
		}
		sort(con.begin(),con.end(),[&](Node a,Node b)->bool{return a.w>b.w;});
		vector<int>fa(tot+1,0);
		for(int i=1;i<=tot;i++) fa[i]=i;
		auto Find=[&](auto self, int o)->int{ return (o==fa[o])?(o):(fa[o]=self(self,fa[o])); };
		int now=0;
		while(con[now].w!=0){
			fa[Find(Find,mp[con[now].u])]=Find(Find,mp[con[now].v]);
			now++;
		} bool flag=false;
		while(now<n){
			if(Find(Find,mp[con[now].u])==Find(Find,mp[con[now].v])) {flag=true; break;}
			now++;
		}
		puts((flag==false)?"YES":"NO");
	}
}