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
		int n = (int)SZ(s);
		int l = s[0] - 'a', r = s[n - 1] - 'a';
		vector<PII> v;
		rep (i, 1, n - 2) {
			int tem = s[i] - 'a';
			if (tem <= max(l, r) && tem >= min(l, r))
				v.pb({s[i] - 'a', i + 1});
		}
		cout << abs(l - r) << ' ' << (v.size() + 2) << '\n';
		if (l < r)
			sort(all(v), [&](PII x, PII y) {return x.fi < y.fi;});
		else
			sort(all(v), [&](PII x, PII y) {return x.fi > y.fi;});
		cout << "1 ";
		for (auto it : v) cout << it.se << ' ';
		cout << n << '\n';
	}
	return 0;
}