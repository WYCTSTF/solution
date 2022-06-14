#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
const int N = 40000;
// const int M = 1000000;
int main(int argc, char* argv[]) {
  registerGen(argc, argv, 1);
  ofstream os;
  string tem = "in";
  for (int i = 0; i < strlen(argv[2]); i++) {
    tem.push_back(argv[2][i]);
  }
  cout << tem << endl;
  os.open(tem.c_str(), ios::out | ios::trunc);

  int n = rnd.next(101000, 500000);
  int m = rnd.next(101000, 500000);
  if (n > m) swap(n, m);
  // int m = rnd.next(1, M);
  os << n << ' ' << m << endl;
  // for (int i = 1; i <= m; i++) {
  //   int op = rnd.next(1, 2);
  //   if (op == 1) {
  //     int x = rnd.next(1, n);
  //     int y = rnd.next(1, M);
  //     os << op << ' ' << x << ' ' << y << endl;
  //   } else os << op << endl;
  // }
  os.close();
  return 0;
}