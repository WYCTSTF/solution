#include<bits/stdc++.h>
using namespace std;
int main() {
	int n; cin>>n; int tem;
	vector<int>a;
	for(int i=0;i<n;i++) cin>>tem,a.push_back(tem);
	int ans=accumulate(a.begin(),a.end(),0);
	cout<<ans<<endl;
	return 0;
}