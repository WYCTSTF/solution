#include <bits/stdc++.h>

using namespace std;

#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
// #define mp make_pair
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

int mp[110][110], vis[110][110];

void solve() {
	int n, m;
	cin >> n >> m;

	memset(mp, 0, sizeof mp);
	memset(vis, 0, sizeof vis);

	rep (i, 1, n) {
		string s;
		cin >> s;
		rep (j, 1, m)
			mp[i][j] = ((s[j - 1] == '.') ? 0 : 1);
	}

	// for (int i = 1; i <= n; ++i)
	// 	for (int j = 1; j <= m; ++j)
	// 		cout << mp[i][j] <<" \n"[j == m];

	bool ok = true;
	int tot = 0;

	vector<pair<PII, int>> node;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			if (mp[i][j] && !vis[i][j]) {
				if (i > 1 && mp[i - 1][j] && !vis[i - 1][j]) {
					if (j > 1 && mp[i][j - 1] && !vis[i][j - 1]) { // type 1
						vis[i][j] = vis[i - 1][j] = vis[i][j - 1] = 1;
						node.pb({{i, j}, ++tot});
						node.pb({{i - 1, j}, tot});
						node.pb({{i, j - 1}, tot});
					} else if (j < m && mp[i][j + 1] && !vis[i][j + 1]) { // type 2
						vis[i][j] = vis[i - 1][j] = vis[i][j + 1] = 1;
						node.pb({{i, j}, ++tot});
						node.pb({{i - 1, j}, tot});
						node.pb({{i, j + 1}, tot});
					}
				} else if (i < n && mp[i + 1][j] && !vis[i + 1][j]) {
					if (mp[i][j - 1] && !vis[i][j - 1]) { // type 3
						vis[i][j] = vis[i + 1][j] = vis[i][j - 1] = 1;
						node.pb({{i, j}, ++tot});
						node.pb({{i + 1, j}, tot});
						node.pb({{i, j - 1}, tot});
					} else if (j < m && mp[i][j + 1] && !vis[i][j + 1]) { // type 4
						vis[i][j] = vis[i + 1][j] = vis[i][j + 1] = 1;
						node.pb({{i, j}, ++tot});
						node.pb({{i + 1, j}, tot});
						node.pb({{i, j + 1}, tot});
					}
				}
			}
		}

	sort(all(node));

	// for (auto it : node)
	// 	cout << it.fi.fi << ' ' << it.fi.se << ' ' << it.se << '\n';

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (mp[i][j] && !vis[i][j]) {
				cout << "NO\n";
				return;
			}
		}
	}

	for (int i = 0; i < node.size(); ++i) {
		for (int j = i + 1; j < node.size(); ++j) {
			int x1 = node[i].fi.fi, y1 = node[i].fi.se, t1 = node[i].se;
			int x2 = node[j].fi.fi, y2 = node[j].fi.se, t2 = node[j].se;
			if (t1 == t2)
				continue;
			if (abs(x1 - x2) <= 1 && abs(y1 - y2) <= 1) {
				// cout << x1 << ' ' << x2 << ' ' << y1 << ' ' << y2 << '\n';
				cout << "NO\n";
				return;
			}
		}
	}
	cout << "YES\n";
}

int main() {
	int tt;
	cin >> tt;

	while (tt--) {
		solve();
	}
	return 0;
}