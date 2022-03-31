#ifdef ONLINE_JUDGE
#pragma
#endif
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
int main() {
	int n,q;scan(n),scan(q);
	vector sum(n+1,0LL);
	vector c(2,vector<ll>(n+1,0LL));
	auto add=[&](int k,int x,ll v) {
		for(;x<=n;x+=x&-x) c[k][x]+=v;
	};
	auto qry=[&](int k,int x) {
		ll ans=0; for(;x;x-=x&-x) ans+=c[k][x]; return ans;
	};
	for(int i=1;i<=n;i++)
		scan(sum[i]),sum[i]+=sum[i-1];
	for(;q;q--){
		int op,l,r; scan(op),scan(l),scan(r);
		if(op==1){
			ll v; scan(v); add(0,l,v); add(0,r+1,-v); add(1,l,l*v); add(1,r+1,-(r+1)*v);
		} else {
			ll ans=sum[r]+(r+1)*qry(0,r)-qry(1,r);
			ans-=sum[l-1]+l*qry(0,l-1)-qry(1,l-1);
			cout<<ans<<endl;
		}
	}
	return 0;
}