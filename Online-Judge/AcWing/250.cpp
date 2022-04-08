#include <bits/stdc++.h>
#define int long long
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
bool vis[250010];
int xX,yY,l[510],r[510],mx[510];
struct Node {int d,m,p,r;} a[250010];
bool cmpM(const Node &A,const Node &B){return A.m<B.m;}
bool cmpD(const Node &A,const Node &B){return A.d<B.d;}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>xX>>yY>>a[0].p>>a[0].r>>n;
	a[0].r*=a[0].r;
	rep(i,1,n){
		int x,y;cin>>x>>y>>a[i].m>>a[i].p>>a[i].r;
		a[i].d=(x-xX)*(x-xX)+(y-yY)*(y-yY), a[i].r*=a[i].r;
	}
	sort(a+1,a+1+n,cmpM);
	int len=sqrt(n),top=ceil(1.0*n/len),ans=0;
	rep(i,1,top){
		l[i]=(i-1)*len+1,r[i]=min(i*len,n);
		rep(j,l[i],r[i]) mx[i]=max(mx[i],a[j].m);
		sort(a+l[i],a+r[i]+1,cmpD);
	}
	auto check=[&](Node A,Node B)->bool{
		if(A.p>=B.m&&A.r>=B.d) return true;
		else return false;
	};
	queue<Node>q; q.push(a[0]);
	while(!q.empty()){
		auto tem=q.front(); q.pop();
		rep(i,1,top){
			if(mx[i]>tem.p) {
				rep(j,l[i],r[i]){
					if(vis[j]==1) continue;
					if(check(tem,a[j])) ans++,vis[j]=true,q.push(a[j]);
				}
				break;
			}
			while(l[i]<=r[i]&&check(tem,a[l[i]])){
				if(vis[l[i]]==true) {l[i]++; continue;}
				ans++;
				q.push(a[l[i]++]);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}