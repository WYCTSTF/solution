#include<bits/stdc++.h>
using namespace std;
int prime(int x){
  for (int i=2;i*i<=x;i++) if(x%i==0) return i;
  return -1;
}
int main() {
  int tt;cin>>tt;
  while(tt--){
    int n,d,k,tot=0;cin>>n>>d;
    while(n%d==0) n/=d,tot++;
    if (tot==1) {puts("NO"); continue;}
    if (prime(n)!=-1) {puts("YES"); continue;}

    if (tot==3&&prime(d)==n&&d==prime(d)*n) {puts("NO"); continue;}
    if (tot>=3&&prime(d)!=-1) {puts("YES"); continue;}
    puts("NO");
  }
  return 0;
}