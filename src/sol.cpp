#include <deque>
#include <iostream>
#include <utility>
#include <vector>
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i)
    std::cin >> a[i];
  auto fix = [&](std::deque<std::pair<int, int>> &q, int x, int i, int op) -> void {
    if (q.empty())
      q.push_back({x, i});
    else {
      if (op == 0)
        while (!q.empty() && x >= q.back().first)
          q.pop_back();
      else
        while (!q.empty() && x <= q.back().first)
          q.pop_back();
      q.push_back({x, i});
    }
    while (!q.empty() && q.front().second <= i - k)
      q.pop_front();
  };
  std::deque<std::pair<int, int>> qmn, qmx;
  std::vector<int> amx, amn;
  for (int i = 1; i <= n; ++i) {
    fix(qmn, a[i], i, 1),
    fix(qmx, a[i], i, 0);
    if (i >= k)
      amx.emplace_back(qmx.front().first), amn.emplace_back(qmn.front().first);
  }
  for (auto x : amn)
    std::cout << x << ' ';
  std::cout << '\n';
  for (auto x : amx)
    std::cout << x << ' ';
}
