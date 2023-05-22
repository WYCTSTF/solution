#include <bits/stdc++.h>
inline char gc() {
	static const int N = 1 << 20;
	static char buf[N | 1], *S = buf, *T = buf;
	return S == T && (T = (S = buf) + fread(buf, 1, N, stdin), S == T) ? EOF : *S++;
}
template<typename T>
inline void read(T &x) {
	x = 0;
	char ch = gc();
	for (; ch < '0' || ch > '9';) ch = gc();
	for (; ch <= '9' && ch >= '0';)
		x = x * 10 + (ch ^ 48), ch = gc();
}
int n, heap[1000010], tp;
void up(int pos) {
	while (pos > 1 && heap[pos / 2] > heap[pos])
		std::swap(heap[pos], heap[pos / 2]), pos /= 2;
}
void down(int pos) {
	int nxt = pos * 2;
	while (nxt <= tp) {
		if (nxt < tp && heap[nxt] > heap[nxt + 1])
			nxt++;
		if (heap[nxt] < heap[pos]) {
			std::swap(heap[nxt], heap[pos]);
			pos = nxt, nxt = pos * 2;
		} else break;
	}
}
int main() {
	int n;
	read(n);
	for (int i = 1; i <= n; ++i) {
		int op;
		read(op);
		if (op == 1) {
			int x;
			read(x);
			heap[++tp] = x;
			up(tp);
		} else if (op == 2) {
			std::cout << heap[1] << '\n';
		} else {
			std::swap(heap[1], heap[tp]);
			--tp;
			down(1);
		}
	}
	return 0;
}