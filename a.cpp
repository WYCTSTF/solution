#include<bits/stdc++.h>
using namespace std;
int main() {
	int tt; cin>>tt;
	while(tt--){
		int x1,x2,p1,p2;
		cin>>x1>>p1>>x2>>p2;
		int now=x2/x1,len=0;
		while(now) now/=10,len++;
		double X1=(double)(x1),X2=(double)(x2);
		if(len+p2<p1) puts(">");
		else if(len+p2>p1) puts("<");
		else {
			for(int i=1;i<=len;i++)
				X2=X2/10.0;
			if(X2==X1) puts("=");
			else if(X2<X1) puts(">");
			else puts("<");
		}
	}
	return 0;
}