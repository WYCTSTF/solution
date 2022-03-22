#include<cstdio>
#define max(a, b) (a>b?a:b)
int main() {
  int tt, l, r, a; scanf("%d", &tt);
  while (tt--) {
    scanf("%d%d%d", &l, &r, &a);
    int m=r/a, n=m*a, Max=-1;
    Max=max(Max, max(n-1,l)/a+max(n-1,l)%a);
    Max=max(Max, r/a+r%a);
    printf("%d\n", Max);
  }
  return 0;
}