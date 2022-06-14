#include <bits/stdc++.h>
using namespace std;
int main() {
  ifstream is1, is2;
  // wait(1000);
  puts("Compiling...");
  system("sleep 0.5");
  system("g++ brute.cpp -o b -std=c++17");
  system("g++ std.cpp -o std -std=c++17");
  system("g++ generator.cpp -o g -std=c++17");
  puts("Complete");

  for (int t = 1; t <= 20; t++) {
    string tem = to_string(t);
    // cout << tem << endl;
    string path = "./g 1 " + tem;
    // cout << path << endl;
    system(path.c_str());
    // string c1 = "./b < in"+to_string(t)+" > out"+to_string(t);
    string c2 = "./std < in"+to_string(t)+" > out"+to_string(t);
    // system(c1.c_str());
    system(c2.c_str());
    // system("sleep 1");
    // string o1 = "out"+to_string(t);
    // string o2 = "stdout"+to_string(t);
    // is1.open(o1.c_str(), ios::in);
    // is2.open(o2.c_str(), ios::in);
    // int t1, t2;
    // int tot = 0;
    // while (is1 >> t1) {
    //   tot++;
    //   is2 >> t2;
    //   if (t1 != t2) {
    //     cout << "WA on test case " << to_string(t) << endl;
    //   }
    // }
    // cout << "AC on test case #" << to_string(t) << endl;
  }
  return 0;
}