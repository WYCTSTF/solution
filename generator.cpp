#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
const int N = 500000;
const int M = 1000000;
int main(int argc, char* argv[]) {
  registerGen(argc, argv, 1);
  ofstream os;
  os.open("in", ios::out | ios::trunc);

  int n = rnd.next(1, N);
  int m = rnd.next(1, M);
  os << n << ' ' << m << endl;
  for (int i = 1; i <= n; i++) {
    int op = rnd.next(1, 2);
    if (op == 1) {
      int x = rnd.next(1, n);
      int y = rnd.next(1, M);
      os << op << ' ' << x << ' ' << y << endl;
    } else os << op << endl;
  }
  os.close();
  return 0;
}