#include <bits/stdc++.h>

using ll = long long;

using namespace std;

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<char>ss;
    for(auto c:s)
      ss.push_back(c);
    sort(ss.begin(),ss.end());
    int len = unique(ss.begin(),ss.end())-ss.begin();
    map<char,char> mp;
    for(int i=0;i<len;++i)
      mp[ss[i]]=ss[len-i-1];
    // cout<<len<<'\n';
    for(auto c:s)
      cout<<mp[c];
    cout<<'\n';
  }
  return 0;
}
