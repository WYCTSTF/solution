#include<bits/stdc++.h>
#define int long long
using namespace std;
bool prime(int x){
	if(x==1) return false;
	for(int i=2;i*i<=x;i++) if(x%i==0) return false;
	return true;
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt;cin>>tt;
	bitset<200010>vis;
	while(tt--){
		int n,e;cin>>n>>e; vis.reset(); int ans=0;
		vector a(n+1,0); for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			if(vis[i]==1) continue;
			if(a[i]==1) {
				int prefix=1, now=i+e,tot=0;
				while(now<=n&&a[now]==1) prefix++,vis[now]=1,now+=e;
				if(now<=n&&prime(a[now])) ans+=prefix,now+=e;
				while(now<=n&&a[now]==1) tot++,now+=e;
				ans+=prefix*tot;
			} else if(prime(a[i])) {
				for(int j=i+e;j<=n&&a[j]==1;j+=e)
					ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}