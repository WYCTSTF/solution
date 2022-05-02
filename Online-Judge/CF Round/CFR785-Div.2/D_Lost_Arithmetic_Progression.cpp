// 给定两个有限长度的等差数列A和B
// 显然 对于A B的公共项组成的C 也是一个有限长度的等差数列
// 给出B C的首项 公差和项数 求出A的可能的数量
/*
先正着想 A和B产生C
那么C中的
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
void read(){}
template<typename T,typename... Ts>
inline void read(T &arg,Ts&... args)
{
	T x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c-'0');c=getchar();}
	arg=x*f;
	read(args...);
}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int lcm(int a,int b){return a/gcd(a,b)*b;}
signed main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int b,q,y;
		read(b,q,y);
		int c,r,z;
		read(c,r,z);
		if(r%q||(c-b)%q||(c-b)/q<0) puts("0");
		else
		{
			int L=(c-b)/q+1,R=(c+(z-1)*r-b)/q+1;
			if(R>y) puts("0");
			else if((L-1)*q<r||(y-R)*q<r) puts("-1");
			else
			{
				int res=0;
				for(int i=1;i*i<=r;i++)
				{
					if(r%i) continue;
					int x=i,y=r/i;
					if(lcm(x,q)==r) (res+=y*y)%=mod;
					if(lcm(y,q)==r&&y!=x) (res+=x*x)%=mod;
				}
				cout<<res<<endl;
			}
		}
	}
	return 0;
}