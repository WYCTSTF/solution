pair<vector<int>, vector<int>> manacher(string s) {
  int n = s.size();
  vector<int> d1(n), d2(n);
  int ans = 0;
  for (int i = 0, l = 0, r = -1; i < n; ++i) {
    int len = (i > r) ? 1 : min(r - i + 1, d1[l + r - i]);
    while (i - len >= 0 && i + len < n && s[i - len] == s[i + len]) ++len;
    d1[i] = len;
    if (r < i + len - 1) r = i + len - 1, l = i - len + 1;
  }
  for (int i = 0, l = 0, r = -1; i < n; ++i) {
    int len = (i > r) ? 0 : min(r - i + 1, d2[l + r - i + 1]);
    while (i - len - 1 >= 0 && i + len < n && s[i - len - 1] == s[i + len])
      ++len;
    d2[i] = len;
    if (r < i + len - 1) r = i + len - 1, l = i - len;
  }
  return {d1, d2};
}
