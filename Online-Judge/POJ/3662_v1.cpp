#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <cmath>
#include <deque>
#include <bitset>
#include <cstdio>
#include <vector>
#include <string>
#include <complex>
#include <sstream>
#include <utility>
#include <climits>
#include <cstring>
#include <fstream>
#include <functional>
#include <iostream>
#include <algorithm>
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
const int N=1010;
int n,m,k;
int dis[N][N];
bool vis[N][N];
vector<pair<int,int> > e[N];
priority_queue<pair <int,pair<int,int> > > q;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	rep(i,1,n) rep(j,0,k) dis[i][j]=INF;
	for(int i=1;i<=m;i++){
		int u,v,w; cin>>u>>v>>w;
		e[u].pb(mp(v,w));
		e[v].pb(mp(u,w));
	}
	dis[1][0]=0; q.push(mp(0,mp(1,0)));
	while(!q.empty()){
		int i=q.top().se.fi,j=q.top().se.se; q.pop();
		if(vis[i][j]==true) continue;
		vis[i][j]=true;
		for(int G=0;G<e[i].size();G++){
			int v=e[i][G].fi,w=e[i][G].se;
			if(dis[v][j]>max(dis[i][j],w)){
				dis[v][j]=max(dis[i][j],w);
				q.push(mp(-dis[v][j],mp(v,j)));
			}
			if(j<k&&dis[v][j+1]>dis[i][j]){
				dis[v][j+1]=dis[i][j];
				q.push(mp(-dis[v][j+1],mp(v,j+1)));
			}
		}
	}
	int ans=INT_MAX;
	rep(i,0,k) ans=min(ans,dis[n][i]);
	if(ans==INT_MAX) puts("-1");
	else cout<<ans<<endl;
	return 0;
}
// 瞬光斩黯淡，昭明破晦夜