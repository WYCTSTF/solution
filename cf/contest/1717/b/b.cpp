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

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int n, k, r, c;
		cin >> n >> k >> r >> c;
		r %= k, c %= k;
		if (r == 0)
			r = k;
		if (c == 0)
			c = k;
		vector<PII> pos;
		int nr = 1, nc = 1;
		pos.pb({r, c});
		while (nr <= k && nc <= k) {
			if (nr == r) {
				nr++;
				continue;
			}
			if (nc == c) {
				nc++;
				continue;
			}
			pos.pb({nr++, nc++});
		}
		vector<VI> _map(n + 1, VI(n + 1, 0));
		for (int i = 0; i < n / k; ++i) {
			for (int j = 0; j < n / k; ++j) {
				for (auto [x, y] : pos)
					_map[i * k + x][j * k + y] = 1;
			}
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j)
				if (_map[i][j] == 1)
					putchar('X');
				else
					putchar('.');
			putchar('\n');
		}
	}
	return 0;
}