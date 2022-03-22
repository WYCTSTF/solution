#include<bits/stdc++.h>
using namespace std;
struct RAM
{
    int RAM,COST;
}a[1010];
bool cmp(const RAM &A, const RAM &B){
    return A.COST<B.COST;
}

int main(){
    int tt;cin>>tt;
    int n,k;
    while(tt--){
        cin>>n>>k;
        for(int i=1;i<=n;i++)
            cin>>a[i].COST;
        for(int i=1;i<=n;i++)
            cin>>a[i].RAM;
        sort(a+1,a+1+n,cmp);
        for(int i=1;i<=n&&k>=a[i].COST;i++){
            k+=a[i].RAM;
        }
        cout<<k<<endl;
    }
    return 0;
}