#include<bits/stdc++.h>
#define low(x) (x&-x)
using namespace std;
using ll=long long;
const int N=201000;
int n,y[N],bit[N],BIG[N],SMALL[N];
void add(int p){while(p<=n) bit[p]++,p+=p&-p;}
ll ask(int p){ll ans=0;while(p>0)ans+=bit[p],p-=p&-p;return ans;}
int main() {
	cin>>n;
	for(int i=1;i<=n;i++) cin>>y[i];
	memset(bit,0,sizeof(bit));
	for(int i=1;i<=n;i++){
		SMALL[i]=ask(y[i]-1);
		BIG[i]=ask(n)-ask(y[i]);
		add(y[i]);
	}
	ll ans1=0,ans2=0; memset(bit,0,sizeof(bit));
	for(int i=n;i>=1;i--){
		ans1+=SMALL[i]*ask(y[i]-1);
		ans2+=BIG[i]*(ask(n)-ask(y[i]));
		add(y[i]);
	}
	cout<<ans2<<' '<<ans1<<endl;
	return 0;
}