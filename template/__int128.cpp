#include <bits/stdc++.h>
using namespace std;
void scan(__int128 &x) { //输入
	x = 0;
	__int128 f = 1;
	char ch;
	if((ch = getchar()) == '-') f = -f;
	else x = x*10 + ch-'0';
	while((ch = getchar()) >= '0' && ch <= '9')
		x = x*10 + ch-'0';
	x *= f;
}
void _print(__int128 x) {
    if (x > 9) _print(x / 10);
    putchar(x % 10 + '0');
}
inline void print(__int128 x) {
    if (x < 0) x = -x, putchar('-');
    _print(x);
}
int main() {
    __int128 a, b;
    scan(a), scan(b);
    print(a + b);
    return 0;
}