#include <bits/stdc++.h>
using namespace std;
void solve() {
	int n;
	cin >> n;
	string s1, s2;
	cin >> s1 >> s2;
	auto test = [&](int st) -> bool {
		for (int i = 0; i < n; ++i) {
			if (s1[i] == 'B' && s2[i] == 'B')
				st = 3 - st;
			else if (s1[i] == 'B' && st == 2) {
				// cout << "f1\n";
				return false;
			}
			else if (s2[i] == 'B' && st == 1) {
				// cout << "f2\n";
				return false;
			}
			else if (s1[i] == 'W' && s2[i] == 'W') {
				// cout << i << ' ' << "f3\n";
				return false;
			}
		}
		return true;
	};
	if (test(1) || test(2))
		cout << "YES\n";
	else
		cout << "NO\n";
}
int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		solve();
	}
	return 0;
}