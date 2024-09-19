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

void solve() {
  string s[4];
  cin>>s[1]>>s[2]>>s[3];
  if(s[1][0]!='.'&&s[1][0]==s[1][1]&&s[1][1]==s[1][2]){cout<<s[1][0]<<'\n';return;}
  if(s[2][0]!='.'&&s[2][0]==s[2][1]&&s[2][1]==s[2][2]){cout<<s[2][0]<<'\n';return;}
  if(s[3][0]!='.'&&s[3][0]==s[3][1]&&s[3][1]==s[3][2]){cout<<s[3][0]<<'\n';return;}
  if(s[1][0]!='.'&&s[1][0]==s[2][0]&&s[2][0]==s[3][0]){cout<<s[1][0]<<'\n';return;}
  if(s[1][1]!='.'&&s[1][1]==s[2][1]&&s[2][1]==s[3][1]){cout<<s[1][1]<<'\n';return;}
  if(s[1][2]!='.'&&s[1][2]==s[2][2]&&s[2][2]==s[3][2]){cout<<s[1][2]<<'\n';return;}
  if(s[1][0]!='.'&&s[1][0]==s[2][1]&&s[2][1]==s[3][2]){cout<<s[1][0]<<'\n';return;}
  if(s[1][2]!='.'&&s[1][2]==s[2][1]&&s[2][1]==s[3][0]){cout<<s[1][2]<<'\n';return;}
  cout<<"DRAW\n";
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) solve();
  return 0;
}
