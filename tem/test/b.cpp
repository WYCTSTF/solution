#include<bits/stdc++.h>
#define int long long
using namespace std;
bool solve() {
	multiset<int>s;
	int tem,n;cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++) cin>>tem,sum+=tem,s.insert(tem);
	queue<int>q;
	q.push(sum/2); q.push(sum-sum/2);
	while(s.size()>1) {
		if(q.front()==0 || q.front()==1) {return false;}
		if(s.count(q.front())>=1) s.erase(q.front());
		else {q.push(q.front()/2); q.push(q.front()-q.front()/2); q.pop();}
	}
	if (s.size()==1&&q.size()==1&&q.front()==*s.begin()) return true;
}
signed main(){
	int tt;cin>>tt;
	while(tt--) {
		if(solve()) puts("YES");
		else puts("NO");
	}
	return 0;
}