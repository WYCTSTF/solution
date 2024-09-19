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

void solve() {
  int n;
  cin >> n;

  string s;
  cin >> s;

  vector<char> pre(26, ' ');
#define p(x) (int(x - 'a'))

  set<char> ch;
  for (int i = 0; i < 26; ++i)
    ch.insert(char(i + 'a'));

  for (auto i : s) {
    if (pre[p(i)] == ' ') {
      for (char c : ch) {
        if (c == i)
          continue;

        auto n1 = c;
        while (pre[p(n1)] != ' ')
          n1 = pre[p(n1)];

        auto n2 = i;
        while (pre[p(n2)] != ' ')
          n2 = pre[p(n2)];

        if (n1 == n2 && ch.size() > 1)
          continue;

        pre[p(i)] = c;
        break;
      }
      if (ch.find(pre[p(i)]) != ch.end())
        ch.erase(pre[p(i)]);
    }
  }

  for (auto i : s)
    cout << pre[p(i)];
  cout << '\n';
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}