#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=5010;
struct {int l,r,ans;}query[N];
int a[N<<1],fa[N<<1],d[N<<1],n,m,t;
int get(int x){
	if(x==fa[x]) return x;
	int root=get(fa[x]);
	d[x]^=d[fa[x]];
	return fa[x]=root;
}
int main() {
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		char str[5];
		scanf("%d%d%s",&query[i].l,&query[i].r,str);
		query[i].ans=(str[0]=='o'?1:0);
		a[++t]=query[i].l-1;a[++t]=query[i].r; // 离散化
	}
	sort(a+1,a+1+t);
	n=unique(a+1,a+1+t)-a-1;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int x=lower_bound(a+1,a+1+n,query[i].l-1)-a;
		int y=lower_bound(a+1,a+1+n,query[i].r)-a;
		int p=get(x),q=get(y);
		if(p==q){
			if((d[x]^d[y])!=query[i].ans){
				printf("%d\n",i-1); return 0;
			}
		} else fa[p]=q,d[p]=d[x]^d[y]^query[i].ans;
	}
	printf("%d\n",m);
	return 0;
}