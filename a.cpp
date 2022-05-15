#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pi acos(-1)
#define il inline
#define rg register
#define SZ(x) ((int)(x).size())
#define all(x) x.begin(),x.end()
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef long long ll;
typedef double db;
const int INF=0x7fffffff;
const int inf=0x3f3f3f3f;
const int MOD=998244353;
const int mod=1e9+7;
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a; }

namespace FAST_IO {
#define ll long long
#define ull unsigned long long
#define db double
#define _8 __int128_t
const int LEN = 1 << 20;
char BUF[LEN], PUF[LEN];
int Pin = LEN, Pout;
inline void flushin() {
	memcpy(BUF, BUF + Pin, LEN - Pin), fread(BUF + LEN - Pin, 1, Pin, stdin),
			Pin = 0;
	return;
}
inline void flushout() {
	fwrite(PUF, 1, Pout, stdout), Pout = 0;
	return;
}
inline char Getc() {
	return (Pin == LEN ? (fread(BUF, 1, LEN, stdin), Pin = 0) : 0), BUF[Pin++];
}
inline char Get() { return BUF[Pin++]; }
inline void Putc(char x) {
	if (Pout == LEN)
		flushout(), Pout = 0;
	PUF[Pout++] = x;
}
inline void Put(char x) { PUF[Pout++] = x; }
template <typename tp = int> inline tp read() {
	(Pin + 32 >= LEN) ? flushin() : void();
	tp res = 0;
	char f = 1, ch = ' ';
	for (; ch < '0' || ch > '9'; ch = Get())
		if (ch == '-')
			f = -1;
	for (; ch >= '0' && ch <= '9'; ch = Get())
		res = (res << 3) + (res << 1) + ch - 48;
	return res * f;
}
template <typename tp> inline void wt(tp a) {
	if (a > 9)
		wt(a / 10);
	Put(a % 10 + '0');
	return;
}
template <typename tp> inline void write(tp a, char b = '\n') {
	static int stk[20], top;
	(Pout + 32 >= LEN) ? flushout() : void();
	if (a < 0)
		Put('-'), a = -a;
	else if (a == 0)
		Put('0');
	for (top = 0; a; a /= 10)
		stk[++top] = a % 10;
	for (; top; --top)
		Put(stk[top] ^ 48);
	Put(b);
	return;
}
inline void wt_str(string s) {
	for (char i : s)
		Putc(i);
	return;
}
} // namespace FAST_IO
using namespace FAST_IO;

int main() {
	vector<int>a;
	int tem;
	while (scanf("%d", &tem)!=EOF) {
		a.pb(tem);
	}
	// deb(a);
	write(a[0]+a[1],'\n');
	flushout();
	return 0;
}