#include<bits/stdc++.h>
using namespace std;
int tot[10][100010];
int main(){
  int tt;
  cin>>tt;
  while(tt--){
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<10;++i)
      tot[i][0]=0;
    for(int i=1;i<=n;++i){
      int now=s[i-1]-'0';
      for(int j=0;j<10;++j)
        tot[j][i]=tot[j][i-1];
      tot[now][i]++;
    }
    int ans=0;
    for(int l=1;l<=n;++l){
      for(int r=l;r<=min(n,l+99);++r){
        int mx=-1,tag=0;
        for(int i=0;i<10;++i){
          mx=max(mx,tot[i][r]-tot[i][l-1]);
          if(tot[i][r]-tot[i][l-1]>0)
            tag++;
        }
        if(mx>tag)
          continue;
        ans++;
      }
    }
    cout<<ans<<'\n';
  }
  return 0;
}