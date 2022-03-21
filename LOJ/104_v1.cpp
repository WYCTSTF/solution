#include<bits/stdc++.h>
using namespace std;
#define ls p<<1
#define rs p<<1|1
#define mid (l+((r-l)>>1))
const int N=1e5+5;
int n,tot,op[N],V[N],lsh[N],seg[N<<2];
void mark(int p,int l,int r,int q,int v){
  if (l==r) {seg[p]+=v; return;}
  if (q<=mid) mark(ls,l,mid,q,v);
  else mark(rs,mid+1,r,q,v);
  seg[p]=seg[ls]+seg[rs];
}
int QueryCnt(int p,int l,int r,int ql,int qr){
  if(l==ql&&qr==r) return seg[p];
  if (qr<=mid) return QueryCnt(ls,l,mid,ql,qr);
  else if(ql>mid) return QueryCnt(rs,mid+1,r,ql,qr);
  return QueryCnt(ls,l,mid,ql,mid)+QueryCnt(rs,mid+1,r,mid+1,qr);
}
int QueryNum(int p,int l,int r,int k){
  if (l==r) return l;
  if (k<=seg[ls]) return QueryNum(ls,l,mid,k);
  else return QueryNum(rs,mid+1,r,k-seg[ls]);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>n;
  for (int i=1;i<=n;i++) {
    cin>>op[i]>>V[i];
    if (op[i]!=4) lsh[++tot]=V[i];
  }
  sort(lsh+1,lsh+1+tot);
  tot=unique(lsh+1,lsh+1+tot)-lsh-1;
  for (int i=1;i<=n;i++) {
    if (op[i]!=4) V[i] = lower_bound(lsh+1,lsh+1+tot,V[i])-lsh;
    if (op[i]==1) mark(1,1,tot,V[i],1);
    if (op[i]==2) mark(1,1,tot,V[i],-1);
    if (op[i]==3) {
      if (V[i]==1) {cout<<'1'<<'\n'; continue;}
      cout<<QueryCnt(1,1,tot,1,V[i]-1)+1<<'\n';
    }
    if (op[i]==4) cout<<lsh[QueryNum(1,1,tot,V[i])]<<'\n';
    if (op[i]==5) {
      int rk=QueryCnt(1,1,tot,1,V[i]-1);
      cout<<lsh[QueryNum(1,1,tot,rk)]<<'\n';
    }
    if (op[i]==6) {
      int rk=QueryCnt(1,1,tot,1,V[i])+1;
      cout<<lsh[QueryNum(1,1,tot,rk)]<<'\n';
    }
  }
}