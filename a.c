#include <stdio.h>
int *read(int *m,int *n) {
  int a[110010];
  for (int i=1;i<=*m;i++){
    for(int  j=1;j<=*n;j++){
      scanf("%d", &a[i*10+j]);
    }
  }
  return a;
}
void print(int *a,int m,int n) {
  int Min = -1;
  int ans;
  for (int i=1;i<=m;i++){
    for (int j=1;j<=n;j++){
      if (a[i*10+j]>Min) {
        Min=a[i*10+j];
        ans=j;
      }
    }
  }
  printf("%d\n",ans);
}
int main() {
  int m, n;
  scanf("%d%d",&m,&n);
  int *a=read(&m, &n);
  print(a, m, n);
  return 0;
}