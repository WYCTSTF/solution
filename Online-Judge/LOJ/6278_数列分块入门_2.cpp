#include<bits/stdc++.h>
using namespace std;
using ll=long long;
template<typename T>
inline void scan(T &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9')
		f=(ch=='-')?-1:1,ch=getchar();
	while (ch>='0'&&ch<='9')
		x=(x<<3)+(x<<1)+ch-48,ch=getchar();
	x*=f;
}
int main(){
	int n; scan(n); int m=sqrt(n);
	vector a(n+1,0),p(n+1,0),tag(m+2,0);
	vector<int>v[505];
	for(int i=1;i<505;i++) v[i].clear();
	for(int i=1;i<=n;i++)
		scan(a[i]),p[i]=(i-1)/m+1,v[p[i]].push_back(a[i]);
	for(int i=1;i<p[n];i++)
		sort(v[i].begin(),v[i].end());
	auto trim=[&](int x)->void{
		v[x].clear();
		for(int i=(x-1)*m+1;i<=min(x*m,n);i++) v[x].push_back(a[i]);
		sort(v[x].begin(),v[x].end());
	};
	auto add=[&](int x,int y,int val)->void{
		for(int i=x;i<=min(p[x]*m,y);i++) a[i]+=val;
		trim(p[x]);
		if(p[x]!=p[y]){
			for(int i=(p[y]-1)*m+1;i<=y;++i) a[i]+=val;
			trim(p[y]);
		}
		for(int i=p[x]+1;i<p[y];i++)
			tag[i]+=val;
	};
	auto query=[&](int x,int y,int val)->int{
		int ans=0;
		for(int i=x;i<=min(p[x]*m,y);i++) if(a[i]+tag[p[x]]<val) ans++;
		if(p[x]!=p[y]){
			for(int i=(p[y]-1)*m+1;i<=y;++i)
				if(a[i]+tag[p[y]]<val) ans++;
		}
		for(int i=p[x]+1;i<p[y];i++){
			int tem=val-tag[i];
			ans+=lower_bound(v[i].begin(),v[i].end(),tem)-v[i].begin();
		}
		return ans;
	};
	for(int i=1;i<=n;i++){
		int op,x,y,val;
		scan(op); scan(x); scan(y); scan(val);
		if(op==0) add(x,y,val);
		else cout<<query(x,y,val*val)<<'\n';
	}
	return 0;
}