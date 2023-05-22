#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k;
  cin>>n>>k;
  vector<int>p(n);
  for(int &x:p)cin>>x;
  int a=1,b=n*(n+1)/2;
  for(int i=0;i<n;++i){
    vector<int>low,high;
    for(int j=i+1;j<n;++j)
      if(p[j]<p[i])low.push_back(p[j]);
      else high.push_back(p[j]);
    int x=-1;
    if(k-a<(int)low.size()){
      sort(low.begin(),low.end());
      x=low[k-a];
    }
    if(b-k<(int)high.size()){
      sort(high.begin(),high.end(),greater<int>());
      x=high[b-k];
    }
    if(x!=-1){
      int j=i;
      while(p[j]!=x)++j;
      reverse(p.begin()+i,p.begin()+j+1);
      break;
    }
    a+=low.size(),b-=high.size();
  }
  for(int &x:p)
  cout<<x<<' ';
  return 0;
}
