#include<bits/stdc++.h>
using namespace std;
int main(){
	int tt;cin>>tt;
	while(tt--){
		int n,k;cin>>n>>k;
		vector<int>a(n); for(int i=0;i<n;i++)cin>>a[i];
		set<int>s{a.begin(),a.end()};
		bool flag=false;
		for(auto it:s) if(s.find(it+k)!=s.end()) {flag=true; break;}
		if(flag) puts("YES");
		else puts("NO");
	}
	return 0;
}