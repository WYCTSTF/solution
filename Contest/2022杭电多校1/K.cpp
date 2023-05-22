#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int mod = 1e9 + 7;

ll qpow(ll a, ll b) {
	ll ans = 1;
	a %= mod;
	for (; b; b >>= 1) {
		if (b & 1)
			ans = ans * a % mod;
		a = a * a % mod;
	}
	return ans;
}

int main() {
	int t;
	cin >> t;

	ll inv2 = qpow(1ll * 2, 1ll * mod - 2);

	while (t--) {
		int n, m;
		cin >> n >> m;
		cout << (n - m) * inv2 % mod << '\n';
	}
	return 0;
}