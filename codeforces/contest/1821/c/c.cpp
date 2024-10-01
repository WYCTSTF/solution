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
  string s;
  cin >> s;
  int n = s.size();
  s = '$' + s;
  vector<int> f(n + 1, 0);
  for (int i = 1; i <= n; ++i)
    f[i] = f[i / 2] + 1;
  int mn = INT_MAX;
  for (int _c = 0; _c < 26; ++_c) {
    int mx = 0;
    char c = _c + 'a';
    for (int i = 1; i <= n; ++i) {
      if (s[i] == c) {
        continue;
      }
      int j = i;
      while (j + 1 <= n && s[j + 1] != c)
        ++j;
      mx = max(mx, f[j - i + 1]);
      i = j;
    }
    mn = min(mn, mx);
  }
  cout << mn << '\n';
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
