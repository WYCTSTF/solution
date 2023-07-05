#include <bits/stdc++.h>

#ifdef LOCAL
#include <dbg.h>
#else
#define dbg(...) 42
#endif

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned int;
using db = double;

using std::cin, std::cout;

#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define fi first
#define se second
#define pi acos(-1)
#define sz(x) ((int)(x).size())
#define all(x) x.begin(),x.end()
typedef std::vector<int> VI;
typedef std::pair<int,int> PII;

i64 gcd(i64 a,i64 b) { return b?gcd(b,a%b):a; }

void solve(){
	int n;
	cin>>n;
	std::vector<int>a(n);
	int now=INT_MAX;
	for(int&x:a)cin>>x;

	sort(all(a));
	if (a[0]<0)cout<<a[0]<<'\n';
	else
		cout<<a[n-1]<<'\n';
}

int main() {
	int tt;
	cin >> tt;
	while (tt--)solve();
	return 0;
}
