#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

struct Edge {
  int to, val;
};

vector<Edge> adj[N];

int dfn[N], low[N], dfncnt, s[N], in_stack[N], tp;
int scc[N], sc;
int sz[N];

void tarjan(int u) {
  low[u] = dfn[u] = ++dfncnt;
  s[++tp] = u;
  in_stack[u] = 1;

  for (auto eg : adj[u]) {
    const int &to = eg.to;
    if (!dfn[to]) {
      tarjan(to);
      low[u] = min(low[u], low[to]);
    } else if (in_stack[to]) {
      low[u] = min(low[u], dfn[to]);
    }
  }
  if (dfn[u] == low[u]) {
    ++sc;
    while (s[tp] != u) {
      scc[s[tp]] = sc;
      sz[sc]++;
      in_stack[s[tp]] = 0;
      --tp;
    }
    scc[s[tp]] = sc;
    sz[sc]++;
    in_stack[s[tp]] = 0;
    --tp;
  }
}