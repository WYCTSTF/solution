#include <bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int n,k1,k2; cin>>n>>k1>>k2;
  vector a(n, 0);
  for(int i=0;i<n;i++) cin>>a[i];
  vector val(k1*2,vector<int>(k2*2,INT_MIN));
  for(int i=0;i<n;i++) {
    vector t1(k1*2,vector<int>(k2*2,INT_MIN));
    for(int x=1;x<k1*2;x++) for(int y=1;y<k2*2;y++) t1[x][y]=max(t1[x][y],val[x][y]);
    int p1=a[i]%k1+k1,p2=a[i]%k2+k2;
    for(int x=1;x<k1*2;x++) for(int y=0;y<k2*2;y++) if(val[x][y]!=INT_MIN){
      int P1=(p1+x)%(k1*2)+k1,P2=(p2+y)%(k2*2)+k2;
      t1[P1][P2]=max(t1[P1][P2], a[i]+val[x][y]);
    }
    t1[p1][p2]=max(t1[p1][p2], a[i]);
    cout<<t1[p1][p2]<<'\n';
    for(int x=1;x<k1*2;x++) for(int y=1;y<k2*2;y++) val[x][y]=t1[x][y];
  }
  int Max=INT_MIN;
  for (int i=1;i<k2*2;i++) cout<<val[0][i]<<' ';
  for(int i=1;i<k2;i++) Max=max(Max,val[0][i]);
  for(int i=k2+1;i<k2*2;i++) Max=max(Max,val[0][i]);
  cout<<Max<<'\n';
}