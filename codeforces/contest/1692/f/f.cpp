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
		VI tot(10, 0);
		rep (i, 1, n) {
			int tem;
			cin >> tem;
			tot[tem % 10]++;
		}
		auto check = [&](int a, int b, int c) {
			auto it = tot;
			it[a]--, it[b]--, it[c]--;
			for (auto iter : it)
				if (iter < 0)
					return false;
			return true;
		};
		bool ok = false;
		for (int i = 0; i < 10 && !ok; ++i)
			for (int j = 0; j < 10 && !ok; ++j)
				for (int k = 0; k < 10 && !ok; ++k) {
					if ((i + j + k) % 10 == 3 && check(i, j, k))
						ok = true;
				}
		if (ok)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}