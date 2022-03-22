#include<bits/stdc++.h>
using namespace std;
int main(){
  int tt;cin>>tt;
  while(tt--){
    int n,d,pp,Min=INT_MAX;cin>>n>>d;
    vector a(n+1,0);
    for(int i=1;i<=n;i++){
      cin>>a[i];
      if(Min>a[i]-a[i-1]-1)Min=a[i]-a[i-1]-1,pp=i;
    }
    auto check=[&](){
      int mx=0,mn=INT_MAX;
      for(int i=1;i<n;i++)mn=min(mn,a[i]-a[i-1]-1);
      for(int i=1;i<n;i++)mx=max(mx,a[i]-a[i-1]-1);
      return min(mn,max(d-a[n-1]-1,mx-1>>1));
    };
    stack<int>sta; int k=n;
    while(k!=pp)
      sta.push(a.back()), k--, a.pop_back();
    int now=a[k]; a.pop_back();
    while(!sta.empty()) a.push_back(sta.top()),sta.pop();
    int ans=check();
    if (pp>1) a[pp-1]=now;
    ans=max(ans,check());
    cout<<ans<<'\n';
  }
  return 0;
}