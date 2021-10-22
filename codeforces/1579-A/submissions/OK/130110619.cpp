#include<bits/stdc++.h>
using namespace std;
 
signed main(){
 int t;
 char n;
	scanf("%d",&t);
	getchar();
 while(t--){
 int m[100]={0};
		n=getchar();
 while(n!='\n'){
			m[n]++;
			n=getchar();
 }
 if((m['A']+m['C'])==m['B']) printf("YES\n\n");
 else printf("NO\n\n");
 }
} 
