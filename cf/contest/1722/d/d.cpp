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
		int n;
		cin >> n;
		string s;
		cin >> s;
		ll ans = 0;
		vector<ll> a;
		for (int i = 1; i <= n; ++i) {
			if (s[i - 1] == 'L' && i <= n / 2)
				a.pb(1ll * ((n - i) - (i - 1)));
			else if (s[i - 1] == 'R' && i > n / 2)
				a.pb(1ll * ((i - 1) - (n - i)));
			else a.pb(0ll);
			if (s[i - 1] == 'L')
				ans += i - 1;
			else
				ans += n - i;
		}
		sort(all(a), greater<ll>());
		for (auto it : a)
			ans += it, cout << ans << ' ';
		cout << '\n';
	}
	return 0;
}