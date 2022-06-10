#include <bits/stdc++.h>
using namespace std;
const int N = 1e8;
bitset<N> vis;
vector<int> primes;
int main() {
  int n, q;
  cin >> n >> q;
  for (int i = 2; i <= n; i++) {
    if (vis[i] == 0) {
      primes.push_back(i);
    }
    for (auto p : primes) {
      if (p * i > n)
        break;
      vis[p * i] = 1;
      if (i % p == 0)
        break;
    }
  }
  return 0;
}