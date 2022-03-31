#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt;cin>>tt;
	for(;tt;tt--){
		vector tot(17,0);
		int l,r,tem; cin>>l>>r;
		for(int i=0;i<=r;i++){
			cin>>tem;
			for(int j=0;j<17;j++) if(tem&(1<<j)) tot[j]++;
		}
		int ans=0;
		for(int i=0;i<17;i++) if(tot[i]>r+1-tot[i]) ans+=(1<<i);
		cout<<ans<<endl;
	}
	return 0;
}