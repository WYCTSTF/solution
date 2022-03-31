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
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,k;
	cin>>n>>k;
	vector v(n,vector<int>(n));
	vector<array<int,2>>pos(n*n);
	rep(i,0,n-1){
		rep(j,0,n-1){
			cin>>v[i][j];
			v[i][j]--;
			pos[v[i][j]]={i,j};
		}
	}
	int p1=-inf,p2=-inf,p3=-inf,p4=-inf;
	vector<string>ans(n,string(n,'G'));
	per(i,0,n*n-1){
		auto [x,y]=pos[i];
		if(p1>x+y+k||p2>-x-y+k||p3>x-y+k||p4>y-x+k) continue;
		ans[x][y]='M';
		p1=max(p1,x+y);
		p2=max(p2,-x-y);
		p3=max(p3,x-y);
		p4=max(p4,y-x);
	}
	rep(i,0,n-1) cout<<ans[i]<<'\n';
}