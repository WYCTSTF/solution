void euler(int n, vector<int> &phi) {
	phi[1] = 1;
	for (int i = 2; i <= n; ++i) {
		if (vis[i] == 0) {
			primes.pb(i);
			phi[i] = i - 1;
		}
		for (int p : primes) {
			if (p * i > n)
				break;
			vis[i * p] = 1;
			if (i % p == 0) {
				phi[i * p] = phi[i] * p;
				break;
			}
			phi[i * p] = phi[i] * (p - 1);
		}
	}
}