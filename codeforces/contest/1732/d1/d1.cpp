#include <bits/stdc++.h>

using namespace std;

#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
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

map<ll, ll> tb;
set<ll> s;

int main() {
  int q;
  cin >> q;
  while (q--) {
    char c;
    ll x;
    cin >> c >> x;
    if (c == '+')
      s.insert(x);
    else {
      ll tem = tb[x];
      while (tem == 0 || s.find(tem) != s.end())
        tem += x;
      tb[x] = tem;
      cout << tem << '\n';
    }
  }
  return 0;
}