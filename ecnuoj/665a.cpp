#include<bits/stdc++.h>
using namespace std;
int lg2[1000010];
int main() {
  int n;
  cin >> n;
  lg2[1]=0;
  for(int i=2;i<=1000000;++i)
    lg2[i]=lg2[i/2]+1;
  cout<<lg2[n]+1<<'\n';
  return 0;
}
