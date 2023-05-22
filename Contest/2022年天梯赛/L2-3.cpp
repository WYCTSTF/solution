#include <bits/stdc++.h>
using namespace std;
const int N = 101000;
int fa[N], tot[N];
int Max = -1, rt;
vector<int> e[N];
void dfs(int u) {
  for(auto v : e[u]) {
    tot[v] = tot[u] + 1;
    dfs(v);
  }
}
int main() {
  int n, m;
  cin >> n >> m; 
  for (int i = 1; i <= n; i++) {
    cin >> fa[i];
    if (fa[i] == -1)
      rt = i;
    else
      e[fa[i]].push_back(i);
  }
  dfs(rt);
	int ans=0;
	set<int>s; s.insert(rt);

	auto up=[&](int u)->void{
		while(u!=rt&&s.find(u)==s.end()){
			ans+=2;
			s.insert(u);
			u=fa[u];
		}
	};

	for(int i=1;i<=m;i++){
		int node; cin>>node;
		up(node);
		Max=max(Max,tot[node]);
		cout<<ans-Max;
		if(i!=m) cout<<endl;
	}
  
  return 0;
}