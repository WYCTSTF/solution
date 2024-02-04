#include <bits/stdc++.h>
using namespace std;
int main() {
  int tt;
  cin>>tt;
  while(tt--){
    int n,r,g,b;
    cin>>n>>r>>g>>b;
    int tot=0;
    if((n-r&1)||(r-1&1))
      tot++;
    if((n-g&1)||(g-1&1))
      tot++;
    if((n-b&1)||(b-1&1))
      tot++;
    if (tot&1)
      cout<<"Alice\n";
    else
      cout<<"Bob\n";
  }
  return 0;
}
