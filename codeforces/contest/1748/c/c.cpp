#include <bits/stdc++.h>

using ll = long long;

int main() {
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int tt;
	std::cin >> tt;
	
	while (tt--) {
		int n;
		std::cin >> n;
		
		std::vector<int> a(n + 1, 0);
		std::vector<ll> sum(n + 1, 0LL);
		for (int i = 1; i <= n; ++i)
			std::cin >> a[i], sum[i] = sum[i - 1] + a[i];

		std::map<ll, int> tot;
		int st, ans = 0;
		for (int i = 1; i <= n; ++i) {
			if (a[i] == 0) {
				st = i;
				break;
			}
			if (sum[i] == 0ll)
				ans++;
		}

		int mx = -1;
		for (int i = n; i >= st; --i) {
			tot[sum[i]]++;
			mx = std::max(mx, tot[sum[i]]);
			if (a[i] == 0) {
				tot.clear();
				ans += mx;
				mx = -1;
			}
		}

		std::cout << ans << '\n';
	}

	return 0;
}
