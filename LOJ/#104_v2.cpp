#include<bits/stdc++.h>
#define mid (l+((r-l)>>1))
using namespace std;
const int L=-1e7-5;
const int R=1e7+5;
const int N=1e5+5;
int n,sz,rt;
int ls[N<<5],rs[N<<5],seg[N<<5];
void pushUp(int p){seg[p]=seg[ls[p]]+seg[rs[p]];}
void mark(int &p,int l,int r,int x,int v) {
  if (!p) p=++sz;
  if (l==r){ seg[p]+=v; return ;}
  if (x<=mid) mark(ls[p],l,mid,x,v);
  else mark(rs[p],mid+1,r,x,v);
  pushUp(p);
}
int QueryCnt(int p,int l,int r,int x,int y) {
  if(!p) return 0;
  if(l==x&&r==y) return seg[p];
  if (y<=mid) return QueryCnt(ls[p],l,mid,x,y);
  else if(x>mid) return QueryCnt(rs[p],mid+1,r,x,y);
  else return QueryCnt(ls[p],l,mid,x,mid)+QueryCnt(rs[p],mid+1,r,mid+1,y);
}
int QueryNum(int p,int l,int r,int k) {
  if (l==r) return l;
  if (seg[ls[p]]>=k) return QueryNum(ls[p],l,mid,k);
  else return QueryNum(rs[p],mid+1,r,k-seg[ls[p]]);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>n; int op,k;
  for(int i=1;i<=n;i++){
    cin>>op>>k;
    if (op==1) mark(rt,L,R,k,1);
    if (op==2) mark(rt,L,R,k,-1);
    if (op==3) cout<<QueryCnt(rt,L,R,L,k-1)+1<<'\n';
    if (op==4) cout<<QueryNum(rt,L,R,k)<<'\n';
    if (op==5) {
      int cnt=QueryCnt(rt,L,R,L,k-1);
      cout<<QueryNum(rt,L,R,cnt)<<'\n';
    }
    if (op==6) {
      int cnt=QueryCnt(rt,L,R,L,k)+1;
      cout<<QueryNum(rt,L,R,cnt)<<'\n';
    }
  }
  return 0;
}