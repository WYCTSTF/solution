#include<bits/stdc++.h>
using namespace std;
int main() {
	int tt;cin>>tt;
	while(tt--){
		int n; cin>>n;
		vector a(n,0); for(int i=0;i<n;i++) cin>>a[i];
		sort(a.begin(),a.end(),greater<int>());
		if(n==1&&a[0]>1) puts("NO");
		else if(a[0]>a[1]+1) puts("NO");
		else puts("YES");
	}
	return 0;
}