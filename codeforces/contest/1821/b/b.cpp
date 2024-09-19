#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <cmath>
#include <deque>
#include <bitset>
#include <cstdio>
#include <vector>
#include <string>
#include <complex>
#include <sstream>
#include <utility>
#include <climits>
#include <cstring>
#include <fstream>
#include <functional>
#include <iostream>
#include <algorithm>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pi acos(-1)
#define il inline
#define rg register
#define SZ(x) ((int)(x).size())
#define all(x) x.begin(),x.end()
#define INF 0x7fffffff;
#define inf 0x3f3f3f3f;
#define MOD 998244353;
#define mod 1000000007;
using namespace std;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef long long ll;
typedef double db;
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a; }
int main() {
  int tt;
  cin>>tt;
  while(tt--){
    int n;
    cin>>n;
    VI a(n+1),b(n+1);
    rep(i,1,n)cin>>a[i];
    rep(i,1,n)cin>>b[i];
    int l=1,r=n;
    while(a[l]==b[l])++l;
    while(a[r]==b[r])--r;
    while(l>1&&b[l]>=b[l-1])--l;
    while(r<n&&b[r]<=b[r+1])++r;
    cout<<l<<' '<<r<<'\n';
  }
  return 0;
}