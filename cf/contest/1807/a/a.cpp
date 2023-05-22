#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int a,b,c;
    cin >> a >> b >> c;
    if(a+b==c){
      cout<<"+\n";
    } else{
      cout<<"-\n";
    }
  }
  return 0;
}
