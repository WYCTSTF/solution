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
		int n;
		cin >> n;
		VI a(n), b(n);
		rep (i, 0, n - 1)
			cin >> a[i];
		rep (i, 0, n - 1)
			cin >> b[i];
		sort(all(a));
		sort(all(b));
		int t1 = 0, t2 = 0;
		VI ta(10, 0), tb(10, 0);
		int ans = 0;
		while (t1 < n && t2 < n) {
			if (a[t1] == b[t2]) {
				t1++, t2++;
				continue;
			} else if (a[t1] < b[t2]) {
				if (a[t1] < 10)
					ta[a[t1]]++;
				else {
					auto it = to_string(a[t1]);
					ta[it.size()]++;
					ans++;
				}
				t1++;
			} else {
				if (b[t2] < 10)
					tb[b[t2]]++;
				else {
					auto it = to_string(b[t2]);
					tb[it.size()]++;
					ans++;
				}
				t2++;
			}
		}
		for (int i = t1; i < n; ++i) {
			if (a[i] < 10)
				ta[a[i]]++;
			else {
				auto it = to_string(a[i]);
				ta[it.size()]++;
				ans++;
			}
		}
		for (int i = t2; i < n; ++i) {
			if (b[i] < 10)
				tb[b[i]]++;
			else {
				auto it = to_string(b[i]);
				tb[it.size()]++;
				ans++;
			}
		}

		for (int i = 2; i <= 9; ++i)
			ans += abs(ta[i] - tb[i]);
		cout << ans << '\n';
	}
	return 0;
}