#include <bits/stdc++.h>
#define rep(i,a,n,k) for(int i=a;i<=n;i+=k)
#define per(i,a,n,k) for(int i=n;i>=a;i-=k)
using namespace std;
// head
const int N=1010;
int a[N][N];
int main(){
    int tt=0; cin>>tt;
    while(tt--){
        int ans=0;
        int n;cin>>n;
        rep(i,1,n,1)
            rep(j,1,n,1)
                cin>>a[i][j];
        rep(sum,4,n<<1,4){
            if(sum<=n)
                rep(i,1,n,2){
                    int j=sum-i;
                    if(j<=n&&j>=1)
                        ans^=a[i][j], ans^=a[i][n-j+1];
                }
            else {
                rep(i,2,n,2){
                    int j=sum-i;
                    if(j<=n&&j>=1)
                        ans^=a[i][j], ans^=a[i][n-j+1];
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}