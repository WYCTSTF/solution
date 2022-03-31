#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin>>tt;
	auto dig=[&](int x)->int{
		int ans=0; while(x) x/=10,ans++; return ans;
	};
	while (tt--) {
		int x1,x2,p1,p2;
		cin>>x1>>p1>>x2>>p2;
		while(dig(x1)<dig(x2)&&p1>0) p1--,x1*=10;
		while(dig(x2)<dig(x1)&&p2>0) p2--,x2*=10;
		if(p1<p2) puts("<");
		else if(p1>p2) puts(">");
		else {
			if(x1==x2) puts("=");
			else if(x1<x2) puts("<");
			else puts(">");
		}
	}
	return 0;
}