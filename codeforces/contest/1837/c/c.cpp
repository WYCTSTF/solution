#include<bits/stdc++.h>
using namespace std;
bitset<300010>v;
int main(){
  int tt;
  cin>>tt;
  while(tt--){
    string s;cin>>s;
    int n=s.size();
    bool all=true;
    for(int i=0;i<n;++i)
      if(s[i]!='?')
        all=false;
    if(all){
      for(int i=1;i<=n;++i)
        cout<<'0';
      cout<<'\n';
      continue;
    }
    queue<int>q;
    v.reset();
    for(int i=0;i<n;++i)
      if(s[i]!='?')
        q.push(i),v[i]=1;
    while(!q.empty()){
      int fr=q.front();q.pop();
      if(fr-1>=0&&!v[fr-1]){
        v[fr-1]=1,s[fr-1]=s[fr];
        q.push(fr-1);
      }
      if(fr+1<n&&!v[fr+1])
        v[fr+1]=1,s[fr+1]=s[fr],q.push(fr+1);
    }
    cout<<s<<'\n';
  }
  return 0;
}
