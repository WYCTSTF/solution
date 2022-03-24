#include<bits/stdc++.h>
using namespace std;
int main(){
	int tt;cin>>tt;
	while(tt--){
		int n;cin>>n; vector<int>a(n);
		bool f1=false;
		for(int i=0;i<n;i++) {cin>>a[i]; if(a[i]==1) f1=true;}
		multiset<int>s{a.begin(),a.end()};
		bool F1=false;
		if(f1) for(auto it:s) if(s.count(it+1)>=1) {F1=true; break;}
		if(F1) {puts("NO"); continue;}
		puts("YES");
	}
	return 0;
}