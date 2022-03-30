#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1001000;
int n,q,a[N];
ll c[N];
template<typename T>
inline void scan(T &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9')
		f=(ch=='-')?-1:1,ch=getchar();
	while (ch>='0'&&ch<='9')
		x=(x<<3)+(x<<1)+ch-48,ch=getchar();
	x*=f;
}
void add(int x,int v) {while (x<=n) c[x]+=v*1LL, x+=x&-x;}
ll qry(int x) {ll ans=0;while(x>0) ans+=c[x],x-=x&-x; return ans;}
int main() {
	scan(n),scan(q);
	for(int i=1;i<=n;i++) scan(a[i]);
	for(int i=1;i<=q;i++){
		int op; scan(op);
		if(op==1){
			int l,r,x; scan(l),scan(r),scan(x); add(l,x); add(r+1,-x);
		} else {
			int x; scan(x); cout<<a[x]+qry(x)<<endl;
		}
	}
	return 0;
}