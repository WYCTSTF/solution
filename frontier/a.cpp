#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
bitset<N> vis;
int mu[N];
vector<int> primes;
void init() {
  mu[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (vis[i] == 0) {
      primes.push_back(i);
      mu[i] = -1;
    }
    for (auto p : primes) {
      if (p * i > n)
        break;
      vis[p * i] = 1;
      if (p % i == 0) {
        mu[i] = 0;
        break;
      } else
        mu[p * i] = mu[p] * mu[i];
    }
  }
}
int main() { 
  return 0;
}