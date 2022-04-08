#include <bits/stdc++.h>
#define low(x) (x&(-x))
using namespace std;
using ll=long long;
const int N=501000;
int c[N],a[N];
int main() {
	int n,m; cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int op,x,y,k;
	auto add=[&](int x,int k){ while(x<=n) c[x]+=k,x+=low(x); };
	auto ask=[&](int x) {ll ans=0; while(x>0) ans+=c[x],x-=low(x); return ans; };
	for(int i=1;i<=m;i++){
		cin>>op>>x;
		if (op==1){
			cin>>y>>k;
			add(x,k),add(y+1,-k);
		} else
			cout<<a[x]+ask(x)<<'\n';
	}
	return 0;
}