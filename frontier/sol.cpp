#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

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
#define INF 0x7fffffff;
#define inf 0x3f3f3f3f;
#define MOD 998244353;
#define mod 1000000007;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef long long ll;
typedef double db;
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a; }

const int N=100010,K=10;
int n,m,k,nn;
int l[N],r[N];
struct point{
	int op,w,d;
	point(int OP=0,int W=0,int D=0){op=OP,w=W,d=D;}
} p[N<<1];
bool cmp(point x,point y){
	if(x.w==y.w) return x.op<y.op;
	return x.w<y.w;
}
int d[K],one[260];
int f[N<<1][260];
void amax(int &a,int b){a=max(a,b);}
int dp(){
	int all=(1<<k)-1;
	rep(i,1,all)one[i]=one[i-(i&-i)]+1;
	rep(i,0,nn) rep(j,0,all) f[i][j]=-inf;
	f[0][0]=0;
	rep(j,1,k) d[j]=-1;
	int now=0;
	rep(i,1,nn){
		int at=-1;
		if(p[i].op==1){
			rep(j,1,k) if(d[j]==-1){
				at=j,d[j]=p[i].d;break;
			}
			cerr << "now " << now << endl;
			assert(~at);
			rep(j,0,now) if((j&now)==j){ // 如果j是now的子集
				amax(f[i][j],f[i-1][j]+(one[j]&1)*(p[i].w-p[i-1].w)); // 取了奇数个区间
				amax(f[i][j|(1<<(at-1))],f[i-1][j]+(one[j]&1)*(p[i].w-p[i-1].w-1)+((one[j]+1)&1));
				cerr << "L " << i << ' ' << j << ' ' << f[i][j] << endl;
			}
			now|=(1<<(at-1));
		} else{
			rep(j,1,k) if(d[j]==p[i].d){at=j,d[j]=-1;break;}
			assert(~at);
			now^=(1<<(at-1));
			cerr << "now " << now << endl;
			rep(j,0,now) if((j&now)==j){
				amax(f[i][j],f[i-1][j]+(one[j]&1)*(p[i].w-p[i-1].w));
				amax(f[i][j],f[i-1][j|(1<<(at-1))]+((one[j]+1)&1)*(p[i].w-p[i-1].w-1)+(one[j]&1));
				cerr << "R " <<i << ' ' << j << ' ' << f[i][j] << endl;
			}
		}
	}
	return f[nn][0];
}
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>n>>m>>k;
	rep(i,1,n){
		cin>>l[i]>>r[i];
		p[++nn]=point(1,l[i],i);
		p[++nn]=point(-1,r[i]+1,i);
	}
	sort(p+1,p+1+nn,cmp);
	cout<<dp()<<endl;
	return 0;
}