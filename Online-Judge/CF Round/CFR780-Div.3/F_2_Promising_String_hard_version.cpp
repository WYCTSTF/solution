#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=200010,INF=0x7fffffff;
char ch;
int n,mx,mn,t[3][N],p[N];
void add(int k,int x,int v){
	for(;x<=mx;x+=x&-x) t[k][x]+=v;
}
int qry(int k,int x){
	int ans=0;
	for(;x;x-=x&-x) ans+=t[k][x];
	return ans;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin>>tt;
	while(tt--){
		int n;cin>>n;p[0]=mx=0;mn=INF;
		for(int i=1;i<=n;i++) {
			cin>>ch; p[i]=p[i-1]+((ch=='-')?1:-1);
			mn=min(mn,p[i]);
		}
		mn-=4; //权值>=1 不然/3的时候寄了
		for(int i=0;i<=n;i++) p[i]-=mn;
		for(int i=0;i<=n;i++) mx=max(mx,p[i]/3); // 权值树状数组上界范围
		for(int i=1;i<=mx;i++) t[0][i]=t[1][i]=t[2][i]=0;
		ll ans=0;
		add(p[0]%3,p[0]/3,1);
		for(int i=1;i<=n;i++){
			ans+=qry(p[i]%3,p[i]/3);
			add(p[i]%3,p[i]/3,1);
		}
		cout<<ans<<endl;
	}
}