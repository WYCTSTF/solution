#include<map>
#include<set>
#include<cmath>
#include<stack>
#include<queue>
#include<cstdio>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define mod 10007
#define pi acos(-1)
#define inf 0x7fffffff
#define ll long long
using namespace std;
ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,blo;
int v[100005],bl[100005],atag[1005],mtag[1005];
void reset(int x)
{
    for(int i=(x-1)*blo+1;i<=min(n,x*blo);i++)
        v[i]=(v[i]*mtag[x]+atag[x])%mod;
    atag[x]=0;mtag[x]=1;
}
void solve(int f,int a,int b,int c)
{
    reset(bl[a]);
    for(int i=a;i<=min(bl[a]*blo,b);i++)
    {
        if(f==0)v[i]+=c;
        else v[i]*=c;
        v[i]%=mod;
    }
    if(bl[a]!=bl[b])
    {
        reset(bl[b]);
        for(int i=(bl[b]-1)*blo+1;i<=b;i++)
        {
            if(f==0)v[i]+=c;
            else v[i]*=c;
            v[i]%=mod;
        }
    }
    for(int i=bl[a]+1;i<=bl[b]-1;i++)
    {
        if(f==0)atag[i]=(atag[i]+c)%mod;
        else 
        {
            atag[i]=(atag[i]*c)%mod;
            mtag[i]=(mtag[i]*c)%mod;
        }
    }
}

int main()
{
    n=read();blo=sqrt(n);
    for(int i=1;i<=n;i++)v[i]=read();
    for(int i=1;i<=n;i++)bl[i]=(i-1)/blo+1;
    for(int i=1;i<=bl[n];i++)mtag[i]=1;        
    for(int i=1;i<=n;i++)
    {
        int f=read(),a=read(),b=read(),c=read();
        if(f==2)printf("%d\n",(v[b]*mtag[bl[b]]+atag[bl[b]])%mod);
        else solve(f,a,b,c);
    }
    return 0;
}