#include <bits/stdc++.h>

using ll = long long;
using namespace std;

bool solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int x = 0, y = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'U') y++;
		if (s[i] == 'D') y--;
		if (s[i] == 'R') x++;
		if (s[i] == 'L') x--;
		if (x == 1 && y == 1)
			return true;
	}
	return false;
}
int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		if (solve()) {
			cout << "YES\n";
		}else {
			cout << "NO\n";
		}
	}
	return 0;
}
