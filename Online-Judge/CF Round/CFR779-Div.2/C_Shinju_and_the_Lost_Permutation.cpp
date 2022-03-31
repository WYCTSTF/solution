#include <bits/stdc++.h>
using namespace std;
int main() {
	int tt;cin>>tt;
	while(tt--){
		int n; cin>>n;
		vector<int>c(n+1);
		int now=0;
		for(int i=1;i<=n;i++) {cin>>c[i];if(c[i]==1) now=i;}
		vector<int>a;
		for(int i=now;i<=n;i++) a.push_back(c[i]);
		for(int i=1;i<now;i++) a.push_back(c[i]);
		bool flag=true;
		for(int i=1;i<n;i++){
			if(a[i]-a[i-1]>1) {flag=false;break;}
			else if(a[i]==1) {flag=false; break;}
		}
		if(now==0) puts("NO");
		else if(flag) puts("YES");
		else puts("NO");
	}
	return 0;
}