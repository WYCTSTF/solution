#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void solve() {
	int n;cin>>n;
	string s;cin>>s;
	vector<vector<int>>pos(26);
	for(int i=0;i<n;++i)
		pos[s[i]-'a'].push_back(i);
	for(int ch=0;ch<26;++ch){
		if(pos[ch].size()>1){
			for(auto l:pos[ch])
				for(auto r:pos[ch]){
					if(l==r||l+1>=r||r+1==n)
						continue;
					if(s[l+1]==s[r+1]){
						cout<<"YES\n";
						return;
					}
				}
		}
	}
	cout<<"NO\n";
}
int main(){
	int tt;
	cin>>tt;
	while(tt--){
		solve();
	}
	return 0;
}