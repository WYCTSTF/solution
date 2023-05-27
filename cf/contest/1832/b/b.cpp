#include<bits/stdc++.h>
using i64=long long;
using std::cin,std::cout;
void solve(){
  int n,k;
  cin>>n>>k;
  std::vector<i64>a(n),s(n);
  for(i64&x:a)cin>>x;
  sort(a.begin(),a.end());
  std::partial_sum(a.begin(),a.end(),s.begin());
  i64 ans=s[n-1]-s[2*k-1];
  for(int j=1;j<k;++j)
    ans=std::max(ans,s[n-j-1]-s[2*(k-j)-1]);
  ans=std::max(ans,s[n-k-1]);
  cout<<ans<<'\n';
}
int main(){
  int tt;cin>>tt;
  while(tt--)solve();
  return 0;
}
