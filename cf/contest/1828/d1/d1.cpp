#include<bits/stdc++.h>
using std::cin,std::cout,std::vector;
using i64=long long;
void solve(){
  int n;cin>>n;
  vector<int>a(n);
  for(int &x:a)cin>>x;
  i64 ans=0;
  for(int i=0;i<n;++i){
    vector<std::pair<int,int>>st;
    for(int j=i;j<n;++j){
      std::pair<int,int>p{a[j],a[j]};
      while(!st.empty()&&st.back().second>a[j]){
        p.second=std::max(p.second,st.back().second);
        p.first=std::min(p.first,st.back().first);
        st.pop_back();
      }
      st.push_back(p);
      ans+=j-i+1-st.size();
    }
  }
  cout<<ans<<'\n';
}
int main() {
  int tt;
  cin>>tt;
  while(tt--){
    solve();
  }
  return 0;
}
