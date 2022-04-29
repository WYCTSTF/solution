#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector a(n, 0LL);
	for (auto &it : a) {
		it = 2;
	}
	cout << accumulate(a.begin(), a.end(), 0LL) << endl;
	return 0;
}