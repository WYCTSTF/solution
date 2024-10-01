#include <bits/stdc++.h>
using namespace std;
void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> p;
	for (int l = 0, r = n - 1; l < r; ++l, --r) {
		if (s[l] != s[r])
			p.push_back(l);
	}
	if (p.empty() || p.back() - p[0] + 1 == (int)p.size())
		cout << "Yes\n";
	else
		cout << "No\n";
}
int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		solve();
	}
	return 0;
}