#include <bits/stdc++.h>
using i64 = long long;
int main() {
	int tt;
	std::cin >> tt;
	while (tt--) {
		int n;
		std::cin >> n;
		for (int i = 1; i <= n; ++i)
			std::cout << i * 2 << " \n"[i == n];
	}
	return 0;
}
