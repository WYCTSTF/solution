#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt;cin>>tt;
	while(tt--){
		ll n;cin>>n; ll k=1;
		while(n%2==0) n/=2,k*=2;
		if(n==1) cout<<"-1\n";
		else cout<<min(n,2*k)<<'\n';
	}
}