#include <bits/stdc++.h>

using ll = long long;
using namespace std;

void amax(int &x, int y) { x = max(x, y); }
void amin(int &x, int y) { x = min(x, y); }

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> d(n + 2, 0);
	vector<int> l(30, INT_MAX), r(30, -1);
	for (int i = 0; i < n; ++i) {
		amin(l[s[i] - 'a'], i);
		amax(r[s[i] - 'a'], i);
	}
	for (int i = 0; i < 26; ++i) {
		if (l[i] != INT_MAX && l[i] != r[i])
			d[l[i] + 1]++, d[r[i] + 1]--;
	}
	int _max = -1;
	for (int i = 1; i < n; ++i)
		d[i] += d[i - 1], _max = max(_max, d[i]);
	_max = max(_max, d[0]);
	set<char> S{s.begin(), s.end()};
	cout << (int)S.size() + _max << '\n';
}

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		solve();
	}
	return 0;
}
