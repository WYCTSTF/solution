#include <bits/stdc++.h>
using namespace std;
struct Node { int u, w, p; };
int main() {
  int tt; cin>>tt;
  while (tt--) {
    int n, m, sum = 0; cin>>n >>m;
    vector<Node>a(m);
    for (int i=0; i<m; i++) cin>>a[i].u>>a[i].w, a[i].p=i+1;
    sort(a.begin(), a.end(),[&](Node a, Node b){return a.w<b.w;});
    for (int i = 0; i < 2 * n; i++) sum += a[i].w;
    sort(a.begin(), a.begin()+2*n,[&](Node a,Node b){return a.u<b.u;});
    cout << sum << '\n';
    for(int i=0;i<n;i++) cout<<a[i].p<<' '<<a[2*n-1-i].p<<'\n';
  }
  return 0;
}