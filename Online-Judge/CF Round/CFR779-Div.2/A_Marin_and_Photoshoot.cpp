#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt;cin>>tt;
	while(tt--){
		int n;cin>>n; string s; cin>>s;
		int tot=0,ans=0;
		for(int i=0;i<n-2;i++)
			if(s[i]=='0'&&s[i+1]=='1'&&s[i+2]=='0') tot++;
		ans+=tot; tot=0;
		for(int i=0;i<n-1;i++)
			if(s[i]=='0'&&s[i+1]=='0') tot++;
		ans+=tot*2;
		cout<<ans<<endl;
	}
	return 0;
}