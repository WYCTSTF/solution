---
title: My Visual Studio Code Settings
tags:
  - 测试
  - 瞎搞
categories: 杂项
---

我原来以为这种trival的事情没有必要记录 直到今天晚上xjb摸快捷键的时候

不小心按了 ⌥ ⇧ d 贴心的Sync把本地设置(和所有扩展)全部反向更新到了2 years ago...

<!-- more -->

## 插件

### Haskell相关
* Hakell
* Haskell Syntax Highlighting

### Git相关
* Git Graph

### Themes & 美化
* Atom One Dark Theme
* Github Theme
* One Dark Pro
* Community Material Theme
* Bracket Pair Colorizer 2
* Brackets Light Pro
* indent-rainbow

### Makrdown
* Markdown All in One
* Markdown PDF


### 一些脚本
* Code Runner


## User Snippets

```json
{
	"contest": {
		"prefix": "contest",
		"body": [
			"#include <bits/stdc++.h>",
			"#define rep(i,a,n,k) for(int i=a;i<=n;i+=k)",
			"#define per(i,a,n,k) for(int i=n;i>=a;i-=k)",
			"#define max(a,b) (a>b?a:b)",
			"#define min(a,b) (a<b?a:b)",
			"#define mp make_pair",
			"#define pb push_back",
			"#define fi first",
			"#define se second",
			"#define il inline",
			"#define rg register",
			"#define SZ(x) ((int)(x).size())",
			"#define all(x) x.begin(),x.end()",
			"using namespace std;",
			"typedef vector<int> VI;",
			"typedef pair<int,int> PII;",
			"typedef long long ll;",
			"typedef double db;",
			"const int INF=0x7fffffff;",
			"const int inf=0x3f3f3f3f;",
			"const int MOD=998244353;",
			"const int mod=1e9+7;",
			"ll gcd(ll a,ll b) { return b?gcd(b,a%b):a; }",
			"// head"
		],
		"description": "缺省源"
	},

	"separator": {
		"prefix": "separator",
		"body": [
			"//----------------------------"
		],
		"description": "分割线"
	},

	"read": {
		"prefix": "read",
		"body": [
			"inline int read(){",
			"\tint x=0,f=1;",
			"\tchar ch=getchar();",
			"\twhile(ch<'0'||ch>'9') f=(ch=='-')?-1:1,ch=getchar();",
			"\twhile(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();",
			"\treturn x*f;",
			"}"
		]
	},

	"headfile": {
        "prefix": "headfile",
        "body": [
            "#include <set>",
            "#include <map>",
            "#include <list>",
            "#include <stack>",
            "#include <queue>",
            "#include <cmath>",
            "#include <deque>",
            "#include <bitset>",
            "#include <cstdio>",
            "#include <vector>",
            "#include <string>",
            "#include <complex>",
            "#include <sstream>",
            "#include <utility>",
            "#include <climits>",
            "#include <cstring>",
            "#include <fstream>",
            "#include <functional>",
            "#include <iostream>",
            "#include <algorithm>",
            "typedef long long ll;",
        ],
        "description": "headfile"
    },

    "write":{
        "prefix": "write",
        "body": [
            "template<typename T>",
            "inline void _write(T x) {",
            "    if (x>=10) _write(x/10);",
            "    putchar('0'+x%10);",
            "}",
            "template<typename T>",
            "inline void write(T x) {",
            "    if (x<0) putchar('-');",
            "    _write(x);",
            "}",
        ],
    },

    "scan":{
        "prefix": "scan",
        "body": [
            "template<typename T>",
            "inline void scan(T &x) {",
            "\tx=0; int f=1; char ch=getchar();",
            "\twhile(ch<'0'||ch>'9')",
            "\t\tf=(ch=='-')?-1:1,ch=getchar();",
            "\twhile (ch>='0'&&ch<='9')",
            "\t\tx=(x<<3)+(x<<1)+ch-48,ch=getchar();",
            "\tx*=f;",
            "}",
        ],
    },

    "fio":{
        "prefix": "fio",
        "body": [
            "ios_base::sync_with_stdio(false);",
            "cin.tie(nullptr);",
        ],
    },

    "Inc":{
        "prefix": "Inc",
        "body": [
            "#include<bits/stdc++.h>",
            "using namespace std;\n",
        ],
    }
}
```