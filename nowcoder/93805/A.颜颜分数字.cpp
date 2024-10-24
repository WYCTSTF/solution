#include <iostream>
#include <string>
#include <set>
#ifdef LOCAL
#include "dbg.h"
#else
#define dbg(...) 42
#endif
int main() {
  int tt;
  std::cin >> tt;
  while (tt--) {
    std::string s;
    std::cin >> s;
    int sum = 0;
    for (char c : s)
      sum += c - '0';
    dbg(sum);
    std::set<int> v;
    for (int i = 2; i * i <= sum; ++i)
      if (sum % i == 0)
        v.insert(i), v.insert(sum / i);
    v.insert(0);
    v.insert(1);
    auto check = [&](int k) -> bool {
      int sum = 0;
      for (char c : s) { 
        if (sum > k) return false;
        if (sum == k) sum = 0;
        sum += c - '0';
      }
      if (sum != 0 && sum != k)
        return false;
      return true;
    };
    bool fl = false;
    for (auto i : v) {
      dbg(i);
      if (check(i)) {
        fl = true;
        break;
      }
    }
    std::cout << (fl ? "YES\n" : "NO\n");
  }
}
