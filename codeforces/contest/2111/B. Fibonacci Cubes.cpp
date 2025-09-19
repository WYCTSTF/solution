#include <array>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
  int tt;
  std::cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    int l1 = 1, l2 =2;
    for (int i = 3; i <= n; ++i) {
      int tem = l1 + l2;
      l1 = l2, l2 = tem;
    }
    for (int i = 1; i <= m; ++i) {
      array<int, 3> arr;
      cin >> arr[0] >> arr[1] >> arr[2];
      sort(arr.begin(), arr.end());
      if (arr[0] >= l2 && arr[1] >= l2 && arr[2] >= l1 + l2)
        cout << '1';
      else
        cout << '0';
    }
    cout << '\n';
  }
  return 0;
}
