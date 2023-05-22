#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		if (n % 2) {
			int now = n - 1 >> 1;
			if (now % 10 != 9) {
				cout << now << ' ' << now + 1 << '\n';
			} else {
				cout << now + 5 << ' ' << now - 4 << '\n';
			}
		} else {
			cout << n / 2 << ' ' << n / 2 << '\n';
		}
	}
	return 0;
}
