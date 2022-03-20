#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1000];
signed main()
{
	int t;
	cin>>t;
	while(t--)	
	{
		int n,sum=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),sum|=a[i];
		cout<<sum<<endl;
	}
}