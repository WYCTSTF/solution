#include<cstdio>
#include<cstring>
#include<algorithm>
const int N=3e5+10;
int n, m, tot, idx, MaxLen, h[N], ver[N<<1], nxt[N<<1], val[N<<1],dep[N];
int dis[N], len[N], f[N][21], cnt[N], _[N], s[N], t[N], p[N], seq[N];

inline void add(int u, int v, int w) {
    ver[++tot] = v, val[tot] = w, nxt[tot] = h[u], h[u] = tot;
}

void dfs(int u, int fa) {
    seq[++idx] = u, f[u][0] = fa, dep[u] = dep[fa] + 1;
    for (int i = h[u]; i; i = nxt[i]) {
        int y = ver[i];
        if (y^fa) {
            dis[y] = dis[u] + val[i], _[y] = val[i];
            dfs(y, u);
        }
    }
}
inline int LCA(int x, int y) {
    if (dep[x] > dep[y]) x ^= y ^= x ^= y;
    for (int i = 20; i >= 0; i--)
        if (dep[f[y][i]] >= dep[x]) y = f[y][i];
    if (x == y) return x;
    for (int i = 20; ~i; i--) if (f[x][i] ^ f[y][i]) x = f[x][i], y = f[y][i];
    return f[x][0];
}

bool check(int x) {
    for (int i = 1; i <= n; i++) cnt[i] = 0;
    int sum = 0;
    for (int i = 1; i <= m; i++)
        if(len[i] > x) ++cnt[s[i]], ++cnt[t[i]], cnt[p[i]]-=2, ++sum;
    for (int i = n; i >= 1; i--) {
        int k = seq[i];
        cnt[f[k][0]] += cnt[k];
        if (cnt[k] == sum && _[k] >= MaxLen - x) return true;
    }
    return false;
}
signed main() {
    scanf("%d%d", &n, &m);
    for (int i = 1, u, v, w; i < n; i++) {
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w), add(v, u, w);
    }
    dfs(1, 0);
    for (int j = 1; j <= 20; j++) for (int i = 1; i <= n; i++) f[i][j] = f[f[i][j-1]][j-1];
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &s[i], &t[i]);
        p[i] = LCA(s[i], t[i]);
        len[i] = dis[s[i]] + dis[t[i]] - (dis[p[i]] * 2);
        MaxLen = std::max(MaxLen, len[i]);
    }
    int l = 0, r = MaxLen, ans;
    while (l <= r) {
        int mid = 1LL * (l + r) >> 1;
        if (check(mid)) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    printf("%d", ans);
    return 0;
}