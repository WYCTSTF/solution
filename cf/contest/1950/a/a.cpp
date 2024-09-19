#include <bits/stdc++.h>

using ll = long long;

int main() {
  int tt;std::cin>>tt;
  while(tt--){
    int a,b,c;std::cin>>a>>b>>c;
    if(a<b and b<c)puts("STAIR");
    else if(a<b and b>c) puts("PEAK");
    else puts("NONE");
  }
  return 0;
}
