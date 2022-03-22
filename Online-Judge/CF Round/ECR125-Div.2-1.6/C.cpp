#include<bits/stdc++.h>
using namespace std;
int main() {
	int tt; cin>>tt;
	while(tt--){
		int n; cin>>n;
		string s; cin>>s;
		int now=0,ans=0;
		while(now<n) {
			if(now==n-1) break;
			if(s[now]=='(') now+=2,ans++;
			else{
				int tag=now+1;
				while(tag<n&&s[tag]=='(') tag++;
				if(tag==n) break;
				else ans++,now=tag+1;
			}
		}
		cout<<ans<<' '<<max(0,n-now)<<'\n';
	}
	return 0;
}