#include <bits/stdc++.h>
#define rep(i, a, n, k) for (int i = a; i <= n; i += k)
#define per(i, a, n, k) for (int i = n; i >= a; i -= k)
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define il inline
#define rg register
#define SZ(x) ((int)(x).size())
#define all(x) x.begin(), x.end()
using namespace std;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef long long ll;
typedef double db;
const int INF = 0x7fffffff;
const int inf = 0x3f3f3f3f;
const int MOD = 998244353;
const int mod = 1e9 + 7;
template <typename T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
// head
const int N = 2e5 + 10;
const int LOG = 20;
int n, a[N], lg[N] = {-1}, st[N][LOG];
int ask(int l, int r) {
  int d = lg[r - l + 1];
  return gcd(st[l][d], st[r - (1 << d) + 1][d]);
}
int main() {
  cin >> n;
  rep(i, 1, n, 1) {
    cin >> st[i][0];
    lg[i] = lg[i >> 1] + 1;
  }
  for (int i = 1; (1 << i) <= n; i++) {
    for (int j = 1; j + (1 << i) - 1 <= n; j++) {
      st[j][i] = gcd(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
    }
  }
  // 考虑贪心，最小点覆盖所有线段 & 二分找到所有寄了的segment
  // 然后这里因为gcd随区间长度上升而单调下降，所以在找到了一个之后，左端点能够继续右移
  // 实现双指针的做法
  int ans = 0, Max = -1, ptr = 1;
  for (int i = 1; i <= n; i++) {
    while (ptr < i && ask(ptr, i) < i - ptr + 1)
      ptr++;
    if (ask(ptr, i) == i - ptr + 1) {
      if (ptr > Max) {
        Max = i;
        ++ans;
      }
    }
    cout << ans << ' ';
  }
  return 0;
}