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
		int n, k;
		cin >> n >> k;
		VI a(n + 1, 0), f(n + 1, 0);
		rep (i, 1, n) cin >> a[i];
		rep (i, 1, n - 1)
			if (a[i] < a[i + 1] * 2)
				f[i] = 1;
		VI s(n + 1, 0);
		rep (i, 1, n)
			s[i] = s[i - 1] + f[i];
		int ans = 0;
		rep (i, 1, n - k)
			if (s[i + k - 1] - s[i - 1] == k)
				ans++;
		cout << ans << '\n';
	}
	return 0;
}