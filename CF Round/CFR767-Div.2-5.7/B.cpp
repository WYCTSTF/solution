#include <bits/stdc++.h>
#define rep(i,a,n,k) for(int i=a;i<=n;i+=k)
#define per(i,a,n,k) for(int i=n;i>=a;i-=k)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(),x.end()
using namespace std;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef long long ll;
typedef double db;
const int INF=0x7fffffff;
const int inf=0x3f3f3f3f;
const int MOD=998244353;
const int mod=1e9+7;
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a; }
// head
int main(){
    int tt;cin>>tt;
    while(tt--){
        int l,r,k;
        cin>>l>>r>>k;
        if(l==r&&k==0){
            if(l!=1) puts("YES");
            else puts("NO");
        }
        else{
            if(l%2==1&&r%2==1){
                if(k>=(r-l)/2+1) puts("YES");
                else puts("NO");
            }
            else if(l%2==0&&r%2==0){
                if(k>=(r-l)/2) puts("YES");
                else puts("NO");
            }
            else {
                if(k>=(r-l+1)/2) puts("YES");
                else puts("NO");
            }
        }
    }
    return 0;
}
// 1 13 2
// 3 5 7 11
/*
解决完质数之后再来处理
*/