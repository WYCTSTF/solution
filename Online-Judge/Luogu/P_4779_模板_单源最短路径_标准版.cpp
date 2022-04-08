#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define ls p<<1
#define rs p<<1|1
#define mid (l+(r-l>>1))
struct Node{
	int u,w;
}seg[N<<2];
void build(int p,int l,int r){
	if(l==r){
		seg[p]=(Node){l,INT_MAX};
		return;
	}
	build(ls,l,mid); build(rs,mid+1,r);
	seg[p]=(Node){seg[ls].u,INT_MAX};
}
void mark(int p,int l,int r,int u,int w){
	if(l==r){
		seg[p].w=w;
		return;
	}
	if(u<=mid) mark(ls,l,mid,u,w);
	else mark(rs,mid+1,r,u,w);
	if(seg[ls].w<seg[rs].w) seg[p]=seg[ls];
	else seg[p]=seg[rs];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m,s,u,v,w;
	cin>>n>>m>>s;
	build(1,1,n);
	vector <vector<pair<int,int>>> e(n+1);
	vector dis(n+1,INT_MAX);
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		e[u].push_back({v,w});
	}
	dis[s]=0; mark(1,1,n,s,0);
	while(seg[1].w!=INT_MAX){
		int u=seg[1].u;
		mark(1,1,n,u,INT_MAX);
		for(auto eg:e[u]){
			int v=eg.first,w=eg.second;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				mark(1,1,n,v,dis[v]);
			}
		}
	}
	for(int i=1;i<=n;i++)
		cout<<dis[i]<<' ';
	return 0;
}