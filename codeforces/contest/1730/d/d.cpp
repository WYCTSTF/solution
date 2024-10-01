#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, n) for (int i = a; i <= n; i++)
#define per(i, a, n) for (int i = n; i >= a; i--)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pi acos(-1)
#define il inline
#define rg register
#define SZ(x) ((int)(x).size())
#define all(x) x.begin(), x.end()
#define INF 0x7fffffff
#define inf 0x3f3f3f3f
#define MOD 998244353
#define mod 1000000007
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef long long ll;
typedef double db;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tt;
  cin >> tt;
  
  while (tt--) {
    int n;
    cin >> n;

    string s1, s2;
    cin >> s1 >> s2;

    s1 = '&' + s1;
    s2 = '&' + s2;

    vector cnt(26, vector<int>(26, 0));
    for (int i = 1; i <= n; ++i) {
      int c1 = (int)s1[i] - 'a', c2 = (int)s2[n - i + 1] - 'a';
      if (c1 > c2)
        swap(c1, c2);
      cnt[c1][c2]++;
    }

    bool ok = true;
    for (int i = 0; i < 26; ++i)
      for (int j = i + 1; j < 26; ++j)
        if (cnt[i][j] & 1) {
          ok = false;
          break;
        }

    int sum = 0;
    for (int i = 0; i < 26; ++i)
      sum += cnt[i][i] % 2;

    if (!ok || sum > n % 2)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
  return 0;
}