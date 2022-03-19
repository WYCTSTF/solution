#include <bits/stdc++.h>
using namespace std;
int Min = 0x7fffffff;
int check(int a, int b) { return min(abs(b - a), (a | b) - b + 1); }
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    Min = 0x7fffffff;
    int a, b;
    cin >> a >> b;
    for (int i = a; i <= b; i++) {
      // cout<<check(i,b)+i-a<<endl;
      Min = min(Min, check(i, b) + i - a);
    }
    int gg = 0;
    for (int i = 24; i >= 0; i--)
      if (a >> i & 1 == 1) {
        gg = i;
        break;
      }
    for (int i = 0; i <= (1 << gg); i++) {
      Min = min(Min, check(a, i + b) + i);
    }
    cout << Min << endl;
  }
  return 0;
}