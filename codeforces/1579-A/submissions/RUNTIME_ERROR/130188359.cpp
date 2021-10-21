#include<stdio.h>
#include<assert.h>
#include<ctype.h>
#include<limits.h>
#include<math.h>
#include<stdbool.h>
#include<stddef.h>
#include<stdint.h>
#include<stdlib.h>
#include<string.h>
 
int main()
{ int N,i;
scanf("%d",&N);
while (N--)
{ char S[]="test";
   scanf("%s",S);
 int LENTH=0;
 for (i=0; S[i]!='\0';i++) LENTH++;
 int A=0,B=0,C=0;
 for (i=0;i<LENTH;i++)
 { if (S[i]=='A')A++;
 if(S[i]=='B')B++;
 if(S[i]=='C')C++;
 }
 if (B==A+C)printf("YES \n");
 else printf("NO \n");
}
return 0;
}
