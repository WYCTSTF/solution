#include <bits/stdc++.h>
using namespace std;
const int inf=0x7fffffff;
int main() {
	map<int,int>mp;
	mp[0]=-1;
	for(int i=1;i<=32768;i*=2) mp[i]=mp[i/2]+1;
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	vector ve(32768,inf/2);
	ve[0]=0;
	for(int i=32767;i>0;i--){
		ve[i]=min(ve[(i+1)%32768]+1,15-mp[i&-i]);
	}
	int n;
	cin>>n;
	vector<int>ans(n);
	for(auto &it:ans) cin>>it;
	for(int i=0;i<n;i++){
		cout<<ve[ans[i]]<<" \n"[i+1==n];
	}
	return 0;
}