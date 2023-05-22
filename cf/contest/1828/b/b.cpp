#include <bits/stdc++.h>

using i64 = long long;

#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pi acos(-1)
#define SZ(x) ((int)(x).size())
#define all(x) x.begin(),x.end()
#define INF 0x7fffffff
#define inf 0x3f3f3f3f
#define MOD 998244353
#define mod 1000000007
typedef std::vector<int> VI;
typedef std::pair<int,int> PII;
typedef double db;
i64 gcd(i64 a,i64 b) { return b?gcd(b,a%b):a; }

int main() {
	int tt;
	std::cin >> tt;
	while (tt--) {
		int n;
		std::cin >> n;
		std::vector<int> p (n + 1);
		rep (i, 1, n)
			std::cin >> p[i];
		int now = std::abs(1 - p[1]);
		rep (i, 2, n)
			now = gcd(now, std::abs(i - p[i]));
		std::cout << now << '\n';
	}
}
