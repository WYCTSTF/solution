#include <bits/stdc++.h>
using ll = long long;
char gc() {
	static const int N = 1 << 20;
	static char buf[N | 1], *S = buf, *T = buf;
	return S == T && (T = (S = buf) + fread(buf, 1, N, stdin), S == T) ? EOF : *S++;
}
template<typename T> void read(T &x) {
	x = 0;
	char ch = gc();
	for (; ch < '0' || ch > '9';) ch = gc();
	for (; ch <= '9' && ch >= '0';)
		x = x * 10 + (ch ^ 48), ch = gc();
}
ll adj[150][150], f[150][150];
int main() {
	int n;
	read(n);
	std::vector<ll> a;
	for (int i = 1; i <= n; ++i) {
		ll x; read(x);
		if (x) a.push_back(x);
	}
	if (a.size() > 120) {
		std::cout << "3\n";
		return 0;
	}
	n = (int)a.size();
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			f[i][j] = adj[i][j] = ((i != j && (a[i] & a[j])) ? 1ll : (ll)INT_MAX / 2);
	ll ans = 300;
	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) {
				if (i == j || j == k || i == k)
					continue;
				ans = std::min(ans, f[i][j] + adj[i][k] + adj[k][j]);
			}
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (f[i][j] > f[i][k] + f[k][j])
					f[i][j] = f[i][k] + f[k][j];
	}
	std::cout << ((ans == 300) ? -1 : ans) << '\n';
	return 0;
}
