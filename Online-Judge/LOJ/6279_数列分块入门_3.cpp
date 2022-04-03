#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int m = sqrt(n);
  vector a(n + 1, 0), p(n + 1, 0), tag(m + 2, 0);
  set<int> s[m + 10];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    p[i] = (i - 1) / m + 1;
    s[p[i]].insert(a[i]);
  }
  auto add = [&](int x, int y, int val) -> void {
    for (int i = x; i <= min(p[x] * m, y); i++) {
      s[p[x]].erase(a[i]);
      a[i] += val;
      s[p[x]].insert(a[i]);
    }
    if (p[x] != p[y]) {
      for (int i = (p[y] - 1) * m + 1; i <= y; i++) {
        s[p[y]].erase(a[i]);
        a[i] += val;
        s[p[y]].insert(a[i]);
      }
    }
    for (int i = p[x] + 1; i < p[y]; i++)
      tag[i] += val;
  };
  auto query = [&](int x, int y, int val) -> int {
		int ans=-1;
		for(int i=x;i<=min(p[x]*m,y);i++) {
      if (a[i]+tag[p[i]]<val) ans=max(a[i]+tag[p[i]],ans);
    }
    if(p[x]!=p[y]){
      for(int i=(p[y]-1)*m+1;i<=y;i++){
        if (a[i]+tag[p[i]]<val) ans=max(a[i]+tag[p[i]],ans);
      }
    }
    for (int i=p[x]+1;i<p[y];i++){
      int x=val-tag[i];
      auto it=s[i].lower_bound(x);
      if(it==s[i].begin()) continue;
      ans=max(ans,*--it+tag[i]);
    }
    return ans;
  };
  for(int i=1;i<=n;i++) {
    int f,x,y,val; cin>>f>>x>>y>>val;
    if(f==0) add(x,y,val);
    else cout<<query(x,y,val)<<'\n';
  }
  return 0;
}