#include<bits/stdc++.h>
#define N 100010
using namespace std;
using ll=long long;
int n,m,a[N],p[N];
int tag[321],fix[321],lef[321],righ[321];
template<typename T> inline void scan(T &x) {
	x=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9')
		f=(ch=='-')?-1:1,ch=getchar();
	while (ch>='0'&&ch<='9')
		x=(x<<3)+(x<<1)+ch-48,ch=getchar();
	x*=f;
}
void reset(int x){
	if(!fix[x]) return;
	for(int i=lef[x];i<=righ[x];i++){
		a[i]=tag[x];
	}
	fix[x]=0; tag[x]=-1;
}
int solve(int x,int y,int val){
	int ans=0;
	reset(p[x]);
	for(int i=x;i<=min(righ[p[x]],y);i++){
		if(a[i]==val) ans++; else a[i]=val;
	}
	if(p[x]!=p[y]){
		reset(p[y]);
		for(int i=lef[p[y]];i<=y;i++)
			if(a[i]==val) ans++; else a[i]=val;
	}
	for(int i=p[x]+1;i<p[y];i++){
		if(fix[i]){
			if(tag[i]==val) ans+=val;
			else tag[i]=val;
		} else{
			for(int j=lef[i];j<=righ[i];j++)
				if(a[j]==val) ans++;
			fix[i]=1; tag[i]=val;
		}
	}
	return ans;
}
int main() {
	scan(n); m=sqrt(n);
	for(int i=1;i<=n;i++) {
		scan(a[i]),p[i]=(i-1)/m+1;
		if(lef[p[i]]==0) lef[p[i]]=i;
		righ[p[i]]=i;
	}
	for(int i=1;i<=n;i++){
		int x,y,val; scan(x),scan(y),scan(val);
		printf("%d\n",solve(x,y,val));
	}
	return 0;
}