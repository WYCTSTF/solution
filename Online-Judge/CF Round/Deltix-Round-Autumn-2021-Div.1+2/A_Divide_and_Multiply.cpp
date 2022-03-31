#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
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
ll a[20];
int main() {
	int tt,n;cin>>tt;
	while(tt--){
		cin>>n;
		ll fac=1;
		for(int i=1;i<=n;i++) {cin>>a[i]; while(a[i]%2==0) a[i]/=2,fac*=2;}
		sort(a+1,a+1+n);
		a[n]*=fac; ll ans=0;
		for(int i=1;i<=n;i++) ans+=a[i];
		cout<<ans<<endl;
	}
	return 0;
}