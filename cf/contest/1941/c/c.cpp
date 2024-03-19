#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned int;
using db = double;
using VI = std::vector<int>;
using PII = std::pair<int, int>;

#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define fi first
#define se second
#define pi acos(-1)
#define sz(x) ((int)(x).size())
#define all(x) x.begin(),x.end()

i64 gcd(i64 a,i64 b) { return b?gcd(b,a%b):a; }

void solve(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  int ans = 0;
  for (int i = 0; i < n - 2; ++i) {
    if (s[i] == 'm' && s[i + 1] == 'a' && s[i + 2] == 'p') {
      ans++;
      if (i + 4 < n && s[i + 3] == 'i' && s[i + 4] == 'e')
        i = i + 5;
    }
    if (s[i] == 'p' && s[i + 1] == 'i' && s[i + 2] == 'e')
      ans++;
  }
  cout << ans << '\n';
}

int main(){
  int tt;
  cin>>tt;
  while(tt--){
    solve();
  }
  return 0;
}
