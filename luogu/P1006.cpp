#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=60;
int a[maxn][maxn];
int F[2*maxn][maxn][maxn];
int main()
{
  int m,n;
  scanf("%d%d",&m,&n);
  for(int i=1;i<=m;i++)
    for(int j=1;j<=n;j++)
      scanf("%d",&a[i][j]);
  //F[sum][i][j]=max{F[sum-1][i][j]...
  memset(F,-1,sizeof(F));//赋初值为-1 (原因在后面） 
  F[2][1][1]=0;//最初的点，在左上角，好感度为0 
  for(int k=3;k<m+n;k++)
    for(int i=1;i<n;i++)
      for(int j=i+1;j<=n;j++)
      {
        int s=F[k][i][j];
        if(F[k-1][i][j]>s)s=F[k-1][i][j];
        if(F[k-1][i-1][j]>s)s=F[k-1][i-1][j];
        if(F[k-1][i][j-1]>s)s=F[k-1][i][j-1];
        if(F[k-1][i-1][j-1]>s)s=F[k-1][i-1][j-1];
        if(s==-1)continue;//当s为-1时，说明四种情况都不能到该点，故不存在。 
        F[k][i][j]=s+a[k-i][i]+a[k-j][j];//该点的值为最大的前一个值与当前F[k][i][j]表示两点的值的和。 
      }
  printf("%d",F[m+n-1][n-1][n]);//因为i永远小于j，所以右下角的点不会求到，
  //但是到右下角只有一种情况，就是在右下角的上面和右下角的左边，直接输出就好了。 
  return 0;
 }
