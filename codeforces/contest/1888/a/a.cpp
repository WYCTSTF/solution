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

#define rep(i, a, n) for (int i = a; i <= n; i++)
#define per(i, a, n) for (int i = n; i >= a; i--)
#define pb push_back
#define fi first
#define se second
#define pi acos(-1)
#define sz(x) ((int)(x).size())
#define all(x) x.begin(), x.end()

i64 gcd(i64 a, i64 b) { return b ? gcd(b, a % b) : a; }

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> tot(26, 0);
    for (char &c : s) {
      tot[c - 'a']++;
    }
    int sum = 0;
    for (int i = 0; i < 26; ++i) {
      if (tot[i] % 2)
        sum += tot[i];
    }
    bool flag = false;
    for (int i = 0; i < 26; ++i) {
      if (tot[i] % 2 && sum - tot[i] == k) {
        flag = true;
        break;
      }
    }
    if(flag||sum==k){
      cout<<"YES\n";
    }
    else
      cout<<"NO\n";
  }
}
