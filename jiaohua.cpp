#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
int nxt[MAXN*30][2], cnt;
int MAXBIT = 20,val[MAXN];
void init()
{
    nxt[0][0] = nxt[0][1] = 0;
    cnt = 1;
}
void add(int n)
{
    int cur = 0;
    for (int i = MAXBIT; i >= 0; --i)
    {
        int bit = (n >> i) & 1;       
        if (!nxt[cur][bit]) {
            nxt[cnt][0] = nxt[cnt][1] = 0;
            nxt[cur][bit] = cnt++;
        }
        cur = nxt[cur][bit];
    }
    val[cur] = n;
}
int que_mx(int x) {
    int u = 0;
    for (int i = MAXBIT; i >= 0; i--) {
        int bit = ((x >> i) & 1);
        if (nxt[u][bit ^ 1]) u = nxt[u][bit ^ 1];
        else u = nxt[u][bit];
    }
    return val[u]^x;
}
int que_mi(int x) {
    int u = 0;
    for (int i = MAXBIT; i >= 0; i--) {
        int bit = ((x >> i) & 1);
        if (nxt[u][bit]) u = nxt[u][bit];
        else u = nxt[u][bit ^ 1];
    }
    return val[u]^x;
}
int L, R,a[MAXN];
void slove() {
    init();
    cin >> L >> R;
    for (int i = L; i <= R; i++) {
        cin >> a[i];
        add(a[i]);
    }   
    for (int i = L; i <= R; i++) {
        int x = a[i] ^ L;
        if (que_mx(x) == R && que_mi(x) == L) {
            cout << x << endl;
            break;
        }
    }
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);;
	int tt;cin>>tt;
	while(tt--){
		solve();
	}
}