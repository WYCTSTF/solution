#include<bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int a[2010], tt, n; cin>>tt;
  stack<int>sta;
  auto turn=[&](auto self, int k) {
    if (k==0) return;
    int now=1; while (a[now]!=k) now++;
    if (now<k) {
      sta.push(now);
      vector<int>e;
      for (int i=now+1; i<=k; i++) e.push_back(a[i]);
      for (int i=1; i<=now; i++) e.push_back(a[i]);
      for (int i=0; i<k; i++) a[i+1]=e[i];
    } else
      sta.push(0);
    self(self, k-1);
  };
  for (; tt; tt--) {
    cin>>n;
    for (int i=1; i<=n; i++) cin>>a[i];
    turn(turn, n);
    while (!sta.empty()) cout<<sta.top()<<' ', sta.pop();
    cout<<'\n';
  }
}