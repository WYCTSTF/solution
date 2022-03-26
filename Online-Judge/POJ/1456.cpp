#include <cstdio>
#include <algorithm>
int n,siz,heap[10100],ans;
struct Node{int d,v;}a[10100];
bool cmp(Node x,Node y){ return x.d < y.d; }
void up(int p){
	while(p>1&&heap[p]<heap[p>>1])
		std::swap(heap[p],heap[p>>1]),p>>=1;
}
void down(int p){
	int s=p<<1;
	while(s<=siz){
		if(s<siz&&heap[s]>heap[s+1]) s++;
		if(heap[s]<heap[p]){
			std::swap(heap[s],heap[p]);
			p=s, s=p<<1;
		} else break;
	}
}
void ins(int x){heap[++siz]=x; up(siz);}
void remove(){ heap[1]=heap[siz--]; down(1); }
int main() {
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;i++) scanf("%d%d",&a[i].v,&a[i].d);
		std::sort(a+1,a+1+n,cmp);ans=0;
		for(int i=1;i<=n;i++){
			if(siz<a[i].d) ins(a[i].v);
			else if(siz==a[i].d&&a[i].v>heap[1]) remove(),ins(a[i].v);
		}
		while(siz>0) ans+=heap[1],remove();
		printf("%d\n",ans);
	}
	return 0;
}