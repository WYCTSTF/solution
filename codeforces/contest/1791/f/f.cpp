#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int low(int x) {return x & (-x);}

unordered_map<int, int> mp;

inline int ope(int x) {
	int ans = 0;
	while (x)
		ans += x % 10, x /= 10;
	return ans;
}

template<typename T>
void write(int x) {
	if (x >= 10)
		write(x / 10);
	putchar(x % 10 + '0');
}

void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n + 1);
	vector<int> c(n + 1, 0);
	auto add = [&](int x, int v) {
		for (; x <= n; x += low(x))
			c[x] += v;
	};
	auto ask = [&](int x) {
		int ans = 0;
		for (; x; x -= low(x))
			ans += c[x];
		return ans;
	};
	for (int i = 1; i <= n; ++i)
		cin >> a[i], mp[a[i]] = ope(a[i]);
	for (int i = 1; i <= q; ++i) {
		int op, l, r, x;
		cin >> op;
		if (op == 1) {
			cin >> l >> r;
			add(l, 1), add(r + 1, -1);
		} else {
			cin >> x;
			int tem = ask(x), _tem = a[x];
			for (int j = 1; j <= tem; ++j)
				_tem = mp[_tem];
			write(_tem);
			putchar('\n');
		}
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	for (int i = 0; i <= 90; ++i)
		mp[i] = ope(i);

	int tt;
	cin >> tt;
	while (tt--) {
		solve();
	}
	return 0;
}
