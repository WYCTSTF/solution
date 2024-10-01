#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 114514
#endif
int n;
int solve(vector<string>&v){
  int t1=1,t2=0;
  for(int i=1;i<n;++i){
    if(v[i]==v[0])t1++;
    else{
      int tag=1;
      for(int j=0;j<n;++j)
        if(v[i][j]==v[0][j])
          tag=0;
      if(tag)
        t2++;
    }
  }
  if(t1+t2!=n){
    return -1;
  }
  int tot=0;
  for(char c:v[0])if(c=='1')tot++;
  int ans = min(t1, t2) + min(n - tot, tot);
  return ans;
}
int main(){
  cin>>n;
  vector<string>v(n);
  for(int i=0;i<n;++i)
    cin>>v[i];
  debug(v);
  vector<string>_v;
  for(int j=0;j<n;++j){
    string tem="";
    for(int i=0;i<n;++i)
      tem+=v[i][j];
    _v.push_back(tem);
  }
  debug(_v);
  int ans=solve(v);
  if(ans==-1){
    cout<<"-1\n";
    return 0;
  }else{
    debug(ans);
    ans=min(ans,solve(_v));
    cout<<ans<<'\n';
  }
  return 0;
}
