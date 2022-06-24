#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

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

int n, m, k;
int l[100010], r[100010];
struct point {
	int op, w, d;
	point(int OP=0, int W=0, int D=0) {op=OP,w=W,d=D;}
};
bool cmp(point x,point y){
	if(x.w==y.w) return x.op<y.op;
	return x.w<y.w;
}
int pcnt;
point p[200010];

int d[15],one[260];
int f[200010][260];
void amax(int &x,int y){x=max(x,y);}

int DP() {
	int ful=(1<<k)-1;
	for(int i=1;i<=ful;i++) one[i]=one[i-(i&-i)]+1;
	for(int i=0;i<=pcnt;i++)
		for(int j=0;j<=ful;j++) f[i][j]=-inf;
	f[0][0]=0;
	for(int i=1;i<=k;i++) d[i]=-1;
	int now=0;
	for(int i=1;i<=pcnt;i++){
		int at=-1;
		if(p[i].op==1){
			for(int j=1;j<=k;j++)
				if(d[j]==-1){at=j,d[j]=p[i].d;break;}
			assert(~at);
			for(int j=0;j<=now;j++){
				if((j&now)==j){
					amax(f[i][j],f[i-1][j]+(one[j]&1)*(p[i].w-p[i-1].w));
					amax(f[i][j|(1<<(at-1))],f[i-1][j]+(one[j]&1)*(p[i].w-p[i-1].w-1)+((one[j]+1)&1));
				}
			}
			now|=(1<<(at-1));
		}else{
			for(int j=1;j<=k;j++){
				if(d[j]==p[i].d){
					at=j,d[j]=-1;
					break;
				}
			}
			assert(~at);
			now^=(1<<(at-1));
			for(int j=0;j<=now;j++) if((j&now)==j){
				amax(f[i][j],f[i-1][j]+(one[j]&1)*(p[i].w-p[i-1].w));
				amax(f[i][j],f[i-1][j|(1<<(at-1))]+((one[j]+1)&1)*(p[i].w-p[i-1].w-1)+(one[j]&1));
			}
		}
	}
	return f[pcnt][0];
}

int main() {
	cin >> n >> m >> k;
	for (int i=1;i<=n;i++){
		cin>>l[i]>>r[i];
		p[++pcnt]=point(1,l[i],i);
		p[++pcnt]=point(-1,r[i]+1,i);
	}
	sort(p+1,p+1+pcnt,cmp);
	cout<<DP()<<endl;
	return 0;
}