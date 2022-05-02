#include <bits/stdc++.h>
using namespace std;
int main() {
	int tt; cin>>tt;
	set<char>S;
	while (tt--) {
		string s;
		vector tot(30,0);
		cin>>s;
		S.clear();
		int point=-1;
		for(int i=0;i<(int)(s.size());i++) {
			if(S.find(s[i])!=S.end()&&point==-1) point=i;
			else S.insert(s[i]);
		}
		if(point==-1) {puts("YES");}
		else {
			bool flag=false;
			// cerr << point << ' ';
			for(int i=0;i<(int)(s.size());i++)
				if(s[i%point]!=s[i]) flag=true;
			if(flag) puts("NO");
			else puts("YES");
		}
	}
	return 0;
}