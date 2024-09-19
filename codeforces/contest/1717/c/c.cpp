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

bool solve() {
	int n;
	cin >> n;
	VI fa(n, 0);
	iota(all(fa), 0);
	function<int(int)> find = [&](int o) {
		return (o == fa[o]) ? o : (fa[o] = find(fa[o]));
	};
	VI a(n), b(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < n; ++i)
		cin >> b[i];
	for (int i = 0; i < n; ++i) {
		if (a[i] > b[i] || b[(i + 1) % n] + 1 < b[i] && a[i] != b[i])
			return false;
		// else if (a[(i + 1) % n] + 1 < b[i])
		// 	if (find(i) == find((i + 1) % n))
		// 		return false;
			// else
			// 	fa[find(i)] = find((i + 1) % n);
	}
	return true;
}

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		if (solve())
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
// 传递性
// 貌似用并查集维护？