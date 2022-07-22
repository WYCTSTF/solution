#include <bits/stdc++.h>
#define ls p << 1
#define rs p << 1 | 1
#define mid ((l + r) >> 1)

using namespace std;
using ll = long long;

const int N = 200010;

// seg 是 以i为起点的三元组数量 建立的线段树
// tot 就区间计数
ll seg[N << 2], tot[N << 2], tag[N << 2];

void update(int p) {
  seg[p] = seg[ls] + seg[rs];
  tot[p] = tot[ls] + tot[rs];
}

void spread(int p) {
  if (tag[p] == 0)
    return;
  seg[ls] += tag[p] * tot[ls], tag[ls] += tag[p];
  seg[rs] += tag[p] * tot[rs], tag[rs] += tag[p];
  tag[p] = 0;
}

void fix(int p, int l, int r, int x, int v, int w) {
  if (l == r) {
    tot[p] = v, seg[p] = w;
    return;
  }
  spread(p);
  if (x <= mid)
    fix(ls, l, mid, x, v, w);
  else
    fix(rs, mid + 1, r, x, v, w);
  update(p);
}

void mark(int p, int l, int r, int x, int y, int d) {
  if (x <= l && r <= y) {
    seg[p] += tot[p] * d, tag[p] += d;
    return;
  }
  spread(p);
  if (x <= mid)
    mark(ls, l, mid, x, y, d);
  if (y > mid)
    mark(rs, mid + 1, r, x, y, d);
  update(p);
}

ll query(int p, int l, int r, int x, int y, ll *arr) {
  if (x <= l && r <= y)
    return arr[p];
  if (y < l || x > r)
    return 0;
  spread(p);
  ll ans = 0;
  if (x <= mid)
    ans += query(ls, l, mid, x, y, arr);
  if (y > mid)
    ans += query(rs, mid + 1, r, x, y, arr);
  return ans;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n = 200000, q, d;
  cin >> q >> d;

  ll ans = 0;

  while (q--) {
    int i;
    cin >> i;

    ll t = query(1, 1, n, min(i + 1, n), min(i + d, n), tot);
    if (query(1, 1, n, i, i, tot)) {
      mark(1, 1, n, max(1, i - d), max(1, i - 1), -1);
      fix(1, 1, n, i, 0, 0);
      ans -=
          t * (t - 1) / 2 + query(1, 1, n, max(1, i - d), max(1, i - 1), seg);
    } else {
      ans +=
          t * (t - 1) / 2 + query(1, 1, n, max(1, i - d), max(1, i - 1), seg);
      mark(1, 1, n, max(1, i - d), max(1, i - 1), 1);
      fix(1, 1, n, i, 1, t);
    }
    cout << ans << endl;
  }
  return 0;
}