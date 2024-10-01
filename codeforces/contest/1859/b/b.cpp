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

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    i64 ans=0;
    int mn=INT_MAX,tmn=INT_MAX;
    int n, m;
    cin >> n;
    rep(i,1,n){
      cin>>m;
      int l1, l2;
      cin>>l1>>l2;if(l1<l2)swap(l1,l2);
      rep(i,3,m){
        int tem;cin>>tem;
        if(tem<l2)l1=l2,l2=tem;
        else if(tem<l1)l1=tem;
      }
      ans+=l1,tmn=min(tmn,l1),mn=min(mn,l2);
    }
    ans=ans-tmn+mn;
    cout<<ans<<'\n';
  }
}
