#include <bits/stdc++.h>
using namespace std;
map<string,int>mp;
int main(){
    int tt;cin>>tt;
    while(tt--){
        mp.clear();
        int n; cin>>n;
        bool flag=false;
        for(int i=1;i<=n;i++){
            string tem; cin>>tem;
            if(tem.size()==1)
                flag=true;
            if(tem.size()==2){
                if(tem[0]==tem[1])
                    flag=true;
                else{
                    string s1=tem; reverse(s1.begin(),s1.end());
                    if(mp[s1]==1)
                        flag=true;
                    else{
                        for(int i=0;i<26;i++){
                            char ch='a'+i;
                            string s2=s1; s2.push_back(ch);
                            if(mp[s2]==1){
                                flag=true;
                                break;
                            }
                        }
                    }
                }
            }
            if(tem.size()==3){
                if(tem[0]==tem[2])
                    flag=true;
                else{
                    string s1=tem; reverse(s1.begin(),s1.end());
                    if(mp[s1]==1)
                        flag=true;
                    else{
                        s1.pop_back();
                        if(mp[s1]==1)
                            flag=true;
                    }
                }
            }
            mp[tem]=1;
        }
        if(flag==true) puts("YES");
        else puts("NO");
    }
}