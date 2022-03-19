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
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    set<int> s;
    s.clear();
    int n;
    cin >> n;
    int g;
    for (int i = 23; i >= 0; i--) {
      if (n - 1 >> i & 1) {
        g = i;
        break;
      }
    }
    for (int i = (1 << g); i <= n - 1; i++)
      s.insert(i);
    int st = *s.begin(), ed = *(--s.end());
    // for(auto it=s.begin();it!=s.end();++it) if(*it!=(st-(1<<g))) cout<<*it<<'
    // ';
    vector<int> ans = {};
    if (s.find(st - (1 << g)) == s.end())
      ans.push_back(st - (1 << g));
    for (auto it : s)
      ans.push_back(it);
    if (s.find(st - (1 << g)) == s.end())
      s.insert(st - (1 << g));
    if (s.find(ed - (1 << g)) == s.end())
      ans.push_back(ed - (1 << g)), s.insert(ed - (1 << g));
    // cout<<"fuck";
    reverse(all(ans));
    for (int i = 0; i < n; i++) {
      if (s.find(i) == s.end())
        ans.push_back(i);
    }
    for (auto it : ans)
      cout << it << ' ';
    cout << endl;
  }
  return 0;
}