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
#define mod 998244353
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
int n,blo,m;
int v[100005];
vector<int>ve[1005];
int st[200005],top;
pair<int,int> query(int b)
{
    int x=1;
    while(b>ve[x].size())
        b-=ve[x].size(),x++;
    return make_pair(x,b-1);
}
void rebuild()
{
    top=0;
    for(int i=1;i<=m;i++)
    {
        for(vector<int>::iterator j=ve[i].begin();j!=ve[i].end();j++)
            st[++top]=*j;
        ve[i].clear();
    }
    int blo2=sqrt(top);
    for(int i=1;i<=top;i++)
        ve[(i-1)/blo2+1].push_back(st[i]);
    m=(top-1)/blo2+1;
}
void insert(int a,int b)
{
    pair<int,int> t=query(a);
    ve[t.first].insert(ve[t.first].begin()+t.second,b);
    if(ve[t.first].size()>20*blo)
        rebuild();
}
int main()
{
    n=read();blo=sqrt(n);
    for(int i=1;i<=n;i++)v[i]=read();
    for(int i=1;i<=n;i++)
        ve[(i-1)/blo+1].push_back(v[i]);
    m=(n-1)/blo+1;
    for(int i=1;i<=n;i++)
    {
        int f=read(),a=read(),b=read(),c=read();
        if(f==0)insert(a,b);
        if(f==1)
        {
            pair<int,int> t=query(b);
            printf("%d\n",ve[t.first][t.second]); 
        }
    }
    return 0;
}