#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=50010;
int n,m;
int p[N],flag[N];
ll a[N],sum[N];
template<typename T>
inline void scan(T &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9')
		f=(ch=='-')?-1:1,ch=getchar();
	while (ch>='0'&&ch<='9')
		x=(x<<3)+(x<<1)+ch-48,ch=getchar();
	x*=f;
}
void solve(int x){
	if(flag[x]==1) return;
	flag[x]=1; sum[x]=0;
	for(int i=(x-1)*m+1;i<=x*m;i++){
		a[i]=sqrt(a[i]),sum[x]+=a[i];
		if(a[i]>1) flag[x]=0;
	}
}
void add(int x,int y){
	for(int i=x;i<=min(p[x]*m,y);i++) sum[p[x]]-=a[i],a[i]=sqrt(a[i]),sum[p[x]]+=a[i];
	if(p[x]!=p[y])
		for(int i=(p[y]-1)*m+1;i<=y;i++) sum[p[y]]-=a[i],a[i]=sqrt(a[i]),sum[p[y]]+=a[i];
	for(int i=p[x]+1;i<p[y];i++)
		solve(i);
}
ll query(int x,int y){
	ll ans=0;
	for(int i=x;i<=min(p[x]*m,y);i++) ans+=a[i];
	if(p[x]!=p[y])
		for(int i=(p[y]-1)*m+1;i<=y;i++) ans+=a[i];
	for(int i=p[x]+1;i<p[y];i++)
		ans+=sum[i];
	return ans;
}
int main() {
	cin>>n; m=sqrt(n);
	for(int i=1;i<=n;i++) scan(a[i]),p[i]=(i-1)/m+1,sum[p[i]]+=a[i];
	for(int i=1;i<=n;i++){
		int op,x,y; ll val;
		scan(op),scan(x),scan(y),scan(val);
		if(op==0) add(x,y);
		else cout<<query(x,y)<<'\n';
	}
	return 0;
}