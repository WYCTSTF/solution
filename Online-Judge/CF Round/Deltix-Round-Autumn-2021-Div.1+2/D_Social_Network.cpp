#include<bits/stdc++.h>
using namespace std;
const int N=2010;
int n,d;
int fa[N],siz[N];
int find(int o){
	return o==fa[o]?o:fa[o]=find(fa[o]);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>d;
	for(int i=1;i<=n;i++) fa[i]=i,siz[i]=1;
	int more=0;
	for(;d;d--){
		int x,y;cin>>x>>y;
		x=find(x),y=find(y);
		vector<int>c={};
		if(x==y) more++;
		else siz[x]+=siz[y],fa[y]=x;
		for(int i=1;i<=n;i++) if(fa[i]==i) c.push_back(siz[i]);
		sort(c.begin(),c.end(),greater<int>());
		int ans=0;for(int i=0;i<=more;i++) ans+=c[i];
		cout<<ans-1<<endl;
	}
	return 0;
}