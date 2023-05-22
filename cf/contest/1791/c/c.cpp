#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		deque<char> q;
		string s;
		cin >> s;
		for (char c : s)
			q.push_back(c);
		while (!q.empty() && q.front() != q.back())
			q.pop_back(), q.pop_front();
		cout << (int)q.size() << '\n';
	}
	return 0;
}
