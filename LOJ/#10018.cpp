#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch)) f = (ch == '-') ? -1 : 1, ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return x * f;
}

int n, k, ans;
int d[10];

void dfs(int x) {
    if (x == k) {
        ans++;
        return;
    }
    for (int i = d[x - 1]; i <= n / (k - x + 1); i++) {
        if (n >= i) {
            n -= i, d[x] = i;
            dfs(x + 1);
            n += i;
        }
        else break;
    }
}

int main() {
    n = read(), k = read();
    d[0] = 1;
    dfs(1);
    printf("%d", ans);
    return 0;
}