#ifdef LOCAL
#include "dbg.h"
#else
#define dbg(...) 42
#endif

#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define rep(i, a, n) for (int i = a; i <= n; i++)
#define per(i, a, n) for (int i = n; i >= a; i--)
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pi acos(-1)
#define il inline
#define rg register
#define SZ(x) ((int)(x).size())
#define all(x) x.begin(), x.end()
#define INF 0x7fffffff;
#define inf 0x3f3f3f3f;
#define MOD 998244353;
#define mod 1000000007;
using namespace std;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef long long ll;
typedef double db;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

void solve() {
  int n;
  cin >> n;
  VI a(n + 1);
  rep(i, 1, n) cin >> a[i];
  sort(a.begin() + 1, a.begin() + 1 + n);
  int tem = a[1], tot = 1;
  VI v;
  rep(i, 2, n) {
    if (a[i] == tem)
      ++tot;
    else
      v.push_back(tot), tot = 1, tem = a[i];
  }
  v.push_back(tot);
  dbg(v);
  dbg(a);
  if(a[1]==a[n])cout<<n/2<<'\n';
  else{
    ll ans=0;int sum=0;
    for(auto i : v)
      sum+=i,ans=max(ans, 1ll*sum*(n-sum));
    cout<<ans<<'\n';
  }
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}