#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned int;
using db = double;

#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pi acos(-1)
#define sz(x) ((int)(x).size())
#define all(x) x.begin(),x.end()
#define INF 0x7fffffff
#define inf 0x3f3f3f3f
#define mod 998244353
#define MOD 1000000007
typedef std::vector<int> VI;
typedef std::pair<int,int> PII;

i64 gcd(i64 a,i64 b) { return b?gcd(b,a%b):a; }

int main() {
  int tt;
  std::cin >> tt;
  while (tt--) {
    std::set<std::string> s;
    std::string _s;
    int n;
    std::cin >> n;
    std::cin >> _s;
    for (int i = 0; i < n - 1; ++i) {
      std::string tem = "";
      tem += _s[i], tem += _s[i + 1];
      s.insert(tem);
    }
    std::cout << s.size() << '\n';
  }
  return 0;
}
