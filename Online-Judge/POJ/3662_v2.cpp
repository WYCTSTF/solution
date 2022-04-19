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
vector<pair<int,int>>e[N];
bool check(int mid){
	vector<pair<int,int>>E[N];
	rep(i,1,n){
		for(auto it:e[i]) {
			if(it.second>mid) E[i].pb({it.first,1});
			else E[i].pb({it.first,0});
		}
	}
	vector<int>dis(n+1,0x7fffffff);
	bitset<1010>vis; vis.reset(); vis[1]=true;
	queue<int>q; q.push(1); dis[1]=0;
	while (!q.empty()) {
		int u=q.front(); q.pop();
		vis[u]=0;
		for(auto eg:E[u]){
			int v=eg.fi,w=eg.se;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				if(vis[v]==false){
					vis[v]=true; q.push(v);
				}
			}
		}
	}
	if(dis[n]<=k) return true;
	else return false;
}
int main() {
	cin>>n>>m>>k;
	int l=0,r=-1,res=-1;
	rep(i,1,m){
		int u,v,w;
		cin>>u>>v>>w;
		r=max(r,w);
		e[u].pb({v,w}), e[v].pb({u,w});
	}
	// assert("false");
	puts("Fuck");
	while (l<r) {
		int mid=l+r>>1;
		if (check(mid)) res=mid,r=mid;
		else mid=l+1;
	}
	cout<<res<<endl;
	return 0;
}