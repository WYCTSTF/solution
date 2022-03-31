#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt;cin>>tt;
	while(tt--){
		ll n,k=1;cin>>n;
		while(n%2==0) n/=2,k*=2;
		if(n==1) {cout<<"-1\n";continue;}
		cout<<min(k*2,n)<<endl;
	}
	return 0;
}