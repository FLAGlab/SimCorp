#include<cstdio>
#include<cstring>
using namespace std;
char s[100]; 
int c[200];
int T;
int main(){
	scanf("%d",&T);
 while(T--){
		scanf("%s",s);
		c['A']=c['B']=c['C']=0;
 for(int i=strlen(s)-1;i>=0;--i)++c[s[i]];
		printf(c['A']+c['C']==c['B']?"YES\n":"NO\n"); 
 }
 return 0;
}
