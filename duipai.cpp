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
template<typename T>
inline void scan(T &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9')
		f=(ch=='-')?-1:1,ch=getchar();
	while (ch>='0'&&ch<='9')
		x=(x<<3)+(x<<1)+ch-48,ch=getchar();
	x*=f;
}
const int N=100005;
int n,blo,m;
VI ve[1005];
int st[N*2],top;
PII query(int b){
	int x=1;
	while(SZ(ve[x]))
		b-=SZ(ve[x]),x++;
	return mp(x,b-1);
}
void rebuild(){
	top=0;
	for(int i=1;i<=m;i++){
		for(auto it:ve[i]) st[++top]=it;
		ve[i].clear();
	}
	int _m=sqrt(top);
	for(int i=1;i<=top;i++)
		ve[(i-1)/_m+1].pb(st[i]);
	blo=(top-1)/_m+1;
}
void insert(int a,int b){
	
}
int main(){
	return 0;
}