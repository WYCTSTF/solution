#include <bits/stdc++.h>
using namespace std;
const int N=100010;
struct line {
	int h,m,s, H,M,S;
	bool operator<(const line &Other) const {
		return (h==Other.h)?(m==Other.m?s<Other.s:m<Other.m):h<Other.h;
	}
} a[N];
int main() {
	int n; cin >> n;
	for(int i=1;i<=n;i++)
		scanf("%d:%d:%d - %d:%d:%d",&a[i].h,&a[i].m,&a[i].s,&a[i].H,&a[i].M,&a[i].S);
	sort(a+1,a+1+n);
	auto compare=[&](line X,line Y)->void{
		if(X.H==Y.h&&X.M==Y.m&&X.S==Y.s) return;
		if(X.H<10) cout<<'0'; cout<<X.H<<":";
		if(X.M<10) cout<<'0'; cout<<X.M<<":";
		if(X.S<10) cout<<'0'; cout<<X.S<<" - ";
		if(Y.h<10) cout<<'0'; cout<<Y.h<<":";
		if(Y.m<10) cout<<'0'; cout<<Y.m<<":";
		if(Y.s<10) cout<<'0'; cout<<Y.s<<"\n";
	};
	line tem = (line){0,0,0,0,0,0};
	compare(tem,a[1]);
	for(int i=1;i<n;i++){
		compare(a[i],a[i+1]);
	}
	tem=(line){23,59,59,23,59,59};
	compare(a[n],tem);
	return 0;
}