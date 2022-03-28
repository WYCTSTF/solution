#include<bits/stdc++.h>
using namespace std;
int main(){
	int tt;cin>>tt;
	while(tt--){
		int n;cin>>n;
		int Max=-1,Min=INT_MAX,p1,p2;
		for(int i=1,tem;i<=n;i++){
			cin>>tem;
			if(tem>Max) Max=tem,p1=i;
			if(tem<Min) Min=tem,p2=i;
		}
		if(p1>p2) swap(p1,p2);
		cout<<p1<<' '<<p2<<'\n';
	}
}