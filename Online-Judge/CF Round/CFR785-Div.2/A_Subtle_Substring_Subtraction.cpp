#include <bits/stdc++.h>
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
int main() {
	int tt; cin >> tt;
	while (tt--) {
		string s; cin>>s;
		int ans1=0,ans2=0,sum=0;
		rep(i,0,s.size()-1) sum+=s[i]-'a'+1;
		if (s.size()%2==0){
			cout<<"Alice "<<sum<<endl;
		}else{
			// Alice with ans1
			ans1=max(sum-(s[0]-'a'+1),sum-(s[s.size()-1]-'a'+1));
			ans2=sum-ans1;
			if(ans1>ans2) cout<<"Alice ";
			else cout<<"Bob ";
			cout<<abs(ans1-ans2)<<endl;
		}
	}
	return 0;
}