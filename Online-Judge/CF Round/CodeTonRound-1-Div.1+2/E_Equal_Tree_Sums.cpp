#include<bits/stdc++.h>
using namespace std;
int main() {
	int tt;cin>>tt;
	while(tt--){
		int n;cin>>n;
		vector e(n+1,vector<int>{});
		vector ans(n+1,0);
		for(int i=1;i<n;i++){ int u,v;cin>>u>>v; e[u].push_back(v),e[v].push_back(u); }
		auto dfs = [&](auto self,int u,int f,int k)->void{
			ans[u]=k*e[u].size();
			for(auto it:e[u]){
				if(it==f) continue;
				self(self,it,u,-k);
			}
		};
		dfs(dfs,1,0,1);
		for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
		cout<<endl;
	}
	return 0;
}