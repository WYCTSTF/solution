#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else #define debug(...) 42
#endif

using i64 = long long;
using ll = long long;
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

bool check(ll a) {
  if (a == 1) return false;
  if (a == 2) return true;
  for (int i = 2; i * i <= a; ++i)
    if (a % i == 0)
      return false;
  return true;
}
bool solve(ll a, ll b) {
  if (a == 1)
    return check(a);
  else {
    if (a % 2 && b % 2)
      return solve(a - 1, b - 3);
    if (a % 2 && b % 2 == 0)
      return solve(a - 1, b - 2);
    if (a % 2 == 0 && b % 2)
      return solve(a - 1, b - 3);
    return (b >= a * 2 && a > 1);
  }
}
int main() {
  ll n, m = 0;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int tem;
    cin >> tem;
    m += tem;
  }
  debug(n, m);
  bool tag = solve(n, m);
  cout << (tag ? "Yes" : "No") << '\n';
}
