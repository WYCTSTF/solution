#include <stdio.h>

int main() {
  int tt; scanf("%d", &tt);
  while (tt--) {
    long long n, s;
    scanf("%lld%lld", &n, &s);
    printf("%lld\n", s / (n * n));
  }
}