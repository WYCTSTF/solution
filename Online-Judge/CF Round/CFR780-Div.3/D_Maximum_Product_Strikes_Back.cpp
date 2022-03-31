#include<bits/stdc++.h>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a>b?b:a)
using namespace std;
const int N=200010;
int a[N];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt;cin>>tt;
	queue<pair<int,int>>q;
	while(tt--){
		int n; cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		int st=1,now=1;
		while(st<=n){
			while(st<=n&&a[st]==0) st++; now=st;
			while(now<=n&&a[now]!=0) now++;
			q.push({st,now-1});
			st=now+1;
		}
		int Max=0,tl=n,tr=0;
		while(!q.empty()){
			int l=q.front().first,r=q.front().second; q.pop();
			int tot1=0,tot2=0; for(int i=l;i<=r;i++) {if(a[i]<0) tot1++; if(a[i]==2||a[i]==-2) tot2++;}
			if(tot1%2==0&&Max<tot2) Max=tot2,tl=l,tr=r;
			int tot3=0,tot4=0;
			int ql=l; while(a[ql]>0) ql++; for(int i=ql+1;i<=r;i++){if(a[i]==2||a[i]==-2) tot3++;}
			int qr=r; while(a[qr]>0) qr--; for(int i=l;i<qr;i++){if(a[i]==2||a[i]==-2) tot4++;}
			if(tot3>Max) Max=tot3,tl=ql+1,tr=r;
			if(tot4>Max) Max=tot4,tl=l,tr=qr-1;
		}
		if(Max==0) cout<<tl<<' '<<tr<<endl;
		else cout<<tl-1<<' '<<n-tr<<endl;
	}
	return 0;
}