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
#define INF 0x7fffffff
#define inf 0x3f3f3f3f
#define MOD 998244353
#define mod 1000000007
typedef std::vector<int> VI;
typedef std::pair<int,int> PII;
typedef long long ll;
typedef double db;
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a; }

inline char gc() {
  static const int N = 1 << 20;
  static char buf[N | 1], *S = buf, *T = buf;
  return S == T && (T = (S = buf) + fread(buf, 1, N, stdin), S == T) ? EOF : *S++;
}
template<typename T>
inline void read(T &x) {
  x = 0;
  char ch = gc();
  for (; ch < '0' || ch > '9';) ch = gc();
  for (; ch <= '9' && ch >= '0';)
    x = x * 10 + (ch ^ 48), ch = gc();
}

int main() {
	int tt;
	read(tt);
	while (tt--) {
  	int n;
  	read(n);
		std::cout << n - 3 << ' ' << "1 1 1\n";
	}
  return 0;
}
