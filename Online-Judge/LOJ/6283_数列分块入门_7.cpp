#include<bits/stdc++.h>
#define mod 10007LL
using namespace std;
using ll=long long;
template<typename T> inline void scan(T &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9') f=(ch=='-')?-1:1,ch=getchar();
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-48,ch=getchar();
	x*=f;
}
int main(){
	int n;scan(n);int m=sqrt(n);
	vector p(n+1,0); vector a(n+1,0LL),add(m+2,0LL),mul(m+2,1LL);
	for(int i=1;i<=n;i++) scan(a[i]),p[i]=(i-1)/m+1;
	auto pushdown=[&](int x){
		for(int i=(x-1)*m+1;i<=min(x*m,n);i++)
			a[i]=((a[i]*mul[x])%mod+add[x])%mod;
		mul[x]=1LL; add[x]=0LL;
	};
	auto mark=[&](int mode,int x,int y,ll val)->void{
		pushdown(p[x]);
		for(int i=x;i<=min(p[x]*m,y);i++)
			a[i]=((mode==0)?(a[i]+val):(a[i]*val))%mod;
		if(p[x]!=p[y]){
			pushdown(p[y]);
			for(int i=(p[y]-1)*m+1;i<=y;i++)
				a[i]=((mode==0)?(a[i]+val):(a[i]*val))%mod;
		}
		for(int i=p[x]+1;i<p[y];i++){
			if(!mode)add[i]=(add[i]+val)%mod;
			else add[i]=(add[i]*val)%mod,mul[i]=(mul[i]*val)%mod;
		}
	};
	for(int i=1;i<=p[n];i++) mul[i]=1,add[i]=0;
	for(int i=1;i<=n;i++){
		int op,x,y; ll val; scan(op),scan(x),scan(y),scan(val);
		if(op!=2) mark(op,x,y,val);
		else cout<<((a[y]*mul[p[y]])%mod+add[p[y]])%mod<<'\n';
	}
	return 0;
}