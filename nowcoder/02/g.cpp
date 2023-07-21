#include <bits/stdc++.h>
using namespace std;
bool solve() {
  string s;
  cin >> s;
  stack<char> sta;
  map<char,char>mp;
  mp['b']='q';
  mp['d']='p';
  mp['p']='d';
  mp['q']='b';
  mp['n']='u';
  mp['u']='n';
  for (char ch:s){
    if(ch=='o'||ch=='x'||ch=='z'||ch=='s')
      continue;
    if(!sta.empty()&&ch==mp[sta.top()])
      sta.pop();
    else
      sta.push(ch);
  }
  return sta.empty();
}
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    if(solve())
      cout<<"Yes\n";
    else
      cout<<"No\n";
  }
  return 0;
}
