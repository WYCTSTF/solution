#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define sz(a) ((int) (a).size())
#define vi vector < int >
#define me(a, x) memset(a, x, sizeof(a))
#define ull unsigned long long 
using namespace std;
const int N = 1e6 + 7;
int n, a[N], b[N];
bool vis[N]; 
int arr[N], tp;
int ok[N], to[N];
int cyc[N];
int qwq[N], tot, ns;
void mark(int c) {
    L(i, 1, tot) {
        int r = c % qwq[i];
        if(cyc[qwq[i]] != -1 && cyc[qwq[i]] != r) ns = false;
        cyc[qwq[i]] = r;
    }
}
bool solve() {
    tot = 0;
    int xp = tp;
    L(i, 2, xp) if(xp % i == 0) {
        qwq[++tot] = i;
    }
    L(i, 1, tp) ok[arr[i]] = i;
    L(i, 1, tp) if(!ok[b[arr[i]]]) return false;
    L(i, 1, tp) to[i] = ok[b[arr[i]]];
    L(i, 1, tp) mark((to[i] - i + tp) % tp);
    return true;
}
void Main() {
    cin >> n;
    L(i, 1, n) vis[i] = false, cyc[i] = -1;
    L(i, 1, n) cin >> a[i];
    L(i, 1, n) cin >> b[i];
    ns = true;
    L(i, 1, n) if(!vis[i]) {
        tp = 0;
        int u = i;
        while(!vis[u]) arr[++tp] = u, vis[u] = true, u = a[u];
        ns &= solve();
        L(j, 1, tp) ok[arr[j]] = false;
    }
    if(ns) cout << "Yes\n";
    else cout << "No\n";
}
int main () {
    ios :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) Main();
    return 0;
}