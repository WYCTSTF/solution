#include<bits/stdc++.h>
using namespace std;
int fa[30010],siz[30010],d[30010],t;
int find(int o){
	if(fa[o]==o) return o;
	int root=fa[o];
	fa[o]=find(fa[o]);
	d[o]+=d[root]; // 递归维护顺序 回溯的时候路径压缩
	return fa[o];
}
int main() {
	scanf("%d",&t);
	for(int i=1;i<=30000;i++) fa[i]=i,siz[i]=1;
	for(int i=1;i<=t;i++){
		char c[5];int x,y;
		scanf("%s %d %d", c+1, &x, &y);
		int fx=find(x),fy=find(y);
		if(c[1]=='M') { fa[fx]=fy; d[fx]=siz[fy]; siz[fy]+=siz[fx]; }
		else{
			if(fx!=fy) puts("-1");
			else cout<<abs(d[x]-d[y])-1<<'\n';
		}
	}
}