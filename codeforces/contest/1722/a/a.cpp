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
		string s;
		cin >> s;
		if (n != 5) {
			puts("NO");
		} else {
			int sum = 0;
			set<char> S;
			for (auto it : s)
				S.insert(it);
			set<char> _S;
			_S.insert('T');
			_S.insert('i');
			_S.insert('m');
			_S.insert('u');
			_S.insert('r');
			if (_S != S)
				puts("NO");
			else
				puts("YES");
		}
	}
	return 0;
}