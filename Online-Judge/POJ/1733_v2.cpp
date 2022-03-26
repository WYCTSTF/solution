#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=5010;
struct{int l,r,ans;}query[N];
int a[N<<1],fa[N<<2],n,m,t;
int get(int x){
	if(x==fa[x]) return x;
	return fa[x]=get(fa[x]);
}
int main() {
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		char str[5];
		scanf("%d%d%s",&query[i].l,&query[i].r,str);
		query[i].ans=(str[0]=='o'?1:0);
		a[++t]=query[i].l-1,a[++t]=query[i].r;
	}
	sort(a+1,a+1+t); n=unique(a+1,a+t+1)-a-1;
	for(int i=1;i<=2*n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int x=lower_bound(a+1,a+1+n,query[i].l-1)-a;
		int y=lower_bound(a+1,a+1+n,query[i].r)-a;
		int x_odd=x,x_even=x+n;
		int y_odd=y,y_even=y+n;
		if(query[i].ans==0){
			if(get(x_odd)==get(y_even)){
				printf("%d",i-1);
				return 0;
			}
			fa[get(x_odd)]=get(y_odd);
			fa[get(x_even)]=get(y_even);
		}else{
			if(get(x_odd)==get(y_odd)){
				printf("%d\n",i-1);
				return 0;
			}
			fa[get(x_odd)]=get(y_even);
			fa[get(x_even)]=get(y_odd);
		}
	}
	printf("%d\n",m);
	return 0;
}