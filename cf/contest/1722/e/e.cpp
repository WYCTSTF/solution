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

ll a[1010][1010], sum[1010][1010];

void solve() {
	int n, q;
	cin >> n >> q;
	memset(a, 0ll, sizeof a);
	memset(sum, 0ll, sizeof sum);
	rep (i, 1, n) {
		int h, w;
		cin >> h >> w;
		a[h][w] += 1ll * w * h;
	}
	rep (i, 1, 1000)
		rep (j, 1, 1000)
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
	rep (i, 1, q) {
		int hs, ws, hb, wb;
		cin >> hs >> ws >> hb >> wb;
		hs++, ws++, hb--, wb--;
		ll r = sum[hs - 1][wb] + sum[hb][ws - 1] - sum[hs - 1][ws - 1];
		cout << sum[hb][wb] - r << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt;
	cin >> tt;

	while (tt--) {
		solve();
	}
	return 0;
}