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
		string s;
		cin >> s;

		int n = (int)s.size();

		vector f(n + 1, vector<int>(n + 1, 0));
		rep (i, 0, n - 2) f[i][i + 1] = (s[i] != s[i + 1]);

		for (int len = 4; len <= n; len += 2) {
			for (int l = 0; l + len <= n; ++l) {
				int r = l + len - 1;
				// Alice - s[l]
				// dp[l][r] = 1 仅当 s[l + 1] 和 s[r]选了都没用的情况
				if ((s[l] < s[r] || f[l + 1][r - 1]) && (f[l + 2][r] || s[l] < s[l + 1]))
					f[l][r] = 1;
				else if ((f[l][r - 2] || s[r] < s[r - 1]) && (f[l + 1][r - 1] || s[r] < s[l]))
					f[l][r] = 1;
				else
					f[l][r] = 0;
			}
		}

		cout << (f[0][n - 1] ? "Alice" : "Draw") << '\n';
	}
	return 0;
}