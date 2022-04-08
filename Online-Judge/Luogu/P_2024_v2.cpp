#include<bits/stdc++.h>
using namespace std;
int n,k,ans,fa[50010],d[50010];
int get(int o){
	if(o==fa[o]) return o;
	int root=get(fa[o]);
	d[o]=(d[o]+d[fa[o]])%3; // 回溯的时候更新 同时路径压缩
	return fa[o]=root;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=k;i++){
		int op,x,y;cin>>op>>x>>y;
		if(x>n||y>n) {ans++; continue;}
		int xx=get(x),yy=get(y);
		if(op==1){
			if(xx==yy&&d[x]!=d[y]) ans++;
			else if(xx!=yy) d[xx]=(d[y]-d[x]+3)%3, fa[xx]=fa[yy];
		}else{
			if(xx==yy&&((d[x]+(3-d[y])%3)%3!=1)){ ans++; continue; }
			if(xx!=yy) {fa[xx]=yy; d[xx]=(d[y]-d[x]+3+1)%3;}
		}
	}
	cout<<ans<<endl;
	return 0;
}