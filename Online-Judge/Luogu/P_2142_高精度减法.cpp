#include <bits/stdc++.h>
using namespace std;
int main() {
	string a, b;
	cin >> a >> b;
	reverse(b.begin(),b.end());
	reverse(a.begin(),a.end());
	auto minus=[&](string a,string b)->string{
		bool flag=false;
		for(int i=0;i<b.size();i++){
			int now=a[i]-b[i];
			if(now<0) a[i+1]--,now+=10;
			a[i]=now+'0';
		}
		for(int i=b.size();i<a.size();i++)
			if(a[i]<'0') a[i+1]--,a[i]=a[i]+10;
		while(a.back()=='0') a.pop_back();
		return a;
	};
	if(a.size()>b.size()||(a.size()==b.size()&&a>=b)){
		if(a==b) cout<<0<<endl;
		else{
			a=minus(a,b); reverse(a.begin(),a.end()); cout<<a<<endl;
		}
	}else{
		b=minus(b,a); reverse(b.begin(),b.end()); cout<<'-'<<b<<endl;
	}
	return 0;
}