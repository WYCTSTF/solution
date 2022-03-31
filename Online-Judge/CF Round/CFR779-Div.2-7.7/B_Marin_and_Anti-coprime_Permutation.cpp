#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
signed main() {
	auto fac=[](int x){
		long long ans=1;
		while(x>0){
			ans=ans*x%mod;
			x--;
		}
		return ans;
	};
	int tt;cin>>tt;
	while(tt--){
		int n;cin>>n;
		if(n%2==1) puts("0");
		else cout<<fac(n/2)*fac(n/2)%mod<<endl;
	}
	return 0;
}