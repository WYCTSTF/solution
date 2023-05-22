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
		set<string> s1, s2, s3;
		map<string, int> mp;
		cin >> n;
		rep (j, 1, n) {
			string s;
			cin >> s;
			s1.insert(s);
			mp[s]++;
		}
		rep (j, 1, n) {
			string s;
			cin >> s;
			s2.insert(s);
			mp[s]++;
		}
		rep (j, 1, n) {
			string s;
			cin >> s;
			s3.insert(s);
			mp[s]++;
		}
		int a1 = 0, a2 = 0, a3 = 0;
		for (auto it : mp) {
			string s = it.fi;
			int c = it.se;
			if (c == 3)
			 continue;
			else if (c == 2) {
				if (s1.find(s) != s1.end())
					a1++;
				if (s2.find(s) != s2.end())
					a2++;
				if (s3.find(s) != s3.end())
					a3++;
			} else {
				if (s1.find(s) != s1.end())
					a1 += 3;
				if (s2.find(s) != s2.end())
					a2 += 3;
				if (s3.find(s) != s3.end())
					a3 += 3;
			}
		}
		cout << a1 << ' ' << a2 << ' ' << a3 << '\n';
	}
	return 0;
}