#include <bits/stdc++.h>

using i64 = long long;

#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pi acos(-1)
#define SZ(x) ((int)(x).size())
#define all(x) x.begin(),x.end()
#define INF 0x7fffffff
#define inf 0x3f3f3f3f
#define MOD 998244353
#define mod 1000000007
typedef std::vector<int> VI;
typedef std::pair<int,int> PII;
typedef double db;
i64 gcd(i64 a,i64 b) { return b?gcd(b,a%b):a; }

void solve() {
	int n;
	std::cin>>n;
	VI a(n),b(n);
	for(int&x:a)std::cin>>x;
	for(int&x:b)std::cin>>x;
	sort(all(a));
	sort(all(b));
	reverse(all(a));
	reverse(all(b));
	VI pre(n);
	rep(i,0,n-1)if(a[i]<=b[i]){std::cout<<"0\n";return;}
	pre[0]=0;
	while(pre[0]<n&&a[pre[0]]>b[0])pre[0]++;
	rep(i,1,n-1){
		pre[i]=pre[i-1];
		while(pre[i]<n&&a[pre[i]]>b[i])
			pre[i]++;
	}
	i64 ans=1;
	for(int i=0;i<n;++i)
		ans=ans*(pre[i]-i)%mod;
	std::cout<<ans<<'\n';
}
int main() {
	int tt;
	std::cin >> tt;
	while (tt--) {
		solve();
	}
}
