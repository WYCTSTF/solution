#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pi acos(-1)
#define il inline
#define rg register
#define SZ(x) ((int)(x).size())
#define all(x) x.begin(),x.end()
using namespace std;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef long long ll;
typedef double db;
const int INF=0x7fffffff;
const int inf=0x3f3f3f3f;
const int MOD=998244353;
const int mod=1e9+7;
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a; }
const int N=50010;
int n,m,a[N],p[N],tot[N];
ll ans,ansx[N],ansy[N];
struct Query{
	int l,r,id;
	bool operator<(const Query &A) const{
		return p[l]==p[A.l]?r<A.r:l<A.l;
	}
}qry[N];
ll query(int x){return 1LL*x*(x-1)/2;}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	int len=sqrt(n);
	rep(i,1,n) cin>>a[i], p[i]=(i-1)/len+1;
	rep(i,1,m) cin>>qry[i].l>>qry[i].r,qry[i].id=i;
	sort(qry+1,qry+1+m);
	int l=1,r=0;
	auto query=[&](int x)->ll{return 1LL*x*(x-1)/2;};
	auto add=[&](int x)->void{ans+=tot[x]++;};
	auto del=[&](int x)->void{ans-=--tot[x];};
	rep(i,1,m){
		int x=qry[i].l,y=qry[i].r;
		if(x==y) {
			ansx[qry[i].id]=0,ansy[qry[i].id]=1;
			continue;
		}
		while(x<l) add(a[--l]);
		while(x>l) del(a[l++]);
		while(y<r) del(a[r--]);
		while(y>r) add(a[++r]);
		ansx[qry[i].id]=ans;
		ansy[qry[i].id]=query(y-x+1);
	}
	for(int i=1;i<=m;i++){
		ll d=gcd(ansx[i],ansy[i]);
		cout<<ansx[i]/d<<'/'<<ansy[i]/d<<endl;
	}
	return 0;
}