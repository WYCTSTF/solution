#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int ans[N];
int main() {
  int tt;
  cin >> tt;
  int n, k;
  string s;
  while (tt--) {
    cin >> n >> k;
    cin >> s;
    for (int i = 0; i < n; i++)
      ans[i] = 0;

    if (k % 2 == 1) {
      int now = 0;
      while (now < s.size() && s[now] == '0')
        now++;
			if(now<s.size()&&s[now]=='1'){
				ans[now]++;
				for (int i = 0; i < now; i++)
					s[i] = '1';
				for (int i = now + 1; i < s.size(); i++)
					if (s[i] == '1')
						s[i] = '0';
					else
						s[i] = '1';
				k--;
				// cout<<s<<endl;
			} else {
				ans[n-1]++;
				for(int i=0;i<s.size()-1;i++)
					if(s[i]=='1') s[i]='0';
					else s[i]='1';
				k--;
			}
    }
    int t1 = 0, t2 = 0;
    for (int i = 0; i < s.size(); i++)
      if (s[i] == '1')
        t1++;
      else
        t2++;
    int p1 = 0, p2 = 0;

    int limit = min(k, t2 / 2 * 2);
    k -= limit;
    while (p1 < n) {
      if (s[p1] == '0' && limit > 0)
        limit--, s[p1] = '1', t1++, t2--,ans[p1]++;
      p1++;
    }

    p1 = 0, p2 = n - 1;
		limit=0;
    while (p1 < p2) {
			if(limit==k) break;
			if(s[p1]=='1') {p1++;continue;}
			if(s[p2]=='0') {p2--;continue;}
			s[p1]='1',s[p2]='0',limit+=2,ans[p1]++,ans[p2]++;
			p1++,p2--;
    }
		k-=limit;
    if (k > 0)
      ans[0] += k;
    cout << s << endl;
    for (int i = 0; i < n; i++)
      cout << ans[i] << ' ';
    cout << endl;
  }
  return 0;
}