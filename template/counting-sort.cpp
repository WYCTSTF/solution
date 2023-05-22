#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
const int W = 1e6+10;
int n,w,a[N],cnt[W],b[N];
void counting_sort(){
  memset(cnt,0,sizeof cnt);
  for(int i=1;i<=n;++i)++cnt[a[i]];
  for(int i=1;i<=w;++i)cnt[i]+=cnt[i-1];
  for(int i=n;i>=1;--i)b[cnt[a[i]]--]=a[i]; // 倒序保证稳定性
}