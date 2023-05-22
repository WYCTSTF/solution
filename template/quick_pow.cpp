inline int qpow(long long a, int b, int p) {
	int ans = 1;
	a = (a % p + p) % p;
	for (; b; b >>= 1) {
		if (b & 1)
			ans = (ans * a) % p;
		a = (a * a) % p;
	}
	return ans;
}