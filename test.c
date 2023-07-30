#include <stdio.h>
#include <math.h>

const int N = 1e6 + 10, lgN = 20;

int n, m;
int x, y;
int a[N], lg[N] = {-1}, f[N][lgN];

int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
        f = (ch == '-') ? -1 : 1, ch = getchar();
    while (ch <= '9' && ch >= '0')
        x = x * 10 + (ch - '0'), ch = getchar();
    return x * f;
}

int max(int a, int b) {
  return a > b ? a : b;
}

int main()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        a[i] = read(), f[i][0] = a[i], lg[i] = lg[i >> 1] + 1;

    for (int j = 1; j <= lg[n]; j++)
        for (int i = 1; i <= n - (1 << j) + 1; i++)
            f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);

    while (m--)
    {
        x = read(), y = read();
        int k = lg[y - x + 1];
        printf("%d\n", max(f[x][k], f[y - (1 << k) + 1][k]));
    }
    return 0;
}
