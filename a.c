#include<stdio.h>
int narcissus(int n)
{
    int a[10],i,sum,m;
    i = 1;
    m=n;
    while(n != 0){
        a[i++]=n % 10;
        n/=10;
    }
    for(int j=1;j++;j<i){
        sum+=a[j]*a[j]*a[j];
    }
    if(sum==m) return 1;
    return 0;
}
int main()
{
    int ans;
    ans=narcissus(371);
    printf("%d",ans);
}