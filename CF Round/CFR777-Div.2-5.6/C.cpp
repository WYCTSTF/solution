#include <bits/stdc++.h>
using namespace std;
int tar[110][110];
struct Node {
  int x1,y1,x2,y2;
};
int main() {
  int tt;cin>>tt;
  int n,m;
  while(tt--){
    cin>>n>>m;
    memset(tar,0,sizeof(tar));
    for(int i=1;i<=n;i++){string s;cin>>s;
      for(int j=0;j<m;j++) {if(s[j]=='0') tar[i][j+1]=0; else tar[i][j+1]=1;}
    }
    if(tar[1][1]==1) {cout<<"-1"<<'\n';continue;}
    queue<Node>q;
    for(int i=n;i>=1;i--){
      for(int j=m;j>=1;j--){
        if(tar[i][j]==1){
          if(j>1) q.push({i,j-1,i,j});
          else q.push({i-1,j,i,j});
        }
      }
    }
    cout<<q.size()<<'\n';
    while(!q.empty()) {
      auto u=q.front(); q.pop();
      cout<<u.x1<<' '<<u.y1<<' '<<u.x2<<' '<<u.y2<<'\n';
    }
  }
  return 0;
}