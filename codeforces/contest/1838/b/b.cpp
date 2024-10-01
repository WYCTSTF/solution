#include <bits/stdc++.h>
using namespace std;


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
  int n;cin>>n;vector<int>a(n+1);
  VI pos(n+1);
  rep(i,1,n)cin>>a[i],pos[a[i]]=i;
  if(n==3){
    if(a[2]==2)
      cout<<pos[2]<<' '<<pos[3]<<'\n';
    else if(a[2]==1)
      cout<<pos[1]<<' '<<pos[3]<<'\n';
    else
      cout<<"1 1\n";
  }
  else{
    if(pos[1]<pos[n]&&pos[2]<pos[n])
      cout<<pos[n]<<' '<<max(pos[1],pos[2])<<'\n';
    else if(pos[1]>pos[n]&&pos[2]>pos[n])
      cout<<pos[n]<<' '<<min(pos[1],pos[2])<<'\n';
    else if(abs(pos[1]-pos[2])>1)
      cout<<min(pos[1],pos[2])+1<<' '<<pos[n]<<'\n';
  }
}

int main() {
  int tt;
  cin>>tt;
  while(tt--){
    solve();
  }
  return 0;
}
