#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int main(){
	int tt;
	cin>>tt;
	while(tt--){
		int n;
		cin>>n;
		vector<int>a(n);
		bool flag=false;
		for(int i=0;i<n;++i)
			cin>>a[i];
		for(int i=0;i<n;++i){
			for(int j=i+1;j<n;++j)
				if(gcd(a[i],a[j])<=2)
					flag=true;
		}
		cout<<(flag?"Yes\n":"No\n");
	}
	return 0;
}
