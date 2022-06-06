#include <bits/stdc++.h>

using namespace std;

int main() {

  double x1, y1, x2, y2, x3, y3, x4, y4;
  scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
  if (x1 > x2)
    swap(x1, x2);
  if (y1 > y2)
    swap(y1, y2);
  if (x3 > x4)
    swap(x3, x4);
  if (y3 > y4)
    swap(y3, y4);
  double l = max(x1, x3);
  double r = min(x2, x4);
  double d = max(y1, y3);
  double u = min(y2, y4);

  cerr << u << ' ' << d << endl;
  cerr << r << ' ' << l << endl;
  if (u <= d || r <= l) {
    puts("0.0000");
    return 0;
  }

  printf("%.4lf", max(0.0, (u - d) * (r - l)));
  return 0;
}