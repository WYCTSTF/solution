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
		int n, m;
		cin >> n >> m;
		if (m < n || (n % 2 == 0 && m % 2 != 0)) {
			cout << "No\n";
			continue;
		} else {
			cout << "Yes\n";
			VI a(n);
			if (n % 2 == 0)
				fill(all(a), m / n), a[0] += (m % n) / 2, a[1] += (m % n) / 2;
			else
				fill(all(a), 1), a[n - 1] += m - n;
			for (auto it : a)
				cout << it << ' ';
			cout << '\n';
		}
	}
	return 0;
}