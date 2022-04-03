#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
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
using ll=long long;
template<typename T>
inline void scan(T &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9')
		f=(ch=='-')?-1:1,ch=getchar();
	while (ch>='0'&&ch<='9')
		x=(x<<3)+(x<<1)+ch-48,ch=getchar();
	x*=f;
}
const int N=5e5+10;
int a[N],f[N];
ll ans=0;
void Merge(int L,int R){
	if(L==R) return;
	int mid=(L+R)>>1;
	Merge(L,mid); Merge(mid+1,R);
	int p=L, q=mid+1, s=L;
	while(s<=R){
		if((a[p]>a[q]&&q<=R)||p>mid)
			f[s++]=a[q++],ans+=max(mid-p+1,0);
		else f[s++]=a[p++];
	}
	for(int i=L;i<=R;i++) a[i]=f[i];
}
int main() {
	int n; scan(n);
	for(int i=1;i<=n;++i) scan(a[i]);
	Merge(1,n);
	cout<<ans<<endl;
	return 0;
}