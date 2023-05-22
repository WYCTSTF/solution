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
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int tt;
	cin >> tt;
	
	while (tt--) {
		ll n, x, y;
		cin >> n >> x >> y;
		string a, b;
		cin >> a >> b;

		queue<int> tag;
		ll ans = 0ll;

		for (int i = 0; i < n; ++i)
			if (a[i] != b[i])
				ans++, tag.push(i);

		if (ans % 2) {
			cout << -1 << '\n';
		} else if (ans == 2) {
			int now = tag.front();
			tag.pop();
			if (tag.front() != now + 1)
				cout << y << '\n';
			else {
				if (y * 2 > x || n == 2)
					cout << x << '\n';
				else
					cout << y * 2 << '\n';
			}
		} else {
			cout << ans / 2 * y << '\n';
		}
	}
	return 0;
}