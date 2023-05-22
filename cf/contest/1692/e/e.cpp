#include <bits/stdc++.h>
using namespace std;

int main() {
	int tt;
	cin >> tt;

	while (tt--) {
		int n, s;
		cin >> n >> s;

		vector<int> a(n + 1, 0);
		int tot = 0;
		for (int i = 1; i <= n; ++i)
			cin >> a[i], tot += a[i];
		if (tot < s) {
			cout << "-1\n";
			continue;
		}
		vector<int> left, right;
		left.push_back(0);
		right.push_back(0);
		for (int i = 1; i <= n; ++i)
			if (a[i] == 1)
				left.push_back(i);
		for (int i = n; i >= 1; --i)
			if (a[i] == 1)
					right.push_back(n - i + 1);

		int ans = 200010;
		for (int i = 0; i <= tot - s; ++i)
			ans = min(ans, left[i] + right[tot - s - i]);
		cout << ans << '\n';
	}
	return 0;
}