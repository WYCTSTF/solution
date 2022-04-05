#include<cstdio>
#include<algorithm>
#include<cmath>
#define N 100010
using namespace std;
int n,st,a[N],bl[N],le[N],ri[N];
int b[321],check[321],l,r,c;

inline int read()
{
	int x=0,f=0; char c=getchar();
	while (c<'0' || c>'9') f=(c=='-') ? 1:f,c=getchar();
	while (c>='0' && c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return f ? -x:x;
}

void update(int x)
{
	if (!check[x]) return;
	for (int i=le[x];i<=ri[x];i++) a[i]=b[x];
	check[x]=0,b[x]=-1;
}

int q_c(int l,int r,int c)
{
	int ans=0;
	update(bl[l]);
	for (int i=l;i<=min(ri[bl[l]],r);i++)
		if (a[i]==c) ans++; else a[i]=c;
	if (bl[l]!=bl[r])
	{
		update(bl[r]);
		for (int i=le[bl[r]];i<=r;i++)
			if (a[i]==c) ans++; else a[i]=c;
	}
	for (int i=bl[l]+1;i<=bl[r]-1;i++)
		if (check[i])
		{
			if (b[i]==c) ans+=st;
			else b[i]=c;
		}
		else
		{
			for (int j=le[i];j<=ri[i];j++)
				if (a[j]==c) ans++;
			check[i]=1,b[i]=c;
		}
	return ans;
}

int main()
{
	n=read(),st=sqrt(n);
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++)
	{
		bl[i]=(i-1)/st+1;
		if (!le[bl[i]]) le[bl[i]]=i;
		ri[bl[i]]=i;
	}
	for (int i=1;i<=n;i++)
	{
		l=read(),r=read(),c=read();
		printf("%d\n",q_c(l,r,c));
	}
	return 0;
}