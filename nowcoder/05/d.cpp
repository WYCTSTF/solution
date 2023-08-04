#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include"algo/debug.h"
#else
#define debug(...) 42
#endif
void solve(){
  int k,c,n;
  cin>>k>>c>>n;
  set<int>del;
  for(int i=2;i*i<=c;++i){
    if(i>=n)
      del.insert(i);
    if(c/i==n)
      del.insert(c/i);
  }

}
int main(){
  int tt;cin>>tt;
  while(tt--){
    solve();
  }
  return 0;
}
