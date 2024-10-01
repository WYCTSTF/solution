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

// int phi[100010];
VI primes;
bitset<100010> vis;

void euler(int n, vector<int> &phi) {
	phi[1] = 1;
	for (int i = 2; i <= n; ++i) {
		if (vis[i] == 0) {
			primes.pb(i);
			phi[i] = i - 1;
		}
		for (int p : primes) {
			if (p * i > n)
				break;
			vis[i * p] = 1;
			if (i % p == 0) {
				phi[i * p] = phi[i] * p;
				break;
			}
			phi[i * p] = phi[i] * (p - 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;

	vis.reset();
	primes.clear();
	VI phi(n + 1);

	euler(n, phi);
	int ans = 0;
	for (int g = 1; g <= n / 2; ++g) {
		for (int k = 2; k * g < n; ++k) {
			ans = (ans + (1ll * ((n - k * g) / gcd(n - k * g, g)) * g % mod) * phi[k] % mod) % mod;
			// ans = (1ll * ans + (((n - k * g) / gcd(n - k * g, g) * g) % mod * phi[k])) % mod;
		}
	}

	cout << ans << '\n';
	return 0;
}