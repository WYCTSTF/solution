#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
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

int ask(int x, int y) {
  cout << "? " << x << ' ' << y << endl;
  int ans;
  cin >> ans;
  return ans;
}
struct perm {
  int len, id;
  bool operator<(const perm &x) const { return len > x.len; }
};
void solve() {
  int n, devNull;
  cin >> n;
  int l = 1, r = n;
  VI st(n + 1);
  rep(i, 1, n) st[i] = ((i & 1) ? (l++) : (r--));
  cout << "+ " << n + 1 << endl;
  cin >> devNull;
  cout << "+ " << n + 2 << endl;
  cin >> devNull;

  vector<perm> a(n + 1);
  a[1].id = 1, a[1].len = 0;
  rep(i, 2, n) a[i].id = i, a[i].len = ask(i, 1);

  sort(a.begin() + 1, a.end());

  VI ans1(n + 1), ans2(n + 1);
  ans1[a[1].id] = st[1], ans2[a[1].id] = st[n];
  // ans1[1] = st[a[1].len + 1], ans2[1] = st[n - a[1].len];
  rep (i, 1, n) {
    if (i == a[1].id) continue;
    int tem = ask(a[1].id, i);
    ans1[i] = st[tem + 1];
    ans2[i] = st[n - tem];
  }
  cout << "! ";
  rep(i, 1, n) cout << ans1[i] << ' ';
  rep(i, 1, n) cout << ans2[i] << " \n"[i == n];
  cin >> devNull;
  if (devNull == -2)
    exit(0);
}
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}