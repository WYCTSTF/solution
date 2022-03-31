#include<cstdio>
#include<cstring>
int main() {
  char s[55], ch;
  int tt; scanf("%d\n", &tt);
  while (tt--) {
    bool flag=false;
    scanf("%s\n%c", s+1, &ch);
    int n=strlen(s+1);
    for(int i=1;i<=n;i++) if(s[i]==ch&&i%2==1) {flag=true; break;}
    puts((flag==true)?"YES":"NO");
  }
}