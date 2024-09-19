#include <bits/stdc++.h>
using namespace std;
void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	int tot = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (a[i] < 0)
			tot++;
		a[i] = abs(a[i]);
	}
	sort(a.begin(), a.end());
	if (tot % 2)
		a[0] = -a[0];
	cout << accumulate(a.begin(), a.end(), 0LL) << '\n';
}
int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		solve();
	}
	return 0;
}
