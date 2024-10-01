#include <bits/stdc++.h>
int n, m;
int x, y, Max1, Max2;
inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch))
        f = (ch == '-') ? -1 : 1, ch = getchar();
    while (isdigit(ch))
        x = x * 10 + (ch - '0'), ch = getchar();
    return x * f;
}
int main()
{
    n = read();
    for (int i = 1; i <= n; i++)
        x = read(), Max1 = std::max(Max1, x);
    m = read();
    for (int i = 1; i <= m; i++)
        x = read(), Max2 = std::max(Max2, x);
    std::cout << Max1 << ' ' << Max2 << '\n';
    return 0;
}