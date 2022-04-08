#include <cstdio>
#include <algorithm>
int n,siz,heap[1001000];
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
	scanf("%d", &n);
	for(int i=1;i<=n;i++){
		int op,x;scanf("%d",&op);
		if(op==1){
			scanf("%d",&x); ins(x);
		} else if(op==2){
			printf("%d\n",heap[1]);
		} else{
			remove();
		}
	}
	return 0;
}