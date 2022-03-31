#include<bits/stdc++.h>
using namespace std;
int main(){
	int tt;cin>>tt;
	stack<char>sta;
	string s;
	bool vis[30];
	while(tt--){
		memset(vis,false,sizeof(vis));
		cin>>s;
		int ans=0;
		for(int i=0;i<(int)(s.size());i++) {
			if(sta.empty()||vis[s[i]-'a']==false) sta.push(s[i]),vis[s[i]-'a']=true;
			else if(vis[s[i]-'a']==true){
				ans+=2; while(sta.empty()==false) sta.pop(); memset(vis,false,sizeof(vis));
			}
		}
		cout<<s.size()-ans<<endl;
	}
	return 0;
}