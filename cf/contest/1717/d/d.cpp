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
	int n, k;
	cin >> n >> k;

	vector<ll> inv(n + 1);
	inv[1] = 1;
	rep (i, 2, n)
		inv[i] = (mod - mod / i) * inv[mod % i] % mod;

	ll ans = 1, now = 1;

	rep (i, 1, min(n, k)) {
		now = (now * (n + 1 - i) % mod) * inv[i] % mod;
		now = (now + mod) % mod;
		ans = (ans + now) % mod;
	}
	cout << ans << '\n';
	return 0;
}