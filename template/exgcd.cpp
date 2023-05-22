int exgcd(int a, int b, int &x, int &y) {
	if (b) {
		int g = exgcd(b, a % b, x, y);
		x -= a / b * y, swap(x, y);
		return g;
	} else {
		x = 1, y = 0;
		return a;
	}
}