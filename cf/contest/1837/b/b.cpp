#include <bits/stdc++.h>

#ifdef LOCAL
#include <dbg.h>
#else
#define dbg(...) 42
#endif

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned int;
using db = double;

using std::cin, std::cout;

#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define fi first
#define se second
#define pi acos(-1)
#define sz(x) ((int)(x).size())
#define all(x) x.begin(),x.end()
typedef std::vector<int> VI;
typedef std::pair<int,int> PII;

i64 gcd(i64 a,i64 b) { return b?gcd(b,a%b):a; }

int main(){
  int tt;
  cin>>tt;
  while(tt--){
    int n;
    cin>>n;
    int ans=1;
    std::string ss;
    cin>>ss;
    int tem=1;
    for(int i=1;i<sz(ss);++i)
      if(ss[i]==ss[i-1])
        tem++,ans=std::max(tem,ans);
      else tem=1;
    cout<<ans+1<<'\n';
  }
  return 0;
}
