	#include <bits/stdc++.h>
	using namespace std;

	void solve() {
		int n;
		int d12, d23, d31;
		cin >> n >> d12 >> d23 >> d31;

		vector<int> p(n);
		iota(p.begin(), p.end(), 1);
		auto print = [&]() {
			cout << "YES\n";
			for (int i = 0; i + 1 < n; ++i)
					cout << p[i] << ' ' << p[i + 1] << '\n';
		};
		if (d12 == d31 + d23) {
			if (d12 == 2)
				swap(p[1], p[2]);
			else {
				swap(p[1], p[d12]);
				swap(p[2], p[d31])
			}
			print();
		} else if (d31 == d12 + d23) {
			swap(p[2], p[d31]);
			swap(p[1], p[d12]);
			print();
		} else if (d23 == d12 + d31) {
			swap(p[0], p[1]);
			swap(p[2], p[d23]);
			swap(p[1], p[d12]);
			print();
		} else {
			int s = (d12 + d31 - d23);
			int k = s / 2, x = d12 - k, y = d31 - k;
			if ((s & 1) || k <= 0 || x <= 0 || y <= 0 || x + y + k > n - 1) {
				cout << "NO\n";
				return;
			}
			cout << "YES\n";
			swap(p[2], p[d12 + y]);
			swap(p[1], p[d12]);

			for (int i = 1; i <= d12; ++i)
					cout << p[i - 1] << ' ' << p[i] << '\n';
			swap(p[d12], p[k]);
			for (int i = d12 + 1; i < n; ++i) {
				cout << p[i - 1] << ' ' << p[i] << '\n';
			}
		}
	}

	int main() {
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int tt;
		cin >> tt;
		while (tt--) {
			solve();
		}
		return 0;
	}
