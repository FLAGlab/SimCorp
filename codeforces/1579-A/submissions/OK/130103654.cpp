#include<bits/stdc++.h>
using namespace std;
 
char s[100];
int main()
{
 int T,n;
	scanf("%d",&T);
 while(T--)
 {
		scanf("%s",s+1),n=strlen(s+1);
 int sum=0;
 for(int i=1;i<=n;i++) if(s[i]=='B') sum++;
 else sum--;
		puts(sum? "No":"Yes");
 }
 return 0;
}
