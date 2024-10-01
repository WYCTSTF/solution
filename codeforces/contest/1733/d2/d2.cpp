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
#define INF 0x7fffffff
#define inf 0x3f3f3f3f
#define MOD 998244353
#define mod 1000000007
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef long long ll;
typedef double db;
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a; }

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int n, x, y;
		cin >> n >> x >> y;
		string a, b;
		cin >> a >> b;
		vector<int> p;
		for (int i = 0; i < n; ++i)
			if (a[i] != b[i])
				p.pb(i);
		if (SZ(p) % 2) {
			cout << "-1\n";
			continue;
		}
		if (x >= y) {
			if (SZ(p) == 2 && p[0] + 1 == p[1]) {
				cout << min(x, y * 2) << '\n';
				continue;
			}
			cout << y * (ll)(SZ(p) / 2) << '\n';
			continue;
		}

		vector<ll> dp(SZ(p) + 1, 0);
		for (int i = 1; i <= SZ(p); ++i) {
			dp[i] = dp[i - 1];
			if (i >= 2) {
				dp[i] = max(dp[i - 2] + y - (ll)x * (p[i - 1] - p[i - 2]), dp[i]);
			}
		}

		cout << y * (ll)(SZ(p) / 2) - dp[SZ(p)] << '\n';
	}
	return 0;
}