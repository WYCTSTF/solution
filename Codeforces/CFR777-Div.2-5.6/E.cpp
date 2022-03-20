#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using VI=vector<int>;
const int N=101000;
int n,p[33][N],a[N],vis[N],ans[N];
vector<int>Vpos[N],Rpos[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>n; set<int>s;
  for (int i=1;i<=n;i++) cin>>p[0][i], s.insert(p[0][i]);
  for (int i=1;i<=n;i++) cin>>a[i];
  int maxx=*max_element(a+1,a+1+n), tt=(maxx-n)/(n-s.size());
  for (int i=1;i<=30;i++) for(int j=1;j<=n;j++)
    p[i][j]=p[i-1][p[i-1][j]];
  for (int i=1;i<=n;i++) {
    int pos=i;
    for (int j=0;j<=30;j++) if(tt&(1<<j)) pos=p[j][pos];
    Vpos[pos].push_back(i); // begin i end pos
  }
  for (int i=1;i<=n;i++) if(a[i]<=n) { // 如果对当前的结束位置有最小值要求
    ans[Vpos[i][0]]=a[i]; // 当前是a[i] 找到最靠前的b[pos]
    vis[a[i]]=1;
    for(int j=1;j<Vpos[i].size();j++) Rpos[a[i]].push_back(Vpos[i][j]); // a[i]插入之后 要把所有同一pos的位置集合起来 保证a[i]是最小的
  }
  set<int>bpos;
  for (int i=1;i<=n;i++) { // 没有位置要求的按升序放置
    if (!vis[i]) {
      int v=*bpos.begin();
      ans[v]=i;
      bpos.erase(v);
    }
    for(auto it:Rpos[i]) bpos.insert(it); // 保证最小数字是i的集合里的位置不会在选择1～i-1时出现
  }
  for(int i=1;i<=n;i++)
    cout<<ans[i]<<' ';
  return 0;
}