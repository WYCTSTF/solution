#define N 100010

int fa[N], dep[N], siz[N], son[N];

void dfs1(int u) {
	siz[u] = 1;
	son[u] = -1;
	for (int v : adj[u]) { // 链式前向星就改掉
		if (!dep[v]) {
			dep[v] = dep[u] + 1;
			fa[v] = u;
			dfs1(v);
			siz[u] += siz[v];
			if (son[u] == -1 || siz[v] > siz[son[u]])
				son[u] = v;
		}
	}
}

int dfc;
int top[N], dfn[N];
int rnk[N]; // 要转化成线性然后区间修改的话

void dfs2(int u, int tp) {
	top[u] = tp;
	dfn[u] = ++dfc;
	rnk[dfc] = u;
	if (son[u] == -1)
		return;
	dfs2(son[u], tp);
	for (int v : adj[u]) {
		if (v != fa[u] && v != son[u])
			dfs2(v, v);
	}
}