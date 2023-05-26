#include<bits/stdc++.h>
using namespace std;
void solve(){
  int n;
  cin>>n;
  string s;
  cin>>s;
  vector<int> acc(n+1,0);
  for(int i=1;i<=n;++i)
    acc[i]=acc[i-1]+(int)(s[i-1]=='('?1:-1);
  if(acc[n]){
    cout<<"-1\n";
    return;
  }
  int pos=0;
  vector<int>ans(n+1,0);
  int col=1;
  while(pos<n){
    int tmp=pos;
    if(s[pos]=='('){
      while(pos<n&&acc[pos+1]>=acc[tmp])
        ans[++pos]=col;
    }else{
      while(pos+1<=n&&acc[pos+1]<=acc[tmp])
        ans[++pos]=col;
    }
    col=3-col;
  }
  cout<<*max_element(ans.begin(),ans.end())<<'\n';
  for(int i=1;i<=n;++i)cout<<ans[i]<<" \n"[i==n];
}
int main(){
  int tt;
  cin>>tt;
  while(tt--){
    solve();
  }
  return 0;
}
