#include<bits/stdc++.h>
using namespace std;
int a[110][110];
int main() {
  int tt;cin>>tt;
  while(tt--){
    int n,m;cin>>n>>m;
    memset(a,0,sizeof(a));
    for(int i=1;i<=n;i++){
      string s;cin>>s;
      for(int j=0;j<m;j++)
        if(s[j]=='0') a[i][j+1]=0;
        else a[i][j+1]=1;
    }
    // 扫描线扫一下
    auto check=[&](){
      for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
          if(a[i][j]==1){
            if(a[i][j-1]==1&&((a[i-1][j-1]+a[i-1][j]==1)||(a[i+1][j-1]+a[i+1][j]==1))) return true;
            if(a[i][j+1]==1&&((a[i-1][j+1]+a[i-1][j]==1)||(a[i+1][j+1]+a[i+1][j]==1))) return true;
          }
        }
      }
      return false;
    };
    if(check()) puts("NO");
    else puts("YES");
  }
}