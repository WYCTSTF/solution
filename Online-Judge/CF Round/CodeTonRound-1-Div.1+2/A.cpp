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
int main() {
	int tt;cin>>tt;
	while(tt--){
		int n;cin>>n;
		int Max=-1,Min=INT_MAX,p1,p2;
		for(int i=1;i<=n;i++) {
			int tem;cin>>tem;
			if(tem>Max) Max=tem,p1=i;
			if(tem<Min) Min=tem,p2=i;
		}
		if(p1>p2) p1^=p2^=p1^=p2;
		cout<<p1<<' '<<p2<<'\n';
	}
	return 0;
}