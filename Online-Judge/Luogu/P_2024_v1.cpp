#include <bits/stdc++.h>
using namespace std;
const int N=50010;
int n,k,ans,fa[N*3];
int get(int o){return fa[o]==o?o:fa[o]=get(fa[o]);}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);;
	cin>>n>>k;
	for(int i=1;i<=3*n;i++) fa[i]=i;
	for(int i=1;i<=k;i++){
		int op,x,y; cin>>op>>x>>y;
		if(x>n||y>n) {ans++; continue;}
		if(op==1){
			if(get(x+n)==get(y)||get(x+n+n)==get(y)){ ans++; continue; }
			fa[get(x)]=get(y); fa[get(x+n)]=get(y+n); fa[get(x+n+n)]=get(y+n+n);
		}else{
			if(get(x)==get(y)||get(x)==get(y+n)) {ans++; continue;}
			fa[get(x+n)]=get(y); fa[get(x+n+n)]=get(y+n); fa[get(x)]=get(y+n+n);
		}
	}
	cout<<ans<<endl;
	return 0;
}