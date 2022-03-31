#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int arr[N],freq[N];
vector<int>ans;
set<int>s;
int main(){
    int tt; cin>>tt;
    while (tt--){
        int n; cin>>n;
        for (int i=1;i<=n;i++){
            cin>>arr[i];
            freq[arr[i]]++;
        }
        int mex=n+1;
        for (int i=0;i<=n;i++){
            if(freq[i]==0){
                mex=i;
                break;
            }
        }
        ans.clear(); s.clear();
        for (int i=1;i<=n;i++){
            if(s.empty()){
                ans.push_back(mex);
                for(int i=0;i<mex;i++){
                    s.insert(i);
                }
            }
            freq[arr[i]]--;
            s.erase(arr[i]);
            if(freq[arr[i]]==0){
                mex=min(mex,arr[i]);
            }
        }
        cout<<ans.size()<<endl;
        for(auto it:ans){
            cout<<it<<' ';
        }
        cout<<endl;
    }
    return 0;
}