#include <bits/stdc++.h>
using namespace std;
struct Node {
  double x, y;
};
int main() {
  vector<Node>v;
  int tt; cin>>tt;
  while (tt--) {
    Node tem;
    v.clear();
    cin>>tem.x>>tem.y;
    v.push_back(tem);
    cin>>tem.x>>tem.y;
    v.push_back(tem);
    cin>>tem.x>>tem.y;
    v.push_back(tem);
    sort(v.begin(),v.end(),[&](const Node &a, const Node &b){return a.y == b.y ? a.x < b.x : a.y > b.y;});
    // for (auto it : v) {
    //   cout << it.x << ' ' << it.y << endl;
    // }
    if(v[1].y==v[0].y)
      printf("%.6lf\n", v[1].x-v[0].x);
    else
      puts("0");
  }
  return 0;
}