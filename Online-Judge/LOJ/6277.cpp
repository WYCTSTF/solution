#include<bits/stdc++.h>
using namespace std;
int main() {
  int n; cin.tie(nullptr)->sync_with_stdio(false); cin>>n; 
  int m=sqrt(n);
  vector a(n+1, 0), tag(n/2+2, 0), pos(n+1, 0);
  for (int i=1; i<=n; i++) cin>>a[i], pos[i]=(i-1)/m+1;
  auto add=[&](int l, int r, int c)->void {
    for (int i=l; i<=min(r,pos[l]*m);i++) a[i]+=c;
    if (pos[l]!=pos[r]) for (int i=(pos[r]-1)*m+1; i<=r; i++) a[i]+=c;
    for (int i=pos[l]+1; i<=pos[r]-1; i++) tag[i]+=c;
  };
  for (int i=1, op, l, r, c; i<=n; i++) {
    cin>>op>>l>>r>>c;
    if (op==0) add(l, r, c); else cout<<a[r]+tag[pos[r]]<<'\n';
  }
  return 0;
}