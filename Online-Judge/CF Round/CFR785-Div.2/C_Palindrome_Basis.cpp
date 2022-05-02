#include <bits/stdc++.h>
using namespace std;
int main() {
  int temp[] = {98, 87, 81, 79, 52, 49, 33, 21, 18, 6};
  int tag = 81;
  int l = 0, r = 9, mid;
  bool flag = false;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (tag == temp[mid]) {
      flag = true;
      break;
    }
    if (tag > temp[mid])
      r = mid - 1;
    else
			l = mid + 1;
  }
	// cout << mid << endl;
  if (flag)
    cout << mid + 1 << endl;
  else
    puts("NO");
  return 0;
}