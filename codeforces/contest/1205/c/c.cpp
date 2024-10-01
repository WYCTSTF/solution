#include <bits/stdc++.h>
using namespace std;
int a[55][55];
int ask(int x1,int y1,int x2,int y2){
  cout<<"? "<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<'\n';
  int ans;cin>>ans;return ans;
}
int main(){
  int n;cin>>n;
  a[1][1]=1;
  // suppose a[1][2]=0
  for(int i=3;i<=n;++i)
      a[1][i]=ask(1,i-2,1,i)?a[1][i-2]:(a[1][i-2]^1);
  for(int i=2;i<=n;++i){
    for(int j=n;j>=1;--j){
      if(j>=2)
        a[i][j]=ask(i-1,j-1,i,j)?a[i-1][j-1]:(a[i-1][j-1]^1);
      else
        a[i][j]=ask(i,j,i,j+2)?a[i][j+2]:(a[i][j+2]^1);
    }
  }
  int tg=0;
  for(int i=1;i<=n;i+=2){
    if(a[i][i]==1&&a[i+2][i+2]==0){
      if(ask(i,i+1,i+2,i+2))
        tg=a[i][i+1];
      else if(ask(i,i,i+1,i+2))
        tg=a[i+1][i+2]^1;
      else{
        if(a[i+1][i+2]==a[i][i+1])
          tg=a[i][i+1]^a[i][i+2]^1;
        else{
          if(a[i][i+2]==0)
            tg=a[i+1][i+2];
          else
            tg=a[i][i+1]^1;
        }
      }
      break;
    }
  }
  return 0;
}