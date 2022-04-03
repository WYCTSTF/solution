#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m; cin>>n; m=sqrt(n);
	vector p(n+1,0);
	vector sum(m+5,0LL), a(n+1,0LL), tag(m+5,0LL);
	for(int i=1;i<=n;i++){
		cin>>a[i]; p[i]=(i-1)/m+1; sum[p[i]]+=a[i];
	}
	auto add=[&](int x,int y,ll val)->void{
		for(int i=x;i<=min(p[x]*m,y);i++)
			sum[p[x]]+=val,a[i]+=val;
		if(p[x]!=p[y]){
			for(int i=(p[y]-1)*m+1;i<=y;i++)
				sum[p[x]]+=val,a[i]+=val;
		}
		for(int i=p[x]+1;i<p[y];i++){
			sum[i]+=m*val,tag[i]+=val;
		}
	};
	auto query=[&](int x,int y)->ll{
		ll ans=0;
		for(int i=x;i<=min(p[x]*m,y);i++) ans+=a[i]+tag[p[x]];
		if(p[x]!=p[y]) for(int i=(p[y]-1)*m+1;i<=y;i++) ans+=a[i]+tag[p[i]];
		for(int i=p[x]+1;i<p[y];i++) ans+=sum[i];
		return ans;
	};
	for(int i=1;i<=n;i++){
		int op,x,y,val;
		cin>>op>>x>>y>>val;
		if(op==0) add(x,y,val);
		else cout<<query(x,y)%(val+1)<<'\n';
	}
	return 0;
}