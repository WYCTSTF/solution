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
bool solve() {
  ll n,m,k;cin>>n>>m>>k;
  if(m<n-1||m>n*(n-1)/2)return false;
  else if(k>=4)return true;
  else if(m==n*(n-1)/2)return (n==1&&k>=2)||(n>1&&k>=3);
  else return false;
}
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    if(solve())puts("YES");
    else puts("NO");
  }
  return 0;
}