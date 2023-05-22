#include <bits/stdc++.h>

using ll = long long;
using namespace std;
int main() {
	set<char> s{'c','d','f','e','s','o','r'};
	int tt;
	cin>>tt;
	while(tt--){
		char c;
		cin>>c;
		if(s.find(c)!=s.end()){
			cout << "YES\n";
		} else{
			cout << "NO\n";
		}
	}
	return 0;
}
