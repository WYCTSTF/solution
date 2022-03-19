#include <bits/stdc++.h>
using namespace std;
const int N=600010;
int trie[N*24][2], latest[N*24];
int s[N], Root[N], n, m, tot;
void insert(int i, int k, int p, int q) { // 统计子树latest，所以用到递归插入
// 当前为s[i]的第k位
    if (k<0) {
        latest[q]=i;
        return ;
    }
    int c=s[i]>>k&1;
    if (p)
        trie[q][c^1]=trie[p][c^1]; // 这里子节点只有c和c^1，反正c要重新插入，会被覆盖，所以就只继承c^1了
    trie[q][c]=++tot;
    insert(i, k-1, trie[p][c], trie[q][c]);
    latest[q]=max(latest[trie[q][0]], latest[trie[q][1]]);
}
int ask(int now, int val, int k, int limit) {
    if (k<0) return s[latest[now]] ^ val;
    int c = val >> k & 1;
    if (latest[trie[now][c^1]]>=limit)
        return ask(trie[now][c^1], val, k-1, limit);
    else
        return ask(trie[now][c], val, k-1, limit);
}
int main() {
    cin>>n>>m;
    latest[0]=-1;
    Root[0]=++tot;
    insert(0, 23, 0, Root[0]);
    for (int i=1; i<=n; i++) {
        int x; cin >> x;
        s[i]=s[i-1]^x;
        Root[i]=++tot;
        insert(i, 23, Root[i-1], Root[i]);
    }
    for (int i=1; i<=m; i++) {
        char op[2]; scanf("%s", op);
        if (op[0]=='A') {
            int x; scanf("%d", &x);
            Root[++n]=++tot;
            s[n]=s[n-1]^x;
            insert(n,23,Root[n-1],Root[n]);
        } else {
            int l, r, x; scanf("%d%d%d", &l, &r, &x);
            cout << ask(Root[r-1], x^s[n], 23, l-1) << endl;
        }
    }
    return 0;
}