#include<bits/stdc++.h>
 
signed main()
{
 int n;
    scanf("%d",&n);
 
 while(n--)
 {
 char s[]="test";
    	scanf("%s",s);
 
 int l=0;
 for(int i=0; s[i]!='\0';i++) l++;
 
 int a=0,b=0,c=0;
 for(int i=0; i<l; i++)
 {
 if(s[i]=='A') a++;
 if(s[i]=='B') b++;
 if(s[i]=='C') c++;
 }
 
 if(b==a+c) printf ("YES\n");
 else printf("NO\n");
 }
 
 return 0;
}
