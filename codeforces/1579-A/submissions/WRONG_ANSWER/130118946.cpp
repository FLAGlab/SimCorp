#include<bits/stdc++.h>
using namespace std;
int t,len,tot;
char c[60];
signed main()
{
	scanf("%d",&t);
 while (t--)
 {
		tot=0;
		scanf("%s",c+1);
		len=strlen(c+1);
 for (int i=1;i<=len;i++)
 if (c[i]=='B')
				tot++;
 if (tot==len/2) printf("Yes\n");
 else printf("No\n");
 }
 return 0;
}
