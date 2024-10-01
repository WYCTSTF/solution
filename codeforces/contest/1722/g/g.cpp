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
		if (n % 2) {
			VI a(n + 1, 0);
			// VI f(n + 1, 0);
			iota(all(a), 0);
			if (((n - 1) / 2) % 2 == 0)
				a[1] = 0;
			rep (i, 1, n)
				cout << a[i] << " \n"[i == n];
			// int a1 = 0, a2 = 0;
			// for (int i = 1; i <= n; i += 2)
			// 	a1 ^= a[i];
			// for (int i = 2; i <= n; i += 2)
			// 	a2 ^= a[i];
			// cout << ((a1 == a2) ? "YES" : "NO") << '\n';
		} else {
			VI a;
			a.pb(0);
			VI f(n + 1, 0);
			rep (i, 0, n / 2 - 1)
				a.pb(i), a.pb(i + n / 2), f[i]++, f[i + n / 2]++;
			if ((n / 2) % 2 == 1) {
				f[a[1]]--;
				a[1] = 1;
				f[1]++;
				if (f[1] > 1)
					a[1] |= 1 << 29, a[2] |= 1 << 29;
			}
			else {
				f[a[1]]--;
				a[1] = 0;
				f[0]++;
				if (f[0] > 0)
					a[1] |= 1 << 29, a[2] |= 1 << 29;
			}
			rep (i, 1, n)
				cout << a[i] << " \n"[i == n];
			// int a1 = 0, a2 = 0;
			// for (int i = 1; i <= n; i += 2)
			// 	a1 ^= a[i];
			// for (int i = 2; i <= n; i += 2)
			// 	a2 ^= a[i];
			// cout << ((a1 == a2) ? "YES" : "NO") << '\n';
		}
	}
	return 0;
}