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
  cin>>n;
  vector<int> a(n+1);
  for(int i=1;i<=n;++i){
    cin>>a[i];
  }
  bool flag = true;
  for (int i = 1; i <= n - 2; ++i) {
    if (a[i] < 0) {
      flag = false;
      break;
    }
    a[i + 1] -= a[i] * 2;
    a[i + 2] -= a[i];
  }
  if (a[n] != 0 || a[n - 1] != 0)
    flag = false;
  puts(flag?"YES":"NO");
}

int main(){
  int tt;cin>>tt;
  while(tt--){
    solve();
  }
  return 0;
}
