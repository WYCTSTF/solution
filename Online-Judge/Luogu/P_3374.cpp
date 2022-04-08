#include<bits/stdc++.h>
#define low(x) (x&(-x))
using namespace std;
using ll=long long;
const int N=501000;
int n,m,c[N];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int tem; cin>>tem;
		int now=i; while(now<=n){c[now]+=tem; now+=low(now);}
	}
	auto query=[&](int x) {
		ll ans=0; while(x>0) {ans+=c[x]; x-=low(x);}
		return ans;
	};
	for(int i=1;i<=m;i++){
		int op,x,k;
		cin>>op>>x>>k;
		if(op==1) while(x<=n){c[x]+=k; x+=low(x);}
		else cout<<query(k)-query(x-1)<<endl;
	}
	return 0;
}