#include <bits/stdc++.h>

using ll = long long;

using namespace std;

int main() {
  int tt;cin>>tt;
  while(tt--){
    int n;cin>>n;
    int sum=0;
    while(n)sum+=n%10,n/=10;
    cout<<sum<<'\n';
  }
  return 0;
}
