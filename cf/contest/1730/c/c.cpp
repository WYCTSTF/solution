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

		int n = SZ(s);
		VI pre(n + 1, 0);

		pre[n - 1] = s[n - 1] - '0';
		per (i, 0, n - 2)
			pre[i] = min(pre[i + 1], s[i] - '0');

		multiset<int> S;

		for (int i = 0; i < n; ++i)
			if ((int)(s[i] - '0') != pre[i])
				S.insert(min(9, (int)(s[i] - '0' + 1)));
			else
				S.insert((int)(s[i] - '0'));

		for (auto it : S)
			cout << it;
		cout << '\n';
	}
	return 0;
}