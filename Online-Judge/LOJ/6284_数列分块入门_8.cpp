#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	int m=sqrt(n);
	vector a(n+1,0),p(n+1,0),L(m+2,0),R(m+2,0),tag(m+2,INT_MIN),fix(m+2,0);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p[i]=(i-1)/m+1;
		fix[p[i]]=0;
		if(L[p[i]]==0) L[p[i]]=i;
		R[p[i]]=i;
	}
	auto free=[&](int x)->void{
		if(fix[x]==0) return;
		for(int i=L[x];i<=R[x];i++)
			a[i]=tag[x];
		fix[x]=0;
	};
	auto qry=[&](int x,int y,int val)->int{
		int ans=0;
		free(p[x]);
		for(int i=x;i<=min(R[p[x]],y);i++)
			if(a[i]!=val) a[i]=val; else ans++;
		if(p[x]==p[y]) return ans;
		free(p[y]);
		for(int i=L[p[y]];i<=y;i++)
			if(a[i]!=val) a[i]=val; else ans++;
		for(int i=p[x]+1;i<p[y];i++){
			if(fix[i]==0){
				for(int j=L[i];j<=R[i];j++)
					if(a[j]==val) ans++;
				fix[i]=1; tag[i]=val;
			}else{
				if(tag[i]==val) ans+=R[i]-L[i]+1;
				else tag[i]=val;
			}
		}
		return ans;
	};
	int x,y,val;
	for(int i=1;i<=n;i++){
		cin>>x>>y>>val;
		int now=qry(x,y,val);
		cout<<now<<'\n';
	}
	return 0;
}