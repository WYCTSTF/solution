#include <bits/stdc++.h>
using namespace std;
const int N=4010;
int n;
int a[N][N],sum[N][N],p[N][N];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt;cin>>tt;
	string s;
	while(tt--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>s; for(int j=1;j<=n;j++) {
				a[i][j]=a[i+n][j]=a[i][j+n]=a[i+n][j+n]=(s[j-1]=='1'?1:0);
			}
		}
		for(int i=1;i<=n*2;i++){
			for(int j=1;j<=n*2;j++){
				sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
				p[i][j]=p[i-1][j-1]+a[i][j];
			}
		}
		int ans=n*n;
		for(int x=n;x<=2*n;x++)
			for(int y=n;y<=2*n;y++)
				ans=min(ans,sum[x][y]-sum[x-n][y]-sum[x][y-n]+sum[x-n][y-n]+n-2*(p[x][y]-p[x-n][y-n]));
		cout<<ans<<endl;
	}
	return 0;
}