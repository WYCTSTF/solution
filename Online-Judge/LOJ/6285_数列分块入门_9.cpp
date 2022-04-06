#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
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
template<typename T>
inline void scan(T &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9')
		f=(ch=='-')?-1:1,ch=getchar();
	while (ch>='0'&&ch<='9')
		x=(x<<3)+(x<<1)+ch-48,ch=getchar();
	x*=f;
}
const int N=100010;
int a[N],p[N],val[N],lg[N]={-1};
int f[2000][2000],cnt[N];
int n,m,q,id;
map<int,int>mp;
vector<int>ve[N];
void pre(int x){
	memset(cnt,0,sizeof(cnt));
	int mx=0,ans=0;
	for(int i=(x-1)*m+1;i<=n;i++){
		cnt[a[i]]++;
		int t=p[i];
		if (cnt[a[i]]>mx||(cnt[a[i]]==mx&&val[a[i]]<val[ans]))
			ans=a[i],mx=cnt[a[i]];
		f[x][t]=ans;
	}
}
int query(int x,int y,int val){ // 查询x到y里面val出现的次数
	int t=upper_bound(all(ve[val]),y)
				-lower_bound(all(ve[val]),x);
	return t;
}
int query(int x,int y){
	int ans=inf,mx=0;
	if(p[x]+1<=p[y]-1)
		ans=f[p[x]+1][p[y]-1], mx=query(x,y,ans);
	for(int i=x;i<=min(p[x]*m,y);i++){
		int t=query(x,y,a[i]);
		if(t>mx||(t==mx&&val[a[i]]<val[ans]))
			ans=a[i],mx=t;
	}
	if(p[x]!=p[y]){
		for(int i=(p[y]-1)*m+1;i<=y;i++){
			int t=query(x,y,a[i]);
			if(t>mx||(t==mx&&val[a[i]]<val[ans]))
				ans=a[i],mx=t;
		}
	}
	return ans;
}
int main() {
	scan(n);
	for(int i=1;i<=n;i++) lg[i]=lg[i/2]+1;
	m=sqrt(n/lg[n]);
	for(int i=1;i<=n;i++) {
		scan(a[i]);
		if(!mp[a[i]]) mp[a[i]]=++id,val[id]=a[i];
		a[i]=mp[a[i]],p[i]=(i-1)/m+1;
		ve[a[i]].pb(i); // 存位置
	}
	for(int i=1;i<=p[n];i++) pre(i);// 枚举所有的起点i 预处理f[i][]
	for(int i=1;i<=n;i++){
		int x,y; scan(x),scan(y);
		cout<<val[query(x,y)]<<'\n';
	}
	return 0;
}