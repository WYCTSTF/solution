#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, q; cin>>n>>q;
	string s;cin>>s;
	s="$"+s;
	auto check=[&](int pos){
		if(s[pos]=='a') {
			if(pos>=n-1) return  false;
			else if(s[pos+1]=='b'&&s[pos+2]=='c') return true;
			else return false;
		} else if(s[pos]=='b'){
			if(pos==n||pos==1) return false;
			else if(s[pos-1]=='a'&&s[pos+1]=='c') return true;
			else return false;
		}else{
			if(pos<=2) return false;
			else if(s[pos-1]=='b'&&s[pos-2]=='a') return true;
			else return false;
		}
	};
	int tot=0;
	for(int i=1;i<=n-2;i++){
		if(s[i]=='a'&&s[i+1]=='b'&&s[i+2]=='c')
			tot++;
	}
	for(int i=1;i<=q;i++){
		int op; char c;
		cin>>op>>c;
		if(check(op)) tot--;
		s[op]=c; if(check(op)) tot++;
		cout<<tot<<endl;
	}
	return 0;
}