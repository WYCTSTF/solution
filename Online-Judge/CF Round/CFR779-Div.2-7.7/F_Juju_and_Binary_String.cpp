#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define il inline
#define rg register
#define SZ(x) ((int)(x).size())
#define all(x) x.begin(),x.end()
using namespace std;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef long long ll;
typedef double db;
const int INF=0x7fffffff;
const int inf=0x3f3f3f3f;
const int MOD=998244353;
const int mod=1e9+7;
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a; }
// head
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);;
	int tt; cin>>tt;
	while(tt--){
		int n,m; cin>>n>>m;
		string s; cin>>s;
		int one=count_if(all(s),[](char c){return c=='1';});
		if(1LL*one*m%n!=0) {cout<<"-1\n"; continue;}
		one=1LL*one*m/n;
		vector c(2*n+1,0);
		s="#"+s+s;
		for(int i=1;i<=m;i++) c[1]+=((s[i]=='1')?1:0);
		for(int i=2;i<=2*n-m+1;i++) {
			c[i]=c[i-1];
			if(s[i-1]=='1') c[i]--;
			if(s[i+m-1]=='1') c[i]++;
		}
		int now;
		for(int i=1;i<=2*n-m+1;i++)
			if(c[i]==one) {now=i; break;}
		if(now>n){
			cout<<"1\n";
			cout<<now%n<<' '<<(now+m-1)%n<<'\n';
		} else {
			if(now+m-1>n) {
				cout<<"2\n";
				cout<<"1 "<<m-(n-now+1)<<'\n';
				cout<<now<<' '<<n<<endl;
			} else{
				cout<<"1\n";
				cout<<now<<' '<<now+m-1<<endl;
			}
		}
	}
	return 0;
}