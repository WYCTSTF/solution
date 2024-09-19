#include <bits/stdc++.h>

using namespace std;

#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pi acos(-1)
#define il inline
#define rg register
#define SZ(x) ((int)(x).size())
#define all(x) x.begin(),x.end()
#define INF 0x7fffffff
#define inf 0x3f3f3f3f
#define MOD 998244353
#define mod 1000000007
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef long long ll;
typedef double db;
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a; }

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    VI tot(26, 0);
    for (auto c : s) {
      tot[c - 'a']++;
    }
    
    for (int i = 1; i <= k; ++i) {
      for (int j = 0; j < 26; ++j) {
        if (tot[j] > 0 && j < n / k)
          tot[j]--;
        else {
          cout << (char)(j + 'a');
          break;
        }
      }
    }
    cout << '\n';
  }
  return 0;
}

/*

cabccadabaac

*/