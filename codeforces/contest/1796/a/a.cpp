#include <bits/stdc++.h>
using namespace std;
string standard = "";
void solve() {
	int n;
	string s;
	cin >> s;
	
}
int main() {
	int tt;
	cin >> tt;
	for (int i = 1; i <= 30; ++i) {
		if (i % 3 == 0)
			standard += 'F';
		if (i % 5 == 0)
			standard += 'B';
	}
	while (tt--) {
		solve();
	}
	return 0;
}