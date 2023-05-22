#include <bits/stdc++.h>

using ll = long long;

const ll A = 1ll << 30;

ll exgcd(ll a, ll b, ll &x, ll &y) {
	ll g = a;
	if (b) {
		g = exgcd(b, a % b, x, y);
		x -= a / b * y;
		std::swap(x, y);
	} else
		x = 1, y = 0;
	return g;
}

int main() {
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int tt;
	std::cin >> tt;
	while (tt--) {
		ll a, b, d;
		std::cin >> a >> b >> d;

		ll x, y, g = exgcd(A, d, x, y);
		ll C = (d - (a | b) % d) % d;
		if (C % g) {
			std::cout << "-1\n";
			continue;
		}
		x = x * (C / g) % (d / g);
		if (x < 0) x += (d / g);
		ll ans = (x << 30) | a | b;
		std::cout << ans << '\n';
//		if (ans % d == 0)
//			std::cout << "Yes\n";
//		else
//			std::cout << "No\n";
	}
	return 0;
}
