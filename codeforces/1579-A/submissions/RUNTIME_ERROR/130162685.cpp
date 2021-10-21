#include <stdio.h>
#include <string.h>
 
int main() {
 int t;
	scanf("%d",&t);
 for (int m=0;m<t;m++)
 {
 char s[20];
        scanf("%s", s);
 int c1=0,c2=0,c3=0;
 int len1 = strlen(s);
 for (int i=0;i<len1;i++)
 {
 if(s[i]=='A'){
                c1 +=1;
 }
 if(s[i]=='B'){
                c2 +=1;
 }
 if(s[i]=='C'){
                c3 +=1;
 }
 }
 if(c1+c3==c2){
            printf("YES\n");
 }
 else
 {
            printf("NO\n");
 }
 }
}
