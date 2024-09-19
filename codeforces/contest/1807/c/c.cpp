#include <bits/stdc++.h>

using ll = long long;
using namespace std;
bool solve() {
  int n;
  cin>>n;
  string s;
  cin>>s;
  vector<int> tag(26,-1);
  for(int i=0;i<n;++i){
    int now=s[i]-'a';
    if(i%2!=tag[now]){
      if(tag[now]==-1)
        tag[now]=i%2;
      else
        return false;
    }
  }
  return true;
}
int main() {
  int tt;
  cin>>tt;
  while(tt--){
    if(solve()) cout<<"YES\n";
    else cout<<"NO\n";
  }
	return 0;
}
