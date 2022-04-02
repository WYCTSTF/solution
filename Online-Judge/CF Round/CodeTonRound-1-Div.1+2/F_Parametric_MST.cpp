#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
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
// head
template<typename T>
inline void scan(T &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9')
		f=(ch=='-')?-1:1,ch=getchar();
	while (ch>='0'&&ch<='9')
		x=(x<<3)+(x<<1)+ch-48,ch=getchar();
	x*=f;
}
void solve(){
	int n;scan(n);
	vector a(n+1,0LL),sum(n+1,0LL);
	rep(i,1,n+1) scan(a[i]);
	sort(a.begin()+1,a.begin()+1+n);
	rep(i,1,n+1) sum[i]=sum[i-1]+a[i];
	if(a[1]*(n-2)+sum[n]>0||a[n]*(n-2)+sum[n]<0){
		puts("INF");
		return;
	}
	ll ans=-2e18;
	auto calc=[&](int pos,ll val)->ll{
		return -(n-1)*val*val+(a[n]+val)*(pos*val+sum[pos])+(a[1]+val)*(sum[n-1]-sum[pos]+(n-1-pos)*val);
	};
	rep(i,1,n) ans=max(ans,calc(i,-a[i]));
	cout<<ans<<endl;
}
int main() {
	int tt;scan(tt);
	while(tt--){
		solve();
	}
	return 0;
}