#include <bits/stdc++.h>
#define rep(i, a, n, k) for (int i = a; i <= n; i += k)
#define per(i, a, n, k) for (int i = n; i >= a; i -= k)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
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
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
// head
int a[110], b[110];
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    int M1 = -1, M2 = -1;
    rep(i, 1, n, 1) cin >> a[i], M1 = max(M1, a[i]);
    rep(i, 1, n, 1) cin >> b[i], M2 = max(M2, b[i]);
    // cout<<M1<<' '<<M2<<endl;
    if (M1 >= M2) {
      rep(i, 1, n, 1) if (b[i] > a[i]) swap(a[i], b[i]);
    } else {
      rep(i, 1, n, 1) if (a[i] > b[i]) swap(a[i], b[i]);
    }
    // rep(i,1,n,1) cout<<a[i]<<' ';
    // cout<<endl;
    // rep(i,1,n,1) cout<<b[i]<<' ';
    // cout<<endl;
    M1 = M2 = -1;
    rep(i, 1, n, 1) M1 = max(M1, a[i]), M2 = max(M2, b[i]);
    cout << M1 * M2 << endl;
  }
  return 0;
}