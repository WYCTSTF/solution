#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
const int M = 2000010;
vector <int> E[N], e[N]; // E是正图 e是反图
bitset <N> vis;
int val[N], fMin[N], fMax[N];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> val[i];
	memset(fMin, 0x7f, sizeof(fMin));
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		E[u].push_back(v);
		e[v].push_back(u);
		if (w == 2) {
			E[v].push_back(u);
			e[u].push_back(v);
		}
	}

	queue <int> q;
	vis.reset();
	vis[1] = 1;
	q.push(1);
	fMin[1] = val[1];
	while (!q.empty()) { // 先用正图预处理最小值
		auto u = q.front();
		q.pop();
		vis[u] = 0;
		
		for (auto v : E[u]) {
			if (fMin[v] > min(fMin[u], val[v])) {
				fMin[v] = min(fMin[u], val[v]);
				if (vis[v] == 0) {
					q.push(v);
					vis[v] = 1;
				}
			}
		}
	}

	q.push(n);
	vis.reset();
	vis[n] = 1;
	fMax[n] = val[n];
	
	while (!q.empty()) {
		auto u = q.front();
		q.pop();

		vis[u] = 0;
		for (auto v: e[u]) {
			if (fMax[v] < max(val[v], fMax[u])) {
				fMax[v] = max(fMax[u], val[v]);
				if (vis[v] == 0) {
					vis[v] = 1;
					q.push(v);
				}
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, fMax[i] - fMin[i]);
	}
	cout << ans << endl;
	return 0;
}