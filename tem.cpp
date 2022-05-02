#include <bits/stdc++.h>
using namespace std;
const int N=40010;
const int mod=1e9+7;
bool check(int n) {
	string tem;
	while(n) tem.push_back('0'+n%10);
	string another=tem;
	reverse(tem.begin(),tem.end());
	return another==tem;
}
int f[N];
vector<int>a;
int main() {
	int tt; cin >> tt;
	for(int i=1;i<=N;i++){
		if(check(i)) a.push_back(i);
	}
	for(auto it:a){
		for(int i=it;i<=N;i++){
			f[i]=(f[i]+f[i-i-it])%mod;
		}
	}
	while (tt--) {
		int n; cin>>n;
		cout<<f[n]<<endl;
	}
	return 0;
}