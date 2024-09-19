#include <bits/stdc++.h>

using namespace std;

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

const int N = 200010;

int lg[N] = {-1};

void solve() {
	int n;
	cin >> n;

	vector<vector<pair<int, pair<ll, ll>>>> adj(n + 1);
	rep (i, 2, n) {
		int p, a, b;
		cin >> p >> a >> b;
		adj[i].pb({p, {a, b}});
		adj[p].pb({i, {a, b}});
	}

	vector<ll> va(n + 1, 0), vb(n + 1, 0);
	VI dep(n + 1, 0);
	vector<VI> fa(n + 1, VI(25, 0));

	function<void(int, int)> dfs = [&](int u, int fr) {
		dep[u] = dep[fr] + 1;
		fa[u][0] = fr;
		for (int i = 1; (1 << i) <= dep[u]; ++i)
			fa[u][i] = fa[fa[u][i - 1]][i - 1];
		for (auto it : adj[u]) {
			int v = it.fi;
			ll a = it.se.fi, b = it.se.se;
			if (v == fr) continue;
			va[v] = va[u] + a, vb[v] = vb[u] + b;
			dfs(v, u);
		}
	};

	dfs(1, 0);

	rep (i, 2, n) {
		int now = i;
		per (j, 0, 20)
			if (vb[fa[now][j]] > va[i])
				now = fa[now][j];
		if (vb[now] > va[i])
			now = fa[now][0];
		// cout << "i " << i << "\nnow " << now << '\n';
		// cout << dep[now] - dep[1] << '\n';
		cout << dep[now] - dep[1] << " \n"[i == n];
	}
}
int main() {
	int tt;
	cin >> tt;

	rep (i, 1, 200000) lg[i] = lg[i / 2] + 1;


	while (tt--) {
		solve();
	}
	return 0;
}