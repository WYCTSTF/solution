#include <bits/stdc++.h>
using namespace std;
int main() {
  ifstream is1, is2;
  is1.open("out", ios::in);
  is2.open("stdout", ios::in);
  int t1, t2;
  int tot = 0;
  while (is1 >> t1) {
    tot++;
    is2 >> t2;
    if (t1 != t2) {
      cout << "WA on Line " << tot; return 0;
    }
  }
  puts("AC");
  return 0;
}