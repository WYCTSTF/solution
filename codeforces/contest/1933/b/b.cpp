#include <bits/stdc++.h>
void solve() {
  int n;
  std::cin>>n;
  int t0=0,t1=0,t2=0,sum=0;
  for(int i=1;i<=n;++i){
    int tem;std::cin>>tem;
    sum+=tem;if(tem%3==0)t0++;
    if(tem%3==1)t1++;
    if(tem%3==2)t2++;
  }
  if(sum%3==2)std::cout<<"1\n";
  if(sum%3==1){
    if(t1)std::cout<<"1\n";
    else std::cout<<"2\n";
  }
  if(sum%3==0){
    std::cout<<"0\n";
  }
  return;
}
int main() {
  int tt;
  std::cin>>tt;
  while(tt--){
    solve();
  }
  return 0;
}
