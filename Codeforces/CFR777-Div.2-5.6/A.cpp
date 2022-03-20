#include<bits/stdc++.h>
using namespace std;
int main() {
  int tt;cin>>tt;
  while(tt--){
    int n;cin>>n;
    int cnt=n/3;
    if (n%3==2){
      for(int i=1;i<=cnt;i++)cout<<"21";
      cout<<n%3;
    }
    else if (n%3==1){
      for(int i=1;i<=cnt;i++)cout<<"12";
      cout<<n%3;
    }
    else for(int i=1;i<=cnt;i++)cout<<"21";
    cout<<'\n';
  }
  return 0;
}