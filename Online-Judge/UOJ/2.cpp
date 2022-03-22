#include<cstdio>
#include<string>
#include<algorithm>
int n,m,val=0,ans=0;
std::pair<std::string,int>a[100010];
int calc(int bit,int now){
    for(int i=1;i<=n;i++){
        int x=a[i].second>>bit&1;
        if(a[i].first=="AND") now&=x;
        else if(a[i].first=="OR") now|=x;
        else now^=x;
    }
    return now;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        char str[5];int x;
        scanf("%s%d",str,&x),a[i]=std::make_pair(str,x);
    }
    for(int bit=29;bit>=0;bit--){
        int res0=calc(bit,0),res1=calc(bit,1);
        if(res0<res1&&(val+(1<<bit))<=m)
            ans+=res1<<bit,val+=1<<bit;
        else ans+=res0<<bit;
    }
    printf("%d",ans);
    return 0;
}