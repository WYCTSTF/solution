#include<bits/stdc++.h>
using namespace std;
int n,t[201000],f[201000],g[401000];
const int N=2e5,mod=998244353;
int main(){
  cin>>n;
  for(int i=0,tem;i<n;++i)cin>>tem,t[tem]++;
	int sj=0;
	f[0]=1;
	for(int i=1;i<=N+200;i++){
		int Z=(sj+t[i])/2;
		for(int j=0;j<=Z;j++)g[j]=0;
		for(int j=0;j<=sj;j++)(g[(j+t[i])/2]+=f[j])%=mod;
		for(int j=Z-1;j>=0;j--)(g[j]+=g[j+1])%=mod;
		for(int j=0;j<=Z;j++)f[j]=g[j];
		sj=Z;
	}
  cout<<f[0]<<'\n';
}
