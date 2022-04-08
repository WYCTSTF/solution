#include <cstdio>
#include <cmath>
const int N=501000;
int n,m,M;
int a[N],pos[N],tag[10005];
void add(int l,int r,int c){
	if(pos[l]==pos[r]) for(int i=l;i<=r;i++) a[i]+=c;
	else {
		for(int i=l;pos[i]==pos[l];i++) a[i]+=c;
		for(int i=r;pos[i]==pos[r];i--) a[i]+=c;
		for(int i=pos[l]+1;i<pos[r];i++) tag[i]+=c;
	}
}
int main() {
	scanf("%d%d",&n,&m); M=sqrt(n);
	for(int i=1;i<=n;i++) scanf("%d", &a[i]),pos[i]=(i-1)/M+1;
	for(int i=1;i<=m;i++) {
		int op,x,y,k; scanf("%d%d",&op, &x);
		if(op==1) {scanf("%d%d",&y,&k); add(x,y,k);}
		else printf("%d\n", a[x]+tag[pos[x]]);
	}
	return 0;
}